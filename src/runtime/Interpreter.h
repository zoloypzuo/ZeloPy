// Interpreter.h
// created on 2020/2/26
// author @zoloypzuo

#ifndef RAILGUN_INTERPRETER_H
#define RAILGUN_INTERPRETER_H

#include "common.h"
#include "util/util.h"

template<typename T>
class ArrayList;

class HiObject;

class CodeObject;

class FrameObject;

class Interpreter {
private:
    FrameObject *_frame{};
    Map<HiObject *, HiObject *> *_builtins{};

public:
    Interpreter();

    void run(CodeObject *codes);

    void build_frame(HiObject *callable, ObjList args);

    void leave_frame(HiObject *ret_value);
};

// execute a file
void dofile(Interpreter *L, const std::string &filename);

#endif //RAILGUN_INTERPRETER_H