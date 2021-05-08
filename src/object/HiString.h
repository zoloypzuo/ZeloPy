// HiString.h
// created on 2020/2/26
// author @zoloypzuo

#ifndef RAILGUN_HISTRING_H
#define RAILGUN_HISTRING_H

#include "common.h"
#include "HiObject.h"

class StringKlass : public Klass {
private:
    StringKlass() = default;

    static StringKlass *instance;

public:
    static StringKlass *get_instance();

    virtual HiObject *equal(HiObject *x, HiObject *y);

    virtual void print(HiObject *obj);
};

class HiString : public HiObject {
private:
    char *_value{};
    size_t _length{};

public:
    explicit HiString(const char *x);

    HiString(const char *x, int length);

    const char *value() { return _value; }

    size_t length() { return _length; }
};


#endif //RAILGUN_HISTRING_H