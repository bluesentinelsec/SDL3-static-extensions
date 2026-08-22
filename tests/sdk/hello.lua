-- The smallest thing that proves the runner has the bindings loaded and can
-- reach the engine: no -l on the command line, so this also checks that the
-- language was inferred from the extension.
local cfg = SDLStaticC.ConfigCreate()
SDLStaticC.ConfigSetHeadless(cfg, true)
SDLStaticC.ConfigSetManualClock(cfg, true)
SDLStaticC.ConfigSetAutoMount(cfg, false)
local engine = SDLStaticC.CreateEngine(cfg)
SDLStaticC.ConfigDestroy(cfg)
assert(engine ~= nil, "the runner could not create an engine")
SDLStaticC.EngineAdvance(engine, 16666667)
SDLStaticC.EngineTick(engine)
assert(SDLStaticC.EngineFrameCount(engine) >= 1)
SDLStaticC.DestroyEngine(engine)
print("runner ok: lua on " .. SDL.GetPlatform())
