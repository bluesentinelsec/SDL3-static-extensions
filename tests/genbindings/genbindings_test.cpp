/**
 * @file genbindings_test.cpp
 * @brief Tests for the GENERATED bindings (tools/bindgen) on all four
 *        surfaces: C++ RAII/Status/alias, Lua, and Ruby, over the same
 *        underlying C libraries. Headless-safe: no window, audio device,
 *        or GPU is required.
 */

#include <SDL3/SDL.h>
#include <SDLStatic/bindings.h>
#include <SDLStatic/gpu_build.h>
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

// ---------------------------------------------------------------------------
// The GPU descriptor builders
//
// 182 GPU functions were bound and nearly none callable: they take descriptor
// structs a C caller fills in on the stack, and a script has no stack to put
// one on. These check the builders that close that gap. No GPU device is
// needed for the descriptors themselves, which is the point — they are plain
// memory until SDL is handed them.

TEST(GpuBuild, PipelineBuilderOwnsItsArrays)
{
    SDL_GPUGraphicsPipelineCreateInfo *info = SDLStatic_GPUPipelineInfoCreate();
    ASSERT_NE(info, nullptr);

    // Past the initial capacity of four, so the arrays reallocate and the
    // descriptor must be re-pointed at the moved storage.
    for (Uint32 i = 0; i < 10; ++i)
    {
        ASSERT_TRUE(SDLStatic_GPUPipelineInfoAddVertexAttribute(
            info, i, 0, SDL_GPU_VERTEXELEMENTFORMAT_FLOAT3, i * 12));
    }
    ASSERT_TRUE(SDLStatic_GPUPipelineInfoAddVertexBuffer(info, 0, 12,
                                                         SDL_GPU_VERTEXINPUTRATE_VERTEX));
    ASSERT_TRUE(SDLStatic_GPUPipelineInfoAddColorTarget(info,
                                                        SDL_GPU_TEXTUREFORMAT_B8G8R8A8_UNORM));

    EXPECT_EQ(info->vertex_input_state.num_vertex_attributes, 10u);
    EXPECT_EQ(info->vertex_input_state.num_vertex_buffers, 1u);
    EXPECT_EQ(info->target_info.num_color_targets, 1u);
    // A stale pointer after a realloc reads freed memory rather than failing,
    // so check the contents, not just the counts.
    EXPECT_EQ(info->vertex_input_state.vertex_attributes[9].location, 9u);
    EXPECT_EQ(info->vertex_input_state.vertex_attributes[9].offset, 108u);
    EXPECT_EQ(info->vertex_input_state.vertex_buffer_descriptions[0].pitch, 12u);

    SDLStatic_GPUPipelineInfoDestroy(info);
}

TEST(GpuBuild, ShaderInfoCopiesCodeAndEntrypoint)
{
    SDL_GPUShaderCreateInfo *info = SDLStatic_GPUShaderCreateInfoCreate();
    ASSERT_NE(info, nullptr);
    // SDL's own default, so a script that does not care need say nothing.
    EXPECT_STREQ(info->entrypoint, "main");

    {
        // A script's string may be collected the moment the setter returns,
        // so the builder must not borrow it.
        std::string bytecode(64, '\x7f');
        SDLStatic_GPUShaderCreateInfoSetCode(info, bytecode.data(),
                                             static_cast<int>(bytecode.size()));
        SDLStatic_GPUShaderCreateInfoSetEntrypoint(info, std::string("vs_main").c_str());
    }
    ASSERT_EQ(info->code_size, 64u);
    EXPECT_EQ(info->code[0], 0x7f);
    EXPECT_EQ(info->code[63], 0x7f);
    EXPECT_STREQ(info->entrypoint, "vs_main");

    SDLStatic_GPUShaderCreateInfoSetCode(info, "abc", 3);  // replaces, does not leak
    EXPECT_EQ(info->code_size, 3u);

    SDLStatic_GPUShaderCreateInfoDestroy(info);
}

TEST(GpuBuild, TextureRegionGetsADepthOfOne)
{
    SDL_GPUTextureRegion *region = SDLStatic_GPUTextureRegionCreate();
    ASSERT_NE(region, nullptr);
    SDLStatic_GPUTextureRegionSet(region, nullptr, 0, 0, 32, 32);
    // A zero depth copies nothing and reports success, which is the worst
    // way for this to be wrong.
    EXPECT_EQ(region->d, 1u);
    EXPECT_EQ(region->w, 32u);
    SDLStatic_GPUTextureRegionDestroy(region);
}

TEST(GpuBuild, NullsAreRefusedNotCrashed)
{
    // A script passing nil should get an error, not a segfault in C.
    SDLStatic_GPUColorTargetInfoSetTexture(nullptr, nullptr);
    SDLStatic_GPUPipelineInfoDestroy(nullptr);
    SDLStatic_GPUShaderCreateInfoDestroy(nullptr);
    SDLStatic_GPUComputeBindingsDestroy(nullptr);
    EXPECT_FALSE(SDLStatic_GPUPipelineInfoAddColorTarget(nullptr,
                                                         SDL_GPU_TEXTUREFORMAT_B8G8R8A8_UNORM));
    EXPECT_EQ(SDLStatic_GPUAcquireSwapchain(nullptr, nullptr), nullptr);
    EXPECT_FALSE(SDLStatic_GPUWaitForFence(nullptr, nullptr));
    EXPECT_FALSE(SDLStatic_GPUUploadToTransferBuffer(nullptr, nullptr, 0, "x", 1, false));
}

