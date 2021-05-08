// Universe.cpp
// created on 2020/2/26
// author @zoloypzuo

#include "Universe.h"

#include "object/object.h"
#include "util/util.h"

HiInteger *Universe::HiTrue = nullptr;
HiInteger *Universe::HiFalse = nullptr;

HiObject *Universe::HiNone = nullptr;

void Universe::genesis() {
    HiTrue = new HiInteger(1);
    HiFalse = new HiInteger(0);

    HiNone = new HiObject();

    HiDict *klass_dict = new HiDict();
    StringKlass::get_instance()->set_klass_dict(klass_dict);
    klass_dict->put(new HiString("upper"), new FunctionObject(string_upper));
}

void Universe::destroy() {
}