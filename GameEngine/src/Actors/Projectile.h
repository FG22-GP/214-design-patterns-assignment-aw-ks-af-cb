#pragma once

#include "../BaseClasses/Actor.h"
#include "../Interfaces/IVelocity.h"

class Projectile final : public Actor, public IVelocity
{
public:
    Projectile(float speed, float2 direction);
    ~Projectile() override = default;

    void Update(float DeltaTime) override;
    
};
