/* GENERATED FILE - DO NOT EDIT.
 * Regenerate: python3 -m tools.bindgen
 * Lua bindings for SDL_net. */
#include "../src/gen_support_lua.h"

#include <SDL3_net/SDL_net.h>
#include <string.h>

static void GenDtor_NET_DestroyStreamSocket(void *p)
{
    NET_StreamSocket *typed = (NET_StreamSocket *)p;
    NET_DestroyStreamSocket(typed);
}

static void GenDtor_NET_DestroyServer(void *p)
{
    NET_Server *typed = (NET_Server *)p;
    NET_DestroyServer(typed);
}

static void GenDtor_NET_DestroyDatagramSocket(void *p)
{
    NET_DatagramSocket *typed = (NET_DatagramSocket *)p;
    NET_DestroyDatagramSocket(typed);
}

static int GenL_NET_CompareAddresses(lua_State *L)
{
    (void)L;
    const NET_Address *a0 = (const NET_Address *)SDLStaticGen_LuaCheckHandle(L, 1, "NET_Address");
    const NET_Address *a1 = (const NET_Address *)SDLStaticGen_LuaCheckHandle(L, 2, "NET_Address");
    int rv = NET_CompareAddresses(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_NET_CreateClient(lua_State *L)
{
    (void)L;
    NET_Address *a0 = (NET_Address *)SDLStaticGen_LuaCheckHandle(L, 1, "NET_Address");
    Uint16 a1 = (Uint16)luaL_checkinteger(L, 2);
    SDL_PropertiesID a2 = (SDL_PropertiesID)luaL_checkinteger(L, 3);
    NET_StreamSocket * rv = NET_CreateClient(a0, a1, a2);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "NET_StreamSocket", GenDtor_NET_DestroyStreamSocket);
    return 1;
}

static int GenL_NET_CreateDatagramSocket(lua_State *L)
{
    (void)L;
    NET_Address *a0 = (NET_Address *)SDLStaticGen_LuaCheckHandle(L, 1, "NET_Address");
    Uint16 a1 = (Uint16)luaL_checkinteger(L, 2);
    SDL_PropertiesID a2 = (SDL_PropertiesID)luaL_checkinteger(L, 3);
    NET_DatagramSocket * rv = NET_CreateDatagramSocket(a0, a1, a2);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "NET_DatagramSocket", GenDtor_NET_DestroyDatagramSocket);
    return 1;
}

static int GenL_NET_CreateServer(lua_State *L)
{
    (void)L;
    NET_Address *a0 = (NET_Address *)SDLStaticGen_LuaCheckHandle(L, 1, "NET_Address");
    Uint16 a1 = (Uint16)luaL_checkinteger(L, 2);
    SDL_PropertiesID a2 = (SDL_PropertiesID)luaL_checkinteger(L, 3);
    NET_Server * rv = NET_CreateServer(a0, a1, a2);
    SDLStaticGen_LuaPushOwned(L, (void *)rv, "NET_Server", GenDtor_NET_DestroyServer);
    return 1;
}

static int GenL_NET_DestroyDatagram(lua_State *L)
{
    (void)L;
    NET_Datagram *a0 = (NET_Datagram *)SDLStaticGen_LuaCheckHandle(L, 1, "NET_Datagram");
    NET_DestroyDatagram(a0);
    return 0;
}

static int GenL_NET_DestroyDatagramSocket(lua_State *L)
{
    (void)L;
    NET_DatagramSocket *a0 = (NET_DatagramSocket *)SDLStaticGen_LuaTakeHandle(L, 1, "NET_DatagramSocket");
    NET_DestroyDatagramSocket(a0);
    return 0;
}

static int GenL_NET_DestroyServer(lua_State *L)
{
    (void)L;
    NET_Server *a0 = (NET_Server *)SDLStaticGen_LuaTakeHandle(L, 1, "NET_Server");
    NET_DestroyServer(a0);
    return 0;
}

static int GenL_NET_DestroyStreamSocket(lua_State *L)
{
    (void)L;
    NET_StreamSocket *a0 = (NET_StreamSocket *)SDLStaticGen_LuaTakeHandle(L, 1, "NET_StreamSocket");
    NET_DestroyStreamSocket(a0);
    return 0;
}

