#pragma once
#include <memory>
#include <SDL_rect.h>
#include <SDL_render.h>
#include "../Struct/float2.h"
#include "Object.h"

class Actor : public Object
{
public:
    Actor(SDL_Rect* Rect,const char FilePath[], int CollisionRadius);
    ~Actor() override = default;
    
#pragma region Params
public:
    SDL_Rect* Rect;
    int CollisionRadius;
    bool ShouldBeDestroyed;
protected:
    SDL_Surface* image;
    float DeltaTime = 0;
    float2 Offset;
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
