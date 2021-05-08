//
// Created by zoloypzuo on 2020/2/26.
//

#include "common_test.h"
#include "inc/railgun.h"

// test
#include "TEST-25-BufferedInputStream/TEST_25_BufferedInputStream.h"
#include "test/TEST-26-BinaryFileParser/TEST_26_BinaryFileParser.h"
#include "Test_Generated.h"

using namespace std;

int main() {
    // TODO pass L as arg
    railgun_init();

    TEST_25_BufferedInputStream().Test();
    TEST_26_BinaryFileParser().Test();

    // [x] put these to a generated test class
    Test_Generated().Test();

    spdlog::info("test pass");
    return 0;
}