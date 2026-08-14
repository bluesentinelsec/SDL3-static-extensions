/**
 * @file script_test.cpp
 * @brief Tests for SDLStatic::Lua, SDLStatic::Ruby, and the game bindings.
 *
 * The require/import story is exercised for real: module chains load from a
 * zip archive mounted through the VFS (plain and encrypted), circular
 * requires resolve like CRuby, and dedup semantics hold. Binding tests run
 * the physics/util surface headlessly from actual scripts, and GC
 * finalizers are forced via collectgarbage / GC.start under ASan.
 */

#include <SDL3/SDL.h>
#include <SDLStatic/bindings.h>
#include <SDLStatic/lua.h>
#include <SDLStatic/vfs.h>
#include <SDLStatic/ruby.h>
#include <gtest/gtest.h>
#include <physfs.h>

#include <lauxlib.h>
#include <mruby/array.h>
#include <mruby/compile.h>
#include <mruby/string.h>
#include <mruby/variable.h>

#include <string>

#ifndef SCRIPT_TEST_ASSETS_DIR
#error "SCRIPT_TEST_ASSETS_DIR must be defined by the build"
#endif

namespace
{

std::string AssetPath(const char *name)
{
    return std::string(SCRIPT_TEST_ASSETS_DIR) + "/" + name;
}

class ScriptVfs : public ::testing::Test
{
  protected:
    void SetUp() override
    {
        ASSERT_TRUE(PHYSFS_init(nullptr));
        ASSERT_TRUE(PHYSFS_mount(AssetPath("scripts.zip").c_str(), "/", 1));
    }
    void TearDown() override
    {
        PHYSFS_deinit();
    }
};

/* ---------------------------------------------------------------- Lua --- */

TEST_F(ScriptVfs, LuaRequiresModuleChainFromZipArchive)
{
    lua_State *L = SDLStatic_CreateLuaState();
    ASSERT_NE(L, nullptr);
    ASSERT_EQ(luaL_dostring(L, "local g = require('geometry')\n"
                               "result = g.diagonal(3, 4)"),
              LUA_OK)
        << lua_tostring(L, -1);
    lua_getglobal(L, "result");
    EXPECT_DOUBLE_EQ(lua_tonumber(L, -1), 5.0);

    // require caches: loading again must not re-execute (same table).
    ASSERT_EQ(luaL_dostring(L, "same = (require('geometry') == require('geometry'))"), LUA_OK);
    lua_getglobal(L, "same");
    EXPECT_TRUE(lua_toboolean(L, -1));
    lua_close(L);
}

TEST_F(ScriptVfs, LuaReportsMissingModulesAndSyntaxErrors)
{
    lua_State *L = SDLStatic_CreateLuaState();
    ASSERT_NE(L, nullptr);
    EXPECT_NE(luaL_dostring(L, "require('no.such.module')"), LUA_OK);
    lua_pop(L, 1);
    EXPECT_NE(luaL_dostring(L, "this is not lua"), LUA_OK);
    lua_pop(L, 1);
    EXPECT_FALSE(SDLStatic_LuaRunVFSScript(L, "missing.lua"));
    lua_close(L);
}

/* --------------------------------------------------------------- Ruby --- */

class RubyVfs : public ScriptVfs
{
  protected:
    void SetUp() override
    {
        ScriptVfs::SetUp();
        mrb_ = SDLStatic_CreateRubyState();
        ASSERT_NE(mrb_, nullptr);
        ASSERT_TRUE(SDLStatic_RubyAddLoadPath(mrb_, "."));
    }
    void TearDown() override
    {
        if (mrb_ != nullptr)
        {
            mrb_close(mrb_);
        }
        ScriptVfs::TearDown();
    }

    mrb_value Eval(const char *code)
    {
        mrb_value result = mrb_load_string(mrb_, code);
        EXPECT_EQ(mrb_->exc, nullptr) << ErrorText();
        return result;
    }

    std::string ErrorText()
    {
        if (mrb_->exc == nullptr)
        {
            return "";
        }
        mrb_value msg = mrb_inspect(mrb_, mrb_obj_value(mrb_->exc));
        std::string text = RSTRING_CSTR(mrb_, msg);
        mrb_->exc = nullptr;
        return text;
    }

