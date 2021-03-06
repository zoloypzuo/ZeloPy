// FrameObject.h
// created on 2020/2/28
// author @zoloypzuo

#ifndef RAILGUN_FRAMEOBJECT_H
#define RAILGUN_FRAMEOBJECT_H

#include "common.h"
#include "util/util.h"
#include "object/object.h"

class Block {
public:
    unsigned char _type;
    unsigned int _target;
    int _level;

    Block() {
        _type = 0;
        _target = 0;
        _level = 0;
    }

    Block(unsigned char b_type,
          unsigned int b_target,
          int b_level) :
            _type(b_type),
            _target(b_target),
            _level(b_level) {
    }

    Block(const Block &b) {
        _type = b._type;
        _target = b._target;
        _level = b._level;
    }
};

class FrameObject {
public:
    explicit FrameObject(CodeObject *codes);

    explicit FrameObject(FunctionObject *func, ObjList args);

    ~FrameObject() = default;

    ArrayList<HiObject *> *_stack{};
    ArrayList<Block *> *_loop_stack{};

    ArrayList<HiObject *> *_consts{};
    ArrayList<HiObject *> *_names{};

    Map<HiObject *, HiObject *> *_locals{};
    Map<HiObject *, HiObject *> *_globals{};
    ObjList _fast_locals{};

    CodeObject *_codes{};
    FrameObject *_sender{};
    int _pc{};

public:
    void set_sender(FrameObject *x) { _sender = x; }

    FrameObject *sender() { return _sender; }

    void set_pc(int x) { _pc = x; }

    int get_pc() { return _pc; }

    ArrayList<HiObject *> *stack() { return _stack; }

    ArrayList<Block *> *loop_stack() { return _loop_stack; }

    ArrayList<HiObject *> *consts() { return _consts; }

    ArrayList<HiObject *> *names() { return _names; }

    Map<HiObject *, HiObject *> *locals() { return _locals; }

    Map<HiObject *, HiObject *> *globals() { return _globals; }

    ObjList fast_locals() { return _fast_locals; }

    bool has_more_codes();

    unsigned char get_op_code();

    int get_op_arg();
};

#endif //RAILGUN_FRAMEOBJECT_H