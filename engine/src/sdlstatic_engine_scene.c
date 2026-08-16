/*
 * sdlstatic_engine_scene.c — the scene stack.
 * Original SDLStatic code (zlib). See SDLStatic/engine_scene.h.
 *
 * Two rules do most of the work here:
 *
 *   Stack changes are deferred. A scene may push, pop or replace from
 *   inside its own update, and the stack will not move until the frame is
 *   over — so the code that asked is never running on a scene that has
 *   just been destroyed.
 *
 *   A transition owns the swap. Fading out, swapping and fading in is one
 *   state machine rather than three things a game has to coordinate, and
 *   the swap happens at the midpoint where the screen is covered.
 */
#include "engine_internal.h"

struct SDLStatic_Scene
{
    /* The definition is *copied*, not pointed at.
     *
     * Storing the caller's pointer would make a scene outlive its
     * definition whenever the definition is a local or a temporary — and
     * the crash lands later, in a callback through a dangling pointer,
     * miles from the cause. Copying costs a dozen pointers per push and
     * makes `SDLStatic_ScenePush(engine, &(SDLStatic_SceneDef){...})`
     * legal, which is exactly what a script binding will generate. */
    SDLStatic_SceneDef def;
    char *name; /* copied too, for the same reason */
    SDLStatic_Engine *engine;
    void *state;
    bool entered; /* has enter() run without a matching exit()? */
};

/* A stack change waiting for the end of the frame. */
typedef enum PendingKind
{
    PENDING_NONE = 0,
    PENDING_PUSH,
    PENDING_POP,
    PENDING_REPLACE,
    PENDING_RESET
} PendingKind;

/* Everything the scene subsystem keeps. It lives in the engine object but
 * only this file knows its shape. */
struct SDLStatic_SceneStack
{
    SDLStatic_Scene scenes[SDLSTATIC_SCENE_STACK_MAX];
    int depth;

    /* Requested changes hold a *copy* of the definition, not a pointer to
       the caller's. A C++ temporary dies at the end of the statement that
       made it, so keeping a pointer until the end of the frame would be a
       use-after-free that only shows up under load. */
    PendingKind pending;
    SDLStatic_SceneDef pending_def;
    char *pending_name;

    /* Transition state machine. */
    SDLStatic_SceneTransition transition;
    SDLStatic_SceneDef transition_def;
    char *transition_name;
    float transition_seconds;
    float transition_elapsed;
    bool transition_swapped; /* has the midpoint swap happened yet? */
    SDL_FColor transition_color;
};

/* --- helpers ------------------------------------------------------------ */

static struct SDLStatic_SceneStack *Stack(SDLStatic_Engine *engine)
{
    if (engine == NULL)
    {
        return NULL;
    }
    if (engine->scenes == NULL)
    {
        engine->scenes =
            (struct SDLStatic_SceneStack *)SDL_calloc(1, sizeof(struct SDLStatic_SceneStack));
        if (engine->scenes != NULL)
        {
            engine->scenes->transition_color = (SDL_FColor){0.0f, 0.0f, 0.0f, 1.0f};
        }
    }
    return engine->scenes;
}

static bool CreateScene(SDLStatic_Engine *engine, const SDLStatic_SceneDef *def,
                        SDLStatic_Scene *out)
{
    SDL_zerop(out);
    out->def = *def;
    out->engine = engine;
    if (def->name != NULL)
    {
        out->name = SDL_strdup(def->name);
        out->def.name = out->name;
    }
    if (def->state_size > 0)
    {
        out->state = SDL_calloc(1, def->state_size);
        if (out->state == NULL)
        {
            SDL_free(out->name);
            return false;
        }
    }
    if (out->def.load != NULL && !out->def.load(out))
    {
        SDL_free(out->state);
        SDL_free(out->name);
        SDL_zerop(out);
        return false; /* the scene has set the error */
    }
    return true;
}

static void DestroyScene(SDLStatic_Scene *scene)
{
    if (scene->engine == NULL)
    {
        return; /* an empty slot */
    }
    if (scene->entered && scene->def.exit != NULL)
    {
        scene->def.exit(scene);
    }
    if (scene->def.unload != NULL)
    {
        scene->def.unload(scene);
    }
    SDL_free(scene->state);
    SDL_free(scene->name);
    SDL_zerop(scene);
}

/* Enter/exit fire on the *top* scene changing, not on the stack changing,
 * so a scene covered by a pause menu sees exit and sees enter again. */