    mrb_state *mrb_ = nullptr;
};

TEST_F(RubyVfs, RequireChainWithRelativeAndCircularFromZipArchive)
{
    // lib_a requires lib_b (which requires lib_a back — circular) and
    // util/helper via require_relative; all inside the mounted zip.
    mrb_value result = Eval("require 'lib_a'; LIB_A");
    EXPECT_EQ(mrb_integer(result), 21 * 2 + 100);

    // Dedup: a second require returns false and does not re-execute.
    mrb_value again = Eval("require 'lib_a'");
    EXPECT_TRUE(mrb_false_p(again));
    mrb_value features = Eval("$LOADED_FEATURES.length");
    EXPECT_EQ(mrb_integer(features), 3);

    // load re-executes unconditionally.
    mrb_value loaded = Eval("load 'util/helper.rb'");
    EXPECT_TRUE(mrb_true_p(loaded));
}

TEST_F(RubyVfs, MissingModulesAndSyntaxErrorsRaise)
{
    mrb_load_string(mrb_, "require 'does_not_exist'");
    EXPECT_NE(ErrorText().find("cannot load such file"), std::string::npos);
    mrb_load_string(mrb_, "require 'geometry.lua'"); // exists but Lua, not .rb
    ErrorText();                                     // just must not crash
    EXPECT_FALSE(SDLStatic_RubyRunVFSScript(mrb_, "missing.rb"));
}

TEST(RubyEncrypted, RequireWorksFromEncryptedArchive)
{
    ASSERT_TRUE(PHYSFS_init(nullptr));
    ASSERT_TRUE(SDLStatic_MountEncryptedArchiveFile(AssetPath("scripts_encrypted.bin").c_str(),
                                                    "scriptKey", nullptr));
    mrb_state *mrb = SDLStatic_CreateRubyState();
    ASSERT_NE(mrb, nullptr);
    SDLStatic_RubyAddLoadPath(mrb, ".");
    mrb_value result = mrb_load_string(mrb, "require 'lib_a'; LIB_A");
    ASSERT_EQ(mrb->exc, nullptr);
    EXPECT_EQ(mrb_integer(result), 142);
    mrb_close(mrb);
    PHYSFS_deinit();
}

TEST(LuaEncrypted, RequireWorksFromEncryptedArchive)
{
    ASSERT_TRUE(PHYSFS_init(nullptr));
    ASSERT_TRUE(SDLStatic_MountEncryptedArchiveFile(AssetPath("scripts_encrypted.bin").c_str(),
                                                    "scriptKey", nullptr));
    lua_State *L = SDLStatic_CreateLuaState();
    ASSERT_NE(L, nullptr);
    ASSERT_EQ(luaL_dostring(L, "d = require('geometry').diagonal(6, 8)"), LUA_OK)
        << lua_tostring(L, -1);
    lua_getglobal(L, "d");
    EXPECT_DOUBLE_EQ(lua_tonumber(L, -1), 10.0);
    lua_close(L);
    PHYSFS_deinit();
}

/* ----------------------------------------------------------- bindings --- */

TEST(BindingsLua, PhysicsAndUtilsDriveFromScriptWithGc)
{
    lua_State *L = SDLStatic_CreateLuaState();
    ASSERT_NE(L, nullptr);
    ASSERT_TRUE(SDLStatic_OpenLuaBindings(L));
    const char *script =
        "local w = SDLStatic.world(0, -10)\n"
        "local ground = w:box(0, 0, 50, 1, false)\n"
        "local ball = w:circle(0, 10, 0.5, true)\n"
        "for i = 1, 120 do w:step() end\n"
        "local x, y = ball:position()\n"
        "assert(y < 9, 'ball must fall, y=' .. y)\n"
        "assert(SDLStatic.sha256('abc'):sub(1, 8) == 'ba7816bf')\n"
        "local blob = SDLStatic.compress(string.rep('data', 200))\n"
        "assert(#SDLStatic.decompress(blob) == 800)\n"
        "local enc = SDLStatic.encrypt('secret', 'pw')\n"
        "assert(SDLStatic.decrypt(enc, 'pw') == 'secret')\n"
        "assert(SDLStatic.b64decode(SDLStatic.b64encode('hi')) == 'hi')\n"
        "ball = nil; ground = nil; w = nil\n"
        "collectgarbage('collect'); collectgarbage('collect')\n";
    ASSERT_EQ(luaL_dostring(L, script), LUA_OK) << lua_tostring(L, -1);
    lua_close(L); /* remaining handles finalize here; ASan verifies */
}

TEST(BindingsRuby, PhysicsAndUtilsDriveFromScriptWithGc)
{
    mrb_state *mrb = SDLStatic_CreateRubyState();
    ASSERT_NE(mrb, nullptr);
    ASSERT_TRUE(SDLStatic_OpenRubyBindings(mrb));
    const char *script =
        "w = SDLStatic.world(0.0, -10.0)\n"
        "ground = w.box(0.0, 0.0, 50.0, 1.0, false)\n"
        "ball = w.circle(0.0, 10.0, 0.5, true)\n"
        "120.times { w.step }\n"
        "x, y = ball.position\n"
        "raise 'ball must fall' unless y < 9\n"
        "raise 'sha' unless SDLStatic.sha256('abc').start_with?('ba7816bf')\n"
        "blob = SDLStatic.compress('data' * 200)\n"
        "raise 'zip' unless SDLStatic.decompress(blob).length == 800\n"
        "enc = SDLStatic.encrypt('secret', 'pw')\n"
        "raise 'crypt' unless SDLStatic.decrypt(enc, 'pw') == 'secret'\n"
        "raise 'b64' unless SDLStatic.b64decode(SDLStatic.b64encode('hi')) == 'hi'\n"
        "ball = nil; ground = nil; w = nil\n"
        "GC.start\n";
    mrb_load_string(mrb, script);
    if (mrb->exc != nullptr)
    {
        mrb_value msg = mrb_inspect(mrb, mrb_obj_value(mrb->exc));
        FAIL() << RSTRING_CSTR(mrb, msg);
    }
    mrb_close(mrb); /* remaining handles finalize here; ASan verifies */
}

TEST(BindingsLua, BodyPinsWorldSoGcOrderIsAlwaysSafe)
{
    lua_State *L = SDLStatic_CreateLuaState();
    ASSERT_NE(L, nullptr);
    ASSERT_TRUE(SDLStatic_OpenLuaBindings(L));
    // A live body handle pins its world through a uservalue: dropping the
    // world reference and forcing GC must NOT invalidate the body.
    EXPECT_EQ(luaL_dostring(L, "b = SDLStatic.world():box(0, 0, 1, 1, true)\n"
                               "collectgarbage('collect'); collectgarbage('collect')\n"
                               "local x, y = b:position()\n"
                               "assert(type(x) == 'number')\n"
                               "b = nil\n"
                               "collectgarbage('collect'); collectgarbage('collect')"),
              LUA_OK)
        << lua_tostring(L, -1);
    lua_close(L);
}

} // namespace
