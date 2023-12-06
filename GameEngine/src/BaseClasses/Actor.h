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
    ~Actor() override;
    
#pragma region Params
public:
    bool Enabled = true;
    int CollisionRadius;
    bool ShouldBeDestroyed;
protected:
    float DeltaTime = 0;
private:
    SDL_Rect* Rect;
    float2 Position;
    float2 Offset;

    SDL_Texture* texture;
#pragma endregion
    

#pragma region Functions
public:
    float2 GetPosition() const;
    void SetPosition(float2 Position);
    void AddPositionOffset(float2 DeltaPosition);
    virtual void RenderPass(SDL_Renderer* renderer);
    virtual void Destroy();

    void Update(float DeltaTime) override;
#pragma endregion
};
