// Engine.cpp
// created on 2021/3/28
// author @zoloypzuo

#include "ZeloPreCompiledHeader.h"
#include "Engine.h"
#include <vld.h>

void Engine::initialize() {
}

void Engine::finalize() {
}

void Engine::update() {
}

Engine::Engine() {
}

Engine::~Engine() {
    finalize();
}

template<> Engine *Singleton<Engine>::msSingleton = nullptr;

Engine *Engine::getSingletonPtr() {
    return msSingleton;
}
