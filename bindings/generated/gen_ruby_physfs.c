/* GENERATED FILE - DO NOT EDIT.
 * Regenerate: python3 -m tools.bindgen
 * mruby bindings for PhysFS. */
#include "../src/gen_support_ruby.h"

#include <physfs.h>
#include <string.h>

static mrb_value GenPush_PHYSFS_Stat(mrb_state *mrb, const PHYSFS_Stat *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "filesize", mrb_int_value(mrb, (mrb_int)in->filesize));
    SDLStaticGen_RubyHashSet(mrb, h, "modtime", mrb_int_value(mrb, (mrb_int)in->modtime));
    SDLStaticGen_RubyHashSet(mrb, h, "createtime", mrb_int_value(mrb, (mrb_int)in->createtime));
    SDLStaticGen_RubyHashSet(mrb, h, "accesstime", mrb_int_value(mrb, (mrb_int)in->accesstime));
    SDLStaticGen_RubyHashSet(mrb, h, "filetype", mrb_int_value(mrb, (mrb_int)in->filetype));
    SDLStaticGen_RubyHashSet(mrb, h, "readonly", mrb_int_value(mrb, (mrb_int)in->readonly));
    return h;
}

static mrb_value GenPush_PHYSFS_Version(mrb_state *mrb, const PHYSFS_Version *in)
{
    mrb_value h = mrb_hash_new(mrb);
    SDLStaticGen_RubyHashSet(mrb, h, "major", mrb_int_value(mrb, (mrb_int)in->major));
    SDLStaticGen_RubyHashSet(mrb, h, "minor", mrb_int_value(mrb, (mrb_int)in->minor));
    SDLStaticGen_RubyHashSet(mrb, h, "patch", mrb_int_value(mrb, (mrb_int)in->patch));
    return h;
}

