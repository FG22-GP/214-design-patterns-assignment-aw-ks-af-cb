#pragma once

#include "Asteroid.h"

Asteroid::Asteroid(float speed, float2 direction): IVelocity(speed, direction) {}

// void Asteroid::Update(float deltaTime)
// {
//     Rect->x += IVelocity::speed * IVelocity::direction.X * deltaTime;
//     Rect->y += IVelocity::speed * IVelocity::direction.Y * deltaTime;
// }