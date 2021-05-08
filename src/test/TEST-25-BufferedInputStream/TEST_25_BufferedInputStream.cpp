// TEST_25_BufferedInputStream.cpp
// created on 2020/2/26
// author @zoloypzuo

#include "TEST_25_BufferedInputStream.h"

#include "common_test.h"
#include "util/BufferedInputStream.h"

using namespace std;

void TEST_25_BufferedInputStream::Test() {
    BufferedInputStream bufferedInputStream(testfile("hello.pyc").c_str());
    assert(bufferedInputStream.read_int() == 0xa0df303);
    spdlog::debug("magic-num={}", bufferedInputStream.read_int());
}
