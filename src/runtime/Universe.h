// Universe.h
// created on 2020/2/26
// author @zoloypzuo

#ifndef RAILGUN_UNIVERSE_H
#define RAILGUN_UNIVERSE_H


class HiInteger;

class HiObject;

class Klass;

template<typename T>
class ArrayList;

class Universe {
public:
    static HiInteger *HiTrue;
    static HiInteger *HiFalse;

    static HiObject *HiNone;
    static ArrayList<Klass *> *klasses;

public:
    static void genesis();

    static void destroy();
};

#endif //RAILGUN_UNIVERSE_H