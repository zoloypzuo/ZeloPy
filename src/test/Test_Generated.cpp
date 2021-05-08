
// Test_Generated.cpp
// created on 2020/2/28
// author @zoloypzuo

#include "Test_Generated.h"
#include "common_test.h"

void Test_Generated::Test() {
    Interpreter L{};

	dofile(&L, testfile("hello.pyc"));;
	dofile(&L, testfile("test_if.pyc"));;
	dofile(&L, testfile("test_var.pyc"));;
	dofile(&L, testfile("test_while.pyc"));;
	dofile(&L, testfile("simple_while.pyc"));;
	dofile(&L, testfile("test_param.pyc"));;
	dofile(&L, testfile("test_default.pyc"));;
	dofile(&L, testfile("test_native.pyc"));;
	dofile(&L, testfile("test_method.pyc"));;
	dofile(&L, testfile("test_class.pyc"));;
	dofile(&L, testfile("t_6_1.pyc"));;
	dofile(&L, testfile("t_6_1_1.pyc"));;
	dofile(&L, testfile("t_8_1.pyc"));;
	dofile(&L, testfile("t_8_2.pyc"));;
}