#pragma once

#include "Asteroid.h"

#include "../BaseClasses/AsteroidPool.h"
#include "../BaseClasses/Core.h"

Asteroid::Asteroid(SDL_Rect* rect, const char filePath[], int collisionRadius, float speed, float2 direction): Actor(rect, collisionRadius) ,IVelocity(speed, direction)
{
    Enabled = false;
}

void Asteroid::Update(float deltaTime)
{
    AddPositionOffset(direction * speed * deltaTime);

    LifeTime += deltaTime;
     if (LifeTime >= MaxLifeTime)
    {
        Destroy();
    }
}

std::shared_ptr<SDL_Texture> Asteroid::GetTexture()
{
    return TextureFlyWeight::Instance->AsteroidTexture;
}

void Asteroid::Destroy()
{
    Enabled = false;
    SetPosition(float2(0,0));
    LifeTime = 0;
    Core::asteroidPool->ReleaseObject(this);
}