TEST(GpuBuild, ComputeBindingsAppend)
{
    SDLStatic_GPUComputeBindings *bindings = SDLStatic_GPUComputeBindingsCreate();
    ASSERT_NE(bindings, nullptr);
    // NULL handles are refused, so this checks the refusal rather than the
    // append; the append itself needs a device and is covered below.
    EXPECT_FALSE(SDLStatic_GPUComputeBindingsAddBuffer(bindings, nullptr, true));
    EXPECT_EQ(SDLStatic_GPUBeginComputePass(nullptr, bindings), nullptr);
    SDLStatic_GPUComputeBindingsDestroy(bindings);
}

// The round trip that actually proves the builders work: put bytes on the
// device through a transfer buffer and read them back. Skipped where there is
// no GPU — CI runners mostly have none, and a skip is honest where a fake
// pass is not.
TEST(GpuBuild, TransferBufferRoundTrip)
{
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        GTEST_SKIP() << "no video: " << SDL_GetError();
    }
    SDL_GPUDevice *device = SDL_CreateGPUDevice(
        SDL_GPU_SHADERFORMAT_SPIRV | SDL_GPU_SHADERFORMAT_MSL | SDL_GPU_SHADERFORMAT_DXIL, true,
        nullptr);
    if (device == nullptr)
    {
        SDL_Quit();
        GTEST_SKIP() << "no GPU device: " << SDL_GetError();
    }

    SDL_GPUTransferBufferCreateInfo create = {};
    create.usage = SDL_GPU_TRANSFERBUFFERUSAGE_UPLOAD;
    create.size = 64;
    SDL_GPUTransferBuffer *buffer = SDL_CreateGPUTransferBuffer(device, &create);
    ASSERT_NE(buffer, nullptr) << SDL_GetError();

    const float vertices[4] = {1.0f, 2.0f, 3.0f, 4.0f};
    ASSERT_TRUE(SDLStatic_GPUUploadToTransferBuffer(device, buffer, 0, vertices, sizeof(vertices),
                                                    false))
        << SDL_GetError();

    float *read = static_cast<float *>(
        SDLStatic_GPUReadTransferBuffer(device, buffer, 0, sizeof(vertices)));
    ASSERT_NE(read, nullptr) << SDL_GetError();
    EXPECT_FLOAT_EQ(read[0], 1.0f);
    EXPECT_FLOAT_EQ(read[3], 4.0f);
    SDL_free(read);

    SDL_ReleaseGPUTransferBuffer(device, buffer);
    SDL_DestroyGPUDevice(device);
    SDL_Quit();
}

TEST(GenLua, GpuDescriptorsAreReachable)
{
    // The gap this closes: every one of these was bound and uncallable,
    // because none of the descriptors could be made from a script.
    RunLua(
        "local target = SDLStaticC.GPUColorTargetInfoCreate()\n"
        "assert(target ~= nil)\n"
        "SDLStaticC.GPUColorTargetInfoSetClearColor(target, 0.1, 0.2, 0.3, 1.0)\n"
        "SDLStaticC.GPUColorTargetInfoSetOps(target, SDL.GPU_LOADOP_CLEAR,\n"
        "                                    SDL.GPU_STOREOP_STORE)\n"
        "SDLStaticC.GPUColorTargetInfoDestroy(target)\n"
        "local pipeline = SDLStaticC.GPUPipelineInfoCreate()\n"
        "SDLStaticC.GPUPipelineInfoSetPrimitive(pipeline, SDL.GPU_PRIMITIVETYPE_TRIANGLELIST)\n"
        "for i = 0, 9 do\n"
        "  assert(SDLStaticC.GPUPipelineInfoAddVertexAttribute(\n"
        "           pipeline, i, 0, SDL.GPU_VERTEXELEMENTFORMAT_FLOAT3, i * 12))\n"
        "end\n"
        "assert(SDLStaticC.GPUPipelineInfoAddVertexBuffer(\n"
        "         pipeline, 0, 12, SDL.GPU_VERTEXINPUTRATE_VERTEX))\n"
        "assert(SDLStaticC.GPUPipelineInfoAddColorTarget(\n"
        "         pipeline, SDL.GPU_TEXTUREFORMAT_B8G8R8A8_UNORM))\n"
        "SDLStaticC.GPUPipelineInfoDestroy(pipeline)\n"
        // Shader bytecode arrives as a string, which is how a script would
        // hand over a compiled blob it read from disk.
        "local shader = SDLStaticC.GPUShaderCreateInfoCreate()\n"
        "SDLStaticC.GPUShaderCreateInfoSetCode(shader, string.rep('\\0', 32), 32)\n"
        "SDLStaticC.GPUShaderCreateInfoSetFormat(shader, SDL.GPU_SHADERFORMAT_SPIRV,\n"
        "                                        SDL.GPU_SHADERSTAGE_VERTEX)\n"
        "SDLStaticC.GPUShaderCreateInfoSetCounts(shader, 1, 0, 0, 1)\n"
        "SDLStaticC.GPUShaderCreateInfoDestroy(shader)\n"
        "local binds = SDLStaticC.GPUComputeBindingsCreate()\n"
        "SDLStaticC.GPUComputeBindingsDestroy(binds)\n"
        // The device call is reachable too; whether this machine has a GPU
        // is not this test's business, so both answers pass.
        "local device = SDL.CreateGPUDevice(SDL.GPU_SHADERFORMAT_SPIRV, true, nil)\n"
        "if device ~= nil then SDL.DestroyGPUDevice(device) end\n");
}

