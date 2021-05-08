// Interpreter.cpp
// created on 2020/2/26
// author @zoloypzuo

#include "Interpreter.h"

#include "util/util.h"
#include "object/object.h"
#include "code/code.h"
#include "FrameObject.h"

#define PUSH(x)       _frame->stack()->add((x))
#define POP()         _frame->stack()->pop()
#define STACK_LEVEL() _frame->stack()->size()

#define HI_TRUE       Universe::HiTrue
#define HI_FALSE      Universe::HiFalse

void Interpreter::run(CodeObject *codes) {
    _frame = new FrameObject(codes);

    while (_frame->has_more_codes()) {
        unsigned char op_code = _frame->get_op_code();
        bool has_argument = (op_code & 0xFF) >= ByteCode::HAVE_ARGUMENT;

        int op_arg = -1;
        if (has_argument) {
            op_arg = _frame->get_op_arg();
        }

        Block *b;
        FunctionObject *fo;
        ArrayList<HiObject *> *args = NULL;
        HiObject *v, *w;


        switch (op_code) {
            case ByteCode::POP_TOP:
                POP();
                break;

            case ByteCode::LOAD_ATTR:
                v = POP();
                w = _frame->_names->get(op_arg);
                PUSH(v->getattr(w));
                break;

            case ByteCode::LOAD_FAST:
                PUSH(_frame->fast_locals()->get(op_arg));
                break;

            case ByteCode::STORE_FAST:
                _frame->_fast_locals->set(op_arg, POP());
                break;

            case ByteCode::LOAD_CONST:
                PUSH(_frame->consts()->get(op_arg));
                break;

            case ByteCode::LOAD_GLOBAL:
                v = _frame->names()->get(op_arg);
                w = _frame->globals()->get(v);
                if (w != Universe::HiNone) {
                    PUSH(w);
                    break;
                }

                w = _builtins->get(v);
                if (w != Universe::HiNone) {
                    PUSH(w);
                    break;
                }

                PUSH(Universe::HiNone);
                break;

            case ByteCode::STORE_GLOBAL:
                v = _frame->names()->get(op_arg);
                _frame->globals()->put(v, POP());
                break;

            case ByteCode::LOAD_NAME:
                v = _frame->names()->get(op_arg);
                w = _frame->locals()->get(v);
                if (w != Universe::HiNone) {
                    PUSH(w);
                    break;
                }

                w = _frame->globals()->get(v);
                if (w != Universe::HiNone) {
                    PUSH(w);
                    break;
                }

                w = _builtins->get(v);
                if (w != Universe::HiNone) {
                    PUSH(w);
                    break;
                }

                PUSH(Universe::HiNone);
                break;

            case ByteCode::STORE_NAME:
                v = _frame->names()->get(op_arg);
                _frame->locals()->put(v, POP());
                break;

            case ByteCode::PRINT_ITEM:
                v = POP();
                v->print();
                break;

            case ByteCode::PRINT_NEWLINE:
                printf("\n");
                break;

            case ByteCode::BINARY_ADD:
                v = POP();
                w = POP();
                PUSH(w->add(v));
                break;

            case ByteCode::MAKE_FUNCTION:
                v = POP();
                fo = new FunctionObject(v);
                fo->set_globals(_frame->globals());
                if (op_arg > 0) {
                    args = new ArrayList<HiObject *>(op_arg);
                    while (op_arg--) {
                        args->set(op_arg, POP());
                    }
                }
                fo->set_default(args);

                if (args != NULL) {
                    delete args;
                    args = NULL;
                }
                PUSH(fo);
                break;

            case ByteCode::CALL_FUNCTION:
                if (op_arg > 0) {
                    args = new ArrayList<HiObject *>(op_arg);
                    while (op_arg--) {
                        args->set(op_arg, POP());
                    }
                }

                build_frame(POP(), args);

                if (args != NULL) {
                    delete args;
                    args = NULL;
                }
                break;

            case ByteCode::RETURN_VALUE:
                leave_frame(POP());
                if (!_frame)
                    return;
                break;

#pragma region control-flow
                //--------------------------------------------------------------------------------------
                // if-else
                //--------------------------------------------------------------------------------------
            case ByteCode::COMPARE_OP:
                w = POP();
                v = POP();

                switch (op_arg) {
                    case ByteCode::GREATER:
                        PUSH(v->greater(w));
                        break;

                    case ByteCode::LESS:
                        PUSH(v->less(w));
                        break;

                    case ByteCode::EQUAL:
                        PUSH(v->equal(w));
                        break;

                    case ByteCode::NOT_EQUAL:
                        PUSH(v->not_equal(w));
                        break;

                    case ByteCode::GREATER_EQUAL:
                        PUSH(v->ge(w));
                        break;

                    case ByteCode::LESS_EQUAL:
                        PUSH(v->le(w));
                        break;

                    case ByteCode::IS:
                        if (v == w)
                            PUSH(HI_TRUE);
                        else
                            PUSH(HI_FALSE);
                        break;

                    case ByteCode::IS_NOT:
                        if (v == w)
                            PUSH(HI_TRUE);
                        else
                            PUSH(HI_FALSE);
                        break;
                    default:
                        printf("Error: Unrecognized compare op %d\n", op_arg);

                }
                break;

            case ByteCode::POP_JUMP_IF_FALSE:
                v = POP();
                if (v == Universe::HiFalse)
                    _frame->set_pc(op_arg);
                break;

            case ByteCode::JUMP_FORWARD:
                _frame->set_pc(op_arg + _frame->get_pc());
                break;
                //--------------------------------------------------------------------------------------
                // while
                //--------------------------------------------------------------------------------------
            case ByteCode::JUMP_ABSOLUTE:
                _frame->set_pc(op_arg);
                break;

            case ByteCode::SETUP_LOOP:
                _frame->loop_stack()->add(new Block(
                        op_code, _frame->get_pc() + op_arg,
                        STACK_LEVEL()));
                break;

            case ByteCode::POP_BLOCK:
                b = _frame->loop_stack()->pop();
                while (STACK_LEVEL() > b->_level) {
                    POP();
                }
                break;

            case ByteCode::BREAK_LOOP:
                b = _frame->loop_stack()->pop();
                while (STACK_LEVEL() > b->_level) {
                    POP();
                }
                _frame->set_pc(b->_target);
                break;
#pragma endregion


            default:
                printf("Error: Unrecognized byte code %d\n", op_code);
        }
    }
}

