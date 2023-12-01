#pragma once

#include "Asteroid.h"

Asteroid::Asteroid(float speed, float2 direction): IVelocity(speed, direction) {}

Asteroid::Asteroid(): IVelocity(1.f, float2(0,0)) {}

// void Asteroid::Update(float deltaTime)
// {
//     Rect->x += IVelocity::speed * IVelocity::direction.X * deltaTime;
//     Rect->y += IVelocity::speed * IVelocity::direction.Y * deltaTime;
// }