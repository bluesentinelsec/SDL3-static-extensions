# repl — interactive Lua/Ruby shell and script runner over the SDLStatic
# interpreters (with VFS-aware require and the game bindings preloaded).
enable_language(C)
add_executable(repl main.c)
target_link_libraries(repl PRIVATE SDLStatic::Lua SDLStatic::Ruby SDLStatic::Bindings)
set_target_properties(repl PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Shipped alongside the library: the SDK is what you build a game against,
# and this is what runs one written in Lua or Ruby without building anything
# at all. It is statically linked like everything else here, so it carries
# its own interpreters and needs nothing installed on the machine.
include(GNUInstallDirs)
install(TARGETS repl RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
