/*
 * Uses the installed SDK the way a game would: include the public headers,
 * link the one archive, run the engine.
 *
 * Written in C on purpose. The archive contains C++ objects, so a C consumer
 * is the case that fails with a wall of missing std:: symbols if the package
 * forgets to name the C++ runtime — and a C++ test would never notice.
 */
#include <SDLStatic/engine.h>
#include <SDLStatic/engine_actor.h>
#include <SDLStatic/engine_config.h>

#include <SDL3/SDL.h>

#include <stdio.h>

int main(void)
{
    /* Headless with a manual clock: no window, no GPU, no wall-clock waiting
       — this has to run on a CI machine with no display. */
    SDLStatic_EngineConfig *config = SDLStatic_ConfigCreate();
    if (config == NULL)
    {
        fprintf(stderr, "ConfigCreate failed: %s\n", SDL_GetError());
        return 1;
    }
    SDLStatic_ConfigSetHeadless(config, true);
    SDLStatic_ConfigSetManualClock(config, true);
    SDLStatic_ConfigSetAutoMount(config, false);

    SDLStatic_Engine *engine = SDLStatic_CreateEngine(config);
    SDLStatic_ConfigDestroy(config);
    if (engine == NULL)
    {
        fprintf(stderr, "CreateEngine failed: %s\n", SDL_GetError());
        return 1;
    }

    /* Spawn an actor and run frames: enough to prove the engine's own objects
       are in the archive, not merely that it linked. */
    SDLStatic_ActorDef *def = SDLStatic_ActorDefCreate();
    SDLStatic_ActorDefSetType(def, "consumer");
    const SDLStatic_ActorId actor = SDLStatic_ActorSpawn(engine, def);
    SDLStatic_ActorDefDestroy(def);
    if (actor == SDLSTATIC_ACTOR_NONE)
    {
        fprintf(stderr, "ActorSpawn failed: %s\n", SDL_GetError());
        SDLStatic_DestroyEngine(engine);
        return 1;
    }

    for (int i = 0; i < 5; ++i)
    {
        SDLStatic_EngineAdvance(engine, 16666667);
        SDLStatic_EngineTick(engine);
    }

    const Uint64 frames = SDLStatic_EngineFrameCount(engine);
    const int actors = SDLStatic_ActorCount(engine);
    SDLStatic_DestroyEngine(engine);

    if (frames < 5 || actors != 1)
    {
        fprintf(stderr, "engine ran %llu frames with %d actors, expected 5 and 1\n",
                (unsigned long long)frames, actors);
        return 1;
    }
    printf("SDK consumer ok: %llu frames, %d actor, SDL %d.%d.%d\n",
           (unsigned long long)frames, actors, SDL_MAJOR_VERSION, SDL_MINOR_VERSION,
           SDL_MICRO_VERSION);
    return 0;
}
