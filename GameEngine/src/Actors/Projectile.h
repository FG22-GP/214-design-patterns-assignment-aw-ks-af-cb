#pragma once

#include "../BaseClasses/Actor.h"
#include "../Interfaces/IVelocity.h"

class Projectile final : public Actor, public IVelocity
{
public:
    Projectile(SDL_Rect* rect, const char filePath[], int collisionRadius, float speed, float2 direction);
    ~Projectile() override;

    const float MAXLIFETIME = 10;

    void Update(float DeltaTime) override;

    void RenderPass(SDL_Renderer* renderer) override;

    void Destroy() override;

    void Reset();

    std::shared_ptr<SDL_Texture> GetTexture() override;
protected:
    float Lifetime = 0;
};
