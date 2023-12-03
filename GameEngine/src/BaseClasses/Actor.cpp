#include "Actor.h"

#include <iostream>
#include <SDL_image.h>

#include "../Struct/float2.h"

Actor::Actor(SDL_Rect* Rect, const char* FilePath, float CollisionRadius)
{
    this->Rect = Rect;
    this->image = IMG_Load(FilePath);
    this->CollisionRadius = CollisionRadius;
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
    SDL_RenderCopy(renderer, texture, NULL, Rect);
}

void Actor::Destroy()
{
    delete this;
}

void Actor::Update(float DeltaTime)
{
    Object::Update(DeltaTime);
}
