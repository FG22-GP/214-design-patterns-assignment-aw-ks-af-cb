#pragma once

#include "Projectile.h"

Projectile::Projectile(SDL_Rect* rect, const char filePath[], float collisionRadius, float speed, float2 direction): Actor(rect, filePath, collisionRadius) ,IVelocity(speed, direction) {}

void Projectile::Update(float deltaTime)
{
    Rect->x += static_cast<int>(speed * direction.X * deltaTime);
    Rect->y += static_cast<int>(speed * direction.Y * deltaTime);
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
    Rect->x = 9999;
    Rect->y = 9999;
    direction = {0, 0};
    speed = 0;
}
