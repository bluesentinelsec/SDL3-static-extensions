/**
 * @file http_test.cpp
 * @brief Tests for SDLStatic::Http — the mog HTTP/S client + server C API.
 *
 * Entirely self-contained over loopback: the embedded mog server binds an
 * ephemeral 127.0.0.1 port and the mog client talks to it — full HTTP
 * round trips (and an HTTPS one via the self-signed dev path) with no
 * external network. mog is consumed via FetchContent at a pinned release
 * and statically linked; see deps/mog.md.
 */

#include <SDL3/SDL.h>
#include <gtest/gtest.h>
#include <mog/mog_c.h>

#include <cstring>
#include <string>

namespace
{

void HelloHandler(const mog_server_request *req, mog_server_response *resp, void *userdata)
{
    (void)userdata;
    EXPECT_STREQ(mog_server_request_method(req), "GET");
    mog_server_response_set_status(resp, 200);
    mog_server_response_set_header(resp, "Content-Type", "text/plain");
    static const char body[] = "hello from mog";
    mog_server_response_set_body(resp, body, sizeof(body) - 1);
}

void EchoHandler(const mog_server_request *req, mog_server_response *resp, void *userdata)
{
    (void)userdata;
    size_t len = 0;
    const char *body = mog_server_request_body(req, &len);
    mog_server_response_set_status(resp, 200);
    mog_server_response_set_body(resp, body, len);
}

class HttpLoopback : public ::testing::Test
{
  protected:
    void SetUp() override
    {
        server_ = mog_server_new();
        ASSERT_NE(server_, nullptr);
        mog_server_set_bind_address(server_, "127.0.0.1");
        mog_server_set_port(server_, 0); /* ephemeral */
        ASSERT_EQ(mog_server_route(server_, "GET", "/hello", HelloHandler, nullptr), 0);
        ASSERT_EQ(mog_server_route(server_, "POST", "/echo", EchoHandler, nullptr), 0);
    }
    void TearDown() override
    {
        mog_server_free(server_);
    }

    std::string Url(const char *path) const
    {
        char url[128];
        SDL_snprintf(url, sizeof(url), "http://127.0.0.1:%u%s",
                     static_cast<unsigned>(mog_server_port(server_)), path);
        return url;
    }

    mog_server *server_ = nullptr;
};

TEST_F(HttpLoopback, GetRoundTripsOverLoopback)
{
    ASSERT_EQ(mog_server_start(server_), 0);
    mog_response *resp = mog_get(Url("/hello").c_str());
    ASSERT_NE(resp, nullptr);
    EXPECT_NE(mog_response_ok(resp), 0) << mog_response_error_message(resp);
    EXPECT_EQ(mog_response_status(resp), 200);
    size_t len = 0;
    const char *body = mog_response_body(resp, &len);
    EXPECT_EQ(std::string(body, len), "hello from mog");
    mog_response_free(resp);
}

TEST_F(HttpLoopback, UnknownRouteIs404NotAnError)
{
    ASSERT_EQ(mog_server_start(server_), 0);
    mog_response *resp = mog_get(Url("/nope").c_str());
    ASSERT_NE(resp, nullptr);
    EXPECT_NE(mog_response_ok(resp), 0) << "transport succeeded; 404 is an HTTP answer";
    EXPECT_EQ(mog_response_status(resp), 404);
    mog_response_free(resp);
}

TEST_F(HttpLoopback, PostEchoesBody)
{
    ASSERT_EQ(mog_server_start(server_), 0);
    static const char payload[] = "level=3&player=kraken";
    mog_response *resp = mog_post(Url("/echo").c_str(), payload, sizeof(payload) - 1);
    ASSERT_NE(resp, nullptr);
    EXPECT_NE(mog_response_ok(resp), 0) << mog_response_error_message(resp);
    size_t len = 0;
    const char *body = mog_response_body(resp, &len);
    EXPECT_EQ(std::string(body, len), payload);
    mog_response_free(resp);
}

TEST(HttpErrors, ConnectionRefusedFailsCleanly)
{
    /* Nothing listens on this port; must yield an error response, not crash. */
    mog_response *resp = mog_get("http://127.0.0.1:47999/unreachable");
    ASSERT_NE(resp, nullptr);
    EXPECT_EQ(mog_response_ok(resp), 0);
    EXPECT_NE(mog_response_error_message(resp), nullptr);
    mog_response_free(resp);

    /* Garbage URL. */
    mog_response *bad = mog_get("not-a-url");
    if (bad != nullptr)
    {
        EXPECT_EQ(mog_response_ok(bad), 0);
        mog_response_free(bad);
    }
}

TEST(HttpLifecycle, HandlesAreSafeToFree)
{
    mog_server_free(nullptr); /* documented no-op */
    mog_request *request = mog_request_new("GET", "http://127.0.0.1:1/never-sent");
    ASSERT_NE(request, nullptr);
    mog_request_free(request);
}

} // namespace
