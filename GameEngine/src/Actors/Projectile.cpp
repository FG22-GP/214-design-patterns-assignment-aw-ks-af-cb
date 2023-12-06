#pragma once

#include "Projectile.h"


Projectile::Projectile(SDL_Rect* rect, const char filePath[], int collisionRadius, float speed, float2 direction): Actor(rect, filePath, collisionRadius) ,IVelocity(speed, direction) {}

void Projectile::Update(float DeltaTime)
{
    AddPositionOffset(direction * speed * DeltaTime);
}

void Projectile::RenderPass(SDL_Renderer* renderer)
{
    Actor::RenderPass(renderer);
}

void Projectile::Destroy()
{
    Actor::Destroy();
}

void Projectile::Reset()
{
    SetPosition(float2(10000, 10000));
    direction = {0, 0};
    speed = 0;
}