static void SetTopEntered(struct SDLStatic_SceneStack *stack, bool entered)
{
    if (stack->depth <= 0)
    {
        return;
    }
    SDLStatic_Scene *top = &stack->scenes[stack->depth - 1];
    if (top->engine == NULL || top->entered == entered)
    {
        return;
    }
    top->entered = entered;
    if (entered)
    {
        if (top->def.enter != NULL)
        {
            top->def.enter(top);
        }
    }
    else if (top->def.exit != NULL)
    {
        top->def.exit(top);
    }
}

static bool PushNow(SDLStatic_Engine *engine, const SDLStatic_SceneDef *def)
{
    struct SDLStatic_SceneStack *stack = Stack(engine);
    if (stack == NULL || def == NULL)
    {
        return SDL_InvalidParamError("engine/def");
    }
    if (stack->depth >= SDLSTATIC_SCENE_STACK_MAX)
    {
        SDL_SetError("scene stack is full (%d)", SDLSTATIC_SCENE_STACK_MAX);
        return false;
    }
    SetTopEntered(stack, false);

    SDLStatic_Scene scene;
    if (!CreateScene(engine, def, &scene))
    {
        SetTopEntered(stack, true); /* the old top is still in charge */
        return false;
    }
    stack->scenes[stack->depth++] = scene;
    SetTopEntered(stack, true);
    return true;
}

static bool PopNow(SDLStatic_Engine *engine)
{
    struct SDLStatic_SceneStack *stack = Stack(engine);
    if (stack == NULL || stack->depth <= 0)
    {
        SDL_SetError("the scene stack is empty");
        return false;
    }
    DestroyScene(&stack->scenes[--stack->depth]);
    SetTopEntered(stack, true);
    return true;
}

static void ApplyPending(SDLStatic_Engine *engine)
{
    struct SDLStatic_SceneStack *stack = Stack(engine);
    if (stack == NULL || stack->pending == PENDING_NONE)
    {
        return;
    }
    const PendingKind kind = stack->pending;
    const SDLStatic_SceneDef *def = &stack->pending_def;
    stack->pending = PENDING_NONE;

    switch (kind)
    {
    case PENDING_PUSH:
        PushNow(engine, def);
        break;
    case PENDING_POP:
        PopNow(engine);
        break;
    case PENDING_REPLACE:
        if (stack->depth > 0)
        {
            PopNow(engine);
        }
        PushNow(engine, def);
        break;
    case PENDING_RESET:
        while (stack->depth > 0)
        {
            PopNow(engine);
        }
        PushNow(engine, def);
        break;
    case PENDING_NONE:
    default:
        break;
    }
}

/* --- the public stack operations ---------------------------------------- */

/* Take a copy of a definition, including its name, into `out`/`out_name`. */
static bool CopyDef(const SDLStatic_SceneDef *def, SDLStatic_SceneDef *out, char **out_name)
{
    *out = *def;
    SDL_free(*out_name);
    *out_name = NULL;
    if (def->name != NULL)
    {
        *out_name = SDL_strdup(def->name);
        if (*out_name == NULL)
        {
            return false;
        }
        out->name = *out_name;
    }
    return true;
}

static bool Defer(SDLStatic_Engine *engine, PendingKind kind, const SDLStatic_SceneDef *def)
{
    struct SDLStatic_SceneStack *stack = Stack(engine);
    if (stack == NULL)
    {
        return SDL_InvalidParamError("engine");
    }
    if (stack->pending != PENDING_NONE)
    {
        /* Two changes in one frame is a game bug — the second would
           silently win — so say so rather than pick one. */
        SDL_SetError("a scene change is already queued this frame");
        return false;
    }
    if (def != NULL && !CopyDef(def, &stack->pending_def, &stack->pending_name))
    {
        return false;
    }
    stack->pending = kind;
    return true;
}

bool SDLStatic_ScenePush(SDLStatic_Engine *engine, const SDLStatic_SceneDef *def)
{
    if (def == NULL)
    {
        return SDL_InvalidParamError("def");
    }
    return Defer(engine, PENDING_PUSH, def);
}

bool SDLStatic_ScenePop(SDLStatic_Engine *engine)
{
    return Defer(engine, PENDING_POP, NULL);
}

bool SDLStatic_SceneReplace(SDLStatic_Engine *engine, const SDLStatic_SceneDef *def)
{
    if (def == NULL)
    {
        return SDL_InvalidParamError("def");
    }
    return Defer(engine, PENDING_REPLACE, def);
}

