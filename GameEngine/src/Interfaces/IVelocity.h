#pragma once

#include "../Struct/float2.h"

class IVelocity
{
public:
    IVelocity(float speed, float2 direction);
    float speed;
    float2 direction;
};
