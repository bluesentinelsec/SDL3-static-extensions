# repl — interactive Lua/Ruby shell and script runner over the SDLStatic
# interpreters (with VFS-aware require and the game bindings preloaded).
enable_language(C)
add_executable(repl main.c)
target_link_libraries(repl PRIVATE SDLStatic::Lua SDLStatic::Ruby SDLStatic::Bindings)
set_target_properties(repl PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
