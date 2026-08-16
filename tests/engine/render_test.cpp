// Engine-owned rendering: draw order, culling, origins, interpolation.
//
// These read the framebuffer rather than trusting the draw list, because
// the failure that matters is what ends up on screen. The headless engine
// is a real software renderer, so "which colour is at this pixel" is an
// honest answer to "which sprite won".
#include <SDLStatic/engine_render.h>

#include <gtest/gtest.h>

#include <vector>

namespace
{

// A solid-colour sprite: no texture, so the engine fills a rectangle. That
// is a real feature (it is how a game draws before it has art) and it makes
// these tests independent of image loading.
SDLStatic_Sprite Solid(float r, float g, float b, float size, int layer = 0)
{
    SDLStatic_Sprite sprite = SDLStatic_SpriteDefault();
    sprite.color = SDL_FColor{r, g, b, 1.0f};
    sprite.width = size;
    sprite.height = size;
    sprite.layer = layer;
    return sprite;
}

class RenderHarness : public ::testing::Test
{
  protected:
    void SetUp() override
    {
        ASSERT_TRUE(SDL_Init(0)) << SDL_GetError();
        SDLStatic_EngineConfig config{};
        config.headless = true;
        config.manual_clock = true;
        config.no_auto_mount = true;
        config.design_width = 320;
        config.design_height = 240;
        config.window_width = 320;
        config.window_height = 240;
        engine_ = SDLStatic_CreateEngine(&config);
        ASSERT_NE(engine_, nullptr) << SDL_GetError();
        SDLStatic_CameraInit(&camera_, engine_);
        SDLStatic_CameraSnap(&camera_, 160.0f, 120.0f);
        SDLStatic_CameraUpdate(&camera_, engine_, 0.0f);
    }
    void TearDown() override
    {
        SDLStatic_DestroyEngine(engine_);
        SDL_Quit();
    }

    SDLStatic_ActorId Spawn(float x, float y)
    {
        SDLStatic_ActorDef def{};
        def.type = "sprite";
        def.x = x;
        def.y = y;
        const SDLStatic_ActorId id = SDLStatic_ActorSpawn(engine_, &def);
        // One frame so the actor is admitted; queries and rendering both
        // deliberately ignore actors that are still pending.
        SDLStatic_EngineAdvance(engine_, 16666667ull);
        SDLStatic_EngineTick(engine_);
        return id;
    }

    void Draw(const SDLStatic_Camera *camera = nullptr, float alpha = 1.0f)
    {
        SDL_Renderer *r = SDLStatic_EngineRenderer(engine_);
        SDL_SetRenderDrawBlendMode(r, SDL_BLENDMODE_NONE);
        SDL_SetRenderDrawColorFloat(r, 0.0f, 0.0f, 0.0f, 1.0f);
        SDL_RenderClear(r);
        SDLStatic_RenderWorld(engine_, (camera != nullptr) ? camera : &camera_, alpha);
    }

    // The colour at a design-space point, as an (r,g,b) triple 0-255.
    std::vector<int> PixelAt(int x, int y)
    {
        SDL_Renderer *r = SDLStatic_EngineRenderer(engine_);
        int w = 0;
        int h = 0;
        SDLStatic_EnginePixelSize(engine_, &w, &h);
        SDL_Rect read{0, 0, w, h};
        SDL_Surface *surface = SDL_RenderReadPixels(r, &read);
        if (surface == nullptr)
        {
            return {-1, -1, -1};
        }
        Uint8 red = 0;
        Uint8 green = 0;
        Uint8 blue = 0;
        Uint8 alpha = 0;
        const SDL_PixelFormatDetails *details = SDL_GetPixelFormatDetails(surface->format);
        const Uint32 *pixels = static_cast<const Uint32 *>(surface->pixels);
        const int pitch = surface->pitch / 4;
        SDL_GetRGBA(pixels[y * pitch + x], details, SDL_GetSurfacePalette(surface), &red, &green,
                    &blue, &alpha);
        SDL_DestroySurface(surface);
        return {red, green, blue};
    }

