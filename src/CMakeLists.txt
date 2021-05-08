# created on 2021/3/28
# author @zoloypzuo
include_directories(./)

file(GLOB Src *.cpp)
add_library(Runtime ${Src})
