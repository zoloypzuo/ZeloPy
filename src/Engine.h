// Engine.h
// created on 2021/3/28
// author @zoloypzuo

#ifndef ZELOENGINE_ENGINE_H
#define ZELOENGINE_ENGINE_H

#include "ZeloPrerequisites.h"
#include "ZeloSingleton.h"

class Engine : public Singleton<Engine>, public IRuntimeModule {
public:
    Engine();

    ~Engine() override;

    void initialize() override;

    void finalize() override;

    void update() override;

public:
    static Engine *getSingletonPtr();
};

#endif //ZELOENGINE_ENGINE_H