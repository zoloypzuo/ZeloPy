# created on 2019/9/23
# author @zoloypzuo
cmake_minimum_required(VERSION 3.18.4)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

project(ZeloPy)

if (WIN32)
    set(VCPKG_TARGET_TRIPLET x86-windows)
else ()
    set(VCPKG_TARGET_TRIPLET x64-windows)
endif ()

set(VcpkgDir "D:/vcpkg" CACHE STRING "vcpkg install directory")
message(STATUS VcpkgDir=${VcpkgDir})

include(${VcpkgDir}/scripts/buildsystems/vcpkg.cmake)

find_package(spdlog CONFIG REQUIRED)
link_libraries(spdlog::spdlog spdlog::spdlog_header_only)

option(DetectMemoryLeak "DetectMemoryLeak" ON)
message(STATUS DetectMemoryLeak=${DetectMemoryLeak})

if (DetectMemoryLeak)
    set(VldIncludeDir "C:/Program Files (x86)/Visual Leak Detector/include")
    if (WIN32)
        set(VldLibDir "C:/Program Files (x86)/Visual Leak Detector/lib/Win32")
    else ()
        set(VldLibDir "C:/Program Files (x86)/Visual Leak Detector/lib/Win64")
    endif ()
    include_directories(${VldIncludeDir})
    link_directories(${VldLibDir})
endif ()

# use unicode, wstring and etc
add_compile_definitions(UNICODE)
# avoid some bugs with Windows...
add_compile_definitions(NOMINMAX)

add_compile_definitions(ZELO_DEBUG)
add_subdirectory(src)

include_directories(include)
link_libraries(Runtime)

add_executable(hello main.cpp)

# build test
option(BuildTest "BuildTest" OFF)
message(STATUS BuildTest=${BuildTest})

if (BuildTest)
    find_package(gtest CONFIG REQUIRED)

    include(CTest)
    enable_testing()
    add_subdirectory(src/test)
endif ()
