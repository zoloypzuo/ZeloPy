def compile(fn):
    return '"C:\\Python27\\python.exe" -m compileall py\\%s.py\n' % fn


def mv(fn):
    return 'move py\\%s.pyc pyc\n' % fn


def writeall(text, fn):
    with open(fn, 'w') as f:
        f.write(text)


TEST_FILES = [
    'hello',
    # ch 4
    'test_if',
    'test_var',
    'test_while',
    'simple_while',
    # ch 6
    'test_param',
    'test_default',
    'test_native',
    'test_method',
    # ch 8
    'test_class'
]

# TODO find all test file with prefix t_
# TODO generate cpp code to test

import pathlib

for i in pathlib.Path('./py').iterdir():
    i = str(i)[3:][:-3]
    print(i)
    if i.startswith('t_'):
        TEST_FILES.append(i)

print(TEST_FILES)

code = []
for fn in TEST_FILES:
    code.append(compile(fn))
    code.append(mv(fn))
code.append('pause\n')
code = ''.join(code)
print(code)

writeall(code, 'pyc_compiler.bat')

print()
print()
print()

code = r'''
// Test_Generated.cpp
// created on 2020/2/28
// author @zoloypzuo

#include "Test_Generated.h"
#include "common_test.h"

void Test_Generated::Test() {
    Interpreter L{};

%s}'''

code = code % ''.join(['\tdofile(&L, testfile("%s.pyc"));;\n' % fn for fn in TEST_FILES])

writeall(code, '../test/Test_Generated.cpp')

print('done')
input()
