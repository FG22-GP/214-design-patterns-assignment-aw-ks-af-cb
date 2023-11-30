#pragma once

#include "IVelocity.h"

IVelocity::IVelocity(float speed, float2 direction)
{
    this->speed = speed;
    this->direction = direction;
}