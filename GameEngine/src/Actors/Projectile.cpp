#pragma once

#include "Projectile.h"
#include "../BaseClasses/Core.h"
#include <iostream>


Projectile::Projectile(SDL_Rect* rect, const char filePath[], int collisionRadius, float speed, float2 direction): Actor(rect, collisionRadius) ,IVelocity(speed, direction) {}

Projectile::~Projectile()
{
}

void Projectile::Update(float DeltaTime)
{
    Actor::Update(DeltaTime);
    
    Lifetime += DeltaTime;

    float2 offset = direction * speed;
    offset = offset * DeltaTime;
    
    AddPositionOffset(offset);

    if (Lifetime >= MAXLIFETIME)
    {
        Destroy();
    }
}

void Projectile::RenderPass(SDL_Renderer* renderer)
{
    Actor::RenderPass(renderer);

    
    int startX = static_cast<int>(std::round(Position.X));
    int startY = static_cast<int>(std::round(Position.Y));
    int endX = static_cast<int>(std::round(Position.X + (-direction.X * 200 * Lifetime / 2)));
    int endY = static_cast<int>(std::round(Position.Y + (-direction.Y * 200 * Lifetime / 2)));

    SDL_SetRenderDrawColor(renderer, 215, 63, 49,255 / 2);
    const int Size = 3;
    for (int x = -Size/2; x < Size/2; ++x)
    {
        for (int y = -Size/2; y < Size / 2; ++y)
        {
            SDL_RenderDrawLine(renderer, startX + x * 3, startY + y * 3, endX + x * 3, endY + y * 3);
        }
    }
    

    SDL_SetRenderDrawColor(renderer, 55, 66, 89, 255);
}

void Projectile::Destroy()
{
    // Actor::Destroy();
    Enabled = false;
    Lifetime = 0;
    Core::projectilePool->ReleaseObject(this);
}

std::shared_ptr<SDL_Texture> Projectile::GetTexture()
{
    return TextureFlyWeight::Instance->ProjectileTexture;
}
