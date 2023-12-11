#pragma once

#include "Projectile.h"
#include "../BaseClasses/Core.h"
#include <iostream>


Projectile::Projectile(SDL_Rect* rect, const char filePath[], int collisionRadius, float speed, float2 direction): Actor(rect, filePath, collisionRadius) ,IVelocity(speed, direction) {}

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
}

void Projectile::Destroy()
{
    // Actor::Destroy();
    Enabled = false;
    Lifetime = 0;
    Core::projectilePool->ReleaseObject(this);
}

void Projectile::Reset()
{
    SetPosition(float2(10000, 10000));
    direction = {0, 0};
    speed = 0;
}
