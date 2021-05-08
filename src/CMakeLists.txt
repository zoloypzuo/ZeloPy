# created on 2021/3/28
# author @zoloypzuo
include_directories(./)

file(GLOB Src *.cpp)
add_library(Runtime ${Src})

add_library(railgun
        cpp_lang_patch.h
        util/BufferedInputStream.cpp util/BufferedInputStream.h
        common.cpp common.h
        object/HiString.cpp object/HiString.h
        util/ArrayList.cpp util/ArrayList.h
        object/CodeObject.cpp object/CodeObject.h
        object/HiInteger.cpp object/HiInteger.h
        object/HiObject.cpp object/HiObject.h
        code/BinaryFileParser.cpp code/BinaryFileParser.h
        code/ByteCode.cpp code/ByteCode.h
        runtime/Interpreter.cpp runtime/Interpreter.h
        runtime/Universe.cpp runtime/Universe.h
        util/Map.cpp util/Map.h
        object/object.h
        code/code.cpp code/code.h
        util/util.h
        inc/railgun.h
        object/Klass.cpp object/Klass.h
        runtime/FrameObject.cpp runtime/FrameObject.h
        object/FunctionObject.cpp object/FunctionObject.h
        runtime/StringTable.cpp runtime/StringTable.h
        )

link_libraries(railgun)
#add_executable(main main.cpp)
add_subdirectory(test)
