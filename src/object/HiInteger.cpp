// HiInteger.cpp
// created on 2020/2/26
// author @zoloypzuo

#include "HiInteger.h"
#include "HiString.h"

IntegerKlass *IntegerKlass::instance = NULL;

IntegerKlass *IntegerKlass::get_instance() {
    if (instance == NULL)
        instance = new IntegerKlass();

    return instance;
}

void IntegerKlass::print(HiObject *obj) {
    HiInteger *int_obj = (HiInteger *) obj;

    assert(int_obj && ((char *) int_obj->klass()) == ((char *) this));

    printf("%d", int_obj->value());
}

HiObject *IntegerKlass::greater(HiObject *x, HiObject *y) {
    HiInteger *ix = (HiInteger *) x;
    HiInteger *iy = (HiInteger *) y;

    assert(ix && (ix->klass() == (Klass *) this));
    assert(iy && (iy->klass() == (Klass *) this));

    if (ix->value() > iy->value())
        return Universe::HiTrue;
    else
        return Universe::HiFalse;
}

HiObject *IntegerKlass::less(HiObject *x, HiObject *y) {
    HiInteger *ix = (HiInteger *) x;
    HiInteger *iy = (HiInteger *) y;

    assert(ix && (ix->klass() == (Klass *) this));
    assert(iy && (iy->klass() == (Klass *) this));

    if (ix->value() < iy->value())
        return Universe::HiTrue;
    else
        return Universe::HiFalse;
}

HiObject *IntegerKlass::equal(HiObject *x, HiObject *y) {
    if (x->klass() != y->klass())
        return Universe::HiFalse;

    HiInteger *ix = (HiInteger *) x;
    HiInteger *iy = (HiInteger *) y;

    assert(ix && (ix->klass() == (Klass *) this));
    assert(iy && (iy->klass() == (Klass *) this));

    if (ix->value() == iy->value())
        return Universe::HiTrue;
    else
        return Universe::HiFalse;
}

HiObject *IntegerKlass::not_equal(HiObject *x, HiObject *y) {
    HiInteger *ix = (HiInteger *) x;
    HiInteger *iy = (HiInteger *) y;

    assert(ix && (ix->klass() == (Klass *) this));
    assert(iy && (iy->klass() == (Klass *) this));

    if (ix->value() != iy->value())
        return Universe::HiTrue;
    else
        return Universe::HiFalse;
}

HiObject *IntegerKlass::ge(HiObject *x, HiObject *y) {
    HiInteger *ix = (HiInteger *) x;
    HiInteger *iy = (HiInteger *) y;

    assert(ix && (ix->klass() == (Klass *) this));
    assert(iy && (iy->klass() == (Klass *) this));

    if (ix->value() >= iy->value())
        return Universe::HiTrue;
    else
        return Universe::HiFalse;
}

HiObject *IntegerKlass::le(HiObject *x, HiObject *y) {
    HiInteger *ix = (HiInteger *) x;
    HiInteger *iy = (HiInteger *) y;

    assert(ix && (ix->klass() == (Klass *) this));
    assert(iy && (iy->klass() == (Klass *) this));

    if (ix->value() <= iy->value())
        return Universe::HiTrue;
    else
        return Universe::HiFalse;
}

HiObject *IntegerKlass::add(HiObject *x, HiObject *y) {
    HiInteger *ix = (HiInteger *) x;
    HiInteger *iy = (HiInteger *) y;

    assert(ix && (ix->klass() == (Klass *) this));
    assert(iy && (iy->klass() == (Klass *) this));

    return new HiInteger(ix->value() + iy->value());
}

HiObject *IntegerKlass::sub(HiObject *x, HiObject *y) {
    HiInteger *ix = (HiInteger *) x;
    HiInteger *iy = (HiInteger *) y;

    assert(ix && (ix->klass() == (Klass *) this));
    assert(iy && (iy->klass() == (Klass *) this));

    return new HiInteger(ix->value() - iy->value());
}

HiObject *IntegerKlass::mul(HiObject *x, HiObject *y) {
    HiInteger *ix = (HiInteger *) x;
    HiInteger *iy = (HiInteger *) y;

    assert(ix && (ix->klass() == (Klass *) this));
    assert(iy && (iy->klass() == (Klass *) this));

    return new HiInteger(ix->value() * iy->value());
}

HiObject *IntegerKlass::div(HiObject *x, HiObject *y) {
    HiInteger *ix = (HiInteger *) x;
    HiInteger *iy = (HiInteger *) y;

    assert(ix && (ix->klass() == (Klass *) this));
    assert(iy && (iy->klass() == (Klass *) this));
    assert(iy->value() != 0);

    return new HiInteger(ix->value() / iy->value());
}

HiObject *IntegerKlass::mod(HiObject *x, HiObject *y) {
    HiInteger *ix = (HiInteger *) x;
    HiInteger *iy = (HiInteger *) y;

    assert(ix && (ix->klass() == (Klass *) this));
    assert(iy && (iy->klass() == (Klass *) this));
    assert(iy->value() != 0);

    return new HiInteger(ix->value() % iy->value());
}

HiInteger::HiInteger(int x) {
    _value = x;
    set_klass(IntegerKlass::get_instance());
}

IntegerKlass::IntegerKlass() {
    set_name(new HiString("int"));
    (new HiTypeObject())->set_own_klass(this);
}

HiObject *IntegerKlass::allocate_instance(ArrayList<HiObject *> *args) {
    if (!args || args->length() == 0)
        return new HiInteger(0);
    else
        return NULL;
}