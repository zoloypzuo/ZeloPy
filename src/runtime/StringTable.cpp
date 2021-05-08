// StringTable.cpp
// created on 2020/2/28
// author @zoloypzuo

#include "StringTable.h"

StringTable *StringTable::instance = NULL;

StringTable *StringTable::get_instance() {
    if (instance == NULL)
        instance = new StringTable();

    return instance;
}

StringTable::StringTable() {
    next_str = new HiString("next");
    mod_str = new HiString("__module__");
    init_str = new HiString("__init__");
    add_str = new HiString("__add__");
    len_str = new HiString("__len__");
    call_str = new HiString("__call__");
    name_str = new HiString("__name__");
    iter_str = new HiString("__iter__");
    repr_str = new HiString("__repr__");
    getitem_str = new HiString("__getitem__");
    setitem_str = new HiString("__setitem__");
    getattr_str = new HiString("__getattr__");
    setattr_str = new HiString("__setattr__");

    so_pre_str = new HiString("lib");
    libdir_pre_str = new HiString("./lib/");
    empty_str = new HiString("");
    so_suf_str = new HiString(".so");
    pyc_suf_str = new HiString(".pyc");
}