void Interpreter::build_frame(HiObject *callable, ObjList args) {
    if (callable->klass() == NativeFunctionKlass::get_instance()) {
        PUSH(((FunctionObject *) callable)->call(args));
    } else if (MethodObject::is_method(callable)) {
        MethodObject *method = (MethodObject *) callable;
        // return value is ignored here, because they are handled
        // by other pathes.
        if (!args) {
            args = new ArrayList<HiObject *>(1);
        }
        args->insert(0, method->owner());
        build_frame(method->func(), args);
    } else if (callable->klass() == FunctionKlass::get_instance()) {
        FrameObject *frame = new FrameObject((FunctionObject *) callable, args);
        frame->set_sender(_frame);
        _frame = frame;
    } else if (callable->klass() == TypeKlass::get_instance()) {
        HiObject *inst = ((HiTypeObject *) callable)->own_klass()->
                allocate_instance(args);
        PUSH(inst);
    }
}

void Interpreter::leave_frame(HiObject *return_value) {
    if (!_frame->sender()) {
        delete _frame;
        _frame = NULL;
        return;
    }

    FrameObject *temp = _frame;
    _frame = _frame->sender();
    PUSH(return_value);

    delete temp;
}

Interpreter::Interpreter() {
    _builtins = new Map<HiObject *, HiObject *>();

    _builtins->put(new HiString("True"), Universe::HiTrue);
    _builtins->put(new HiString("False"), Universe::HiFalse);
    _builtins->put(new HiString("None"), Universe::HiNone);
    _builtins->put(new HiString("len"), new FunctionObject(len));
    _builtins->put(new HiString("type"), new FunctionObject(type_of));
    _builtins->put(new HiString("isinstance"), new FunctionObject(isinstance));

    _builtins->put(new HiString("int"), IntegerKlass::get_instance()->type_object());
    _builtins->put(new HiString("object"), ObjectKlass::get_instance()->type_object());
    _builtins->put(new HiString("str"), StringKlass::get_instance()->type_object());
//    _builtins->put(new HiString("list"),     ListKlass::get_instance()->type_object());

}

void dofile(Interpreter *L, const std::string &filename) {
    spdlog::debug_section("dofile");
    spdlog::debug("dofile, fn={}", filename);
    BufferedInputStream stream(filename.c_str());
    BinaryFileParser parser(&stream);
    CodeObject *main_code = parser.parse();
    L->run(main_code);
}