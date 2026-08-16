/*
 * sdlstatic_engine_binding.c — actions, and the bindings that feed them.
 * Original SDLStatic code (zlib).
 *
 * An action is a name and a list of bindings. Reading one evaluates every
 * binding and sums them, which is what makes "move_x bound to A, D and the
 * left stick" work with all three at once rather than making the game pick
 * a mode.
 *
 * Actions are signed and analog on purpose. A boolean action cannot express
 * a stick, so an engine with boolean actions grows a parallel "axis" API
 * and every game ends up using both. One value in [-1, 1] covers a button
 * (sign, or nothing), a trigger (0..1), and a stick (its deflection), and
 * `Down` is just "past the threshold".
 */
#include "engine_internal.h"

#include <SDLStatic/engine_binding.h>

#include <toml.h>

#include <stdlib.h>

#define MAX_BINDINGS 8
#define ACTION_THRESHOLD 0.5f

typedef struct Action
{
    char *name;
    SDLStatic_Binding bindings[MAX_BINDINGS];
    int binding_count;

    /* This frame's value and last frame's, per player, so edges can be
       computed without the game having to remember anything. */
    float frame_value[SDLSTATIC_MAX_PLAYERS];
    float previous[SDLSTATIC_MAX_PLAYERS];
    Uint64 previous_frame[SDLSTATIC_MAX_PLAYERS];
} Action;

struct SDLStatic_ActionMap
{
    Action *actions;
    int count, capacity;
    int keyboard_player;
};

SDLStatic_ActionMap *SDLStatic_ActionMapCreate(void)
{
    SDLStatic_ActionMap *map = (SDLStatic_ActionMap *)SDL_calloc(1, sizeof(*map));
    if (map != NULL)
    {
        map->keyboard_player = 0;
    }
    return map;
}

void SDLStatic_ActionMapDestroy(SDLStatic_ActionMap *map)
{
    if (map == NULL)
    {
        return;
    }
    for (int i = 0; i < map->count; ++i)
    {
        SDL_free(map->actions[i].name);
    }
    SDL_free(map->actions);
    SDL_free(map);
}

void SDLStatic_ActionMapSetKeyboardPlayer(SDLStatic_ActionMap *map, int player)
{
    if (map != NULL)
    {
        map->keyboard_player = player;
    }
}

int SDLStatic_ActionMapKeyboardPlayer(SDLStatic_ActionMap *map)
{
    return (map != NULL) ? map->keyboard_player : -1;
}

static Action *Find(SDLStatic_ActionMap *map, const char *name)
{
    if (map == NULL || name == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < map->count; ++i)
    {
        if (SDL_strcmp(map->actions[i].name, name) == 0)
        {
            return &map->actions[i];
        }
    }
    return NULL;
}

static Action *FindOrAdd(SDLStatic_ActionMap *map, const char *name)
{
    Action *action = Find(map, name);
    if (action != NULL)
    {
        return action;
    }
    if (map == NULL || name == NULL)
    {
        return NULL;
    }
    if (map->count >= map->capacity)
    {
        const int next = (map->capacity > 0) ? map->capacity * 2 : 16;
        Action *grown = (Action *)SDL_realloc(map->actions, (size_t)next * sizeof(Action));
        if (grown == NULL)
        {
            return NULL;
        }
        map->actions = grown;
        map->capacity = next;
    }
    action = &map->actions[map->count];
    SDL_zerop(action);
    action->name = SDL_strdup(name);
    if (action->name == NULL)
    {
        return NULL;
    }
    map->count++;
    return action;
}

bool SDLStatic_ActionBind(SDLStatic_ActionMap *map, const char *action_name,
                          SDLStatic_Binding binding)
{
    if (binding.source == SDLSTATIC_BIND_NONE)
    {
        return false;
    }
    Action *action = FindOrAdd(map, action_name);
    if (action == NULL || action->binding_count >= MAX_BINDINGS)
    {
        return false;
    }
    if (binding.sign == 0)
    {
        binding.sign = 1;
    }
    action->bindings[action->binding_count++] = binding;
    return true;
}