static int GenL_NET_GetAddressStatus(lua_State *L)
{
    (void)L;
    NET_Address *a0 = (NET_Address *)SDLStaticGen_LuaCheckHandle(L, 1, "NET_Address");
    NET_Status rv = NET_GetAddressStatus(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_NET_GetAddressString(lua_State *L)
{
    (void)L;
    NET_Address *a0 = (NET_Address *)SDLStaticGen_LuaCheckHandle(L, 1, "NET_Address");
    const char * rv = NET_GetAddressString(a0);
    if (rv == NULL) { lua_pushnil(L); } else { lua_pushstring(L, rv); }
    return 1;
}

static int GenL_NET_GetConnectionStatus(lua_State *L)
{
    (void)L;
    NET_StreamSocket *a0 = (NET_StreamSocket *)SDLStaticGen_LuaCheckHandle(L, 1, "NET_StreamSocket");
    NET_Status rv = NET_GetConnectionStatus(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_NET_GetStreamSocketAddress(lua_State *L)
{
    (void)L;
    NET_StreamSocket *a0 = (NET_StreamSocket *)SDLStaticGen_LuaCheckHandle(L, 1, "NET_StreamSocket");
    NET_Address * rv = NET_GetStreamSocketAddress(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "NET_Address");
    return 1;
}

static int GenL_NET_GetStreamSocketPendingWrites(lua_State *L)
{
    (void)L;
    NET_StreamSocket *a0 = (NET_StreamSocket *)SDLStaticGen_LuaCheckHandle(L, 1, "NET_StreamSocket");
    int rv = NET_GetStreamSocketPendingWrites(a0);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_NET_Init(lua_State *L)
{
    (void)L;
    bool rv = NET_Init();
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_NET_Quit(lua_State *L)
{
    (void)L;
    NET_Quit();
    return 0;
}

static int GenL_NET_RefAddress(lua_State *L)
{
    (void)L;
    NET_Address *a0 = (NET_Address *)SDLStaticGen_LuaCheckHandle(L, 1, "NET_Address");
    NET_Address * rv = NET_RefAddress(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "NET_Address");
    return 1;
}

static int GenL_NET_ResolveHostname(lua_State *L)
{
    (void)L;
    const char *a0 = lua_isnoneornil(L, 1) ? NULL : luaL_checkstring(L, 1);
    NET_Address * rv = NET_ResolveHostname(a0);
    SDLStaticGen_LuaPushHandle(L, (void *)rv, "NET_Address");
    return 1;
}

static int GenL_NET_SendDatagram(lua_State *L)
{
    (void)L;
    NET_DatagramSocket *a0 = (NET_DatagramSocket *)SDLStaticGen_LuaCheckHandle(L, 1, "NET_DatagramSocket");
    NET_Address *a1 = (NET_Address *)SDLStaticGen_LuaCheckHandle(L, 2, "NET_Address");
    Uint16 a2 = (Uint16)luaL_checkinteger(L, 3);
    size_t len3 = 0;
    const char *a3 = lua_isnoneornil(L, 4) ? NULL : luaL_checklstring(L, 4, &len3);
    bool rv = NET_SendDatagram(a0, a1, a2, (const void *)a3, (int)len3);
    lua_pushboolean(L, (int)rv);
    return 1;
}

static int GenL_NET_SimulateAddressResolutionLoss(lua_State *L)
{
    (void)L;
    int a0 = (int)luaL_checkinteger(L, 1);
    NET_SimulateAddressResolutionLoss(a0);
    return 0;
}

static int GenL_NET_SimulateDatagramPacketLoss(lua_State *L)
{
    (void)L;
    NET_DatagramSocket *a0 = (NET_DatagramSocket *)SDLStaticGen_LuaCheckHandle(L, 1, "NET_DatagramSocket");
    int a1 = (int)luaL_checkinteger(L, 2);
    NET_SimulateDatagramPacketLoss(a0, a1);
    return 0;
}

static int GenL_NET_SimulateStreamPacketLoss(lua_State *L)
{
    (void)L;
    NET_StreamSocket *a0 = (NET_StreamSocket *)SDLStaticGen_LuaCheckHandle(L, 1, "NET_StreamSocket");
    int a1 = (int)luaL_checkinteger(L, 2);
    NET_SimulateStreamPacketLoss(a0, a1);
    return 0;
}

static int GenL_NET_UnrefAddress(lua_State *L)
{
    (void)L;
    NET_Address *a0 = (NET_Address *)SDLStaticGen_LuaCheckHandle(L, 1, "NET_Address");
    NET_UnrefAddress(a0);
    return 0;
}

static int GenL_NET_Version(lua_State *L)
{
    (void)L;
    int rv = NET_Version();
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_NET_WaitUntilConnected(lua_State *L)
{
    (void)L;
    NET_StreamSocket *a0 = (NET_StreamSocket *)SDLStaticGen_LuaCheckHandle(L, 1, "NET_StreamSocket");
    Sint32 a1 = (Sint32)luaL_checkinteger(L, 2);
    NET_Status rv = NET_WaitUntilConnected(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_NET_WaitUntilResolved(lua_State *L)
{
    (void)L;
    NET_Address *a0 = (NET_Address *)SDLStaticGen_LuaCheckHandle(L, 1, "NET_Address");
    Sint32 a1 = (Sint32)luaL_checkinteger(L, 2);
    NET_Status rv = NET_WaitUntilResolved(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_NET_WaitUntilStreamSocketDrained(lua_State *L)
{
    (void)L;
    NET_StreamSocket *a0 = (NET_StreamSocket *)SDLStaticGen_LuaCheckHandle(L, 1, "NET_StreamSocket");
    Sint32 a1 = (Sint32)luaL_checkinteger(L, 2);
    int rv = NET_WaitUntilStreamSocketDrained(a0, a1);
    lua_pushinteger(L, (lua_Integer)rv);
    return 1;
}

static int GenL_NET_WriteToStreamSocket(lua_State *L)
{
    (void)L;
    NET_StreamSocket *a0 = (NET_StreamSocket *)SDLStaticGen_LuaCheckHandle(L, 1, "NET_StreamSocket");
    size_t len1 = 0;
    const char *a1 = lua_isnoneornil(L, 2) ? NULL : luaL_checklstring(L, 2, &len1);
    bool rv = NET_WriteToStreamSocket(a0, (const void *)a1, (int)len1);
    lua_pushboolean(L, (int)rv);
    return 1;
}

int SDLStaticGen_OpenLua_net(lua_State *L);
int SDLStaticGen_OpenLua_net(lua_State *L)
{
    lua_createtable(L, 0, 27);
    lua_pushcfunction(L, GenL_NET_CompareAddresses);
    lua_setfield(L, -2, "CompareAddresses");
    lua_pushcfunction(L, GenL_NET_CreateClient);
    lua_setfield(L, -2, "CreateClient");
    lua_pushcfunction(L, GenL_NET_CreateDatagramSocket);
    lua_setfield(L, -2, "CreateDatagramSocket");
    lua_pushcfunction(L, GenL_NET_CreateServer);
    lua_setfield(L, -2, "CreateServer");
    lua_pushcfunction(L, GenL_NET_DestroyDatagram);
    lua_setfield(L, -2, "DestroyDatagram");
    lua_pushcfunction(L, GenL_NET_DestroyDatagramSocket);
    lua_setfield(L, -2, "DestroyDatagramSocket");
    lua_pushcfunction(L, GenL_NET_DestroyServer);
    lua_setfield(L, -2, "DestroyServer");
    lua_pushcfunction(L, GenL_NET_DestroyStreamSocket);
    lua_setfield(L, -2, "DestroyStreamSocket");
    lua_pushcfunction(L, GenL_NET_GetAddressStatus);
    lua_setfield(L, -2, "GetAddressStatus");
    lua_pushcfunction(L, GenL_NET_GetAddressString);
    lua_setfield(L, -2, "GetAddressString");
    lua_pushcfunction(L, GenL_NET_GetConnectionStatus);
    lua_setfield(L, -2, "GetConnectionStatus");
    lua_pushcfunction(L, GenL_NET_GetStreamSocketAddress);
    lua_setfield(L, -2, "GetStreamSocketAddress");
    lua_pushcfunction(L, GenL_NET_GetStreamSocketPendingWrites);
    lua_setfield(L, -2, "GetStreamSocketPendingWrites");
    lua_pushcfunction(L, GenL_NET_Init);
    lua_setfield(L, -2, "Init");
    lua_pushcfunction(L, GenL_NET_Quit);
    lua_setfield(L, -2, "Quit");
    lua_pushcfunction(L, GenL_NET_RefAddress);
    lua_setfield(L, -2, "RefAddress");
    lua_pushcfunction(L, GenL_NET_ResolveHostname);
    lua_setfield(L, -2, "ResolveHostname");
    lua_pushcfunction(L, GenL_NET_SendDatagram);
    lua_setfield(L, -2, "SendDatagram");
    lua_pushcfunction(L, GenL_NET_SimulateAddressResolutionLoss);
    lua_setfield(L, -2, "SimulateAddressResolutionLoss");
    lua_pushcfunction(L, GenL_NET_SimulateDatagramPacketLoss);
    lua_setfield(L, -2, "SimulateDatagramPacketLoss");
    lua_pushcfunction(L, GenL_NET_SimulateStreamPacketLoss);
    lua_setfield(L, -2, "SimulateStreamPacketLoss");
    lua_pushcfunction(L, GenL_NET_UnrefAddress);
    lua_setfield(L, -2, "UnrefAddress");
    lua_pushcfunction(L, GenL_NET_Version);
    lua_setfield(L, -2, "Version");
    lua_pushcfunction(L, GenL_NET_WaitUntilConnected);
    lua_setfield(L, -2, "WaitUntilConnected");
    lua_pushcfunction(L, GenL_NET_WaitUntilResolved);
    lua_setfield(L, -2, "WaitUntilResolved");
    lua_pushcfunction(L, GenL_NET_WaitUntilStreamSocketDrained);
    lua_setfield(L, -2, "WaitUntilStreamSocketDrained");
    lua_pushcfunction(L, GenL_NET_WriteToStreamSocket);
    lua_setfield(L, -2, "WriteToStreamSocket");
    lua_pushinteger(L, (lua_Integer)NET_FAILURE);
    lua_setfield(L, -2, "FAILURE");
    lua_pushinteger(L, (lua_Integer)NET_WAITING);
    lua_setfield(L, -2, "WAITING");
    lua_pushinteger(L, (lua_Integer)NET_SUCCESS);
    lua_setfield(L, -2, "SUCCESS");
    lua_setglobal(L, "NET");
    return 0;
}
