/**
 * @file net_test.cpp
 * @brief Tests for SDLStatic::Net (vendored SDL_net, NET_* API).
 *
 * Entirely self-contained: every data-path test runs over 127.0.0.1, so no
 * external network or DNS is required (CI runners always have loopback).
 * Ports are picked from a high range with retry, since there is no
 * bound-port getter for ephemeral binds.
 */

#include <SDL3/SDL.h>
#include <SDL3_net/SDL_net.h>
#include <gtest/gtest.h>

#include <cstring>

namespace
{

class NetFoundation : public ::testing::Test
{
  protected:
    static void SetUpTestSuite()
    {
        ASSERT_TRUE(SDL_Init(0)) << SDL_GetError();
        ASSERT_TRUE(NET_Init()) << SDL_GetError();
    }
    static void TearDownTestSuite()
    {
        NET_Quit();
        SDL_Quit();
    }

    // Resolve 127.0.0.1 synchronously; never touches real DNS.
    static NET_Address *Loopback()
    {
        NET_Address *addr = NET_ResolveHostname("127.0.0.1");
        EXPECT_NE(addr, nullptr) << SDL_GetError();
        EXPECT_EQ(NET_WaitUntilResolved(addr, 5000), NET_SUCCESS) << SDL_GetError();
        return addr;
    }

