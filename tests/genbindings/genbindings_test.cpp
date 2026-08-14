/**
 * @file genbindings_test.cpp
 * @brief Tests for the GENERATED bindings (tools/bindgen) on all four
 *        surfaces: C++ RAII/Status/alias, Lua, and Ruby, over the same
 *        underlying C libraries. Headless-safe: no window, audio device,
 *        or GPU is required.
 */

#include <SDL3/SDL.h>
#include <SDLStatic/bindings.h>
#include <SDLStatic/lua.h>
#include <SDLStatic/ruby.h>
#include <box2d/box2d.h>
#include <cJSON.h>
#include <gtest/gtest.h>

#include <mruby/compile.h>
#include <mruby/string.h>

#include <string>
#include <utility>

#include "sdlstatic/sdlstatic.h"

namespace
{

// ---------------------------------------------------------------------------
// C++ surface

TEST(GenCpp, SurfaceRaiiOwnsAndMoves)
{
    sdlstatic::Result<sdlstatic::sdl::Surface> surface =
        sdlstatic::sdl::Surface::CreateSurface(64, 48, SDL_PIXELFORMAT_RGBA8888);
    ASSERT_TRUE(surface.ok()) << surface.status().message();
    ASSERT_NE(surface->get(), nullptr);
    EXPECT_EQ(surface->get()->w, 64);

    sdlstatic::sdl::Surface owned = std::move(surface).value();
    sdlstatic::sdl::Surface moved = std::move(owned);
    EXPECT_NE(moved.get(), nullptr);
    EXPECT_EQ(owned.get(), nullptr);

    SDL_Surface *released = moved.release();
    ASSERT_NE(released, nullptr);
    SDL_DestroySurface(released);
}

TEST(GenCpp, FactoryFailureCarriesSdlError)
{
    sdlstatic::Result<sdlstatic::sdl::Surface> bad =
        sdlstatic::sdl::Surface::CreateSurface(0, 0, SDL_PIXELFORMAT_UNKNOWN);
    EXPECT_FALSE(bad.ok());
    EXPECT_FALSE(bad.status().message().empty());

    sdlstatic::Result<sdlstatic::img::Surface> missing =
        sdlstatic::img::Surface::Load("no-such-image.png");
    EXPECT_FALSE(missing.ok());
}

TEST(GenCpp, ByValuePropertiesRaii)
{
    sdlstatic::Result<sdlstatic::sdl::Properties> props =
        sdlstatic::sdl::Properties::CreateProperties();
    ASSERT_TRUE(props.ok());
    sdlstatic::Status set = props->SetNumberProperty("gen.test", 42);
    ASSERT_TRUE(set.ok()) << set.message();
    EXPECT_EQ(props->GetNumberProperty("gen.test", 0), 42);
    // Destructor destroys the by-value id (ASan-verified, engaged_ path).
}

TEST(GenCpp, StatusWrapperAndAlias)
{
    sdlstatic::Status status =
        sdlstatic::sdl::SetAppMetadata("genbindings", "1.0", "com.example.gen");
    EXPECT_TRUE(status.ok());
    const char *platform = sdlstatic::sdl::GetPlatform();
    ASSERT_NE(platform, nullptr);
    EXPECT_GT(std::string(platform).size(), 0u);
}

TEST(GenCpp, JsonDocumentRaii)
{
    sdlstatic::Result<sdlstatic::json::JsonDocument> doc =
        sdlstatic::json::JsonDocument::Parse("{\"answer\": 41.5}");
    ASSERT_TRUE(doc.ok());
    cJSON *item = cJSON_GetObjectItem(doc->get(), "answer");
    ASSERT_NE(item, nullptr);
    EXPECT_DOUBLE_EQ(cJSON_GetNumberValue(item), 41.5);

    sdlstatic::Result<sdlstatic::json::JsonDocument> bad =
        sdlstatic::json::JsonDocument::Parse("{nope");
    EXPECT_FALSE(bad.ok());
}

TEST(GenCpp, PhysicsWorldRaii)
{
    b2WorldDef def = b2DefaultWorldDef();
    sdlstatic::Result<sdlstatic::b2::PhysicsWorld> world =
        sdlstatic::b2::PhysicsWorld::CreateWorld(&def);
    ASSERT_TRUE(world.ok());
    EXPECT_TRUE(b2World_IsValid(world->get()));
    world->World_Step(1.0f / 60.0f, 4);
    b2WorldId id = world->get();
    world->reset();
    EXPECT_FALSE(b2World_IsValid(id));
}

TEST(GenCpp, ExtTiledFactoryFailsCleanly)
{
    sdlstatic::Result<sdlstatic::ext::TiledMapHandle> missing =
        sdlstatic::ext::TiledMapHandle::LoadTiledMap("no-such-map.tmj");
    EXPECT_FALSE(missing.ok());
}

// ---------------------------------------------------------------------------
// Lua surface

void RunLua(const char *script)
{
    lua_State *L = SDLStatic_CreateLuaState();
    ASSERT_NE(L, nullptr);
    ASSERT_TRUE(SDLStatic_OpenLuaBindings(L));
    ASSERT_EQ(luaL_dostring(L, script), LUA_OK) << lua_tostring(L, -1);
    lua_close(L);
}

TEST(GenLua, AliasEnumAndPodRoundTrip)
{
    RunLua(
        "assert(type(SDL.GetPlatform()) == 'string')\n"
        "assert(type(SDL.PIXELFORMAT_RGBA8888) == 'number')\n"
        "local ok, u = SDL.GetRectUnion({x=0, y=0, w=2, h=2}, {x=4, y=4, w=2, h=2})\n"
        "assert(ok and u.w == 6 and u.h == 6)\n"
        "local c = NK.rgb(10, 20, 30)\n"
        "assert(c.r == 10 and c.g == 20 and c.b == 30)\n");
}

TEST(GenLua, OwnedHandleGcAndExplicitDestroy)
{
    RunLua(
        "local s = SDL.CreateSurface(32, 32, SDL.PIXELFORMAT_RGBA8888)\n"
        "assert(s ~= nil and tostring(s):find('owned'))\n"
        "SDL.DestroySurface(s)  -- empties the box\n"
        "collectgarbage('collect')  -- __gc must not double-free\n"
        "local s2 = SDL.CreateSurface(16, 16, SDL.PIXELFORMAT_RGBA8888)\n"
        "s2 = nil\n"
        "collectgarbage('collect')  -- GC owns this one\n");
}

TEST(GenLua, JsonTreeWalk)
{
    RunLua(
        "local d = JSON.Parse('{\"a\": 7}')\n"
        "assert(d ~= nil)\n"
        "local item = JSON.GetObjectItem(d, 'a')\n"
        "assert(JSON.GetNumberValue(item) == 7)\n"
        "JSON.Delete(d)\n"
        "collectgarbage('collect')\n");
}

TEST(GenLua, PhysicsWorldByValueIds)
{
    RunLua(
        "local def = B2.DefaultWorldDef()\n"
        "assert(type(def) == 'table')\n"
        "local w = B2.CreateWorld(def)\n"
        "assert(B2.World_IsValid(w))\n"
        "B2.World_Step(w, 1/60, 4)\n"
        "local g = B2.World_GetGravity(w)\n"
        "assert(type(g) == 'table' and g.y < 0)\n"
        "B2.DestroyWorld(w)\n"
        "assert(not B2.World_IsValid(w))\n");
}

// ---------------------------------------------------------------------------
// Ruby surface

void RunRuby(const char *script)
{
    mrb_state *mrb = SDLStatic_CreateRubyState();
    ASSERT_NE(mrb, nullptr);
    ASSERT_TRUE(SDLStatic_OpenRubyBindings(mrb));
    mrb_load_string(mrb, script);
    if (mrb->exc != nullptr)
    {
        mrb_value msg = mrb_inspect(mrb, mrb_obj_value(mrb->exc));
        FAIL() << RSTRING_CSTR(mrb, msg);
    }
    mrb_close(mrb);
}

TEST(GenRuby, AliasEnumAndPodRoundTrip)
{
    RunRuby(
        "raise 'platform' unless SDL.GetPlatform.is_a?(String)\n"
        "raise 'const' unless SDL::PIXELFORMAT_RGBA8888.is_a?(Integer)\n"
        "c = NK.rgb(10, 20, 30)\n"
        "raise 'color' unless c[:r] == 10 && c[:g] == 20 && c[:b] == 30\n");
}

TEST(GenRuby, OwnedHandleGcAndExplicitDestroy)
{
    RunRuby(
        "s = SDL.CreateSurface(32, 32, SDL::PIXELFORMAT_RGBA8888)\n"
        "raise 'surface' if s.nil?\n"
        "SDL.DestroySurface(s)\n"
        "GC.start  # dfree must not double-free\n"
        "s2 = SDL.CreateSurface(16, 16, SDL::PIXELFORMAT_RGBA8888)\n"
        "s2 = nil\n"
        "GC.start  # GC owns this one\n");
}

TEST(GenRuby, JsonTreeWalkAndPhysics)
{
    RunRuby(
        "d = JSON.Parse('{\"a\": 7}')\n"
        "raise 'parse' if d.nil?\n"
        "item = JSON.GetObjectItem(d, 'a')\n"
        "raise 'value' unless JSON.GetNumberValue(item) == 7\n"
        "JSON.Delete(d)\n"
        "GC.start\n"
        "def_ = B2.DefaultWorldDef\n"
        "w = B2.CreateWorld(def_)\n"
        "raise 'world' unless B2.World_IsValid(w)\n"
        "B2.World_Step(w, 1.0 / 60.0, 4)\n"
        "B2.DestroyWorld(w)\n"
        "raise 'destroy' if B2.World_IsValid(w)\n");
}

} // namespace