bool SDLStatic_SceneReset(SDLStatic_Engine *engine, const SDLStatic_SceneDef *def)
{
    if (def == NULL)
    {
        return SDL_InvalidParamError("def");
    }
    return Defer(engine, PENDING_RESET, def);
}

SDLStatic_Scene *SDLStatic_SceneCurrent(SDLStatic_Engine *engine)
{
    struct SDLStatic_SceneStack *stack = Stack(engine);
    if (stack == NULL || stack->depth <= 0)
    {
        return NULL;
    }
    return &stack->scenes[stack->depth - 1];
}

int SDLStatic_SceneDepth(SDLStatic_Engine *engine)
{
    struct SDLStatic_SceneStack *stack = Stack(engine);
    return (stack != NULL) ? stack->depth : 0;
}

SDLStatic_Scene *SDLStatic_SceneFind(SDLStatic_Engine *engine, const char *name)
{
    struct SDLStatic_SceneStack *stack = Stack(engine);
    if (stack == NULL || name == NULL)
    {
        return NULL;
    }
    for (int i = stack->depth - 1; i >= 0; i--)
    {
        const SDLStatic_SceneDef *def = &stack->scenes[i].def;
        if (def->name != NULL && SDL_strcmp(def->name, name) == 0)
        {
            return &stack->scenes[i];
        }
    }
    return NULL;
}

void *SDLStatic_SceneState(SDLStatic_Scene *scene)
{
    return (scene != NULL) ? scene->state : NULL;
}

SDLStatic_Engine *SDLStatic_SceneEngine(SDLStatic_Scene *scene)
{
    return (scene != NULL) ? scene->engine : NULL;
}

const char *SDLStatic_SceneName(SDLStatic_Scene *scene)
{
    if (scene == NULL || scene->engine == NULL)
    {
        return NULL;
    }
    return scene->def.name;
}

bool SDLStatic_SceneIsActive(SDLStatic_Scene *scene)
{
    if (scene == NULL || scene->engine == NULL)
    {
        return false;
    }
    return SDLStatic_SceneCurrent(scene->engine) == scene;
}

/* --- transitions -------------------------------------------------------- */

bool SDLStatic_SceneTransitionTo(SDLStatic_Engine *engine, const SDLStatic_SceneDef *def,
                                 SDLStatic_SceneTransition transition, float seconds)
{
    struct SDLStatic_SceneStack *stack = Stack(engine);
    if (stack == NULL || def == NULL)
    {
        return SDL_InvalidParamError("engine/def");
    }
    if (transition == SDLSTATIC_TRANSITION_NONE || seconds <= 0.0f)
    {
        return SDLStatic_SceneReplace(engine, def);
    }
    if (stack->transition != SDLSTATIC_TRANSITION_NONE)
    {
        SDL_SetError("a transition is already running");
        return false;
    }
    if (!CopyDef(def, &stack->transition_def, &stack->transition_name))
    {
        return false;
    }
    stack->transition = transition;
    stack->transition_seconds = seconds;
    stack->transition_elapsed = 0.0f;
    stack->transition_swapped = false;
    return true;
}

void SDLStatic_SceneSetTransitionColor(SDLStatic_Engine *engine, SDL_FColor color)
{
    struct SDLStatic_SceneStack *stack = Stack(engine);
    if (stack != NULL)
    {
        stack->transition_color = color;
    }
}

bool SDLStatic_SceneTransitioning(SDLStatic_Engine *engine)
{
    struct SDLStatic_SceneStack *stack = Stack(engine);
    return stack != NULL && stack->transition != SDLSTATIC_TRANSITION_NONE;
}

/* How opaque the transition overlay is right now: 0 at the start, 1 at the
 * midpoint where the swap happens, 0 again at the end. */
static float TransitionCover(const struct SDLStatic_SceneStack *stack)
{
    if (stack->transition == SDLSTATIC_TRANSITION_NONE || stack->transition_seconds <= 0.0f)
    {
        return 0.0f;
    }
    const float t = SDL_clamp(stack->transition_elapsed / stack->transition_seconds, 0.0f,
                              1.0f);
    return (t < 0.5f) ? (t * 2.0f) : ((1.0f - t) * 2.0f);
}

