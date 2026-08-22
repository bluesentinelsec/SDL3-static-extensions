/**
 * @file mog.hpp
 * @brief Umbrella header for the mog HTTP client and server library.
 */
#pragma once

#include "mog/backend.hpp"
#include "mog/cli.hpp"
#include "mog/dynload.hpp"
#include "mog/error.hpp"
#include "mog/http.hpp"
#include "mog/log.hpp"
#include "mog/options.hpp"
#include "mog/response.hpp"
#include "mog/server.hpp"
#include "mog/session.hpp"
#include "mog/util.hpp"
#include "mog/version.hpp"

// nlohmann/json interop (cppboot preferred JSON library) when built with MOG_WITH_JSON.
#if defined(MOG_HAS_JSON) && MOG_HAS_JSON
#include "mog/json.hpp"
#endif
