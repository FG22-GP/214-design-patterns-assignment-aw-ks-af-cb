#pragma once

#include "../BaseClasses/Actor.h"
#include "../Interfaces/IVelocity.h"

class Projectile final : public Actor, public IVelocity
{
public:
    Projectile(SDL_Rect* rect, const char filePath[], float collisionRadius, float speed, float2 direction);
    ~Projectile() override = default;

    void Update(float deltaTime) override;

    void RenderPass(SDL_Renderer* renderer) override;

    void Destroy() override;

    void Reset();
};