static void AdvanceTransition(SDLStatic_Engine *engine, float dt)
{
    struct SDLStatic_SceneStack *stack = Stack(engine);
    if (stack == NULL || stack->transition == SDLSTATIC_TRANSITION_NONE)
    {
        return;
    }
    stack->transition_elapsed += dt;
    const float half = stack->transition_seconds * 0.5f;

    if (!stack->transition_swapped && stack->transition_elapsed >= half)
    {
        /* The midpoint: the screen is fully covered, so swapping here is
           invisible — which is the entire trick. */
        stack->transition_swapped = true;
        if (stack->depth > 0)
        {
            PopNow(engine);
        }
        PushNow(engine, &stack->transition_def);
    }
    if (stack->transition_elapsed >= stack->transition_seconds)
    {
        stack->transition = SDLSTATIC_TRANSITION_NONE;
        stack->transition_elapsed = 0.0f;
        stack->transition_swapped = false;
    }
}

/* --- dispatch from the loop --------------------------------------------- */

/* The lowest scene that has to be drawn: walk down while each scene says
 * it does not fill the screen. */
static int LowestVisible(const struct SDLStatic_SceneStack *stack)
{
    int lowest = stack->depth - 1;
    while (lowest > 0 && (stack->scenes[lowest].def.flags & SDLSTATIC_SCENE_TRANSPARENT) != 0)
    {
        lowest--;
    }
    return lowest;
}

void SDLStatic_SceneDispatchFixedUpdate(SDLStatic_Engine *engine, float step)
{
    struct SDLStatic_SceneStack *stack = Stack(engine);
    if (stack == NULL)
    {
        return;
    }
    for (int i = 0; i < stack->depth; i++)
    {
        SDLStatic_Scene *scene = &stack->scenes[i];
        const bool is_top = (i == stack->depth - 1);
        const bool covered_but_running =
            (scene->def.flags & SDLSTATIC_SCENE_UPDATE_WHEN_COVERED) != 0;
        if ((is_top || covered_but_running) && scene->def.fixed_update != NULL)
        {
            scene->def.fixed_update(scene, step);
        }
    }
}

void SDLStatic_SceneDispatchUpdate(SDLStatic_Engine *engine, float dt)
{
    struct SDLStatic_SceneStack *stack = Stack(engine);
    if (stack == NULL)
    {
        return;
    }
    for (int i = 0; i < stack->depth; i++)
    {
        SDLStatic_Scene *scene = &stack->scenes[i];
        const bool is_top = (i == stack->depth - 1);
        const bool covered_but_running =
            (scene->def.flags & SDLSTATIC_SCENE_UPDATE_WHEN_COVERED) != 0;
        if ((is_top || covered_but_running) && scene->def.update != NULL)
        {
            scene->def.update(scene, dt);
        }
    }
    AdvanceTransition(engine, dt);
    /* Deferred stack changes land here, at the end of the frame's logic
       and before anything draws. */
    ApplyPending(engine);
}

void SDLStatic_SceneDispatchRender(SDLStatic_Engine *engine, float alpha)
{
    struct SDLStatic_SceneStack *stack = Stack(engine);
    if (stack == NULL || stack->depth == 0)
    {
        return;
    }
    for (int i = LowestVisible(stack); i < stack->depth; i++)
    {
        SDLStatic_Scene *scene = &stack->scenes[i];
        if (scene->def.render != NULL)
        {
            scene->def.render(scene, alpha);
        }
    }

    const float cover = TransitionCover(stack);
    if (cover > 0.0f)
    {
        const SDL_FColor color = stack->transition_color;
        SDL_SetRenderDrawBlendMode(engine->renderer, SDL_BLENDMODE_BLEND);
        SDL_SetRenderDrawColorFloat(engine->renderer, color.r, color.g, color.b,
                                    color.a * cover);
        SDL_RenderFillRect(engine->renderer, NULL);
    }
}

void SDLStatic_SceneDispatchEvent(SDLStatic_Engine *engine, const SDL_Event *event)
{
    /* Only the top scene: a pause menu must not let the level underneath
       also act on the same key press. */
    SDLStatic_Scene *scene = SDLStatic_SceneCurrent(engine);
    if (scene != NULL && scene->def.event != NULL)
    {
        scene->def.event(scene, event);
    }
}

void SDLStatic_SceneShutdown(SDLStatic_Engine *engine)
{
    struct SDLStatic_SceneStack *stack = (engine != NULL) ? engine->scenes : NULL;
    if (stack == NULL)
    {
        return;
    }
    while (stack->depth > 0)
    {
        DestroyScene(&stack->scenes[--stack->depth]);
    }
    SDL_free(stack->pending_name);
    SDL_free(stack->transition_name);
    SDL_free(stack);
    engine->scenes = NULL;
}
