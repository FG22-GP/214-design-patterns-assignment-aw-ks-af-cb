#pragma once
#include <SDL_rect.h>
#include <SDL_render.h>
#include "float2.h"
#include "Object.h"

class Actor : Object
{
    Actor();
#pragma region Params
public:
    SDL_Rect* Rect;
    SDL_Surface* image;
    float CollisionRadius;
#pragma endregion

#pragma region Functions
public:
    float2 GetPosition();
    void SetPosition(float2 Position);
    void RenderPass(SDL_Renderer* renderer);
    void Destroy();
#pragma endregion
};
