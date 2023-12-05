#pragma once
#include <memory>

#include "../Actors/Projectile.h"

class ProjectileFactory
{
private:
    float2 defaultSize;
    const char* defaultFilePath;
    int defaultCollisionRadius;
    
    
public:
    float defaultSpeed;
    
    ProjectileFactory();
    ~ProjectileFactory() = default;
    
    std::unique_ptr<Projectile> CreateProjectile(float2 position, float2 direction) const;
};
