#pragma once

#include <memory>
#include <vector>
#include "../Actors/Projectile.h"
#include "../Factories/ProjectileFactory.h"


class ProjectilePool
{
private:
    std::vector<std::unique_ptr<Projectile>> pool;
    ProjectileFactory projectileFactory;

public:
    ProjectilePool(size_t poolSize);

    std::unique_ptr<Projectile> AcquireObject(float2 position, float2 direction);
    void ReleaseObject(std::unique_ptr<Projectile> projectile);
};