    // Bind a server on a high port, retrying on collisions.
    static NET_Server *BindServer(NET_Address *addr, Uint16 *out_port)
    {
        for (Uint16 port = 42750; port < 42800; ++port)
        {
            NET_Server *server = NET_CreateServer(addr, port, 0);
            if (server != nullptr)
            {
                *out_port = port;
                return server;
            }
        }
        return nullptr;
    }
};

TEST_F(NetFoundation, VersionIsWired)
{
    EXPECT_GE(NET_Version(), SDL_NET_VERSION);
}

TEST_F(NetFoundation, ResolvesLoopbackAndFormatsAddress)
{
    NET_Address *addr = Loopback();
    ASSERT_NE(addr, nullptr);
    EXPECT_EQ(NET_GetAddressStatus(addr), NET_SUCCESS);
    const char *str = NET_GetAddressString(addr);
    ASSERT_NE(str, nullptr);
    EXPECT_STREQ(str, "127.0.0.1");

    // The bytes are documented as an opaque, protocol-specific blob (e.g. a
    // whole sockaddr) — the string above is the canonical representation, so
    // here we only assert the documented contract: non-NULL and sized.
    int num_bytes = 0;
    const void *bytes = NET_GetAddressBytes(addr, &num_bytes);
    ASSERT_NE(bytes, nullptr) << SDL_GetError();
    EXPECT_GT(num_bytes, 0);

    // Refcounting round-trip must be balanced and harmless.
    EXPECT_EQ(NET_RefAddress(addr), addr);
    NET_UnrefAddress(addr);
    NET_UnrefAddress(addr);
}

TEST_F(NetFoundation, CompareAddressesIsConsistent)
{
    NET_Address *a = Loopback();
    NET_Address *b = Loopback();
    ASSERT_NE(a, nullptr);
    ASSERT_NE(b, nullptr);
    EXPECT_EQ(NET_CompareAddresses(a, a), 0);
    EXPECT_EQ(NET_CompareAddresses(a, b), 0) << "two loopback resolves should compare equal";
    NET_UnrefAddress(a);
    NET_UnrefAddress(b);
}

TEST_F(NetFoundation, ResolutionOfInvalidHostFailsCleanly)
{
    // RFC 2606 reserves .invalid: resolution must fail, not crash or hang.
    NET_Address *addr = NET_ResolveHostname("does-not-exist.invalid");
    ASSERT_NE(addr, nullptr) << "resolution is async; handle should be created";
    const NET_Status status = NET_WaitUntilResolved(addr, 15000);
    EXPECT_EQ(status, NET_FAILURE) << "resolving a .invalid name should fail";
    NET_UnrefAddress(addr);
}

TEST_F(NetFoundation, TcpLoopbackEchoBothDirections)
{
    NET_Address *addr = Loopback();
    ASSERT_NE(addr, nullptr);

    Uint16 port = 0;
    NET_Server *server = BindServer(addr, &port);
    ASSERT_NE(server, nullptr) << SDL_GetError();

    NET_StreamSocket *client = NET_CreateClient(addr, port, 0);
    ASSERT_NE(client, nullptr) << SDL_GetError();
    ASSERT_EQ(NET_WaitUntilConnected(client, 5000), NET_SUCCESS) << SDL_GetError();

    // Accept may need a beat for the connection to land.
    NET_StreamSocket *accepted = nullptr;
    for (int i = 0; i < 50 && accepted == nullptr; ++i)
    {
        ASSERT_TRUE(NET_AcceptClient(server, &accepted)) << SDL_GetError();
        if (accepted == nullptr)
        {
            SDL_Delay(20);
        }
    }
    ASSERT_NE(accepted, nullptr) << "no connection accepted within 1s";

    // client -> server
    const char ping[] = "ping over SDLStatic::Net";
    ASSERT_TRUE(NET_WriteToStreamSocket(client, ping, sizeof(ping))) << SDL_GetError();
    ASSERT_EQ(NET_WaitUntilStreamSocketDrained(client, 5000), 0);

    char buffer[64] = {};
    int got = 0;
    for (int i = 0; i < 50 && got < static_cast<int>(sizeof(ping)); ++i)
    {
        const int n = NET_ReadFromStreamSocket(accepted, buffer + got,
                                               static_cast<int>(sizeof(buffer)) - got);
        ASSERT_GE(n, 0) << SDL_GetError();
        got += n;
        if (got < static_cast<int>(sizeof(ping)))
        {
            SDL_Delay(20);
        }
    }
    ASSERT_EQ(got, static_cast<int>(sizeof(ping)));
    EXPECT_STREQ(buffer, ping);

    // server -> client
    const char pong[] = "pong";
    ASSERT_TRUE(NET_WriteToStreamSocket(accepted, pong, sizeof(pong))) << SDL_GetError();
    std::memset(buffer, 0, sizeof(buffer));
    got = 0;
    for (int i = 0; i < 50 && got < static_cast<int>(sizeof(pong)); ++i)
    {
        const int n = NET_ReadFromStreamSocket(client, buffer + got,
                                               static_cast<int>(sizeof(buffer)) - got);
        ASSERT_GE(n, 0) << SDL_GetError();
        got += n;
        if (got < static_cast<int>(sizeof(pong)))
        {
            SDL_Delay(20);
        }
    }
    ASSERT_EQ(got, static_cast<int>(sizeof(pong)));
    EXPECT_STREQ(buffer, pong);

    NET_DestroyStreamSocket(accepted);
    NET_DestroyStreamSocket(client);
    NET_DestroyServer(server);
    NET_UnrefAddress(addr);
}

TEST_F(NetFoundation, UdpLoopbackDatagramRoundTrip)
{
    NET_Address *addr = Loopback();
    ASSERT_NE(addr, nullptr);

    Uint16 recv_port = 0;
    NET_DatagramSocket *receiver = nullptr;
    for (Uint16 port = 42850; port < 42900 && receiver == nullptr; ++port)
    {
        receiver = NET_CreateDatagramSocket(addr, port, 0);
        if (receiver != nullptr)
        {
            recv_port = port;
        }
    }
    ASSERT_NE(receiver, nullptr) << SDL_GetError();

    NET_DatagramSocket *sender = NET_CreateDatagramSocket(addr, 0, 0);
    ASSERT_NE(sender, nullptr) << SDL_GetError();

    const char payload[] = "datagram payload";
    NET_Datagram *dgram = nullptr;
    // UDP is lossy even on loopback in theory; send a few times.
    for (int attempt = 0; attempt < 5 && dgram == nullptr; ++attempt)
    {
        ASSERT_TRUE(NET_SendDatagram(sender, addr, recv_port, payload, sizeof(payload)))
            << SDL_GetError();
        for (int i = 0; i < 25 && dgram == nullptr; ++i)
        {
            ASSERT_TRUE(NET_ReceiveDatagram(receiver, &dgram)) << SDL_GetError();
            if (dgram == nullptr)
            {
                SDL_Delay(20);
            }
        }
    }
    ASSERT_NE(dgram, nullptr) << "datagram never arrived on loopback";
    ASSERT_EQ(dgram->buflen, static_cast<int>(sizeof(payload)));
    EXPECT_STREQ(reinterpret_cast<const char *>(dgram->buf), payload);
    EXPECT_EQ(NET_CompareAddresses(dgram->addr, addr), 0);

    NET_DestroyDatagram(dgram);
    NET_DestroyDatagramSocket(sender);
    NET_DestroyDatagramSocket(receiver);
    NET_UnrefAddress(addr);
}

TEST_F(NetFoundation, WaitUntilInputAvailableSeesIncomingData)
{
    NET_Address *addr = Loopback();
    ASSERT_NE(addr, nullptr);

    Uint16 port = 0;
    NET_Server *server = BindServer(addr, &port);
    ASSERT_NE(server, nullptr) << SDL_GetError();
    NET_StreamSocket *client = NET_CreateClient(addr, port, 0);
    ASSERT_NE(client, nullptr) << SDL_GetError();
    ASSERT_EQ(NET_WaitUntilConnected(client, 5000), NET_SUCCESS);

    NET_StreamSocket *accepted = nullptr;
    for (int i = 0; i < 50 && accepted == nullptr; ++i)
    {
        ASSERT_TRUE(NET_AcceptClient(server, &accepted));
        if (accepted == nullptr)
        {
            SDL_Delay(20);
        }
    }
    ASSERT_NE(accepted, nullptr);

    const char byte = 'x';
    ASSERT_TRUE(NET_WriteToStreamSocket(client, &byte, 1));

    void *sockets[1] = {accepted};
    const int ready = NET_WaitUntilInputAvailable(sockets, 1, 5000);
    EXPECT_EQ(ready, 1) << SDL_GetError();

    NET_DestroyStreamSocket(accepted);
    NET_DestroyStreamSocket(client);
    NET_DestroyServer(server);
    NET_UnrefAddress(addr);
}

TEST_F(NetFoundation, ConnectionToClosedPortFailsCleanly)
{
    NET_Address *addr = Loopback();
    ASSERT_NE(addr, nullptr);
    // Nothing listens here (outside the ranges the other tests bind).
    NET_StreamSocket *client = NET_CreateClient(addr, 42999, 0);
    if (client != nullptr)
    {
        const NET_Status status = NET_WaitUntilConnected(client, 5000);
        EXPECT_EQ(status, NET_FAILURE) << "connecting to a closed loopback port should fail";
        NET_DestroyStreamSocket(client);
    }
    NET_UnrefAddress(addr);
}

TEST_F(NetFoundation, GetLocalAddressesReportsSomething)
{
    int count = 0;
    NET_Address **addresses = NET_GetLocalAddresses(&count);
    ASSERT_NE(addresses, nullptr) << SDL_GetError();
    EXPECT_GT(count, 0);
    for (int i = 0; i < count; ++i)
    {
        EXPECT_NE(NET_GetAddressString(addresses[i]), nullptr);
    }
    NET_FreeLocalAddresses(addresses);
}

} // namespace
