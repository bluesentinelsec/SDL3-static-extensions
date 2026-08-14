"""Library inventory for the binding generator.

Header locations are relative to the repo root. SDL3 and its satellites
come from the FetchContent trees (pinned by CMake, path passed on the
command line via --deps); vendored module headers live in the repo.
"""

from __future__ import annotations

from dataclasses import dataclass, field
from pathlib import Path


@dataclass
class LibrarySpec:
    key: str  # manifest key + generated-file stem
    title: str  # human name for reports
    macro_style: str  # parser pattern key (see parse._FUNC_PATTERNS)
    script_module: str  # Lua table / Ruby module name for the flat surface
    prefix: str  # C symbol prefix stripped for script names
    headers: list[str]  # glob patterns
    from_deps: bool = False  # resolve under the FetchContent deps dir
    exclude_headers: list[str] = field(default_factory=list)  # basename globs
    includes: list[str] = field(default_factory=list)  # emit-time #includes
    error_fn: str | None = None  # C expr returning const char* last error
    free_fn: str | None = None  # frees char* returns owned by the caller
    exclude: set[str] = field(default_factory=set)  # function names to skip


LIBRARIES: list[LibrarySpec] = [
    LibrarySpec(
        key="sdl",
        free_fn="SDL_free",
        title="SDL3 core",
        macro_style="sdl",
        script_module="SDL",
        prefix="SDL_",
        # Only headers SDL.h pulls in: vulkan/egl/opengl/test headers are
        # opt-in and reference foreign types; main_impl is app plumbing.
        headers=["sdl3-src/include/SDL3/SDL_*.h"],
        exclude_headers=[
            "SDL_vulkan.h", "SDL_egl.h", "SDL_opengl*.h", "SDL_opengles*.h",
            "SDL_test*.h", "SDL_main_impl.h", "SDL_begin_code.h",
            "SDL_close_code.h", "SDL_copying.h", "SDL_intrin.h",
            "SDL_platform_defines.h", "SDL_revision.h", "SDL_oldnames.h",
            "SDL_main.h",
        ],
        from_deps=True,
        includes=["<SDL3/SDL.h>"],
        error_fn="SDL_GetError()",
        # Excluded families: language-runtime plumbing, not game API.
        exclude=set(),
    ),
    LibrarySpec(
        key="mix",
        free_fn="SDL_free",
        title="SDL_mixer",
        macro_style="sdl",
        script_module="MIX",
        prefix="MIX_",
        headers=["mixer/include/SDL3_mixer/*.h"],
        includes=["<SDL3_mixer/SDL_mixer.h>"],
        error_fn="SDL_GetError()",
    ),
    LibrarySpec(
        key="img",
        free_fn="SDL_free",
        title="SDL_image",
        macro_style="sdl",
        script_module="IMG",
        prefix="IMG_",
        headers=["image/include/SDL3_image/*.h"],
        includes=["<SDL3_image/SDL_image.h>"],
        error_fn="SDL_GetError()",
    ),
    LibrarySpec(
        key="ttf",
        free_fn="SDL_free",
        title="SDL_ttf",
        macro_style="sdl",
        script_module="TTF",
        prefix="TTF_",
        headers=["ttf/include/SDL3_ttf/*.h"],
        includes=["<SDL3_ttf/SDL_ttf.h>", "<SDL3_ttf/SDL_textengine.h>"],
        error_fn="SDL_GetError()",
    ),
    LibrarySpec(
        key="net",
        free_fn="SDL_free",
        title="SDL_net",
        macro_style="sdl",
        script_module="NET",
        prefix="NET_",
        headers=["net/include/SDL3_net/*.h"],
        includes=["<SDL3_net/SDL_net.h>"],
        error_fn="SDL_GetError()",
    ),
    LibrarySpec(
        key="physfs",
        title="PhysFS",
        macro_style="physfs",
        script_module="PHYSFS",
        prefix="PHYSFS_",
        headers=["vfs/include/physfs.h"],
        includes=["<physfs.h>"],
        error_fn="PHYSFS_getErrorByCode(PHYSFS_getLastErrorCode())",
    ),
    LibrarySpec(
        key="b2",
        title="Box2D",
        macro_style="b2",
        script_module="B2",
        prefix="b2",
        headers=["physics/include/box2d/*.h"],
        includes=["<box2d/box2d.h>"],
    ),
    LibrarySpec(
        key="nk",
        title="Nuklear",
        macro_style="nk",
        script_module="NK",
        prefix="nk_",
        headers=["gui/include/nuklear.h"],
        includes=["<SDLStatic/nuklear.h>"],
    ),
    LibrarySpec(
        key="cjson",
        free_fn="cJSON_free",
        title="cJSON",
        macro_style="cjson",
        script_module="JSON",
        prefix="cJSON_",
        headers=["formats/include/cJSON.h"],
        includes=["<cJSON.h>"],
    ),
    LibrarySpec(
        key="sdlstatic",
        free_fn="SDL_free",
        title="SDLStatic modules",
        macro_style="sdlstatic",
        script_module="SDLStaticC",
        prefix="SDLStatic_",
        headers=[
            "mixer/include/SDLStatic/*.h",
            "gfx/include/SDLStatic/*.h",
            "extras/include/SDLStatic/*.h",
            "vfs/include/SDLStatic/*.h",
            "gui/include/SDLStatic/gui_grid.h",
            "tiled/include/SDLStatic/*.h",
        ],
        includes=[],
        error_fn="SDL_GetError()",
    ),
]


