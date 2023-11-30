#include "Actor.h"

#include "../Struct/float2.h"

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
    if (image == nullptr) return;
    
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_RenderCopy(renderer, texture, NULL, Rect);
}

void Actor::Destroy()
{
    delete this;
}
