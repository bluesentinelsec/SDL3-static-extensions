# Filter a generated .def down to the symbols we mean to publish.
#
#   cmake -DINPUT=all.def -DOUTPUT=exports.def -DPREFIXES=a;b -DPATTERNS=x
#         -P cmake/FilterExportDef.cmake
#
# MSVC has no pattern form for export lists, which is why the DLL was
# exporting whatever the objects happened to define — mbedtls internals and
# all. Rather than parse dumpbin output, this takes the complete list CMake
# itself produces (the same machinery WINDOWS_EXPORT_ALL_SYMBOLS uses) and
# keeps the names matching the prefixes the version script and the
# exported-symbols list already use, so all three platforms answer "what is
# public?" the same way.
#
# It also drops the junk that made the unfiltered list fail to link:
# precompiled-header symbols arrive as `__` and `__@@_PchSym_...`, and no
# prefix of ours matches them.
cmake_minimum_required(VERSION 3.20)

if(NOT DEFINED INPUT OR NOT DEFINED OUTPUT)
  message(FATAL_ERROR "usage: -DINPUT=... -DOUTPUT=... [-DPREFIXES=...] [-DPATTERNS=...]")
endif()

file(STRINGS "${INPUT}" lines)

set(kept "")
foreach(line IN LISTS lines)
  string(STRIP "${line}" name)
  if(name STREQUAL "" OR name STREQUAL "EXPORTS")
    continue()
  endif()
  # CMake writes one symbol per line, sometimes with trailing decoration
  # such as ` DATA` for variables; keep that with the name.
  string(REGEX MATCH "^[^ \t]+" symbol "${name}")

  set(publish OFF)
  foreach(prefix IN LISTS PREFIXES)
    if(symbol MATCHES "^${prefix}")
      set(publish ON)
      break()
    endif()
  endforeach()
  if(NOT publish)
    foreach(pattern IN LISTS PATTERNS)
      # The pattern list is shared with the Mach-O exported-symbols file,
      # where `*` is a glob. CMake's MATCHES wants a regular expression, and
      # a bare leading `*` is a compile error rather than a mismatch.
      string(REPLACE "*" ".*" regex "${pattern}")
      if(symbol MATCHES "${regex}")
        set(publish ON)
        break()
      endif()
    endforeach()
  endif()

  if(publish)
    list(APPEND kept "${name}")
  endif()
endforeach()

list(REMOVE_DUPLICATES kept)
list(LENGTH kept count)
if(count EQUAL 0)
  message(FATAL_ERROR
    "no symbols survived the export filter — the DLL would export nothing, "
    "which links fine and fails on the consumer's first call")
endif()

list(SORT kept)
set(content "EXPORTS\n")
foreach(symbol IN LISTS kept)
  string(APPEND content "    ${symbol}\n")
endforeach()
file(WRITE "${OUTPUT}" "${content}")
message(STATUS "export filter kept ${count} symbols")
