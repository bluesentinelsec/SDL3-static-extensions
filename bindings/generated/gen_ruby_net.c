/* GENERATED FILE - DO NOT EDIT.
 * Regenerate: python3 -m tools.bindgen
 * mruby bindings for SDL_net. */
#include "../src/gen_support_ruby.h"

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

static mrb_value GenR_NET_CompareAddresses(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const NET_Address *a0 = (const NET_Address *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "NET_Address");
    const NET_Address *a1 = (const NET_Address *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "NET_Address");
    int rv = NET_CompareAddresses(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_NET_CreateClient(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    NET_Address *a0 = (NET_Address *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "NET_Address");
    Uint16 a1 = (Uint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_PropertiesID a2 = (SDL_PropertiesID)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    NET_StreamSocket * rv = NET_CreateClient(a0, a1, a2);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "NET_StreamSocket", GenDtor_NET_DestroyStreamSocket);
    }
}

static mrb_value GenR_NET_CreateDatagramSocket(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    NET_Address *a0 = (NET_Address *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "NET_Address");
    Uint16 a1 = (Uint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_PropertiesID a2 = (SDL_PropertiesID)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    NET_DatagramSocket * rv = NET_CreateDatagramSocket(a0, a1, a2);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "NET_DatagramSocket", GenDtor_NET_DestroyDatagramSocket);
    }
}

static mrb_value GenR_NET_CreateServer(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    NET_Address *a0 = (NET_Address *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "NET_Address");
    Uint16 a1 = (Uint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    SDL_PropertiesID a2 = (SDL_PropertiesID)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    NET_Server * rv = NET_CreateServer(a0, a1, a2);
    return SDLStaticGen_RubyPushOwned(mrb, (void *)rv, "NET_Server", GenDtor_NET_DestroyServer);
    }
}

