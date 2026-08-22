# The Ruby half of the same check.
cfg = SDLStaticC.ConfigCreate
SDLStaticC.ConfigSetHeadless(cfg, true)
SDLStaticC.ConfigSetManualClock(cfg, true)
SDLStaticC.ConfigSetAutoMount(cfg, false)
engine = SDLStaticC.CreateEngine(cfg)
SDLStaticC.ConfigDestroy(cfg)
raise "the runner could not create an engine" if engine.nil?
SDLStaticC.EngineAdvance(engine, 16666667)
SDLStaticC.EngineTick(engine)
raise "no frames" unless SDLStaticC.EngineFrameCount(engine) >= 1
SDLStaticC.DestroyEngine(engine)
puts "runner ok: ruby on #{SDL.GetPlatform}"
