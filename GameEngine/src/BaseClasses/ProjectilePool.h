#pragma once

#include <memory>
#include <vector>
#include "../Actors/Projectile.h"
#include "../Factories/ProjectileFactory.h"


class ProjectilePool
{
private:
    std::vector<Projectile*> pool;
    ProjectileFactory projectileFactory;

public:
    ProjectilePool(size_t poolSize);

    Projectile* AcquireObject(float2 position, float2 direction);
    void ReleaseObject(Projectile* projectile);
};
