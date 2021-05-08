// ArrayList.h
// created on 2020/2/26
// author @zoloypzuo

#ifndef RAILGUN_ARRAYLIST_H
#define RAILGUN_ARRAYLIST_H

#include "common.h"

template<typename T>
class ArrayList {
private:
    // size of `_array`, aka. capacity
    int _length{};
    T *_array{};
    // actual number of elements
    int _size{};

    // expand capacity
    void expand();

public:
    explicit ArrayList(int n = 8);

    void add(T t);

    void insert(int index, T t);

    T get(int index);

    // set index
    // expand when need
    void set(int index, T t);

    int size();

    int length();

    T pop();
};

template<typename T>
void ArrayList<T>::expand() {
    const float kExpand = 1.5f;
    auto new_length = static_cast<int>(kExpand * _length);
    auto new_array = new T[_length];
    for (int i = 0; i < _length; ++i) {
        new_array[i] = _array[i];
    }
    //delete[] _array;
    _array = new_array;
    _length = new_length;
    spdlog::debug("[ArrayList<T>::expand] size={}, length={}", _size, _length);
}

template<typename T>
ArrayList<T>::ArrayList(int n) {
    _length = n;
    _size = 0;
    _array = new T[n]{};
}

template<typename T>
void ArrayList<T>::insert(int index, T t) {
    add(T());
    for (int i = _size; i > index; i--) {
        _array[i] = _array[i - 1];
    }
    _array[index] = t;
}

template<typename T>
T ArrayList<T>::get(int index) {
    return _array[index];
}

template<typename T>
T ArrayList<T>::pop() {
    return _array[--_size];
}

template<typename T>
int ArrayList<T>::size() {
    return _size;
}

template<typename T>
void ArrayList<T>::add(T t) {
    if (_size > _length)
        expand();
    _array[_size++] = t;
}

template<typename T>
void ArrayList<T>::set(int index, T t) {
    if (_size <= index)
        _size = index + 1;

    while (_size > _length)
        expand();

    _array[index] = t;
}

template<typename T>
int ArrayList<T>::length() {
    return _length;
}

// TODO move it out
class HiObject;

typedef ArrayList<HiObject *> *ObjList;


#endif //RAILGUN_ARRAYLIST_H