bool SDLStatic_ActionBindKey(SDLStatic_ActionMap *map, const char *action, SDL_Scancode key)
{
    return SDLStatic_ActionBindKeySigned(map, action, key, 1);
}

bool SDLStatic_ActionBindKeySigned(SDLStatic_ActionMap *map, const char *action, SDL_Scancode key,
                                   int sign)
{
    SDLStatic_Binding binding;
    SDL_zero(binding);
    binding.source = SDLSTATIC_BIND_KEY;
    binding.code = (int)key;
    binding.sign = (sign < 0) ? -1 : 1;
    return SDLStatic_ActionBind(map, action, binding);
}

bool SDLStatic_ActionBindMouse(SDLStatic_ActionMap *map, const char *action,
                               SDLStatic_MouseButton button)
{
    SDLStatic_Binding binding;
    SDL_zero(binding);
    binding.source = SDLSTATIC_BIND_MOUSE_BUTTON;
    binding.code = (int)button;
    binding.sign = 1;
    return SDLStatic_ActionBind(map, action, binding);
}

bool SDLStatic_ActionBindPad(SDLStatic_ActionMap *map, const char *action,
                             SDLStatic_GamepadButton button)
{
    SDLStatic_Binding binding;
    SDL_zero(binding);
    binding.source = SDLSTATIC_BIND_PAD_BUTTON;
    binding.code = (int)button;
    binding.sign = 1;
    return SDLStatic_ActionBind(map, action, binding);
}

bool SDLStatic_ActionBindAxis(SDLStatic_ActionMap *map, const char *action,
                              SDLStatic_GamepadAxis axis, int half)
{
    SDLStatic_Binding binding;
    SDL_zero(binding);
    binding.source = SDLSTATIC_BIND_PAD_AXIS;
    binding.code = (int)axis;
    binding.sign = 1;
    binding.axis_half = (half > 0) ? 1 : ((half < 0) ? -1 : 0);
    return SDLStatic_ActionBind(map, action, binding);
}

bool SDLStatic_ActionBindDirection(SDLStatic_ActionMap *map, const char *action,
                                   SDLStatic_Direction direction)
{
    SDLStatic_Binding binding;
    SDL_zero(binding);
    binding.source = SDLSTATIC_BIND_PAD_DIRECTION;
    binding.code = (int)direction;
    binding.sign = 1;
    return SDLStatic_ActionBind(map, action, binding);
}

void SDLStatic_ActionClear(SDLStatic_ActionMap *map, const char *action_name)
{
    Action *action = Find(map, action_name);
    if (action != NULL)
    {
        action->binding_count = 0;
    }
}

int SDLStatic_ActionCount(SDLStatic_ActionMap *map)
{
    return (map != NULL) ? map->count : 0;
}

const char *SDLStatic_ActionName(SDLStatic_ActionMap *map, int index)
{
    if (map == NULL || index < 0 || index >= map->count)
    {
        return NULL;
    }
    return map->actions[index].name;
}

int SDLStatic_ActionBindingCount(SDLStatic_ActionMap *map, const char *action_name)
{
    const Action *action = Find(map, action_name);
    return (action != NULL) ? action->binding_count : 0;
}

bool SDLStatic_ActionBindingAt(SDLStatic_ActionMap *map, const char *action_name, int index,
                               SDLStatic_Binding *out)
{
    const Action *action = Find(map, action_name);
    if (action == NULL || out == NULL || index < 0 || index >= action->binding_count)
    {
        return false;
    }
    *out = action->bindings[index];
    return true;
}

/* --- evaluation ---------------------------------------------------------- */

/* Does this player get keyboard and mouse input? There is one keyboard and
   it cannot be shared by four people, so exactly one player owns it. */
