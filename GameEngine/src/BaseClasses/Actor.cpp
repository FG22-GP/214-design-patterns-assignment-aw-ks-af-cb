#include "Actor.h"

#include <iostream>
#include <SDL_image.h>

#include "Core.h"
#include "../Struct/float2.h"

Actor::Actor(SDL_Rect* Rect, const char* FilePath, int CollisionRadius)
{
    this->Rect = Rect;
    SDL_Surface* surface = IMG_Load(FilePath);
    this->CollisionRadius = CollisionRadius;
    Offset = float2(Rect->w/2, Rect->h/2);
    texture = SDL_CreateTextureFromSurface(Core::renderer, surface);
    SDL_FreeSurface(surface);

    Core::Actors.push_back(std::unique_ptr<Actor>(this));
}

Actor::~Actor()
{
    SDL_DestroyTexture(texture);
}

float2 Actor::GetPosition() const
{
    return Position;
}

void Actor::SetPosition(float2 Position)
{
    this->Position = Position;
}

void Actor::AddPositionOffset(float2 DeltaPosition)
{
    SetPosition(GetPosition() + DeltaPosition);
}

void Actor::RenderPass(SDL_Renderer* renderer)
{
    if (renderer == nullptr)
        return;
    
    Rect->x = static_cast<int>(std::floor(Position.X - Offset.X));
    Rect->y = static_cast<int>(std::floor(Position.Y - Offset.Y));
    
    SDL_RenderCopy(renderer, texture, nullptr, Rect);
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
