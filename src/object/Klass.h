// Klass.h
// created on 2020/2/28
// author @zoloypzuo

#ifndef RAILGUN_KLASS_H
#define RAILGUN_KLASS_H

#include "common.h"
#include "util/ArrayList.h"
#include "util/Map.h"

class HiObject;

class HiString;

class HiTypeObject;

class Klass {
private:
    Klass *_super{};
    HiString *_name{};
    HiDict *_klass_dict{};
    HiTypeObject *_type_object{};

public:
    Klass() = default;;

    void set_super(Klass *x) { _super = x; }

    Klass *super() { return _super; }

    void set_name(HiString *x) { _name = x; }

    HiString *name() { return _name; }

    void set_klass_dict(HiDict *dict) { _klass_dict = dict; }

    HiDict *klass_dict() { return _klass_dict; }

    void set_type_object(HiTypeObject *x) { _type_object = x; }

    HiTypeObject *type_object() { return _type_object; }

public:
    virtual void print(HiObject *obj) {};

    virtual HiObject *greater(HiObject *x, HiObject *y) { return 0; }

    virtual HiObject *less(HiObject *x, HiObject *y) { return 0; }

    virtual HiObject *equal(HiObject *x, HiObject *y) { return 0; }

    virtual HiObject *not_equal(HiObject *x, HiObject *y) { return 0; }

    virtual HiObject *ge(HiObject *x, HiObject *y) { return 0; }

    virtual HiObject *le(HiObject *x, HiObject *y) { return 0; }

    virtual HiObject *add(HiObject *x, HiObject *y) { return 0; }

    virtual HiObject *sub(HiObject *x, HiObject *y) { return 0; }

    virtual HiObject *mul(HiObject *x, HiObject *y) { return 0; }

    virtual HiObject *div(HiObject *x, HiObject *y) { return 0; }

    virtual HiObject *mod(HiObject *x, HiObject *y) { return 0; }

    virtual HiObject *call(ArrayList<HiObject *> *args) { return 0; }

    virtual HiObject* allocate_instance(ArrayList<HiObject*>* args) { return 0; }
};


#endif //RAILGUN_KLASS_H