static bool OwnsKeyboard(const SDLStatic_ActionMap *map, int player)
{
    return map->keyboard_player >= 0 && map->keyboard_player == player;
}

static float EvaluateBinding(SDLStatic_Engine *engine, const SDLStatic_ActionMap *map,
                             int player, const SDLStatic_Binding *binding)
{
    const float sign = (binding->sign < 0) ? -1.0f : 1.0f;

    switch (binding->source)
    {
    case SDLSTATIC_BIND_KEY:
        if (!OwnsKeyboard(map, player))
        {
            return 0.0f;
        }
        return SDLStatic_KeyDown(engine, (SDL_Scancode)binding->code) ? sign : 0.0f;

    case SDLSTATIC_BIND_MOUSE_BUTTON:
        if (!OwnsKeyboard(map, player))
        {
            return 0.0f;
        }
        return SDLStatic_MouseDown(engine, (SDLStatic_MouseButton)binding->code) ? sign : 0.0f;

    case SDLSTATIC_BIND_MOUSE_WHEEL: {
        if (!OwnsKeyboard(map, player))
        {
            return 0.0f;
        }
        float x = 0.0f;
        float y = 0.0f;
        SDLStatic_MouseWheel(engine, &x, &y);
        const float value = (binding->code == 1) ? x : y;
        return SDL_clamp(value * sign, -1.0f, 1.0f);
    }

    case SDLSTATIC_BIND_PAD_BUTTON:
        return SDLStatic_GamepadButtonDown(engine, player,
                                           (SDLStatic_GamepadButton)binding->code)
                   ? sign
                   : 0.0f;

    case SDLSTATIC_BIND_PAD_AXIS: {
        const float value =
            SDLStatic_GamepadAxisValue(engine, player, (SDLStatic_GamepadAxis)binding->code);
        /* Half-axis bindings ignore the other side, so the left half of a
           stick can drive one action and the right half another. */
        if (binding->axis_half > 0 && value < 0.0f)
        {
            return 0.0f;
        }
        if (binding->axis_half < 0 && value > 0.0f)
        {
            return 0.0f;
        }
        if (binding->axis_half != 0)
        {
            return SDL_fabsf(value) * sign;
        }
        return value * sign;
    }

    case SDLSTATIC_BIND_PAD_DIRECTION:
        return SDLStatic_GamepadDirectionRepeat(engine, player,
                                                (SDLStatic_Direction)binding->code)
                   ? sign
                   : 0.0f;

    case SDLSTATIC_BIND_NONE:
    default:
        return 0.0f;
    }
}

static float Evaluate(SDLStatic_Engine *engine, SDLStatic_ActionMap *map, int player,
                      const Action *action)
{
    float total = 0.0f;
    for (int i = 0; i < action->binding_count; ++i)
    {
        total += EvaluateBinding(engine, map, player, &action->bindings[i]);
    }
    return SDL_clamp(total, -1.0f, 1.0f);
}

float SDLStatic_ActionValue(SDLStatic_Engine *engine, SDLStatic_ActionMap *map, int player,
                            const char *action_name)
{
    const Action *action = Find(map, action_name);
    if (engine == NULL || action == NULL || player < 0 || player >= SDLSTATIC_MAX_PLAYERS)
    {
        return 0.0f;
    }
    return Evaluate(engine, map, player, action);
}

bool SDLStatic_ActionDown(SDLStatic_Engine *engine, SDLStatic_ActionMap *map, int player,
                          const char *action_name)
{
    return SDL_fabsf(SDLStatic_ActionValue(engine, map, player, action_name)) >=
           ACTION_THRESHOLD;
}

/*
 * Edges, without the game having to remember anything.
 *
 * The previous value is cached per action per player and stamped with the
 * frame it came from, so it is updated exactly once per frame however many
 * times the game asks. That is what lets `Pressed` be true for every fixed
 * step in a frame — poll it from three steps and all three see the press,
 * which is the behaviour a game actually wants and the one a naive
 * "compare and overwrite" gets wrong.
 */
