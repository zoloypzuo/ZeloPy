// common.cpp
// created on 2020/2/26
// author @zoloypzuo



#include "common.h"

#if defined(DEBUG) || defined(_DEBUG)
#define _CRTDBG_MAP_ALLOC

#include <crtdbg.h>

#endif

void railgun_init() {
    spdlog::set_level(spdlog::level::debug);
    spdlog::debug_section("railgun_init");

    // Enable run-time memory check for debug builds.
#if defined(DEBUG) | defined(_DEBUG)
    spdlog::debug("[init] enable memory leak check");
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    // HINT set breakpoint to break when alloc
    //_CrtSetBreakAlloc(164);
#endif

    Universe::genesis();
}

void spdlog::debug_section(const std::string &title) {
    spdlog::debug(title);
    spdlog::debug(std::string(title.length(), '~'));

}