def resolve_headers(spec: LibrarySpec, repo: Path, deps: Path) -> list[Path]:
    import fnmatch

    root = deps if spec.from_deps else repo
    out: list[Path] = []
    for pattern in spec.headers:
        for path in sorted(root.glob(pattern)):
            if any(fnmatch.fnmatch(path.name, ex) for ex in spec.exclude_headers):
                continue
            out.append(path)
    return out


# ---------------------------------------------------------------------------
# Ownership: which opaque handles are resources with create/destroy pairs.
# The C++ emitter turns these into RAII classes; the Lua/Ruby emitters
# register __gc / dfree for values returned by the create functions.
#
# destroy: one-arg destroy function.
# Non-trivial cases (context-bound destroys like SDL_ReleaseGPUBuffer,
# ambiguous frees) are handled or excluded here explicitly.


@dataclass
class ResourceSpec:
    ctype: str  # opaque C type name (or value-id type for Box2D)
    cpp_class: str
    destroy: str
    create_fns: list[str]  # functions returning this type that pass ownership
    by_value: bool = False  # Box2D id structs are passed by value
    # C++ expression deciding whether a freshly created value is invalid.
    # "{v}" is substituted with the value. Pointers default to a null check.
    invalid_expr: str = "{v} == nullptr"


RESOURCES: dict[str, list[ResourceSpec]] = {
    "sdl": [
        ResourceSpec("SDL_Window", "Window", "SDL_DestroyWindow",
                     ["SDL_CreateWindow", "SDL_CreatePopupWindow", "SDL_CreateWindowWithProperties"]),
        ResourceSpec("SDL_Renderer", "Renderer", "SDL_DestroyRenderer",
                     ["SDL_CreateRenderer", "SDL_CreateRendererWithProperties",
                      "SDL_CreateSoftwareRenderer"]),
        ResourceSpec("SDL_Texture", "Texture", "SDL_DestroyTexture",
                     ["SDL_CreateTexture", "SDL_CreateTextureFromSurface",
                      "SDL_CreateTextureWithProperties"]),
        ResourceSpec("SDL_Surface", "Surface", "SDL_DestroySurface",
                     ["SDL_CreateSurface", "SDL_CreateSurfaceFrom", "SDL_LoadBMP",
                      "SDL_LoadBMP_IO", "SDL_DuplicateSurface", "SDL_ConvertSurface",
                      "SDL_ScaleSurface", "SDL_ConvertSurfaceAndColorspace"]),
        ResourceSpec("SDL_AudioStream", "AudioStream", "SDL_DestroyAudioStream",
                     ["SDL_CreateAudioStream", "SDL_OpenAudioDeviceStream"]),
        ResourceSpec("SDL_Camera", "Camera", "SDL_CloseCamera", ["SDL_OpenCamera"]),
        ResourceSpec("SDL_Gamepad", "Gamepad", "SDL_CloseGamepad", ["SDL_OpenGamepad"]),
        ResourceSpec("SDL_Joystick", "Joystick", "SDL_CloseJoystick", ["SDL_OpenJoystick"]),
        ResourceSpec("SDL_Haptic", "Haptic", "SDL_CloseHaptic",
                     ["SDL_OpenHaptic", "SDL_OpenHapticFromJoystick", "SDL_OpenHapticFromMouse"]),
        ResourceSpec("SDL_Sensor", "Sensor", "SDL_CloseSensor", ["SDL_OpenSensor"]),
        ResourceSpec("SDL_Cursor", "Cursor", "SDL_DestroyCursor",
                     ["SDL_CreateCursor", "SDL_CreateColorCursor", "SDL_CreateSystemCursor"]),
        ResourceSpec("SDL_Palette", "Palette", "SDL_DestroyPalette", ["SDL_CreatePalette"]),
        ResourceSpec("SDL_PropertiesID", "Properties", "SDL_DestroyProperties",
                     ["SDL_CreateProperties"], by_value=True,
                     invalid_expr="{v} == 0"),
        ResourceSpec("SDL_IOStream", "IoStream", "SDL_CloseIO",
                     ["SDL_IOFromFile", "SDL_IOFromMem", "SDL_IOFromConstMem",
                      "SDL_IOFromDynamicMem"]),
        ResourceSpec("SDL_AsyncIOQueue", "AsyncIoQueue", "SDL_DestroyAsyncIOQueue",
                     ["SDL_CreateAsyncIOQueue"]),
        ResourceSpec("SDL_Storage", "Storage", "SDL_CloseStorage",
                     ["SDL_OpenTitleStorage", "SDL_OpenUserStorage", "SDL_OpenFileStorage",
                      "SDL_OpenStorage"]),
        ResourceSpec("SDL_Mutex", "Mutex", "SDL_DestroyMutex", ["SDL_CreateMutex"]),
        ResourceSpec("SDL_RWLock", "RwLock", "SDL_DestroyRWLock", ["SDL_CreateRWLock"]),
        ResourceSpec("SDL_Semaphore", "Semaphore", "SDL_DestroySemaphore",
                     ["SDL_CreateSemaphore"]),
        ResourceSpec("SDL_Condition", "Condition", "SDL_DestroyCondition",
                     ["SDL_CreateCondition"]),
        ResourceSpec("SDL_Process", "Process", "SDL_DestroyProcess",
                     ["SDL_CreateProcess", "SDL_CreateProcessWithProperties"]),
        ResourceSpec("SDL_Tray", "Tray", "SDL_DestroyTray", ["SDL_CreateTray"]),
        ResourceSpec("SDL_SharedObject", "SharedObject", "SDL_UnloadObject",
                     ["SDL_LoadObject"]),
        ResourceSpec("SDL_Environment", "Environment", "SDL_DestroyEnvironment",
                     ["SDL_CreateEnvironment"]),
        ResourceSpec("SDL_GPUDevice", "GpuDevice", "SDL_DestroyGPUDevice",
                     ["SDL_CreateGPUDevice", "SDL_CreateGPUDeviceWithProperties"]),
    ],
    "mix": [
        ResourceSpec("MIX_Mixer", "Mixer", "MIX_DestroyMixer",
                     ["MIX_CreateMixer", "MIX_CreateMixerDevice"]),
        ResourceSpec("MIX_Audio", "Audio", "MIX_DestroyAudio",
                     ["MIX_LoadAudio", "MIX_LoadAudio_IO", "MIX_LoadAudioWithProperties",
                      "MIX_LoadRawAudio", "MIX_LoadRawAudio_IO",
                      "MIX_CreateSineWaveAudio"]),
        ResourceSpec("MIX_Track", "Track", "MIX_DestroyTrack", ["MIX_CreateTrack"]),
        ResourceSpec("MIX_AudioDecoder", "AudioDecoder", "MIX_DestroyAudioDecoder",
                     ["MIX_CreateAudioDecoder", "MIX_CreateAudioDecoder_IO"]),
    ],
    "img": [
        ResourceSpec("IMG_Animation", "Animation", "IMG_FreeAnimation",
                     ["IMG_LoadAnimation", "IMG_LoadAnimation_IO",
                      "IMG_LoadAnimationTyped_IO"]),
        # IMG loaders hand back surfaces the caller owns.
        ResourceSpec("SDL_Surface", "Surface", "SDL_DestroySurface",
                     ["IMG_Load", "IMG_Load_IO", "IMG_LoadTyped_IO"]),
    ],
    "ttf": [
        ResourceSpec("TTF_Font", "Font", "TTF_CloseFont",
                     ["TTF_OpenFont", "TTF_OpenFontIO", "TTF_OpenFontWithProperties",
                      "TTF_CopyFont"]),
        ResourceSpec("TTF_TextEngine", "TextEngine", "TTF_DestroyRendererTextEngine",
                     ["TTF_CreateRendererTextEngine"]),
        ResourceSpec("TTF_Text", "Text", "TTF_DestroyText", ["TTF_CreateText"]),
        # TTF render functions hand back surfaces the caller owns.
        ResourceSpec("SDL_Surface", "Surface", "SDL_DestroySurface",
                     ["TTF_RenderText_Solid", "TTF_RenderText_Shaded",
                      "TTF_RenderText_Blended", "TTF_RenderText_LCD",
                      "TTF_RenderText_Solid_Wrapped", "TTF_RenderText_Shaded_Wrapped",
                      "TTF_RenderText_Blended_Wrapped", "TTF_RenderText_LCD_Wrapped",
                      "TTF_RenderGlyph_Solid", "TTF_RenderGlyph_Shaded",
                      "TTF_RenderGlyph_Blended", "TTF_RenderGlyph_LCD"]),
    ],
    "net": [
        ResourceSpec("NET_StreamSocket", "StreamSocket", "NET_DestroyStreamSocket",
                     ["NET_CreateClient"]),
        ResourceSpec("NET_Server", "Server", "NET_DestroyServer", ["NET_CreateServer"]),
        ResourceSpec("NET_DatagramSocket", "DatagramSocket", "NET_DestroyDatagramSocket",
                     ["NET_CreateDatagramSocket"]),
    ],
    "physfs": [],
    "b2": [
        ResourceSpec("b2WorldId", "PhysicsWorld", "b2DestroyWorld", ["b2CreateWorld"],
                     by_value=True, invalid_expr="!b2World_IsValid({v})"),
        ResourceSpec("b2BodyId", "PhysicsBody", "b2DestroyBody", ["b2CreateBody"],
                     by_value=True, invalid_expr="!b2Body_IsValid({v})"),
    ],
    "nk": [],
    "cjson": [
        ResourceSpec("cJSON", "JsonDocument", "cJSON_Delete",
                     ["cJSON_Parse", "cJSON_ParseWithLength", "cJSON_CreateObject",
                      "cJSON_CreateArray"]),
    ],
    "sdlstatic": [
        ResourceSpec("SDLStatic_TiledMap", "TiledMapHandle", "SDLStatic_FreeTiledMap",
                     ["SDLStatic_LoadTiledMap"]),
    ],
}


# Structs marshaled as POD even though some fields are unmarshalable
# (userData pointers, task callbacks). Those fields are simply skipped:
# omitted on push, left zero on read. Curated — never applied broadly,
# because it would silently break handle semantics for types like
# SDL_Surface whose pointer fields are the payload.
POD_SKIP_FIELD_STRUCTS: set[str] = {
    "b2WorldDef",
    "b2BodyDef",
    "b2ShapeDef",
    "b2ChainDef",
    "b2Filter",
    "b2QueryFilter",
}