static void EdgeState(SDLStatic_Engine *engine, SDLStatic_ActionMap *map, int player,
                      const char *action_name, bool *down_now, bool *down_before)
{
    *down_now = false;
    *down_before = false;
    Action *action = Find(map, action_name);
    if (engine == NULL || action == NULL || player < 0 || player >= SDLSTATIC_MAX_PLAYERS)
    {
        return;
    }
    const Uint64 frame = SDLStatic_EngineFrameCount(engine) + 1; /* 0 means "never" */
    const float value = Evaluate(engine, map, player, action);

    if (action->previous_frame[player] != frame)
    {
        action->previous_frame[player] = frame;
        action->previous[player] = action->frame_value[player];
        action->frame_value[player] = value;
    }
    *down_now = SDL_fabsf(value) >= ACTION_THRESHOLD;
    *down_before = SDL_fabsf(action->previous[player]) >= ACTION_THRESHOLD;
}

bool SDLStatic_ActionPressed(SDLStatic_Engine *engine, SDLStatic_ActionMap *map, int player,
                             const char *action_name)
{
    bool now = false;
    bool before = false;
    EdgeState(engine, map, player, action_name, &now, &before);
    return now && !before;
}

bool SDLStatic_ActionReleased(SDLStatic_Engine *engine, SDLStatic_ActionMap *map, int player,
                              const char *action_name)
{
    bool now = false;
    bool before = false;
    EdgeState(engine, map, player, action_name, &now, &before);
    return !now && before;
}

void SDLStatic_ActionVector(SDLStatic_Engine *engine, SDLStatic_ActionMap *map, int player,
                            const char *x_action, const char *y_action, float *x, float *y)
{
    float vx = SDLStatic_ActionValue(engine, map, player, x_action);
    float vy = SDLStatic_ActionValue(engine, map, player, y_action);

    /* Normalise past unit length, so holding two keys does not move a
       player 41% faster diagonally — the oldest bug in 2D games. A stick
       already inside the circle is left alone, so a gentle push stays
       gentle. */
    const float magnitude = SDL_sqrtf(vx * vx + vy * vy);
    if (magnitude > 1.0f)
    {
        vx /= magnitude;
        vy /= magnitude;
    }
    if (x != NULL)
    {
        *x = vx;
    }
    if (y != NULL)
    {
        *y = vy;
    }
}

/* --- rebinding ----------------------------------------------------------- */

bool SDLStatic_ActionCapture(SDLStatic_Engine *engine, int player, SDLStatic_Binding *out)
{
    if (engine == NULL || out == NULL)
    {
        return false;
    }
    SDL_zerop(out);
    out->sign = 1;

    const int key = SDLStatic_InputFirstPressedKey(engine);
    if (key >= 0)
    {
        out->source = SDLSTATIC_BIND_KEY;
        out->code = key;
        return true;
    }

    for (int b = 0; b < SDLSTATIC_MOUSE_COUNT; ++b)
    {
        if (SDLStatic_MousePressed(engine, (SDLStatic_MouseButton)b))
        {
            out->source = SDLSTATIC_BIND_MOUSE_BUTTON;
            out->code = b;
            return true;
        }
    }

    for (int p = 0; p < SDLSTATIC_MAX_PLAYERS; ++p)
    {
        if (player >= 0 && p != player)
        {
            continue;
        }
        for (int b = 0; b < SDLSTATIC_PAD_BUTTON_COUNT; ++b)
        {
            if (SDLStatic_GamepadButtonPressed(engine, p, (SDLStatic_GamepadButton)b))
            {
                out->source = SDLSTATIC_BIND_PAD_BUTTON;
                out->code = b;
                return true;
            }
        }
        /* Sticks are captured as directions rather than raw axes: a player
           pushing a stick to bind it means "this direction", and a stick
           resting slightly off-centre would otherwise capture itself the
           instant the prompt opened. */
        for (int d = 0; d < SDLSTATIC_DIR_COUNT; ++d)
        {
            if (SDLStatic_GamepadDirectionPressed(engine, p, (SDLStatic_Direction)d))
            {
                out->source = SDLSTATIC_BIND_PAD_DIRECTION;
                out->code = d;
                return true;
            }
        }
    }

    out->source = SDLSTATIC_BIND_NONE;
    return false;
}

