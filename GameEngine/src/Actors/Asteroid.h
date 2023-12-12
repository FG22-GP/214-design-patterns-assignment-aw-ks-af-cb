#pragma once

#include "../BaseClasses/Actor.h"
#include "../Interfaces/IVelocity.h"

class Asteroid final : public Actor, public IVelocity
{
public:
    Asteroid(SDL_Rect* rect, const char fielPath[], int collisionRadius, float speed, float2 direction);
    ~Asteroid() override = default;

    void Update(float deltaTime) override;

    void RenderPass(SDL_Renderer* renderer) override;

    std::shared_ptr<SDL_Texture> GetTexture() override;

    void Destroy() override;

    float RotationSpeed = 0.0f;
    float Rotation = 0.0f;
    
private:
    const float MaxLifeTime = 10.f;
    float LifeTime = 0;
};
