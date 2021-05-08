// TEST_26_BinaryFileParser.cpp
// created on 2020/2/26
// author @zoloypzuo

#include <util/BufferedInputStream.h>
#include <code/BinaryFileParser.h>
#include "TEST_26_BinaryFileParser.h"
#include "common_test.h"

void TEST_26_BinaryFileParser::Test() {
    BufferedInputStream bufferedInputStream(testfile("hello.pyc").c_str());
    BinaryFileParser parser(&bufferedInputStream);
    CodeObject *main_code = parser.parse();
}