/* --- text ---------------------------------------------------------------- */

static const char *kPadButtonNames[SDLSTATIC_PAD_BUTTON_COUNT] = {
    "a",        "b",         "x",         "y",        "back",      "guide",   "start",
    "lstick",   "rstick",    "lb",        "rb",       "dup",       "ddown",   "dleft",
    "dright",   "share",     "paddle1",   "paddle2",  "paddle3",   "paddle4", "touchpad",
    "lt",       "rt"};

static const char *kAxisNames[SDLSTATIC_AXIS_COUNT] = {"left_x",  "left_y",  "right_x",
                                                       "right_y", "left_trigger",
                                                       "right_trigger"};

static const char *kDirectionNames[SDLSTATIC_DIR_COUNT] = {"up", "down", "left", "right"};

static const char *kMouseNames[SDLSTATIC_MOUSE_COUNT] = {"left", "middle", "right", "x1", "x2"};

const char *SDLStatic_BindingToString(SDLStatic_Binding binding, char *buffer, size_t size)
{
    if (buffer == NULL || size == 0)
    {
        return "";
    }
    const char *sign = (binding.sign < 0) ? "-" : "";

    switch (binding.source)
    {
    case SDLSTATIC_BIND_KEY: {
        const char *name = SDL_GetScancodeName((SDL_Scancode)binding.code);
        SDL_snprintf(buffer, size, "%s%s", sign, (name != NULL && name[0] != '\0') ? name : "?");
        break;
    }
    case SDLSTATIC_BIND_MOUSE_BUTTON:
        SDL_snprintf(buffer, size, "%smouse:%s", sign,
                     (binding.code >= 0 && binding.code < SDLSTATIC_MOUSE_COUNT)
                         ? kMouseNames[binding.code]
                         : "?");
        break;
    case SDLSTATIC_BIND_MOUSE_WHEEL:
        SDL_snprintf(buffer, size, "%swheel:%s", sign, (binding.code == 1) ? "x" : "y");
        break;
    case SDLSTATIC_BIND_PAD_BUTTON:
        SDL_snprintf(buffer, size, "%spad:%s", sign,
                     (binding.code >= 0 && binding.code < SDLSTATIC_PAD_BUTTON_COUNT)
                         ? kPadButtonNames[binding.code]
                         : "?");
        break;
    case SDLSTATIC_BIND_PAD_AXIS: {
        const char *half = (binding.axis_half > 0) ? "+" : ((binding.axis_half < 0) ? "-" : "");
        SDL_snprintf(buffer, size, "%saxis:%s%s", sign,
                     (binding.code >= 0 && binding.code < SDLSTATIC_AXIS_COUNT)
                         ? kAxisNames[binding.code]
                         : "?",
                     half);
        break;
    }
    case SDLSTATIC_BIND_PAD_DIRECTION:
        SDL_snprintf(buffer, size, "%sdir:%s", sign,
                     (binding.code >= 0 && binding.code < SDLSTATIC_DIR_COUNT)
                         ? kDirectionNames[binding.code]
                         : "?");
        break;
    case SDLSTATIC_BIND_NONE:
    default:
        SDL_snprintf(buffer, size, "none");
        break;
    }
    return buffer;
}

static int IndexOf(const char *const *names, int count, const char *text)
{
    for (int i = 0; i < count; ++i)
    {
        if (names[i] != NULL && SDL_strcasecmp(names[i], text) == 0)
        {
            return i;
        }
    }
    return -1;
}