static mrb_value GenR_PHYSFS_caseFold(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_uint32 a0 = (PHYSFS_uint32)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    PHYSFS_uint32 io1 = (PHYSFS_uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = PHYSFS_caseFold(a0, &io1);
    mrb_value rets[2];
    rets[0] = mrb_int_value(mrb, (mrb_int)rv);
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_PHYSFS_close(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "PHYSFS_File");
    int rv = PHYSFS_close(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_PHYSFS_deinit(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int rv = PHYSFS_deinit();
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_PHYSFS_delete(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    int rv = PHYSFS_delete(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_PHYSFS_deregisterArchiver(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    int rv = PHYSFS_deregisterArchiver(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_PHYSFS_eof(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "PHYSFS_File");
    int rv = PHYSFS_eof(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_PHYSFS_exists(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    int rv = PHYSFS_exists(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_PHYSFS_fileLength(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "PHYSFS_File");
    PHYSFS_sint64 rv = PHYSFS_fileLength(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_PHYSFS_flush(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "PHYSFS_File");
    int rv = PHYSFS_flush(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_PHYSFS_getAllocator(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const PHYSFS_Allocator * rv = PHYSFS_getAllocator();
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "PHYSFS_Allocator");
    }
}

static mrb_value GenR_PHYSFS_getBaseDir(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char * rv = PHYSFS_getBaseDir();
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_PHYSFS_getDirSeparator(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char * rv = PHYSFS_getDirSeparator();
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_PHYSFS_getErrorByCode(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_ErrorCode a0 = (PHYSFS_ErrorCode)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char * rv = PHYSFS_getErrorByCode(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_PHYSFS_getLastErrorCode(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_ErrorCode rv = PHYSFS_getLastErrorCode();
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_PHYSFS_getLinkedVersion(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_Version out0;
    memset(&out0, 0, sizeof(out0));
    PHYSFS_getLinkedVersion(&out0);
    return GenPush_PHYSFS_Version(mrb, &out0);
    }
}

static mrb_value GenR_PHYSFS_getMountPoint(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char * rv = PHYSFS_getMountPoint(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_PHYSFS_getPrefDir(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char * rv = PHYSFS_getPrefDir(a0, a1);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_PHYSFS_getRealDir(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char * rv = PHYSFS_getRealDir(a0);
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_PHYSFS_getWriteDir(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char * rv = PHYSFS_getWriteDir();
    return (rv == NULL ? mrb_nil_value() : mrb_str_new_cstr(mrb, rv));
    }
}

static mrb_value GenR_PHYSFS_init(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    int rv = PHYSFS_init(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_PHYSFS_isInit(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int rv = PHYSFS_isInit();
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_PHYSFS_mkdir(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    int rv = PHYSFS_mkdir(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_PHYSFS_mount(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int a2 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int rv = PHYSFS_mount(a0, a1, a2);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_PHYSFS_mountHandle(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "PHYSFS_File");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int a3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    int rv = PHYSFS_mountHandle(a0, a1, a2, a3);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_PHYSFS_mountIo(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_Io *a0 = (PHYSFS_Io *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "PHYSFS_Io");
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int a3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    int rv = PHYSFS_mountIo(a0, a1, a2, a3);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_PHYSFS_openAppend(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    PHYSFS_File * rv = PHYSFS_openAppend(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "PHYSFS_File");
    }
}

static mrb_value GenR_PHYSFS_openRead(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    PHYSFS_File * rv = PHYSFS_openRead(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "PHYSFS_File");
    }
}

static mrb_value GenR_PHYSFS_openWrite(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    PHYSFS_File * rv = PHYSFS_openWrite(a0);
    return SDLStaticGen_RubyPushHandle(mrb, (void *)rv, "PHYSFS_File");
    }
}

static mrb_value GenR_PHYSFS_permitSymbolicLinks(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int a0 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    PHYSFS_permitSymbolicLinks(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_PHYSFS_readSBE16(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "PHYSFS_File");
    PHYSFS_sint16 io1 = (PHYSFS_sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = PHYSFS_readSBE16(a0, &io1);
    mrb_value rets[2];
    rets[0] = mrb_int_value(mrb, (mrb_int)rv);
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_PHYSFS_readSBE32(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "PHYSFS_File");
    PHYSFS_sint32 io1 = (PHYSFS_sint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = PHYSFS_readSBE32(a0, &io1);
    mrb_value rets[2];
    rets[0] = mrb_int_value(mrb, (mrb_int)rv);
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_PHYSFS_readSBE64(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "PHYSFS_File");
    PHYSFS_sint64 io1 = (PHYSFS_sint64)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = PHYSFS_readSBE64(a0, &io1);
    mrb_value rets[2];
    rets[0] = mrb_int_value(mrb, (mrb_int)rv);
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_PHYSFS_readSLE16(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "PHYSFS_File");
    PHYSFS_sint16 io1 = (PHYSFS_sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = PHYSFS_readSLE16(a0, &io1);
    mrb_value rets[2];
    rets[0] = mrb_int_value(mrb, (mrb_int)rv);
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_PHYSFS_readSLE32(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "PHYSFS_File");
    PHYSFS_sint32 io1 = (PHYSFS_sint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = PHYSFS_readSLE32(a0, &io1);
    mrb_value rets[2];
    rets[0] = mrb_int_value(mrb, (mrb_int)rv);
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_PHYSFS_readSLE64(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "PHYSFS_File");
    PHYSFS_sint64 io1 = (PHYSFS_sint64)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = PHYSFS_readSLE64(a0, &io1);
    mrb_value rets[2];
    rets[0] = mrb_int_value(mrb, (mrb_int)rv);
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_PHYSFS_readUBE16(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "PHYSFS_File");
    PHYSFS_uint16 io1 = (PHYSFS_uint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = PHYSFS_readUBE16(a0, &io1);
    mrb_value rets[2];
    rets[0] = mrb_int_value(mrb, (mrb_int)rv);
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_PHYSFS_readUBE32(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "PHYSFS_File");
    PHYSFS_uint32 io1 = (PHYSFS_uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = PHYSFS_readUBE32(a0, &io1);
    mrb_value rets[2];
    rets[0] = mrb_int_value(mrb, (mrb_int)rv);
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_PHYSFS_readUBE64(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "PHYSFS_File");
    PHYSFS_uint64 io1 = (PHYSFS_uint64)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = PHYSFS_readUBE64(a0, &io1);
    mrb_value rets[2];
    rets[0] = mrb_int_value(mrb, (mrb_int)rv);
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_PHYSFS_readULE16(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "PHYSFS_File");
    PHYSFS_uint16 io1 = (PHYSFS_uint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = PHYSFS_readULE16(a0, &io1);
    mrb_value rets[2];
    rets[0] = mrb_int_value(mrb, (mrb_int)rv);
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_PHYSFS_readULE32(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "PHYSFS_File");
    PHYSFS_uint32 io1 = (PHYSFS_uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = PHYSFS_readULE32(a0, &io1);
    mrb_value rets[2];
    rets[0] = mrb_int_value(mrb, (mrb_int)rv);
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_PHYSFS_readULE64(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "PHYSFS_File");
    PHYSFS_uint64 io1 = (PHYSFS_uint64)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = PHYSFS_readULE64(a0, &io1);
    mrb_value rets[2];
    rets[0] = mrb_int_value(mrb, (mrb_int)rv);
    rets[1] = mrb_int_value(mrb, (mrb_int)io1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_PHYSFS_registerArchiver(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const PHYSFS_Archiver *a0 = (const PHYSFS_Archiver *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "PHYSFS_Archiver");
    int rv = PHYSFS_registerArchiver(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_PHYSFS_seek(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "PHYSFS_File");
    PHYSFS_uint64 a1 = (PHYSFS_uint64)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = PHYSFS_seek(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_PHYSFS_setAllocator(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const PHYSFS_Allocator *a0 = (const PHYSFS_Allocator *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "PHYSFS_Allocator");
    int rv = PHYSFS_setAllocator(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_PHYSFS_setBuffer(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "PHYSFS_File");
    PHYSFS_uint64 a1 = (PHYSFS_uint64)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = PHYSFS_setBuffer(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_PHYSFS_setErrorCode(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_ErrorCode a0 = (PHYSFS_ErrorCode)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    PHYSFS_setErrorCode(a0);
    return mrb_nil_value();
    }
}

static mrb_value GenR_PHYSFS_setRoot(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = PHYSFS_setRoot(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_PHYSFS_setSaneConfig(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    const char *a2 = SDLStaticGen_RubyToStr(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    int a3 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 3 ? argv[3] : mrb_nil_value()));
    int a4 = (int)SDLStaticGen_RubyToInt(mrb, (argc > 4 ? argv[4] : mrb_nil_value()));
    int rv = PHYSFS_setSaneConfig(a0, a1, a2, a3, a4);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_PHYSFS_setWriteDir(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    int rv = PHYSFS_setWriteDir(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_PHYSFS_stat(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    PHYSFS_Stat out1;
    memset(&out1, 0, sizeof(out1));
    int rv = PHYSFS_stat(a0, &out1);
    mrb_value rets[2];
    rets[0] = mrb_int_value(mrb, (mrb_int)rv);
    rets[1] = GenPush_PHYSFS_Stat(mrb, &out1);
    return mrb_ary_new_from_values(mrb, 2, rets);
    }
}

static mrb_value GenR_PHYSFS_swapSBE16(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_sint16 a0 = (PHYSFS_sint16)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    PHYSFS_sint16 rv = PHYSFS_swapSBE16(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_PHYSFS_swapSBE32(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_sint32 a0 = (PHYSFS_sint32)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    PHYSFS_sint32 rv = PHYSFS_swapSBE32(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_PHYSFS_swapSBE64(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_sint64 a0 = (PHYSFS_sint64)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    PHYSFS_sint64 rv = PHYSFS_swapSBE64(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_PHYSFS_swapSLE16(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_sint16 a0 = (PHYSFS_sint16)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    PHYSFS_sint16 rv = PHYSFS_swapSLE16(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_PHYSFS_swapSLE32(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_sint32 a0 = (PHYSFS_sint32)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    PHYSFS_sint32 rv = PHYSFS_swapSLE32(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_PHYSFS_swapSLE64(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_sint64 a0 = (PHYSFS_sint64)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    PHYSFS_sint64 rv = PHYSFS_swapSLE64(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_PHYSFS_swapUBE16(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_uint16 a0 = (PHYSFS_uint16)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    PHYSFS_uint16 rv = PHYSFS_swapUBE16(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_PHYSFS_swapUBE32(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_uint32 a0 = (PHYSFS_uint32)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    PHYSFS_uint32 rv = PHYSFS_swapUBE32(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_PHYSFS_swapUBE64(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_uint64 a0 = (PHYSFS_uint64)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    PHYSFS_uint64 rv = PHYSFS_swapUBE64(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_PHYSFS_swapULE16(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_uint16 a0 = (PHYSFS_uint16)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    PHYSFS_uint16 rv = PHYSFS_swapULE16(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_PHYSFS_swapULE32(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_uint32 a0 = (PHYSFS_uint32)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    PHYSFS_uint32 rv = PHYSFS_swapULE32(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_PHYSFS_swapULE64(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_uint64 a0 = (PHYSFS_uint64)SDLStaticGen_RubyToInt(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    PHYSFS_uint64 rv = PHYSFS_swapULE64(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_PHYSFS_symbolicLinksPermitted(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    int rv = PHYSFS_symbolicLinksPermitted();
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_PHYSFS_tell(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "PHYSFS_File");
    PHYSFS_sint64 rv = PHYSFS_tell(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_PHYSFS_unmount(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    int rv = PHYSFS_unmount(a0);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_PHYSFS_utf8FromLatin1(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char *src1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    char *a1 = SDL_strdup(src1 != NULL ? src1 : "");
    PHYSFS_uint64 a2 = (PHYSFS_uint64)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    PHYSFS_utf8FromLatin1(a0, a1, a2);
    SDL_free(a1);
    return mrb_nil_value();
    }
}

static mrb_value GenR_PHYSFS_utf8ToUcs2(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    PHYSFS_uint16 io1 = (PHYSFS_uint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    PHYSFS_uint64 a2 = (PHYSFS_uint64)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    PHYSFS_utf8ToUcs2(a0, &io1, a2);
    return mrb_int_value(mrb, (mrb_int)io1);
    }
}

static mrb_value GenR_PHYSFS_utf8ToUcs4(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    PHYSFS_uint32 io1 = (PHYSFS_uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    PHYSFS_uint64 a2 = (PHYSFS_uint64)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    PHYSFS_utf8ToUcs4(a0, &io1, a2);
    return mrb_int_value(mrb, (mrb_int)io1);
    }
}

static mrb_value GenR_PHYSFS_utf8ToUtf16(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    PHYSFS_uint16 io1 = (PHYSFS_uint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    PHYSFS_uint64 a2 = (PHYSFS_uint64)SDLStaticGen_RubyToInt(mrb, (argc > 2 ? argv[2] : mrb_nil_value()));
    PHYSFS_utf8ToUtf16(a0, &io1, a2);
    return mrb_int_value(mrb, (mrb_int)io1);
    }
}

static mrb_value GenR_PHYSFS_utf8stricmp(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    const char *a0 = SDLStaticGen_RubyToStr(mrb, (argc > 0 ? argv[0] : mrb_nil_value()));
    const char *a1 = SDLStaticGen_RubyToStr(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = PHYSFS_utf8stricmp(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_PHYSFS_writeBytes(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "PHYSFS_File");
    size_t len1 = 0;
    const char *a1 = SDLStaticGen_RubyToBlob(mrb, (argc > 1 ? argv[1] : mrb_nil_value()), &len1);
    PHYSFS_sint64 rv = PHYSFS_writeBytes(a0, (const void *)a1, (PHYSFS_uint64)len1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_PHYSFS_writeSBE16(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "PHYSFS_File");
    PHYSFS_sint16 a1 = (PHYSFS_sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = PHYSFS_writeSBE16(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_PHYSFS_writeSBE32(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "PHYSFS_File");
    PHYSFS_sint32 a1 = (PHYSFS_sint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = PHYSFS_writeSBE32(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_PHYSFS_writeSBE64(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "PHYSFS_File");
    PHYSFS_sint64 a1 = (PHYSFS_sint64)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = PHYSFS_writeSBE64(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_PHYSFS_writeSLE16(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "PHYSFS_File");
    PHYSFS_sint16 a1 = (PHYSFS_sint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = PHYSFS_writeSLE16(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_PHYSFS_writeSLE32(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "PHYSFS_File");
    PHYSFS_sint32 a1 = (PHYSFS_sint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = PHYSFS_writeSLE32(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_PHYSFS_writeSLE64(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "PHYSFS_File");
    PHYSFS_sint64 a1 = (PHYSFS_sint64)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = PHYSFS_writeSLE64(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_PHYSFS_writeUBE16(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "PHYSFS_File");
    PHYSFS_uint16 a1 = (PHYSFS_uint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = PHYSFS_writeUBE16(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_PHYSFS_writeUBE32(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "PHYSFS_File");
    PHYSFS_uint32 a1 = (PHYSFS_uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = PHYSFS_writeUBE32(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_PHYSFS_writeUBE64(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "PHYSFS_File");
    PHYSFS_uint64 a1 = (PHYSFS_uint64)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = PHYSFS_writeUBE64(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_PHYSFS_writeULE16(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "PHYSFS_File");
    PHYSFS_uint16 a1 = (PHYSFS_uint16)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = PHYSFS_writeULE16(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_PHYSFS_writeULE32(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "PHYSFS_File");
    PHYSFS_uint32 a1 = (PHYSFS_uint32)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = PHYSFS_writeULE32(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

static mrb_value GenR_PHYSFS_writeULE64(mrb_state *mrb, mrb_value self)
{
    const mrb_value *argv = NULL;
    mrb_int argc = 0;
    (void)self;
    mrb_get_args(mrb, "*", &argv, &argc);
    {
    PHYSFS_File *a0 = (PHYSFS_File *)SDLStaticGen_RubyCheckHandle(mrb, (argc > 0 ? argv[0] : mrb_nil_value()), "PHYSFS_File");
    PHYSFS_uint64 a1 = (PHYSFS_uint64)SDLStaticGen_RubyToInt(mrb, (argc > 1 ? argv[1] : mrb_nil_value()));
    int rv = PHYSFS_writeULE64(a0, a1);
    return mrb_int_value(mrb, (mrb_int)rv);
    }
}

void SDLStaticGen_OpenRuby_physfs(mrb_state *mrb);
void SDLStaticGen_OpenRuby_physfs(mrb_state *mrb)
{
    struct RClass *mod;
    SDLStaticGen_RubyEnsureHandleClass(mrb);
    mod = mrb_define_module(mrb, "PHYSFS");
    mrb_define_module_function(mrb, mod, "caseFold", GenR_PHYSFS_caseFold, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "close", GenR_PHYSFS_close, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "deinit", GenR_PHYSFS_deinit, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "delete", GenR_PHYSFS_delete, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "deregisterArchiver", GenR_PHYSFS_deregisterArchiver, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "eof", GenR_PHYSFS_eof, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "exists", GenR_PHYSFS_exists, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "fileLength", GenR_PHYSFS_fileLength, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "flush", GenR_PHYSFS_flush, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "getAllocator", GenR_PHYSFS_getAllocator, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "getBaseDir", GenR_PHYSFS_getBaseDir, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "getDirSeparator", GenR_PHYSFS_getDirSeparator, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "getErrorByCode", GenR_PHYSFS_getErrorByCode, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "getLastErrorCode", GenR_PHYSFS_getLastErrorCode, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "getLinkedVersion", GenR_PHYSFS_getLinkedVersion, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "getMountPoint", GenR_PHYSFS_getMountPoint, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "getPrefDir", GenR_PHYSFS_getPrefDir, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "getRealDir", GenR_PHYSFS_getRealDir, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "getWriteDir", GenR_PHYSFS_getWriteDir, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "init", GenR_PHYSFS_init, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "isInit", GenR_PHYSFS_isInit, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "mkdir", GenR_PHYSFS_mkdir, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "mount", GenR_PHYSFS_mount, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "mountHandle", GenR_PHYSFS_mountHandle, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "mountIo", GenR_PHYSFS_mountIo, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "openAppend", GenR_PHYSFS_openAppend, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "openRead", GenR_PHYSFS_openRead, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "openWrite", GenR_PHYSFS_openWrite, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "permitSymbolicLinks", GenR_PHYSFS_permitSymbolicLinks, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "readSBE16", GenR_PHYSFS_readSBE16, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "readSBE32", GenR_PHYSFS_readSBE32, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "readSBE64", GenR_PHYSFS_readSBE64, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "readSLE16", GenR_PHYSFS_readSLE16, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "readSLE32", GenR_PHYSFS_readSLE32, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "readSLE64", GenR_PHYSFS_readSLE64, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "readUBE16", GenR_PHYSFS_readUBE16, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "readUBE32", GenR_PHYSFS_readUBE32, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "readUBE64", GenR_PHYSFS_readUBE64, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "readULE16", GenR_PHYSFS_readULE16, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "readULE32", GenR_PHYSFS_readULE32, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "readULE64", GenR_PHYSFS_readULE64, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "registerArchiver", GenR_PHYSFS_registerArchiver, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "seek", GenR_PHYSFS_seek, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "setAllocator", GenR_PHYSFS_setAllocator, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "setBuffer", GenR_PHYSFS_setBuffer, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "setErrorCode", GenR_PHYSFS_setErrorCode, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "setRoot", GenR_PHYSFS_setRoot, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "setSaneConfig", GenR_PHYSFS_setSaneConfig, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "setWriteDir", GenR_PHYSFS_setWriteDir, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "stat", GenR_PHYSFS_stat, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "swapSBE16", GenR_PHYSFS_swapSBE16, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "swapSBE32", GenR_PHYSFS_swapSBE32, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "swapSBE64", GenR_PHYSFS_swapSBE64, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "swapSLE16", GenR_PHYSFS_swapSLE16, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "swapSLE32", GenR_PHYSFS_swapSLE32, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "swapSLE64", GenR_PHYSFS_swapSLE64, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "swapUBE16", GenR_PHYSFS_swapUBE16, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "swapUBE32", GenR_PHYSFS_swapUBE32, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "swapUBE64", GenR_PHYSFS_swapUBE64, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "swapULE16", GenR_PHYSFS_swapULE16, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "swapULE32", GenR_PHYSFS_swapULE32, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "swapULE64", GenR_PHYSFS_swapULE64, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "symbolicLinksPermitted", GenR_PHYSFS_symbolicLinksPermitted, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "tell", GenR_PHYSFS_tell, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "unmount", GenR_PHYSFS_unmount, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "utf8FromLatin1", GenR_PHYSFS_utf8FromLatin1, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "utf8ToUcs2", GenR_PHYSFS_utf8ToUcs2, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "utf8ToUcs4", GenR_PHYSFS_utf8ToUcs4, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "utf8ToUtf16", GenR_PHYSFS_utf8ToUtf16, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "utf8stricmp", GenR_PHYSFS_utf8stricmp, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "writeBytes", GenR_PHYSFS_writeBytes, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "writeSBE16", GenR_PHYSFS_writeSBE16, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "writeSBE32", GenR_PHYSFS_writeSBE32, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "writeSBE64", GenR_PHYSFS_writeSBE64, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "writeSLE16", GenR_PHYSFS_writeSLE16, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "writeSLE32", GenR_PHYSFS_writeSLE32, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "writeSLE64", GenR_PHYSFS_writeSLE64, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "writeUBE16", GenR_PHYSFS_writeUBE16, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "writeUBE32", GenR_PHYSFS_writeUBE32, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "writeUBE64", GenR_PHYSFS_writeUBE64, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "writeULE16", GenR_PHYSFS_writeULE16, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "writeULE32", GenR_PHYSFS_writeULE32, MRB_ARGS_ANY());
    mrb_define_module_function(mrb, mod, "writeULE64", GenR_PHYSFS_writeULE64, MRB_ARGS_ANY());
    mrb_define_const(mrb, mod, "ENUM_ERROR", mrb_int_value(mrb, (mrb_int)PHYSFS_ENUM_ERROR));
    mrb_define_const(mrb, mod, "ENUM_STOP", mrb_int_value(mrb, (mrb_int)PHYSFS_ENUM_STOP));
    mrb_define_const(mrb, mod, "ENUM_OK", mrb_int_value(mrb, (mrb_int)PHYSFS_ENUM_OK));
    mrb_define_const(mrb, mod, "ERR_OK", mrb_int_value(mrb, (mrb_int)PHYSFS_ERR_OK));
    mrb_define_const(mrb, mod, "ERR_OTHER_ERROR", mrb_int_value(mrb, (mrb_int)PHYSFS_ERR_OTHER_ERROR));
    mrb_define_const(mrb, mod, "ERR_OUT_OF_MEMORY", mrb_int_value(mrb, (mrb_int)PHYSFS_ERR_OUT_OF_MEMORY));
    mrb_define_const(mrb, mod, "ERR_NOT_INITIALIZED", mrb_int_value(mrb, (mrb_int)PHYSFS_ERR_NOT_INITIALIZED));
    mrb_define_const(mrb, mod, "ERR_IS_INITIALIZED", mrb_int_value(mrb, (mrb_int)PHYSFS_ERR_IS_INITIALIZED));
    mrb_define_const(mrb, mod, "ERR_ARGV0_IS_NULL", mrb_int_value(mrb, (mrb_int)PHYSFS_ERR_ARGV0_IS_NULL));
    mrb_define_const(mrb, mod, "ERR_UNSUPPORTED", mrb_int_value(mrb, (mrb_int)PHYSFS_ERR_UNSUPPORTED));
    mrb_define_const(mrb, mod, "ERR_PAST_EOF", mrb_int_value(mrb, (mrb_int)PHYSFS_ERR_PAST_EOF));
    mrb_define_const(mrb, mod, "ERR_FILES_STILL_OPEN", mrb_int_value(mrb, (mrb_int)PHYSFS_ERR_FILES_STILL_OPEN));
    mrb_define_const(mrb, mod, "ERR_INVALID_ARGUMENT", mrb_int_value(mrb, (mrb_int)PHYSFS_ERR_INVALID_ARGUMENT));
    mrb_define_const(mrb, mod, "ERR_NOT_MOUNTED", mrb_int_value(mrb, (mrb_int)PHYSFS_ERR_NOT_MOUNTED));
    mrb_define_const(mrb, mod, "ERR_NOT_FOUND", mrb_int_value(mrb, (mrb_int)PHYSFS_ERR_NOT_FOUND));
    mrb_define_const(mrb, mod, "ERR_SYMLINK_FORBIDDEN", mrb_int_value(mrb, (mrb_int)PHYSFS_ERR_SYMLINK_FORBIDDEN));
    mrb_define_const(mrb, mod, "ERR_NO_WRITE_DIR", mrb_int_value(mrb, (mrb_int)PHYSFS_ERR_NO_WRITE_DIR));
    mrb_define_const(mrb, mod, "ERR_OPEN_FOR_READING", mrb_int_value(mrb, (mrb_int)PHYSFS_ERR_OPEN_FOR_READING));
    mrb_define_const(mrb, mod, "ERR_OPEN_FOR_WRITING", mrb_int_value(mrb, (mrb_int)PHYSFS_ERR_OPEN_FOR_WRITING));
    mrb_define_const(mrb, mod, "ERR_NOT_A_FILE", mrb_int_value(mrb, (mrb_int)PHYSFS_ERR_NOT_A_FILE));
    mrb_define_const(mrb, mod, "ERR_READ_ONLY", mrb_int_value(mrb, (mrb_int)PHYSFS_ERR_READ_ONLY));
    mrb_define_const(mrb, mod, "ERR_CORRUPT", mrb_int_value(mrb, (mrb_int)PHYSFS_ERR_CORRUPT));
    mrb_define_const(mrb, mod, "ERR_SYMLINK_LOOP", mrb_int_value(mrb, (mrb_int)PHYSFS_ERR_SYMLINK_LOOP));
    mrb_define_const(mrb, mod, "ERR_IO", mrb_int_value(mrb, (mrb_int)PHYSFS_ERR_IO));
    mrb_define_const(mrb, mod, "ERR_PERMISSION", mrb_int_value(mrb, (mrb_int)PHYSFS_ERR_PERMISSION));
    mrb_define_const(mrb, mod, "ERR_NO_SPACE", mrb_int_value(mrb, (mrb_int)PHYSFS_ERR_NO_SPACE));
    mrb_define_const(mrb, mod, "ERR_BAD_FILENAME", mrb_int_value(mrb, (mrb_int)PHYSFS_ERR_BAD_FILENAME));
    mrb_define_const(mrb, mod, "ERR_BUSY", mrb_int_value(mrb, (mrb_int)PHYSFS_ERR_BUSY));
    mrb_define_const(mrb, mod, "ERR_DIR_NOT_EMPTY", mrb_int_value(mrb, (mrb_int)PHYSFS_ERR_DIR_NOT_EMPTY));
    mrb_define_const(mrb, mod, "ERR_OS_ERROR", mrb_int_value(mrb, (mrb_int)PHYSFS_ERR_OS_ERROR));
    mrb_define_const(mrb, mod, "ERR_DUPLICATE", mrb_int_value(mrb, (mrb_int)PHYSFS_ERR_DUPLICATE));
    mrb_define_const(mrb, mod, "ERR_BAD_PASSWORD", mrb_int_value(mrb, (mrb_int)PHYSFS_ERR_BAD_PASSWORD));
    mrb_define_const(mrb, mod, "ERR_APP_CALLBACK", mrb_int_value(mrb, (mrb_int)PHYSFS_ERR_APP_CALLBACK));
    mrb_define_const(mrb, mod, "FILETYPE_REGULAR", mrb_int_value(mrb, (mrb_int)PHYSFS_FILETYPE_REGULAR));
    mrb_define_const(mrb, mod, "FILETYPE_DIRECTORY", mrb_int_value(mrb, (mrb_int)PHYSFS_FILETYPE_DIRECTORY));
    mrb_define_const(mrb, mod, "FILETYPE_SYMLINK", mrb_int_value(mrb, (mrb_int)PHYSFS_FILETYPE_SYMLINK));
    mrb_define_const(mrb, mod, "FILETYPE_OTHER", mrb_int_value(mrb, (mrb_int)PHYSFS_FILETYPE_OTHER));
#ifdef PHYSFS_VER_MAJOR
    mrb_define_const(mrb, mod, "VER_MAJOR", mrb_int_value(mrb, (mrb_int)(PHYSFS_VER_MAJOR)));
#endif
#ifdef PHYSFS_VER_MINOR
    mrb_define_const(mrb, mod, "VER_MINOR", mrb_int_value(mrb, (mrb_int)(PHYSFS_VER_MINOR)));
#endif
#ifdef PHYSFS_VER_PATCH
    mrb_define_const(mrb, mod, "VER_PATCH", mrb_int_value(mrb, (mrb_int)(PHYSFS_VER_PATCH)));
#endif
}
