#include "Actor.h"

#include <iostream>
#include <SDL_image.h>

#include "Core.h"
#include "../Struct/float2.h"

Actor::Actor(SDL_Rect* Rect, const char* FilePath, int CollisionRadius)
{
    this->Rect = Rect;
    this->image = IMG_Load(FilePath);
    this->CollisionRadius = CollisionRadius;

    Core::Actors.push_back(std::unique_ptr<Actor>(this));
}

float2 Actor::GetPosition()
{
    return float2(Rect->x, Rect->y);
}

void Actor::SetPosition(float2 Position)
{
    Rect->x = Position.X;
    Rect->y = Position.Y;
}

void Actor::RenderPass(SDL_Renderer* renderer)
{
    if (image == nullptr)
    {
        std::cout << "image is null \n";
        return;
    }

    if (renderer == nullptr)
        return;
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_RenderCopy(renderer, texture, nullptr, Rect);
    SDL_DestroyTexture(texture);
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