bool SDLStatic_BindingFromString(const char *text, SDLStatic_Binding *out)
{
    if (text == NULL || out == NULL)
    {
        return false;
    }
    SDL_zerop(out);
    out->sign = 1;

    if (text[0] == '-')
    {
        out->sign = -1;
        text++;
    }
    else if (text[0] == '+')
    {
        text++;
    }

    if (SDL_strncmp(text, "pad:", 4) == 0)
    {
        const int index = IndexOf(kPadButtonNames, SDLSTATIC_PAD_BUTTON_COUNT, text + 4);
        if (index < 0)
        {
            return false;
        }
        out->source = SDLSTATIC_BIND_PAD_BUTTON;
        out->code = index;
        return true;
    }
    if (SDL_strncmp(text, "mouse:", 6) == 0)
    {
        const int index = IndexOf(kMouseNames, SDLSTATIC_MOUSE_COUNT, text + 6);
        if (index < 0)
        {
            return false;
        }
        out->source = SDLSTATIC_BIND_MOUSE_BUTTON;
        out->code = index;
        return true;
    }
    if (SDL_strncmp(text, "wheel:", 6) == 0)
    {
        out->source = SDLSTATIC_BIND_MOUSE_WHEEL;
        out->code = (SDL_strcasecmp(text + 6, "x") == 0) ? 1 : 0;
        return true;
    }
    if (SDL_strncmp(text, "dir:", 4) == 0)
    {
        const int index = IndexOf(kDirectionNames, SDLSTATIC_DIR_COUNT, text + 4);
        if (index < 0)
        {
            return false;
        }
        out->source = SDLSTATIC_BIND_PAD_DIRECTION;
        out->code = index;
        return true;
    }
    if (SDL_strncmp(text, "axis:", 5) == 0)
    {
        char name[32];
        SDL_strlcpy(name, text + 5, sizeof(name));
        size_t length = SDL_strlen(name);
        if (length > 0 && (name[length - 1] == '+' || name[length - 1] == '-'))
        {
            out->axis_half = (name[length - 1] == '+') ? 1 : -1;
            name[length - 1] = '\0';
        }
        const int index = IndexOf(kAxisNames, SDLSTATIC_AXIS_COUNT, name);
        if (index < 0)
        {
            return false;
        }
        out->source = SDLSTATIC_BIND_PAD_AXIS;
        out->code = index;
        return true;
    }

    /* Anything else is a key name, which is what SDL calls it. */
    const SDL_Scancode key = SDL_GetScancodeFromName(text);
    if (key == SDL_SCANCODE_UNKNOWN)
    {
        return false;
    }
    out->source = SDLSTATIC_BIND_KEY;
    out->code = (int)key;
    return true;
}

/* --- persistence --------------------------------------------------------- */

char *SDLStatic_ActionMapToToml(SDLStatic_ActionMap *map)
{
    if (map == NULL)
    {
        return NULL;
    }
    size_t capacity = 512;
    char *text = (char *)SDL_malloc(capacity);
    if (text == NULL)
    {
        return NULL;
    }
    SDL_strlcpy(text,
                "# Control bindings. Safe to edit; anything unrecognised is ignored.\n"
                "\n[bindings]\n",
                capacity);

    for (int i = 0; i < map->count; ++i)
    {
        const Action *action = &map->actions[i];
        char line[512];
        SDL_snprintf(line, sizeof(line), "%s = [", action->name);
        for (int b = 0; b < action->binding_count; ++b)
        {
            char rendered[64];
            SDLStatic_BindingToString(action->bindings[b], rendered, sizeof(rendered));
            SDL_strlcat(line, (b > 0) ? ", \"" : "\"", sizeof(line));
            SDL_strlcat(line, rendered, sizeof(line));
            SDL_strlcat(line, "\"", sizeof(line));
        }
        SDL_strlcat(line, "]\n", sizeof(line));

        const size_t needed = SDL_strlen(text) + SDL_strlen(line) + 1;
        if (needed > capacity)
        {
            capacity = needed * 2;
            char *grown = (char *)SDL_realloc(text, capacity);
            if (grown == NULL)
            {
                SDL_free(text);
                return NULL;
            }
            text = grown;
        }
        SDL_strlcat(text, line, capacity);
    }
    return text;
}

