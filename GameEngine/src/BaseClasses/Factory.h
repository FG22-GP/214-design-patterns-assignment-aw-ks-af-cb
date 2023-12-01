#pragma once

#include "Actor.h"
template<typename T>

class Factory<T>
{
public:
    virtual ~Factory() = default;
    virtual T* CreateActor() = 0;
};