    SDLStatic_Engine *engine_ = nullptr;
    SDLStatic_Camera camera_{};
};

TEST_F(RenderHarness, ADefaultSpriteIsVisibleAndWhite)
{
    const SDLStatic_Sprite sprite = SDLStatic_SpriteDefault();
    EXPECT_TRUE(sprite.visible) << "a zeroed sprite would be invisible";
    EXPECT_FLOAT_EQ(sprite.color.a, 1.0f) << "and fully transparent";
    EXPECT_FLOAT_EQ(sprite.origin_x, 0.5f) << "and pinned by its corner";
    EXPECT_FLOAT_EQ(sprite.origin_y, 0.5f);
}

TEST_F(RenderHarness, ASpriteIsDrawnWhereTheActorIs)
{
    const SDLStatic_ActorId id = Spawn(160.0f, 120.0f);
    const SDLStatic_Sprite sprite = Solid(1.0f, 0.0f, 0.0f, 40.0f);
    ASSERT_TRUE(SDLStatic_ActorSetSprite(SDLStatic_ActorGet(engine_, id), &sprite));

    Draw();
    EXPECT_EQ(PixelAt(160, 120)[0], 255) << "red, at the actor";
    EXPECT_EQ(PixelAt(10, 10)[0], 0) << "and not everywhere else";
}

// The default origin is the middle, so the sprite straddles the position.
TEST_F(RenderHarness, TheOriginDecidesWhereThePositionSits)
{
    const SDLStatic_ActorId id = Spawn(160.0f, 120.0f);
    SDLStatic_Sprite sprite = Solid(0.0f, 1.0f, 0.0f, 40.0f);
    SDLStatic_ActorSetSprite(SDLStatic_ActorGet(engine_, id), &sprite);

    Draw();
    EXPECT_EQ(PixelAt(160, 105)[1], 255) << "centred: 20 units above is covered";
    EXPECT_EQ(PixelAt(160, 135)[1], 255) << "and 20 below";

    // Feet-anchored: the position is the bottom edge, which is what you
    // want for anything standing on ground.
    sprite.origin_y = 1.0f;
    SDLStatic_ActorSetSprite(SDLStatic_ActorGet(engine_, id), &sprite);
    Draw();
    EXPECT_EQ(PixelAt(160, 105)[1], 255) << "now entirely above the position";
    EXPECT_EQ(PixelAt(160, 135)[1], 0);
}

// --- ordering -------------------------------------------------------------

TEST_F(RenderHarness, HigherLayersAreDrawnInFront)
{
    const SDLStatic_ActorId back = Spawn(160.0f, 120.0f);
    const SDLStatic_ActorId front = Spawn(160.0f, 120.0f);

    const SDLStatic_Sprite red = Solid(1.0f, 0.0f, 0.0f, 60.0f, 10);
    const SDLStatic_Sprite blue = Solid(0.0f, 0.0f, 1.0f, 60.0f, 20);
    SDLStatic_ActorSetSprite(SDLStatic_ActorGet(engine_, back), &red);
    SDLStatic_ActorSetSprite(SDLStatic_ActorGet(engine_, front), &blue);

    Draw();
    const std::vector<int> pixel = PixelAt(160, 120);
    EXPECT_EQ(pixel[2], 255) << "the higher layer wins";
    EXPECT_EQ(pixel[0], 0);

    // Swapping the layers swaps the result — the order is the layer, not
    // the spawn order.
    SDLStatic_ActorSprite(SDLStatic_ActorGet(engine_, back))->layer = 30;
    Draw();
    EXPECT_EQ(PixelAt(160, 120)[0], 255);
}

TEST_F(RenderHarness, OrderBreaksTiesWithinALayer)
{
    const SDLStatic_ActorId first = Spawn(160.0f, 120.0f);
    const SDLStatic_ActorId second = Spawn(160.0f, 120.0f);

    SDLStatic_Sprite red = Solid(1.0f, 0.0f, 0.0f, 60.0f, 5);
    red.order = 10.0f;
    SDLStatic_Sprite blue = Solid(0.0f, 0.0f, 1.0f, 60.0f, 5);
    blue.order = 1.0f;
    SDLStatic_ActorSetSprite(SDLStatic_ActorGet(engine_, first), &red);
    SDLStatic_ActorSetSprite(SDLStatic_ActorGet(engine_, second), &blue);

    Draw();
    EXPECT_EQ(PixelAt(160, 120)[0], 255) << "the higher order is in front";
}

// Y-sorting is how a top-down game gets depth: something further down the
// screen is nearer the viewer, so it draws in front.
TEST_F(RenderHarness, YSortingPutsLowerSpritesInFront)
{
    const SDLStatic_ActorId far_away = Spawn(160.0f, 100.0f);
    const SDLStatic_ActorId near_by = Spawn(160.0f, 130.0f);

    SDLStatic_Sprite red = Solid(1.0f, 0.0f, 0.0f, 60.0f, 5);
    red.sort_by_y = true;
    SDLStatic_Sprite blue = Solid(0.0f, 0.0f, 1.0f, 60.0f, 5);
    blue.sort_by_y = true;
    SDLStatic_ActorSetSprite(SDLStatic_ActorGet(engine_, far_away), &red);
    SDLStatic_ActorSetSprite(SDLStatic_ActorGet(engine_, near_by), &blue);

    Draw();
    // Where they overlap, the lower (blue, y=130) is in front.
    EXPECT_EQ(PixelAt(160, 115)[2], 255);

    // Move the red one below the blue and it takes over — the sort happens
    // after the actors have moved, which is the point of doing it here.
    SDLStatic_ActorSetPosition(SDLStatic_ActorGet(engine_, far_away), 160.0f, 160.0f);
    Draw();
    EXPECT_EQ(PixelAt(160, 140)[0], 255);
}

// --- culling --------------------------------------------------------------

TEST_F(RenderHarness, OffScreenSpritesAreCulled)
{
    Spawn(160.0f, 120.0f);
    const SDLStatic_ActorId visible = SDLStatic_ActorFindByType(engine_, "sprite");
    SDLStatic_Sprite sprite = Solid(1.0f, 1.0f, 1.0f, 20.0f);
    SDLStatic_ActorSetSprite(SDLStatic_ActorGet(engine_, visible), &sprite);

    // A long way outside the camera's view.
    const SDLStatic_ActorId offscreen = Spawn(9000.0f, 9000.0f);
    SDLStatic_ActorSetSprite(SDLStatic_ActorGet(engine_, offscreen), &sprite);

    Draw();
    const SDLStatic_RenderStats stats = SDLStatic_RenderLastStats(engine_);
    EXPECT_EQ(stats.considered, 2);
    EXPECT_EQ(stats.culled, 1);
    EXPECT_EQ(stats.drawn, 1) << "a level is bigger than the screen; that is the point";
}

// A sprite straddling the edge must still be drawn, or things pop in.
TEST_F(RenderHarness, PartiallyVisibleSpritesAreNotCulled)
{
    const SDLStatic_ActorId id = Spawn(0.0f, 120.0f); // half off the left edge
    const SDLStatic_Sprite sprite = Solid(1.0f, 1.0f, 0.0f, 40.0f);
    SDLStatic_ActorSetSprite(SDLStatic_ActorGet(engine_, id), &sprite);

    Draw();
    EXPECT_EQ(SDLStatic_RenderLastStats(engine_).drawn, 1);
    EXPECT_EQ(PixelAt(5, 120)[0], 255) << "the visible half is on screen";
}

// A rotated sprite sweeps a bigger area than its rectangle, so culling
// against the unrotated one would clip it as it turned near the edge.
TEST_F(RenderHarness, RotationWidensTheCullBounds)
{
    // Just outside the view by the width of the sprite, but its rotated
    // corner reaches back in.
    const SDLStatic_ActorId id = Spawn(-24.0f, 120.0f);
    const SDLStatic_Sprite sprite = Solid(1.0f, 1.0f, 1.0f, 40.0f);
    SDLStatic_Actor *actor = SDLStatic_ActorGet(engine_, id);
    SDLStatic_ActorSetSprite(actor, &sprite);

    Draw();
    EXPECT_EQ(SDLStatic_RenderLastStats(engine_).drawn, 0) << "square: fully outside";

    SDLStatic_ActorTransform t = SDLStatic_ActorLocal(actor);
    t.rotation = 45.0f;
    SDLStatic_ActorSetLocal(actor, &t);
    Draw();
    EXPECT_EQ(SDLStatic_RenderLastStats(engine_).drawn, 1) << "turned: its corner reaches in";
}

TEST_F(RenderHarness, WithoutACameraNothingIsCulled)
{
    const SDLStatic_ActorId id = Spawn(9000.0f, 9000.0f);
    const SDLStatic_Sprite sprite = Solid(1.0f, 1.0f, 1.0f, 20.0f);
    SDLStatic_ActorSetSprite(SDLStatic_ActorGet(engine_, id), &sprite);

    SDL_Renderer *r = SDLStatic_EngineRenderer(engine_);
    SDL_RenderClear(r);
    SDLStatic_RenderWorld(engine_, nullptr, 1.0f);
    EXPECT_EQ(SDLStatic_RenderLastStats(engine_).culled, 0);
}

// --- visibility -----------------------------------------------------------

TEST_F(RenderHarness, HiddenAndClearedSpritesDrawNothing)
{
    const SDLStatic_ActorId id = Spawn(160.0f, 120.0f);
    SDLStatic_Sprite sprite = Solid(1.0f, 0.0f, 0.0f, 40.0f);
    SDLStatic_Actor *actor = SDLStatic_ActorGet(engine_, id);
    SDLStatic_ActorSetSprite(actor, &sprite);

    Draw();
    ASSERT_EQ(PixelAt(160, 120)[0], 255);

    SDLStatic_ActorSprite(actor)->visible = false;
    Draw();
    EXPECT_EQ(PixelAt(160, 120)[0], 0);
    EXPECT_EQ(SDLStatic_RenderLastStats(engine_).considered, 0) << "not even considered";

    SDLStatic_ActorSprite(actor)->visible = true;
    SDLStatic_ActorClearSprite(actor);
    Draw();
    EXPECT_EQ(PixelAt(160, 120)[0], 0);
    EXPECT_EQ(SDLStatic_ActorSprite(actor), nullptr);
}

// A destroyed actor's sprite must stop drawing on the same frame the actor
// stops existing, not one frame later.
TEST_F(RenderHarness, ADestroyedActorStopsDrawing)
{
    const SDLStatic_ActorId id = Spawn(160.0f, 120.0f);
    const SDLStatic_Sprite sprite = Solid(1.0f, 0.0f, 0.0f, 40.0f);
    SDLStatic_ActorSetSprite(SDLStatic_ActorGet(engine_, id), &sprite);
    Draw();
    ASSERT_EQ(PixelAt(160, 120)[0], 255);

    SDLStatic_ActorDestroy(engine_, id);
    Draw();
    EXPECT_EQ(PixelAt(160, 120)[0], 0) << "doomed actors are already gone from queries";
}

// --- transforms -----------------------------------------------------------

TEST_F(RenderHarness, ChildSpritesFollowTheirParent)
{
    const SDLStatic_ActorId parent = Spawn(100.0f, 120.0f);

    SDLStatic_ActorDef def{};
    def.type = "child";
    def.x = 40.0f;
    def.parent = parent;
    const SDLStatic_ActorId child = SDLStatic_ActorSpawn(engine_, &def);
    SDLStatic_EngineAdvance(engine_, 16666667ull);
    SDLStatic_EngineTick(engine_);

    const SDLStatic_Sprite sprite = Solid(0.0f, 1.0f, 1.0f, 20.0f);
    SDLStatic_ActorSetSprite(SDLStatic_ActorGet(engine_, child), &sprite);

    Draw();
    EXPECT_EQ(PixelAt(140, 120)[1], 255) << "drawn at parent + local";

    SDLStatic_ActorMove(SDLStatic_ActorGet(engine_, parent), 40.0f, 0.0f);
    Draw();
    EXPECT_EQ(PixelAt(180, 120)[1], 255) << "and follows when the parent moves";
    EXPECT_EQ(PixelAt(140, 120)[1], 0);
}

TEST_F(RenderHarness, ActorScaleScalesTheSprite)
{
    const SDLStatic_ActorId id = Spawn(160.0f, 120.0f);
    const SDLStatic_Sprite sprite = Solid(1.0f, 0.0f, 1.0f, 20.0f);
    SDLStatic_Actor *actor = SDLStatic_ActorGet(engine_, id);
    SDLStatic_ActorSetSprite(actor, &sprite);

    Draw();
    EXPECT_EQ(PixelAt(160, 105)[0], 0) << "20 units tall: 15 above is outside";

    SDLStatic_ActorTransform t = SDLStatic_ActorLocal(actor);
    t.scale_x = 3.0f;
    t.scale_y = 3.0f;
    SDLStatic_ActorSetLocal(actor, &t);
    Draw();
    EXPECT_EQ(PixelAt(160, 105)[0], 255) << "60 units tall: now it reaches";
}

// Sprites are drawn at the interpolated transform, so a game gets smooth
// motion without writing its own previous_x.
TEST_F(RenderHarness, SpritesAreDrawnInterpolated)
{
    SDLStatic_ActorDef def{};
    def.type = "mover";
    def.x = 100.0f;
    def.y = 120.0f;
    def.fixed_update = [](SDLStatic_Actor *actor, float) {
        SDLStatic_ActorMove(actor, 60.0f, 0.0f);
    };
    const SDLStatic_ActorId id = SDLStatic_ActorSpawn(engine_, &def);
    for (int i = 0; i < 3; ++i)
    {
        SDLStatic_EngineAdvance(engine_, 16666667ull);
        SDLStatic_EngineTick(engine_);
    }

    const SDLStatic_Sprite sprite = Solid(1.0f, 1.0f, 1.0f, 10.0f);
    SDLStatic_Actor *actor = SDLStatic_ActorGet(engine_, id);
    SDLStatic_ActorSetSprite(actor, &sprite);

    const float now = SDLStatic_ActorWorld(actor).x;
    Draw(nullptr, 1.0f);
    EXPECT_EQ(PixelAt(static_cast<int>(now), 120)[0], 255);

    Draw(nullptr, 0.0f);
    EXPECT_EQ(PixelAt(static_cast<int>(now) - 60, 120)[0], 255) << "a whole step behind";
    EXPECT_EQ(PixelAt(static_cast<int>(now), 120)[0], 0);
}

// --- overlay --------------------------------------------------------------

// A HUD belongs to the player, not to a viewport: it is drawn once, in
// design coordinates, whatever the camera is doing.
TEST_F(RenderHarness, ScreenSpaceSpritesIgnoreTheCamera)
{
    const SDLStatic_ActorId world_actor = Spawn(160.0f, 120.0f);
    const SDLStatic_ActorId hud = Spawn(40.0f, 40.0f);

    SDLStatic_Sprite world_sprite = Solid(1.0f, 0.0f, 0.0f, 30.0f);
    SDLStatic_Sprite hud_sprite = Solid(0.0f, 1.0f, 0.0f, 30.0f);
    hud_sprite.screen_space = true;
    SDLStatic_ActorSetSprite(SDLStatic_ActorGet(engine_, world_actor), &world_sprite);
    SDLStatic_ActorSetSprite(SDLStatic_ActorGet(engine_, hud), &hud_sprite);

    // The world pass ignores the HUD...
    Draw();
    EXPECT_EQ(SDLStatic_RenderLastStats(engine_).drawn, 1);
    EXPECT_EQ(PixelAt(40, 40)[1], 0);

    // ...and the overlay pass draws it, unmoved by a camera that has
    // scrolled a long way away.
    SDLStatic_CameraSnap(&camera_, 5000.0f, 5000.0f);
    SDLStatic_CameraUpdate(&camera_, engine_, 0.0f);
    Draw();
    EXPECT_EQ(SDLStatic_RenderOverlay(engine_, 1.0f), 1);
    EXPECT_EQ(PixelAt(40, 40)[1], 255) << "still exactly where it was put";
}

// --- split screen ---------------------------------------------------------

// Each pass culls to its own viewport, which is most of what makes four
// views affordable.
TEST_F(RenderHarness, EachCameraCullsToItsOwnView)
{
    SDLStatic_Camera cameras[SDLSTATIC_SPLIT_MAX];
    for (SDLStatic_Camera &c : cameras)
    {
        SDLStatic_CameraInit(&c, engine_);
    }
    ASSERT_EQ(SDLStatic_CameraSplit(engine_, SDLSTATIC_SPLIT_VERTICAL, 2, 0.0f, cameras), 2);

    const SDLStatic_ActorId left = Spawn(100.0f, 120.0f);
    const SDLStatic_ActorId right = Spawn(4000.0f, 120.0f);
    const SDLStatic_Sprite sprite = Solid(1.0f, 1.0f, 1.0f, 20.0f);
    SDLStatic_ActorSetSprite(SDLStatic_ActorGet(engine_, left), &sprite);
    SDLStatic_ActorSetSprite(SDLStatic_ActorGet(engine_, right), &sprite);

    SDLStatic_CameraSnap(&cameras[0], 100.0f, 120.0f);
    SDLStatic_CameraSnap(&cameras[1], 4000.0f, 120.0f);
    SDLStatic_CameraUpdate(&cameras[0], engine_, 0.0f);
    SDLStatic_CameraUpdate(&cameras[1], engine_, 0.0f);

    EXPECT_EQ(SDLStatic_RenderWorld(engine_, &cameras[0], 1.0f), 1);
    EXPECT_EQ(SDLStatic_RenderLastStats(engine_).culled, 1);
    EXPECT_EQ(SDLStatic_RenderWorld(engine_, &cameras[1], 1.0f), 1);
    EXPECT_EQ(SDLStatic_RenderLastStats(engine_).culled, 1);
}

TEST_F(RenderHarness, NullsAreHandled)
{
    EXPECT_FALSE(SDLStatic_ActorSetSprite(nullptr, nullptr));
    EXPECT_EQ(SDLStatic_ActorSprite(nullptr), nullptr);
    SDLStatic_ActorClearSprite(nullptr);
    EXPECT_EQ(SDLStatic_RenderWorld(nullptr, nullptr, 0.0f), 0);
    EXPECT_EQ(SDLStatic_RenderOverlay(nullptr, 0.0f), 0);
    EXPECT_EQ(SDLStatic_RenderLastStats(nullptr).drawn, 0);
}

// The draw list is reused between frames; make sure growing it and
// shrinking back does not lose or duplicate anything.
TEST_F(RenderHarness, TheDrawListSurvivesGrowingAndShrinking)
{
    std::vector<SDLStatic_ActorId> ids;
    for (int i = 0; i < 200; ++i)
    {
        SDLStatic_ActorDef def{};
        def.type = "many";
        def.x = 160.0f;
        def.y = 120.0f;
        ids.push_back(SDLStatic_ActorSpawn(engine_, &def));
    }
    SDLStatic_EngineAdvance(engine_, 16666667ull);
    SDLStatic_EngineTick(engine_);

    const SDLStatic_Sprite sprite = Solid(1.0f, 1.0f, 1.0f, 8.0f);
    for (const SDLStatic_ActorId id : ids)
    {
        SDLStatic_ActorSetSprite(SDLStatic_ActorGet(engine_, id), &sprite);
    }

    Draw();
    EXPECT_EQ(SDLStatic_RenderLastStats(engine_).drawn, 200);

    for (size_t i = 0; i < ids.size(); i += 2)
    {
        SDLStatic_ActorDestroy(engine_, ids[i]);
    }
    SDLStatic_EngineAdvance(engine_, 16666667ull);
    SDLStatic_EngineTick(engine_);

    Draw();
    EXPECT_EQ(SDLStatic_RenderLastStats(engine_).drawn, 100);
}

} // namespace
