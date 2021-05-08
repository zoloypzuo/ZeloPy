// common.h
// created on 2020/2/26
// author @zoloypzuo

#ifndef RAILGUN_COMMON_H
#define RAILGUN_COMMON_H

//--------------------------------------------------------------------------------------
// c stdlib
//--------------------------------------------------------------------------------------
#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>

//--------------------------------------------------------------------------------------
// cpp stdlib
//--------------------------------------------------------------------------------------
#include <memory>
#include <iostream>
#include <map>
#include <vector>
#include <string>

//--------------------------------------------------------------------------------------
// external lib
//--------------------------------------------------------------------------------------
#include <spdlog/spdlog.h>

//--------------------------------------------------------------------------------------
// my own shit
//--------------------------------------------------------------------------------------
#include "cpp_lang_patch.h"
#include "runtime/Universe.h"

namespace spdlog {
    // e.g.
    // [00:00:01]: GLInfo
    // [00:00:01]: ~~~~~~
    //
    // add one more log with ~ of same length
    // this is used for replacing "start XXX"
    void debug_section(const std::string &title);
}


void railgun_init();

#endif //RAILGUN_COMMON_H