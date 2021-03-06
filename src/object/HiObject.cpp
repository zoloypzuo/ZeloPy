// HiObject.cpp
// created on 2020/2/26
// author @zoloypzuo

#include "HiObject.h"
#include "FunctionObject.h"
#include "runtime/StringTable.h"

void HiObject::print() {
    klass()->print(this);
}

HiObject *HiObject::greater(HiObject *rhs) {
    return klass()->greater(this, rhs);
}

HiObject *HiObject::add(HiObject *rhs) {
    return klass()->add(this, rhs);
}

HiObject *HiObject::sub(HiObject *rhs) {
    return klass()->sub(this, rhs);
}

HiObject *HiObject::mul(HiObject *rhs) {
    return klass()->mul(this, rhs);
}

HiObject *HiObject::div(HiObject *rhs) {
    return klass()->div(this, rhs);
}

HiObject *HiObject::mod(HiObject *rhs) {
    return klass()->mod(this, rhs);
}

HiObject *HiObject::less(HiObject *rhs) {
    return klass()->less(this, rhs);
}

HiObject *HiObject::equal(HiObject *rhs) {
    return klass()->equal(this, rhs);
}

HiObject *HiObject::not_equal(HiObject *rhs) {
    return klass()->not_equal(this, rhs);
}

HiObject *HiObject::ge(HiObject *rhs) {
    return klass()->ge(this, rhs);
}

HiObject *HiObject::le(HiObject *rhs) {
    return klass()->le(this, rhs);
}

HiObject *HiObject::getattr(HiObject *x) {
    HiObject *result = Universe::HiNone;

    result = klass()->klass_dict()->get(x);

    if (result == Universe::HiNone)
        return result;

    // Only klass attribute needs bind.
    if (MethodObject::is_function(result)) {
        result = new MethodObject((FunctionObject *) result, this);
    }
    return result;
}

ObjectKlass *ObjectKlass::instance = NULL;

ObjectKlass::ObjectKlass() {
    set_super(NULL);
}

ObjectKlass *ObjectKlass::get_instance() {
    if (instance == NULL)
        instance = new ObjectKlass();

    return instance;
}

/*
 * TypeObject is a special object
 */
TypeKlass *TypeKlass::instance = NULL;

TypeKlass *TypeKlass::get_instance() {
    if (instance == NULL)
        instance = new TypeKlass();

    return instance;
}

void TypeKlass::print(HiObject *obj) {
    assert(obj->klass() == (Klass *) this);
    printf("<type ");
    Klass *own_klass = ((HiTypeObject *) obj)->own_klass();

    HiDict *attr_dict = own_klass->klass_dict();
    if (attr_dict) {
        HiObject *mod = attr_dict->get((HiObject *)
                                               StringTable::get_instance()->mod_str);
        if (mod != Universe::HiNone) {
            mod->print();
            printf(".");
        }
    }

    own_klass->name()->print();
    printf(">");
}

HiTypeObject::HiTypeObject() {
    set_klass(TypeKlass::get_instance());
}

void HiTypeObject::set_own_klass(Klass *k) {
    _own_klass = k;
    k->set_type_object(this);
}