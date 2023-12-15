#pragma once

#include "Asteroid.h"
#include <random>

#include "../ObjectPools/AsteroidPool.h"
#include "../Core.h"

Asteroid::Asteroid(SDL_Rect* rect, const char filePath[], int collisionRadius, float speed, float2 direction): Actor(rect, collisionRadius) ,IVelocity(speed, direction)
{
    Enabled = false;
}

void Asteroid::Update(float deltaTime)
{
    AddPositionOffset(direction * speed * deltaTime);

    Rotation += RotationSpeed * deltaTime;

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

void Asteroid::RenderPass(SDL_Renderer* renderer)
{
    if (renderer == nullptr) return;

    SDL_Point center = { Rect->w / 2, Rect->h / 2};
    
    SDL_RenderCopyEx(renderer, GetTexture().get(), nullptr, Rect, Rotation, &center, SDL_FLIP_NONE);
}