#pragma once
#include <SDL_rect.h>
#include <SDL_render.h>
#include "../Struct/float2.h"
#include "Object.h"

class Actor : public Object
{
public:
    Actor(SDL_Rect* Rect,const char FilePath[], float CollisionRadius);
    
#pragma region Params
public:
    SDL_Rect* Rect;
    float CollisionRadius;
protected:
    SDL_Surface* image;
#pragma endregion

#pragma region Functions
public:
    float2 GetPosition();
    void SetPosition(float2 Position);
    virtual void RenderPass(SDL_Renderer* renderer);
    virtual void Destroy();

    void Update(float DeltaTime) override;
#pragma endregion
};
