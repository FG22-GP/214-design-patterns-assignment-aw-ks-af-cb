#pragma once

#include "Asteroid.h"

#include "../BaseClasses/AsteroidPool.h"
#include "../BaseClasses/Core.h"

Asteroid::Asteroid(SDL_Rect* rect, const char filePath[], int collisionRadius, float speed, float2 direction): Actor(rect, filePath, collisionRadius) ,IVelocity(speed, direction) {}

void Asteroid::Update(float deltaTime)
{
    // Rect->x += static_cast<int>(speed * direction.X * deltaTime);
    // Rect->y += static_cast<int>(speed * direction.Y * deltaTime);
}

void Asteroid::Destroy()
{
    Enabled = false;
    Core::asteroidPool->ReleaseObject(this);
}
