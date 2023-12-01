#pragma once

#include "Actor.h"

class Factory
{
public:
    virtual ~Factory() = default;
    virtual Actor* CreateActor() = 0;
};