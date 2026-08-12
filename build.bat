@echo off
setlocal EnableExtensions EnableDelayedExpansion

rem Idiomatic Windows wrapper around the CMake build (mirrors Makefile targets).
rem Usage: build.bat [target]
rem   build.bat            -> debug
rem   build.bat release
rem   build.bat test
rem   build.bat help

set "PROJECT_NAME=SDL3-static-extensions"
set "PROJECT_MACRO=SDL3_STATIC_EXTENSIONS"
set "BUILD_DEBUG=build\debug"
set "BUILD_RELEASE=build\release"
set "BUILD_SANITIZER=build\sanitizer"
set "EXE_NAME=%PROJECT_NAME%.exe"

set "GENERATOR_FLAG="
if defined GENERATOR (
  set "GENERATOR_FLAG=-G %GENERATOR%"
) else (
  where ninja >nul 2>&1
  if not errorlevel 1 set "GENERATOR_FLAG=-G Ninja"
)

set "CMD=%~1"
if "%CMD%"=="" set "CMD=debug"

if /I "%CMD%"=="help" goto help
if /I "%CMD%"=="/?" goto help
if /I "%CMD%"=="-h" goto help
if /I "%CMD%"=="all" goto debug
if /I "%CMD%"=="debug" goto debug
if /I "%CMD%"=="release" goto release
if /I "%CMD%"=="test" goto test
if /I "%CMD%"=="bench" goto bench
if /I "%CMD%"=="sanitizer" goto sanitizer
if /I "%CMD%"=="fmt" goto fmt
if /I "%CMD%"=="doc" goto doc
if /I "%CMD%"=="clean" goto clean
if /I "%CMD%"=="reconfigure-debug" goto reconfigure_debug
if /I "%CMD%"=="reconfigure-release" goto reconfigure_release
if /I "%CMD%"=="configure-debug" goto configure_debug
if /I "%CMD%"=="configure-release" goto configure_release
if /I "%CMD%"=="tags" goto tags
echo Unknown target: %CMD%
echo Run "build.bat help" for usage.
exit /b 1

:help
echo Targets:
echo   build.bat / build.bat debug  - configure ^& build Debug
echo   build.bat release            - configure ^& build Release
echo   build.bat test               - run unit tests ^(Debug^)
echo   build.bat bench              - run microbenchmarks ^(Release^)
echo   build.bat sanitizer          - not supported on Windows ^(use Linux^)
echo   build.bat fmt                - run clang-format on sources
echo   build.bat doc                - generate Doxygen HTML under docs\html
echo   build.bat tags          - regenerate ctags index
echo   build.bat reconfigure-debug  - wipe build\debug and reconfigure
echo   build.bat clean              - remove local build trees
echo.
echo Environment:
echo   set GENERATOR=Ninja          - force a CMake generator
echo   set CMAKE_FLAGS=...          - extra flags passed to cmake configure
goto :eof

:reconfigure_debug
if exist "%BUILD_DEBUG%" rmdir /s /q "%BUILD_DEBUG%"
call :configure_debug
goto :eof

:reconfigure_release
if exist "%BUILD_RELEASE%" rmdir /s /q "%BUILD_RELEASE%"
call :configure_release
goto :eof

:configure_debug
cmake -S . -B "%BUILD_DEBUG%" %GENERATOR_FLAG% -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=ON %CMAKE_FLAGS%
if errorlevel 1 exit /b 1
if exist "%BUILD_DEBUG%\compile_commands.json" (
  copy /Y "%BUILD_DEBUG%\compile_commands.json" compile_commands.json >nul
  echo copied compile_commands.json from %BUILD_DEBUG%
)
goto :eof

:configure_release
cmake -S . -B "%BUILD_RELEASE%" %GENERATOR_FLAG% -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXPORT_COMPILE_COMMANDS=ON %CMAKE_FLAGS%
if errorlevel 1 exit /b 1
goto :eof

:debug
call :configure_debug
if errorlevel 1 exit /b 1
cmake --build "%BUILD_DEBUG%" --parallel
if errorlevel 1 exit /b 1
if exist "%BUILD_DEBUG%\bin\%EXE_NAME%" copy /Y "%BUILD_DEBUG%\bin\%EXE_NAME%" "%EXE_NAME%" >nul
goto :eof

:release
call :configure_release
if errorlevel 1 exit /b 1
cmake --build "%BUILD_RELEASE%" --parallel
if errorlevel 1 exit /b 1
if exist "%BUILD_RELEASE%\bin\%EXE_NAME%" copy /Y "%BUILD_RELEASE%\bin\%EXE_NAME%" "%EXE_NAME%" >nul
goto :eof

:test
call :debug
if errorlevel 1 exit /b 1
ctest --test-dir "%BUILD_DEBUG%" --output-on-failure --parallel
goto :eof

:bench
call :release
if errorlevel 1 exit /b 1
set "FOUND="
for /r "%BUILD_RELEASE%" %%F in (*bench.exe *_bench.exe) do (
  if not defined FOUND set "FOUND=%%F"
)
if not defined FOUND (
  echo No benchmark executables found. Add benchmarks\^<component^>\ then rebuild.
  exit /b 0
)
echo Running %FOUND%
"%FOUND%" --benchmark_min_time=0.01s
goto :eof

:sanitizer
echo build.bat sanitizer is intended for Linux ^(GCC/Clang^), not Windows.
exit /b 1

:fmt
where clang-format >nul 2>&1
if errorlevel 1 (
  echo clang-format not found
  exit /b 1
)
for %%D in (src tests benchmarks include) do (
  if exist "%%D" (
    for /r "%%D" %%F in (*.cpp *.hpp *.h *.cc *.cxx *.cppm *.ixx) do (
      clang-format -i "%%F"
    )
  )
)
goto :eof

:doc
where doxygen >nul 2>&1
if errorlevel 1 (
  echo doxygen not found
  exit /b 1
)
set "VER="
for /f "usebackq tokens=* delims=" %%V in ("VERSION") do (
  if not defined VER set "VER=%%V"
)
set "VER=%VER: =%"
if /I "%VER:~0,1%"=="v" set "VER=%VER:~1%"
powershell -NoProfile -Command "(Get-Content -Raw Doxyfile) -replace 'PROJECT_NUMBER\s*=.*', ('PROJECT_NUMBER         = "' + $env:VER + '"') | & doxygen -"
goto :eof

:clean
if exist build rmdir /s /q build
if exist docs\html rmdir /s /q docs\html
if exist docs\latex rmdir /s /q docs\latex
if exist docs\xml rmdir /s /q docs\xml
if exist compile_commands.json del /f /q compile_commands.json
if exist "%EXE_NAME%" del /f /q "%EXE_NAME%"
if exist tags del /f /q tags
if exist TAGS del /f /q TAGS
goto :eof

:tags
where ctags >nul 2>&1
if errorlevel 1 (
  echo ctags not found ^(install universal-ctags^)
  exit /b 1
)
ctags -R
echo wrote tags
goto :eof