bool SDLStatic_ActionMapLoadToml(SDLStatic_ActionMap *map, const char *toml)
{
    if (map == NULL || toml == NULL)
    {
        return false;
    }
    char *copy = SDL_strdup(toml);
    if (copy == NULL)
    {
        return false;
    }
    char error[256] = {0};
    toml_table_t *root = toml_parse(copy, error, (int)sizeof(error));
    SDL_free(copy);
    if (root == NULL)
    {
        SDL_SetError("bindings.toml: %s", error);
        return false;
    }

    const toml_table_t *bindings = toml_table_in(root, "bindings");
    if (bindings == NULL)
    {
        bindings = root; /* accept a flat file too */
    }

    for (int i = 0;; ++i)
    {
        const char *key = toml_key_in(bindings, i);
        if (key == NULL)
        {
            break;
        }
        const toml_array_t *list = toml_array_in(bindings, key);
        if (list == NULL)
        {
            continue;
        }
        /* Replace this action's bindings entirely, but leave actions the
           file does not mention alone — so a player who rebound one key
           does not lose the rest when the game adds a new action. */
        Action *action = FindOrAdd(map, key);
        if (action == NULL)
        {
            continue;
        }
        action->binding_count = 0;
        const int n = toml_array_nelem(list);
        for (int b = 0; b < n; ++b)
        {
            toml_datum_t item = toml_string_at(list, b);
            if (!item.ok)
            {
                continue;
            }
            SDLStatic_Binding binding;
            if (SDLStatic_BindingFromString(item.u.s, &binding))
            {
                SDLStatic_ActionBind(map, key, binding);
            }
            free(item.u.s);
        }
    }

    toml_free(root);
    return true;
}

/* The bindings file sits beside config.toml, for the same reasons. */
static char *BindingsPath(const char *org, const char *app)
{
    if (app == NULL || app[0] == '\0')
    {
        return NULL;
    }
    char *base = SDL_GetPrefPath(org, app);
    if (base == NULL)
    {
        return NULL;
    }
    const size_t need = SDL_strlen(base) + SDL_strlen("media/bindings.toml") + 1;
    char *path = (char *)SDL_malloc(need);
    if (path != NULL)
    {
        SDL_snprintf(path, need, "%smedia/bindings.toml", base);
    }
    const size_t dir_need = SDL_strlen(base) + SDL_strlen("media") + 1;
    char *dir = (char *)SDL_malloc(dir_need);
    if (dir != NULL)
    {
        SDL_snprintf(dir, dir_need, "%smedia", base);
        SDL_CreateDirectory(dir);
        SDL_free(dir);
    }
    SDL_free(base);
    return path;
}

bool SDLStatic_ActionMapSave(SDLStatic_ActionMap *map, const char *org, const char *app)
{
    char *path = BindingsPath(org, app);
    if (path == NULL)
    {
        return false;
    }
    char *text = SDLStatic_ActionMapToToml(map);
    if (text == NULL)
    {
        SDL_free(path);
        return false;
    }
    const bool ok = SDL_SaveFile(path, text, SDL_strlen(text));
    SDL_free(text);
    SDL_free(path);
    return ok;
}

bool SDLStatic_ActionMapLoad(SDLStatic_ActionMap *map, const char *org, const char *app)
{
    char *path = BindingsPath(org, app);
    if (path == NULL)
    {
        return false;
    }
    size_t size = 0;
    void *data = SDL_LoadFile(path, &size);
    SDL_free(path);
    if (data == NULL)
    {
        return false; /* first run: not an error */
    }
    const bool ok = SDLStatic_ActionMapLoadToml(map, (const char *)data);
    SDL_free(data);
    return ok;
}