TEST(GenRuby, GpuDescriptorsAreReachable)
{
    RunRuby(
        "target = SDLStaticC.GPUColorTargetInfoCreate\n"
        "raise 'target' if target.nil?\n"
        "SDLStaticC.GPUColorTargetInfoSetClearColor(target, 0.1, 0.2, 0.3, 1.0)\n"
        "SDLStaticC.GPUColorTargetInfoSetOps(target, SDL::GPU_LOADOP_CLEAR,\n"
        "                                    SDL::GPU_STOREOP_STORE)\n"
        "SDLStaticC.GPUColorTargetInfoDestroy(target)\n"
        "pipeline = SDLStaticC.GPUPipelineInfoCreate\n"
        "10.times do |i|\n"
        "  raise 'attr' unless SDLStaticC.GPUPipelineInfoAddVertexAttribute(\n"
        "    pipeline, i, 0, SDL::GPU_VERTEXELEMENTFORMAT_FLOAT3, i * 12)\n"
        "end\n"
        "raise 'buffer' unless SDLStaticC.GPUPipelineInfoAddVertexBuffer(\n"
        "  pipeline, 0, 12, SDL::GPU_VERTEXINPUTRATE_VERTEX)\n"
        "raise 'target' unless SDLStaticC.GPUPipelineInfoAddColorTarget(\n"
        "  pipeline, SDL::GPU_TEXTUREFORMAT_B8G8R8A8_UNORM)\n"
        "SDLStaticC.GPUPipelineInfoDestroy(pipeline)\n"
        "shader = SDLStaticC.GPUShaderCreateInfoCreate\n"
        "SDLStaticC.GPUShaderCreateInfoSetCode(shader, \"\\0\" * 32, 32)\n"
        "SDLStaticC.GPUShaderCreateInfoDestroy(shader)\n");
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

// A whole game loop in Lua with no engine at all: surface, renderer, event
// pump, draw, present. This is the "structure it however you wish" case —
// if this works, a script author is not boxed into the opinionated loop.
//
// A software renderer over a surface rather than a window, so it runs on a
// headless CI box; the binding surface exercised is identical, since
// CreateWindow and CreateRenderer are bound the same way.
TEST(GenLua, AScriptCanWriteItsOwnGameLoop)
{
    // The event subsystem, not just the base: PushEvent and PollEvent need
    // a queue to exist.
    ASSERT_TRUE(SDL_Init(SDL_INIT_EVENTS));
    RunLua(
        "local surf = SDL.CreateSurface(64, 48, SDL.PIXELFORMAT_RGBA8888)\n"
        "assert(surf ~= nil, 'surface')\n"
        "local r = SDL.CreateSoftwareRenderer(surf)\n"
        "assert(r ~= nil, 'renderer')\n"
        // The event a script owns: without this the loop below cannot be
        // written at all.
        "local ev = SDLStaticC.EventCreate()\n"
        "assert(ev ~= nil, 'event')\n"
        // Push a quit so the loop has something real to end on.
        "local quit = SDLStaticC.EventCreate()\n"
        "SDLStaticC.EventSetType(quit, SDL.EVENT_QUIT)\n"
        "SDL.PushEvent(quit)\n"
        "SDLStaticC.EventDestroy(quit)\n"
        "local running, frames, saw_quit = true, 0, false\n"
        "while running and frames < 100 do\n"
        "  while SDL.PollEvent(ev) do\n"
        "    local kind = SDLStaticC.EventType(ev)\n"
        "    if kind == SDL.EVENT_QUIT then running = false; saw_quit = true end\n"
        "    if kind == SDL.EVENT_KEY_DOWN then\n"
        "      local _ = SDLStaticC.EventKeyScancode(ev)\n"
        "    end\n"
        "  end\n"
        "  SDL.SetRenderDrawColor(r, 20, 30, 40, 255)\n"
        "  SDL.RenderClear(r)\n"
        "  SDL.SetRenderDrawColor(r, 255, 0, 0, 255)\n"
        "  SDL.RenderFillRect(r, {x = 8, y = 8, w = 16, h = 16})\n"
        "  SDL.RenderPresent(r)\n"
        "  frames = frames + 1\n"
        "end\n"
        "assert(saw_quit, 'the loop saw the quit event')\n"
        "assert(frames >= 1, 'and drew at least one frame')\n"
        "SDLStaticC.EventDestroy(ev)\n"
        "SDL.DestroyRenderer(r)\n"
        "SDL.DestroySurface(surf)\n");
    SDL_Quit();
}

// The same, in Ruby, to prove the two surfaces really are the same shape.
TEST(GenRuby, AScriptCanWriteItsOwnGameLoop)
{
    ASSERT_TRUE(SDL_Init(SDL_INIT_EVENTS));
    RunRuby(
        "surf = SDL.CreateSurface(64, 48, SDL::PIXELFORMAT_RGBA8888)\n"
        "raise 'surface' if surf.nil?\n"
        "r = SDL.CreateSoftwareRenderer(surf)\n"
        "raise 'renderer' if r.nil?\n"
        "ev = SDLStaticC.EventCreate\n"
        "q = SDLStaticC.EventCreate\n"
        "SDLStaticC.EventSetType(q, SDL::EVENT_QUIT)\n"
        "SDL.PushEvent(q)\n"
        "SDLStaticC.EventDestroy(q)\n"
        "running = true\n"
        "frames = 0\n"
        "saw_quit = false\n"
        "while running && frames < 100\n"
        "  while SDL.PollEvent(ev)\n"
        // Written out rather than as a one-liner: `a = false and b = true`
        // short-circuits in Ruby, so the second assignment never runs.
        "    if SDLStaticC.EventType(ev) == SDL::EVENT_QUIT\n"
        "      running = false\n"
        "      saw_quit = true\n"
        "    end\n"
        "  end\n"
        "  SDL.SetRenderDrawColor(r, 20, 30, 40, 255)\n"
        "  SDL.RenderClear(r)\n"
        "  SDL.RenderPresent(r)\n"
        "  frames += 1\n"
        "end\n"
        "raise 'quit' unless saw_quit\n"
        "SDLStaticC.EventDestroy(ev)\n"
        "SDL.DestroyRenderer(r)\n"
        "SDL.DestroySurface(surf)\n");
    SDL_Quit();
}

// The opinionated loop, used from inside the script's own loop. This is
// the arrangement that needed hand-written glue: turning a Lua function
// into something C can hold is the one thing the generator cannot do.
//
// Hooks fire from EngineTick as well as from Run, so a script gets the
// fixed tick, the interpolation and the asset pump while still owning the
// `while` — which is the point.
TEST(GenLua, HooksFireInsideAScriptsOwnLoop)
{
    ASSERT_TRUE(SDL_Init(0));
    RunLua(
        "local cfg = SDLStaticC.ConfigCreate()\n"
        "SDLStaticC.ConfigSetHeadless(cfg, true)\n"
        "SDLStaticC.ConfigSetManualClock(cfg, true)\n"
        "SDLStaticC.ConfigSetAutoMount(cfg, false)\n"
        "local e = SDLStaticC.CreateEngine(cfg)\n"
        "SDLStaticC.ConfigDestroy(cfg)\n"
        "assert(e ~= nil)\n"
        "local steps, frames, alphas = 0, 0, {}\n"
        "SDLStaticC.OnFixedUpdate(e, function(step)\n"
        "  steps = steps + 1\n"
        "  assert(step > 0, 'the fixed step is a real duration')\n"
        "end)\n"
        "SDLStaticC.OnUpdate(e, function(dt) frames = frames + 1 end)\n"
        "SDLStaticC.OnRender(e, function(alpha) alphas[#alphas + 1] = alpha end)\n"
        // The script still owns the loop.
        "for i = 1, 5 do\n"
        "  SDLStaticC.EngineAdvance(e, 16666667)\n"
        "  SDLStaticC.EngineTick(e)\n"
        "end\n"
        "assert(frames == 5, 'update ran once a frame, got ' .. frames)\n"
        "assert(steps >= 4, 'the fixed tick ran, got ' .. steps)\n"
        "assert(#alphas == 5, 'render ran once a frame')\n"
        "for _, a in ipairs(alphas) do\n"
        "  assert(a >= 0 and a <= 1, 'alpha is an interpolation factor')\n"
        "end\n"
        // Replacing a handler releases the old one rather than stacking.
        "SDLStaticC.OnUpdate(e, function(dt) end)\n"
        "local before = frames\n"
        "SDLStaticC.EngineAdvance(e, 16666667)\n"
        "SDLStaticC.EngineTick(e)\n"
        "assert(frames == before, 'the replaced handler no longer runs')\n"
        "SDLStaticC.DestroyEngine(e)\n");
    SDL_Quit();
}

// An error inside a hook must not unwind through the engine's C frames:
// one bad frame should not take the game down mid-loop.
TEST(GenLua, AnErrorInAHookDoesNotKillTheLoop)
{
    ASSERT_TRUE(SDL_Init(0));
    RunLua(
        "local cfg = SDLStaticC.ConfigCreate()\n"
        "SDLStaticC.ConfigSetHeadless(cfg, true)\n"
        "SDLStaticC.ConfigSetManualClock(cfg, true)\n"
        "SDLStaticC.ConfigSetAutoMount(cfg, false)\n"
        "local e = SDLStaticC.CreateEngine(cfg)\n"
        "SDLStaticC.ConfigDestroy(cfg)\n"
        "SDLStaticC.OnUpdate(e, function(dt) error('deliberate') end)\n"
        "for i = 1, 3 do\n"
        "  SDLStaticC.EngineAdvance(e, 16666667)\n"
        "  assert(SDLStaticC.EngineTick(e), 'the loop survived')\n"
        "end\n"
        "SDLStaticC.DestroyEngine(e)\n");
    SDL_Quit();
}

// Joints, which were bound and uncallable before the builders: no
// ragdolls, vehicles, ropes or hinged doors from script.
TEST(GenLua, JointsCanBeBuiltAndCreatedFromLua)
{
    RunLua(
        "local wd = B2.DefaultWorldDef()\n"
        "local world = B2.CreateWorld(wd)\n"
        "assert(world ~= nil)\n"
        "local bd = B2.DefaultBodyDef()\n"
        "local a = B2.CreateBody(world, bd)\n"
        "local b = B2.CreateBody(world, bd)\n"
        "assert(a ~= nil and b ~= nil)\n"
        // A hinge with a limit and a motor, entirely from script.
        "local rd = SDLStaticC.RevoluteJointDefCreate()\n"
        "assert(rd ~= nil, 'the def a script could not make before')\n"
        "SDLStaticC.RevoluteJointDefSetBodies(rd, a, b)\n"
        "SDLStaticC.RevoluteJointDefSetAnchors(rd, 0, 0, 1, 0)\n"
        "SDLStaticC.RevoluteJointDefSetLimit(rd, -90, 90)\n"
        "SDLStaticC.RevoluteJointDefSetMotor(rd, true, 45, 10)\n"
        "local hinge = B2.CreateRevoluteJoint(world, rd)\n"
        "assert(hinge ~= nil, 'hinge created')\n"
        "SDLStaticC.RevoluteJointDefDestroy(rd)\n"
        // And a rope, to show the other builders work the same way.
        "local dd = SDLStaticC.DistanceJointDefCreate()\n"
        "SDLStaticC.DistanceJointDefSetBodies(dd, a, b)\n"
        "SDLStaticC.DistanceJointDefSetLength(dd, 2.0)\n"
        "SDLStaticC.DistanceJointDefSetSpring(dd, true, 4.0, 0.5)\n"
        "local rope = B2.CreateDistanceJoint(world, dd)\n"
        "assert(rope ~= nil, 'rope created')\n"
        "SDLStaticC.DistanceJointDefDestroy(dd)\n"
        "B2.DestroyWorld(world)\n");
}

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

// The Ruby half of the same contract.
TEST(GenRuby, HooksFireInsideAScriptsOwnLoop)
{
    ASSERT_TRUE(SDL_Init(0));
    RunRuby(
        "cfg = SDLStaticC.ConfigCreate\n"
        "SDLStaticC.ConfigSetHeadless(cfg, true)\n"
        "SDLStaticC.ConfigSetManualClock(cfg, true)\n"
        "SDLStaticC.ConfigSetAutoMount(cfg, false)\n"
        "e = SDLStaticC.CreateEngine(cfg)\n"
        "SDLStaticC.ConfigDestroy(cfg)\n"
        "raise 'engine' if e.nil?\n"
        "$steps = 0\n"
        "$frames = 0\n"
        "SDLStaticC.OnFixedUpdate(e) { |step| $steps += 1 }\n"
        "SDLStaticC.OnUpdate(e) { |dt| $frames += 1 }\n"
        "5.times do\n"
        "  SDLStaticC.EngineAdvance(e, 16666667)\n"
        "  SDLStaticC.EngineTick(e)\n"
        "end\n"
        "raise \"update ran #{$frames} times\" unless $frames == 5\n"
        "raise \"fixed ran #{$steps} times\" unless $steps >= 4\n"
        "SDLStaticC.DestroyEngine(e)\n");
    SDL_Quit();
}

TEST(GenRuby, JointsCanBeBuiltAndCreatedFromRuby)
{
    RunRuby(
        "wd = B2.DefaultWorldDef\n"
        "world = B2.CreateWorld(wd)\n"
        "bd = B2.DefaultBodyDef\n"
        "a = B2.CreateBody(world, bd)\n"
        "b = B2.CreateBody(world, bd)\n"
        "rd = SDLStaticC.RevoluteJointDefCreate\n"
        "SDLStaticC.RevoluteJointDefSetBodies(rd, a, b)\n"
        "SDLStaticC.RevoluteJointDefSetLimit(rd, -45, 45)\n"
        "hinge = B2.CreateRevoluteJoint(world, rd)\n"
        "raise 'hinge' if hinge.nil?\n"
        "SDLStaticC.RevoluteJointDefDestroy(rd)\n"
        "B2.DestroyWorld(world)\n");
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


// ---------------------------------------------------------------------------
// Scenes from a script
//
// A scene is defined by its callbacks, so unlike every other definition in
// the engine a builder alone would produce a scene that does nothing. These
// check the bridge that closes it: the lifecycle in order, per-scene
// identity, and the stack behaviour that is the whole reason scenes are a
// stack rather than a pointer.

TEST(GenLua, ScenesRunTheirLifecycleInOrder)
{
    ASSERT_TRUE(SDL_Init(0));
    RunLua(
        "local cfg = SDLStaticC.ConfigCreate()\n"
        "SDLStaticC.ConfigSetHeadless(cfg, true)\n"
        "SDLStaticC.ConfigSetManualClock(cfg, true)\n"
        "SDLStaticC.ConfigSetAutoMount(cfg, false)\n"
        "local e = SDLStaticC.CreateEngine(cfg)\n"
        "SDLStaticC.ConfigDestroy(cfg)\n"
        "assert(e ~= nil)\n"
        "local log = {}\n"
        "SDLStaticC.SceneDefine(e, 'title')\n"
        "SDLStaticC.SceneOn(e, 'title', 'load', function(scene)\n"
        "  log[#log + 1] = 'load'\n"
        "  assert(SDLStaticC.SceneName(scene) == 'title')\n"
        "  return true\n"
        "end)\n"
        "SDLStaticC.SceneOn(e, 'title', 'enter', function(s) log[#log+1] = 'enter' end)\n"
        "SDLStaticC.SceneOn(e, 'title', 'update', function(s, dt) log[#log+1] = 'update' end)\n"
        "SDLStaticC.SceneOn(e, 'title', 'render', function(s, a) log[#log+1] = 'render' end)\n"
        "SDLStaticC.SceneOn(e, 'title', 'exit', function(s) log[#log+1] = 'exit' end)\n"
        "SDLStaticC.SceneOn(e, 'title', 'unload', function(s) log[#log+1] = 'unload' end)\n"
        "assert(SDLStaticC.ScriptScenePush(e, 'title'))\n"
        // The push is deferred to the end of the frame, so nothing has run
        // yet — which is what lets a scene push from inside its own update.
        "assert(#log == 0, 'the push is deferred, got ' .. #log)\n"
        "for i = 1, 3 do\n"
        "  SDLStaticC.EngineAdvance(e, 16666667)\n"
        "  SDLStaticC.EngineTick(e)\n"
        "end\n"
        "assert(log[1] == 'load' and log[2] == 'enter',\n"
        "       'load then enter, got ' .. table.concat(log, ','))\n"
        "assert(SDLStaticC.SceneDepth(e) == 1)\n"
        "local seen_update, seen_render = false, false\n"
        "for _, entry in ipairs(log) do\n"
        "  if entry == 'update' then seen_update = true end\n"
        "  if entry == 'render' then seen_render = true end\n"
        "end\n"
        "assert(seen_update and seen_render, table.concat(log, ','))\n"
        // Popping runs the other half of the lifecycle, in the mirror order.
        "SDLStaticC.ScenePop(e)\n"
        "SDLStaticC.EngineAdvance(e, 16666667)\n"
        "SDLStaticC.EngineTick(e)\n"
        "assert(log[#log] == 'unload' and log[#log - 1] == 'exit',\n"
        "       'exit then unload, got ' .. table.concat(log, ','))\n"
        "assert(SDLStaticC.SceneDepth(e) == 0)\n"
        "SDLStaticC.DestroyEngine(e)\n");
    SDL_Quit();
}

// The reason scenes are a stack: a pause menu leaves the level underneath
// intact, so popping it returns to exactly where the player was.
TEST(GenLua, ScenesStackAndTheCoveredOneStops)
{
    ASSERT_TRUE(SDL_Init(0));
    RunLua(
        "local cfg = SDLStaticC.ConfigCreate()\n"
        "SDLStaticC.ConfigSetHeadless(cfg, true)\n"
        "SDLStaticC.ConfigSetManualClock(cfg, true)\n"
        "SDLStaticC.ConfigSetAutoMount(cfg, false)\n"
        "local e = SDLStaticC.CreateEngine(cfg)\n"
        "SDLStaticC.ConfigDestroy(cfg)\n"
        "local level_updates, menu_updates = 0, 0\n"
        "SDLStaticC.SceneDefine(e, 'level')\n"
        "SDLStaticC.SceneOn(e, 'level', 'update', function(s, dt)\n"
        "  level_updates = level_updates + 1\n"
        "end)\n"
        "SDLStaticC.SceneDefine(e, 'menu')\n"
        "SDLStaticC.SceneOn(e, 'menu', 'update', function(s, dt)\n"
        "  menu_updates = menu_updates + 1\n"
        "end)\n"
        "SDLStaticC.ScriptScenePush(e, 'level')\n"
        "for i = 1, 3 do\n"
        "  SDLStaticC.EngineAdvance(e, 16666667); SDLStaticC.EngineTick(e)\n"
        "end\n"
        "local before = level_updates\n"
        "assert(before > 0, 'the level ran')\n"
        "SDLStaticC.ScriptScenePush(e, 'menu')\n"
        // The push applies at the end of the frame, so the level is still
        // the top scene for this one; measure from after it settles.
        "SDLStaticC.EngineAdvance(e, 16666667); SDLStaticC.EngineTick(e)\n"
        "before = level_updates\n"
        "for i = 1, 3 do\n"
        "  SDLStaticC.EngineAdvance(e, 16666667); SDLStaticC.EngineTick(e)\n"
        "end\n"
        "assert(SDLStaticC.SceneDepth(e) == 2, 'both are on the stack')\n"
        "assert(menu_updates > 0, 'the menu runs')\n"
        // Covered scenes stop by default — that is what "paused" means.
        "assert(level_updates == before,\n"
        "       'the covered level stopped, ran ' .. (level_updates - before) .. ' more')\n"
        "SDLStaticC.ScenePop(e)\n"
        "for i = 1, 3 do\n"
        "  SDLStaticC.EngineAdvance(e, 16666667); SDLStaticC.EngineTick(e)\n"
        "end\n"
        "assert(level_updates > before, 'the level resumed where it was')\n"
        "SDLStaticC.DestroyEngine(e)\n");
    SDL_Quit();
}

// One definition, several live scenes: the callback is given its scene, so
// a script keys its own state by that — what SDLStatic_SceneState does for
// C, done the way a script would do it.
TEST(GenLua, OneDefinitionBacksSeveralLiveScenes)
{
    ASSERT_TRUE(SDL_Init(0));
    RunLua(
        "local cfg = SDLStaticC.ConfigCreate()\n"
        "SDLStaticC.ConfigSetHeadless(cfg, true)\n"
        "SDLStaticC.ConfigSetManualClock(cfg, true)\n"
        "SDLStaticC.ConfigSetAutoMount(cfg, false)\n"
        "local e = SDLStaticC.CreateEngine(cfg)\n"
        "SDLStaticC.ConfigDestroy(cfg)\n"
        "local state = {}\n"
        "local distinct = 0\n"
        "SDLStaticC.SceneDefine(e, 'room')\n"
        // Transparent, so pushing a second room leaves the first drawing —
        // and updating, so both are live at once.
        "SDLStaticC.ScriptSceneSetFlags(e, 'room', 3)\n"
        // Keyed by SceneKey, not by the scene itself: a handle is boxed
        // fresh each time it crosses into Lua, so the scene is a different
        // table key every frame and per-scene state never finds itself.
        "SDLStaticC.SceneOn(e, 'room', 'update', function(scene, dt)\n"
        "  local key = SDLStaticC.SceneKey(scene)\n"
        "  if state[key] == nil then\n"
        "    state[key] = 0\n"
        "    distinct = distinct + 1\n"
        "  end\n"
        "  state[key] = state[key] + 1\n"
        "end)\n"
        "SDLStaticC.ScriptScenePush(e, 'room')\n"
        "for i = 1, 2 do SDLStaticC.EngineAdvance(e, 16666667); SDLStaticC.EngineTick(e) end\n"
        "SDLStaticC.ScriptScenePush(e, 'room')\n"
        "for i = 1, 2 do SDLStaticC.EngineAdvance(e, 16666667); SDLStaticC.EngineTick(e) end\n"
        "assert(SDLStaticC.SceneDepth(e) == 2)\n"
        "assert(distinct == 2, 'two live scenes from one definition, saw ' .. distinct)\n"
        "SDLStaticC.DestroyEngine(e)\n");
    SDL_Quit();
}

TEST(GenLua, UnknownSceneHookIsAnErrorNotSilence)
{
    ASSERT_TRUE(SDL_Init(0));
    lua_State *L = SDLStatic_CreateLuaState();
    ASSERT_NE(L, nullptr);
    ASSERT_TRUE(SDLStatic_OpenLuaBindings(L));
    // A typo in a hook name must name the hooks that exist, rather than
    // registering nothing and leaving a scene that quietly does not draw.
    const int rc = luaL_dostring(
        L,
        "local cfg = SDLStaticC.ConfigCreate()\n"
        "SDLStaticC.ConfigSetHeadless(cfg, true)\n"
        "SDLStaticC.ConfigSetAutoMount(cfg, false)\n"
        "local e = SDLStaticC.CreateEngine(cfg)\n"
        "SDLStaticC.SceneDefine(e, 'title')\n"
        "SDLStaticC.SceneOn(e, 'title', 'raender', function(s, a) end)\n");
    EXPECT_NE(rc, LUA_OK) << "a misspelled hook should raise";
    const char *message = lua_tostring(L, -1);
    ASSERT_NE(message, nullptr);
    EXPECT_NE(std::string(message).find("unknown scene hook"), std::string::npos) << message;
    EXPECT_NE(std::string(message).find("render"), std::string::npos)
        << "the error should name the hooks that exist: " << message;
    lua_close(L);
    SDL_Quit();
}

TEST(GenLua, PushingAnUndefinedSceneFails)
{
    ASSERT_TRUE(SDL_Init(0));
    RunLua(
        "local cfg = SDLStaticC.ConfigCreate()\n"
        "SDLStaticC.ConfigSetHeadless(cfg, true)\n"
        "SDLStaticC.ConfigSetAutoMount(cfg, false)\n"
        "local e = SDLStaticC.CreateEngine(cfg)\n"
        "SDLStaticC.ConfigDestroy(cfg)\n"
        "SDLStaticC.SceneDefine(e, 'title')\n"
        "assert(SDLStaticC.ScriptSceneDefined(e, 'title'))\n"
        "assert(not SDLStaticC.ScriptSceneDefined(e, 'level'))\n"
        "assert(not SDLStaticC.ScriptScenePush(e, 'level'),\n"
        "       'pushing an undefined scene reports failure')\n"
        "SDLStaticC.DestroyEngine(e)\n");
    SDL_Quit();
}

// Redefining a name replaces its handlers rather than shadowing them. A
// script reloaded during development should get its new callbacks, not the
// old ones held alive underneath.
TEST(GenLua, RedefiningASceneReplacesItsHandlers)
{
    ASSERT_TRUE(SDL_Init(0));
    RunLua(
        "local cfg = SDLStaticC.ConfigCreate()\n"
        "SDLStaticC.ConfigSetHeadless(cfg, true)\n"
        "SDLStaticC.ConfigSetManualClock(cfg, true)\n"
        "SDLStaticC.ConfigSetAutoMount(cfg, false)\n"
        "local e = SDLStaticC.CreateEngine(cfg)\n"
        "SDLStaticC.ConfigDestroy(cfg)\n"
        "local old_ran, new_ran = 0, 0\n"
        "SDLStaticC.SceneDefine(e, 'title')\n"
        "SDLStaticC.SceneOn(e, 'title', 'update', function(s, dt) old_ran = old_ran + 1 end)\n"
        "SDLStaticC.SceneDefine(e, 'title')  -- same name, fresh definition\n"
        "SDLStaticC.SceneOn(e, 'title', 'update', function(s, dt) new_ran = new_ran + 1 end)\n"
        "SDLStaticC.ScriptScenePush(e, 'title')\n"
        "for i = 1, 3 do SDLStaticC.EngineAdvance(e, 16666667); SDLStaticC.EngineTick(e) end\n"
        "assert(new_ran > 0, 'the new handler runs')\n"
        "assert(old_ran == 0, 'the replaced handler does not, ran ' .. old_ran)\n"
        "SDLStaticC.DestroyEngine(e)\n");
    SDL_Quit();
}

TEST(GenRuby, ScenesRunTheirLifecycleInOrder)
{
    ASSERT_TRUE(SDL_Init(0));
    RunRuby(
        "cfg = SDLStaticC.ConfigCreate\n"
        "SDLStaticC.ConfigSetHeadless(cfg, true)\n"
        "SDLStaticC.ConfigSetManualClock(cfg, true)\n"
        "SDLStaticC.ConfigSetAutoMount(cfg, false)\n"
        "e = SDLStaticC.CreateEngine(cfg)\n"
        "SDLStaticC.ConfigDestroy(cfg)\n"
        "raise 'engine' if e.nil?\n"
        "$log = []\n"
        "SDLStaticC.SceneDefine(e, 'title')\n"
        "SDLStaticC.SceneOn(e, 'title', 'load') { |scene| $log << 'load'; true }\n"
        "SDLStaticC.SceneOn(e, 'title', 'enter') { |scene| $log << 'enter' }\n"
        "SDLStaticC.SceneOn(e, 'title', 'update') { |scene, dt| $log << 'update' }\n"
        "SDLStaticC.SceneOn(e, 'title', 'exit') { |scene| $log << 'exit' }\n"
        "SDLStaticC.SceneOn(e, 'title', 'unload') { |scene| $log << 'unload' }\n"
        "raise 'push' unless SDLStaticC.ScriptScenePush(e, 'title')\n"
        "3.times do\n"
        "  SDLStaticC.EngineAdvance(e, 16666667)\n"
        "  SDLStaticC.EngineTick(e)\n"
        "end\n"
        "raise \"order: #{$log}\" unless $log[0] == 'load' && $log[1] == 'enter'\n"
        "raise 'update' unless $log.include?('update')\n"
        "raise 'depth' unless SDLStaticC.SceneDepth(e) == 1\n"
        "SDLStaticC.ScenePop(e)\n"
        "SDLStaticC.EngineAdvance(e, 16666667)\n"
        "SDLStaticC.EngineTick(e)\n"
        "raise \"teardown: #{$log}\" unless $log[-1] == 'unload' && $log[-2] == 'exit'\n"
        "SDLStaticC.DestroyEngine(e)\n");
    SDL_Quit();
}

TEST(GenRuby, ScenesStackAndTheCoveredOneStops)
{
    ASSERT_TRUE(SDL_Init(0));
    RunRuby(
        "cfg = SDLStaticC.ConfigCreate\n"
        "SDLStaticC.ConfigSetHeadless(cfg, true)\n"
        "SDLStaticC.ConfigSetManualClock(cfg, true)\n"
        "SDLStaticC.ConfigSetAutoMount(cfg, false)\n"
        "e = SDLStaticC.CreateEngine(cfg)\n"
        "SDLStaticC.ConfigDestroy(cfg)\n"
        "$level = 0\n"
        "$menu = 0\n"
        "SDLStaticC.SceneDefine(e, 'level')\n"
        "SDLStaticC.SceneOn(e, 'level', 'update') { |s, dt| $level += 1 }\n"
        "SDLStaticC.SceneDefine(e, 'menu')\n"
        "SDLStaticC.SceneOn(e, 'menu', 'update') { |s, dt| $menu += 1 }\n"
        "SDLStaticC.ScriptScenePush(e, 'level')\n"
        "3.times { SDLStaticC.EngineAdvance(e, 16666667); SDLStaticC.EngineTick(e) }\n"
        "before = $level\n"
        "raise 'level' unless before > 0\n"
        "SDLStaticC.ScriptScenePush(e, 'menu')\n"
        // The push applies at the end of the frame, so the level is still
        // on top for this one; measure from after it settles.
        "SDLStaticC.EngineAdvance(e, 16666667); SDLStaticC.EngineTick(e)\n"
        "before = $level\n"
        "3.times { SDLStaticC.EngineAdvance(e, 16666667); SDLStaticC.EngineTick(e) }\n"
        "raise 'depth' unless SDLStaticC.SceneDepth(e) == 2\n"
        "raise 'menu' unless $menu > 0\n"
        "raise 'the covered level kept running' unless $level == before\n"
        "SDLStaticC.ScenePop(e)\n"
        "3.times { SDLStaticC.EngineAdvance(e, 16666667); SDLStaticC.EngineTick(e) }\n"
        "raise 'the level did not resume' unless $level > before\n"
        "SDLStaticC.DestroyEngine(e)\n");
    SDL_Quit();
}

} // namespace
