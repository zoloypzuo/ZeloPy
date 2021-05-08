# created on 2020/2/26
# author @zoloypzuo

include_directories(./)
add_executable(test_main
        test_main.cpp
        TEST-25-BufferedInputStream/TEST_25_BufferedInputStream.cpp
        common_test.cpp common_test.h TEST-26-BinaryFileParser/TEST_26_BinaryFileParser.cpp TEST-26-BinaryFileParser/TEST_26_BinaryFileParser.h Test_Generated.cpp Test_Generated.h)