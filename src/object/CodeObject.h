// CodeObject.h
// created on 2020/2/26
// author @zoloypzuo

#ifndef RAILGUN_CODEOBJECT_H
#define RAILGUN_CODEOBJECT_H

#include "common.h"
#include "object/HiObject.h"

class HiString;

template<typename T>
class ArrayList;

class CodeObject : public HiObject {
public:
    int _argcount;
    int _nlocals;
    int _stack_size;
    int _flag;

    HiString *_bytecodes;
    ArrayList<HiObject *> *_names;
    ArrayList<HiObject *> *_consts;
    ArrayList<HiObject *> *_var_names;

    ArrayList<HiObject *> *_free_vars;
    ArrayList<HiObject *> *_cell_vars;

    HiString *_co_name;
    HiString *_file_name;

    int _lineno;
    HiString *_notable;

    CodeObject(int argcount, int nlocals, int stacksize, int flag, HiString *bytecodes,
               ArrayList<HiObject *> *consts, ArrayList<HiObject *> *names,
               ArrayList<HiObject *> *varnames,
               ArrayList<HiObject *> *freevars, ArrayList<HiObject *> *cellvars,
               HiString *file_name, HiString *co_name, int lineno, HiString *notable);
};


#endif //RAILGUN_CODEOBJECT_H