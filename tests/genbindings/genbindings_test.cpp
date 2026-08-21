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

TEST(GenCpp, NewLibrarySurfaces)
{
    // gfx: rotozoom returns an owned surface through RAII.
    sdlstatic::Result<sdlstatic::sdl::Surface> src =
        sdlstatic::sdl::Surface::CreateSurface(16, 16, SDL_PIXELFORMAT_RGBA8888);
    ASSERT_TRUE(src.ok());
    sdlstatic::Result<sdlstatic::gfx::Surface> rotated =
        sdlstatic::gfx::Surface::rotozoomSurface(src->get(), 90.0, 2.0, 0);
    ASSERT_TRUE(rotated.ok());
    EXPECT_NE(rotated->get(), nullptr);

    // toml: RAII table from mutable-buffer parse.
    char conf[] = "answer = 42";
    char err[64] = {0};
    sdlstatic::Result<sdlstatic::toml::TomlTable> table =
        sdlstatic::toml::TomlTable::parse(conf, err, sizeof(err));
    ASSERT_TRUE(table.ok()) << err;

    // mog: request builder RAII + version alias.
    ASSERT_NE(sdlstatic::mog::version(), nullptr);
    sdlstatic::Result<sdlstatic::mog::Request> req =
        sdlstatic::mog::Request::request_new("GET", "http://127.0.0.1:1/x");
    ASSERT_TRUE(req.ok());

    // yaml: alias surface reachable.
    int major = 0, minor = 0, patch = 0;
    sdlstatic::yaml::get_version(&major, &minor, &patch);
    EXPECT_GE(major, 0);
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

TEST(GenLua, NewLibraryModules)
{
    RunLua(
        "local s = SDL.CreateSurface(16, 16, SDL.PIXELFORMAT_RGBA8888)\n"
        "local r = SDL.CreateSoftwareRenderer(s)\n"
        "assert(GFX.pixelRGBA(r, 2, 2, 255, 0, 0, 255))\n"
        "assert(GFX.filledCircleRGBA(r, 8, 8, 5, 0, 255, 0, 255))\n"
        "local z = GFX.zoomSurface(s, 2.0, 2.0, 0)\n"
        "assert(z ~= nil and tostring(z):find('owned'))\n"
        "local t = TOML.parse('answer = 42', '', 0)\n"
        "assert(t ~= nil)\n"
        "TOML.free(t)\n"
        "assert(type(MOG.version()) == 'string')\n"
        "local req = MOG.request_new('GET', 'http://127.0.0.1:1/x')\n"
        "assert(req ~= nil and tostring(req):find('owned'))\n"
        "req = nil; collectgarbage('collect')\n");
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

TEST(GenRuby, NewLibraryModules)
{
    RunRuby(
        "s = SDL.CreateSurface(16, 16, SDL::PIXELFORMAT_RGBA8888)\n"
        "r = SDL.CreateSoftwareRenderer(s)\n"
        "raise 'pixel' unless GFX.pixelRGBA(r, 2, 2, 255, 0, 0, 255)\n"
        "z = GFX.zoomSurface(s, 2.0, 2.0, 0)\n"
        "raise 'zoom' if z.nil?\n"
        "t = TOML.parse('answer = 42', '', 0)\n"
        "raise 'toml' if t.nil?\n"
        "TOML.free(t)\n"
        "raise 'mog' unless MOG.version.is_a?(String)\n"
        "req = MOG.request_new('GET', 'http://127.0.0.1:1/x')\n"
        "raise 'req' if req.nil?\n"
        "req = nil\n"
        "GC.start\n");
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

// ---------------------------------------------------------------------------
// The engine, from scripts.
//
// Adding engine/include/SDLStatic/*.h to the bindgen spec generates 377 of
// the engine's 406 functions onto the Lua and Ruby surfaces. What that does
// NOT yet give a script is a way to *start*: SDLStatic_CreateEngine takes an
// SDLStatic_EngineConfig, and SDLStatic_ActorSpawn takes an
// SDLStatic_ActorDef. Both are plain C structs a caller fills in on the
// stack, and both contain pointers (and, for ActorDef, function pointers),
// so the classifier exposes them as opaque handles rather than marshalling
// them from a table the way it does SDL_Rect.
//
// So these check what is actually true today: the surface exists and is
// reachable by name. Driving the engine from a script needs the host layer
// described in docs/engine.md — table-to-struct marshalling for the def
// structs, and a callback bridge for the hooks.

namespace
{

TEST(GenLua, AScriptCanCreateAndDriveAnEngine)
{
    ASSERT_TRUE(SDL_Init(0));
    RunLua(
        // The builder is what makes this possible: a create/destroy pair
        // plus scalar setters is a shape the generator already binds as an
        // owned handle, so no marshalling was written for it.
        "local cfg = SDLStaticC.ConfigCreate()\n"
        "assert(cfg ~= nil)\n"
        "SDLStaticC.ConfigSetHeadless(cfg, true)\n"
        "SDLStaticC.ConfigSetManualClock(cfg, true)\n"
        "SDLStaticC.ConfigSetAutoMount(cfg, false)\n"
        "SDLStaticC.ConfigSetDesignSize(cfg, 320, 240)\n"
        "local e = SDLStaticC.CreateEngine(cfg)\n"
        "assert(e ~= nil, 'engine created from script')\n"
        "SDLStaticC.ConfigDestroy(cfg)\n"
        // The loop, owned by the script.
        "for i = 1, 3 do\n"
        "  SDLStaticC.EngineAdvance(e, 16666667)\n"
        "  SDLStaticC.EngineTick(e)\n"
        "end\n"
        "assert(SDLStaticC.EngineFrameCount(e) >= 3)\n"
        // Actors, spawned from script through the same builder shape.
        "local def = SDLStaticC.ActorDefCreate()\n"
        "SDLStaticC.ActorDefSetType(def, 'goblin')\n"
        "SDLStaticC.ActorDefSetPosition(def, 10, 20)\n"
        "local id = SDLStaticC.ActorSpawn(e, def)\n"
        "SDLStaticC.ActorDefDestroy(def)\n"
        "assert(id ~= 0, 'spawned')\n"
        "SDLStaticC.EngineAdvance(e, 16666667)\n"
        "SDLStaticC.EngineTick(e)\n"
        "assert(SDLStaticC.ActorCount(e) == 1)\n"
        "assert(SDLStaticC.ActorFindByType(e, 'goblin') == id)\n"
        // Lighting and text, to show the newer subsystems came through.
        "SDLStaticC.LightSetPreset(e, SDLStaticC.SDLSTATIC_LIGHT_NIGHT)\n"
        "assert(SDLStaticC.LightSunlight(e) < 0.5)\n"
        "assert(SDLStaticC.TextLoad(e, 'en', '[strings]\\n\"hi\" = \"Hello\"\\n'))\n"
        "assert(SDLStaticC.Text(e, 'hi') == 'Hello')\n"
        "SDLStaticC.DestroyEngine(e)\n");
    SDL_Quit();
}

TEST(GenRuby, AScriptCanCreateAndDriveAnEngine)
{
    ASSERT_TRUE(SDL_Init(0));
    // Ruby uses the same names as Lua, not snake_case.
    RunRuby(
        "cfg = SDLStaticC.ConfigCreate\n"
        "raise 'cfg' if cfg.nil?\n"
        "SDLStaticC.ConfigSetHeadless(cfg, true)\n"
        "SDLStaticC.ConfigSetManualClock(cfg, true)\n"
        "SDLStaticC.ConfigSetAutoMount(cfg, false)\n"
        "SDLStaticC.ConfigSetDesignSize(cfg, 320, 240)\n"
        "e = SDLStaticC.CreateEngine(cfg)\n"
        "raise 'engine' if e.nil?\n"
        "SDLStaticC.ConfigDestroy(cfg)\n"
        "3.times do\n"
        "  SDLStaticC.EngineAdvance(e, 16666667)\n"
        "  SDLStaticC.EngineTick(e)\n"
        "end\n"
        "raise 'frames' unless SDLStaticC.EngineFrameCount(e) >= 3\n"
        "d = SDLStaticC.ActorDefCreate\n"
        "SDLStaticC.ActorDefSetType(d, 'orc')\n"
        "id = SDLStaticC.ActorSpawn(e, d)\n"
        "SDLStaticC.ActorDefDestroy(d)\n"
        "raise 'spawn' if id == 0\n"
        "SDLStaticC.EngineAdvance(e, 16666667)\n"
        "SDLStaticC.EngineTick(e)\n"
        "raise 'count' unless SDLStaticC.ActorCount(e) == 1\n"
        "SDLStaticC.DestroyEngine(e)\n");
    SDL_Quit();
}

} // namespace
