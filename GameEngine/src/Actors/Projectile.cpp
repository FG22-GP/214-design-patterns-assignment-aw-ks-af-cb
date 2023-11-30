#pragma once

#include "Projectile.h"

Projectile::Projectile(float speed, float2 direction): IVelocity(speed, direction) {}

void Projectile::Update(float deltaTime)
{
    Rect->x += IVelocity::speed * IVelocity::direction.X * deltaTime;
    Rect->y += IVelocity::speed * IVelocity::direction.Y * deltaTime;
}
