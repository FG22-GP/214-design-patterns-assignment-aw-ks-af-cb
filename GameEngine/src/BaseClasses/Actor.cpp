#include "Actor.h"

#include <iostream>
#include <SDL_image.h>

#include "../Core.h"
#include "../Struct/float2.h"

Actor::Actor(SDL_Rect* Rect, int CollisionRadius)
{
    this->Rect = Rect;
    this->CollisionRadius = CollisionRadius;
    ShouldBeDestroyed = false;
    Position = float2(static_cast<float>(Rect->x), static_cast<float>(Rect->y));
    Offset = float2(static_cast<float>(Rect->w)/2.f, static_cast<float>(Rect->h)/2.f);

    Core::Actors.push_back(std::unique_ptr<Actor>(this));
}

Actor::~Actor()
{
    delete Rect;
}

std::shared_ptr<SDL_Texture> Actor::GetTexture()
{
    return TextureFlyWeight::Instance->AsteroidTexture;
}

const float2 Actor::GetSize() const
{
    return {static_cast<float>(Rect->w), static_cast<float>(Rect->h)};
}



float2 Actor::GetPosition() const
{
    return Position;
}

void Actor::SetPosition(float2 Position)
{
    this->Position = Position;
}

void Actor::SetSize(float2 size)
{
    Rect->w = static_cast<int>(size.X);
    Rect->h = static_cast<int>(size.Y);
    Offset = float2(static_cast<float>(Rect->w)/2.f, static_cast<float>(Rect->h)/2.f);
}

void Actor::AddPositionOffset(float2 DeltaPosition)
{
    SetPosition(GetPosition() + DeltaPosition);
}

void Actor::RenderPass(SDL_Renderer* renderer)
{
    if (renderer == nullptr)
        return;
    
    Rect->x = static_cast<int>((Position.X - Offset.X));
    Rect->y = static_cast<int>((Position.Y - Offset.Y));
    
    SDL_RenderCopy(renderer, GetTexture().get(), nullptr, Rect);
}

void Actor::Destroy()
{
    ShouldBeDestroyed = true;
}

void Actor::Update(float DeltaTime)
{
    Object::Update(DeltaTime);
    this->DeltaTime = DeltaTime;
}
