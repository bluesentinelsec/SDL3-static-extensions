# Treat warnings as errors to force good habits from day one.
function(cppboot_set_project_warnings target_name)
  if(MSVC)
    target_compile_options(${target_name} PRIVATE /W4 /WX /permissive-)
  else()
    target_compile_options(${target_name} PRIVATE
      -Wall
      -Wextra
      -Wpedantic
      -Werror
      -Wconversion
      -Wshadow
      -Wnon-virtual-dtor
      -Wold-style-cast
      -Wcast-align
      -Wunused
      -Woverloaded-virtual
    )
  endif()
endfunction()

# Prefer system includes for third-party targets so -Werror does not fire inside them.
function(cppboot_mark_system_includes target_name)
  if(TARGET ${target_name})
    get_target_property(_inc ${target_name} INTERFACE_INCLUDE_DIRECTORIES)
    if(_inc)
      set_target_properties(${target_name} PROPERTIES
        INTERFACE_SYSTEM_INCLUDE_DIRECTORIES "${_inc}"
      )
    endif()
  endif()
endfunction()