static mrb_value GenR_NET_DestroyDatagram(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    NET_Datagram *a0 = (NET_Datagram *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "NET_Datagram");
    NET_DestroyDatagram(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_NET_DestroyDatagramSocket(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    NET_DatagramSocket *a0 = (NET_DatagramSocket *)SDLStaticGen_RubyTakeHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "NET_DatagramSocket");
    NET_DestroyDatagramSocket(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_NET_DestroyServer(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    NET_Server *a0 = (NET_Server *)SDLStaticGen_RubyTakeHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "NET_Server");
    NET_DestroyServer(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_NET_DestroyStreamSocket(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    NET_StreamSocket *a0 = (NET_StreamSocket *)SDLStaticGen_RubyTakeHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "NET_StreamSocket");
    NET_DestroyStreamSocket(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_NET_GetAddressStatus(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    NET_Address *a0 = (NET_Address *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "NET_Address");
    NET_Status rv = NET_GetAddressStatus(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_NET_GetAddressString(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    NET_Address *a0 = (NET_Address *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "NET_Address");
    const char * rv = NET_GetAddressString(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_NET_GetConnectionStatus(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    NET_StreamSocket *a0 = (NET_StreamSocket *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "NET_StreamSocket");
    NET_Status rv = NET_GetConnectionStatus(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_NET_GetStreamSocketAddress(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    NET_StreamSocket *a0 = (NET_StreamSocket *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "NET_StreamSocket");
    NET_Address * rv = NET_GetStreamSocketAddress(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "NET_Address");
    }
}

static mrb_value GenR_NET_GetStreamSocketPendingWrites(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    NET_StreamSocket *a0 = (NET_StreamSocket *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "NET_StreamSocket");
    int rv = NET_GetStreamSocketPendingWrites(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_NET_Init(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    bool rv = NET_Init();
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_NET_Quit(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    NET_Quit();
    return mrb_nil_value();
    }
}

static mrb_value GenR_NET_RefAddress(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    NET_Address *a0 = (NET_Address *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "NET_Address");
    NET_Address * rv = NET_RefAddress(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "NET_Address");
    }
}

static mrb_value GenR_NET_ResolveHostname(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    NET_Address * rv = NET_ResolveHostname(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "NET_Address");
    }
}

static mrb_value GenR_NET_SendDatagram(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    NET_DatagramSocket *a0 = (NET_DatagramSocket *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "NET_DatagramSocket");
    NET_Address *a1 = (NET_Address *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), "NET_Address");
    Uint16 a2 = (Uint16)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    size_t len3 = 0;
    const char *a3 = SDLStaticGen_RubyToBlob(mrb, (argc > 3 ? argv[3] : mrb_nil_value()), &len3);
    bool rv = NET_SendDatagram(a0, a1, a2, (const void *)a3, (int)len3);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

static mrb_value GenR_NET_SimulateAddressResolutionLoss(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int a0 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    NET_SimulateAddressResolutionLoss(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_NET_SimulateDatagramPacketLoss(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    NET_DatagramSocket *a0 = (NET_DatagramSocket *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "NET_DatagramSocket");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    NET_SimulateDatagramPacketLoss(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_NET_SimulateStreamPacketLoss(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    NET_StreamSocket *a0 = (NET_StreamSocket *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "NET_StreamSocket");
    int a1 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    NET_SimulateStreamPacketLoss(a0, a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_NET_UnrefAddress(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    NET_Address *a0 = (NET_Address *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "NET_Address");
    NET_UnrefAddress(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_NET_Version(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int rv = NET_Version();
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_NET_WaitUntilConnected(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    NET_StreamSocket *a0 = (NET_StreamSocket *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "NET_StreamSocket");
    Sint32 a1 = (Sint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    NET_Status rv = NET_WaitUntilConnected(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_NET_WaitUntilResolved(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    NET_Address *a0 = (NET_Address *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "NET_Address");
    Sint32 a1 = (Sint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    NET_Status rv = NET_WaitUntilResolved(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_NET_WaitUntilStreamSocketDrained(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    NET_StreamSocket *a0 = (NET_StreamSocket *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "NET_StreamSocket");
    Sint32 a1 = (Sint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = NET_WaitUntilStreamSocketDrained(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_NET_WriteToStreamSocket(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    NET_StreamSocket *a0 = (NET_StreamSocket *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "NET_StreamSocket");
    size_t len1 = 0;
    const char *a1 = SDLStaticGen_RubyToBlob(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &len1);
    bool rv = NET_WriteToStreamSocket(a0, (const void *)a1, (int)len1);
    return mrb_bool_value((mrb_bool)(rv != 0));
    }
}

void SDLStaticGen_OpenRuby_net(mrb_state *mrb);
void SDLStaticGen_OpenRuby_net(mrb_state *mrb)
{
    struct RClass *mod;
    SDLStaticGen_RubyEnsureHandleClass(mrb);
    mod = mrb_define_module(mrb, "NET");
    mrb_define_module_function(mrb, mod, "CompareAddresses", GenR_NET_CompareAddresses, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateClient", GenR_NET_CreateClient, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateDatagramSocket", GenR_NET_CreateDatagramSocket, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "CreateServer", GenR_NET_CreateServer, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DestroyDatagram", GenR_NET_DestroyDatagram, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DestroyDatagramSocket", GenR_NET_DestroyDatagramSocket, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DestroyServer", GenR_NET_DestroyServer, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "DestroyStreamSocket", GenR_NET_DestroyStreamSocket, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetAddressStatus", GenR_NET_GetAddressStatus, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetAddressString", GenR_NET_GetAddressString, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetConnectionStatus", GenR_NET_GetConnectionStatus, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetStreamSocketAddress", GenR_NET_GetStreamSocketAddress, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "GetStreamSocketPendingWrites", GenR_NET_GetStreamSocketPendingWrites, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Init", GenR_NET_Init, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Quit", GenR_NET_Quit, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "RefAddress", GenR_NET_RefAddress, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "ResolveHostname", GenR_NET_ResolveHostname, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SendDatagram", GenR_NET_SendDatagram, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SimulateAddressResolutionLoss", GenR_NET_SimulateAddressResolutionLoss, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SimulateDatagramPacketLoss", GenR_NET_SimulateDatagramPacketLoss, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "SimulateStreamPacketLoss", GenR_NET_SimulateStreamPacketLoss, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "UnrefAddress", GenR_NET_UnrefAddress, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "Version", GenR_NET_Version, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WaitUntilConnected", GenR_NET_WaitUntilConnected, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WaitUntilResolved", GenR_NET_WaitUntilResolved, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WaitUntilStreamSocketDrained", GenR_NET_WaitUntilStreamSocketDrained, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "WriteToStreamSocket", GenR_NET_WriteToStreamSocket, MRB_ARGS_ANY());
    mrb_define_const(mrb, mod, "FAILURE", mrb_int_value(mrb, (mrb_int)NET_FAILURE));
    mrb_define_const(mrb, mod, "WAITING", mrb_int_value(mrb, (mrb_int)NET_WAITING));
    mrb_define_const(mrb, mod, "SUCCESS", mrb_int_value(mrb, (mrb_int)NET_SUCCESS));
}
