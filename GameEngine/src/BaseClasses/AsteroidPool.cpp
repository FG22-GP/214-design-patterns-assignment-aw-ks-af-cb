#include "AsteroidPool.h"

AsteroidPool::AsteroidPool(size_t poolSize)
{
    // Initialize the object pool with objects
    for (size_t i = 0; i < poolSize; ++i)
    {
        auto projectile = projectileFactory.CreateAsteroid({0, 0}, {0, 0}, {0,0}, 10);
        projectile->Enabled = false;
        pool.push_back(projectile);
    }
}

Asteroid* AsteroidPool::AcquireObject(float2 position, float2 direction)
{
    if (!pool.empty())
    {
        auto projectile = std::move(pool.back());
        pool.pop_back();
        projectile->SetPosition(position);
        projectile->direction = direction;
        projectile->Enabled = true;
        return projectile;
    }
    auto projectile = projectileFactory.CreateAsteroid(position, float2(1,1), direction, 10);
    projectile->Enabled = true;
    return projectile;
}

void AsteroidPool::ReleaseObject(Asteroid* Object)
{
    Object->Enabled = false;
    pool.push_back(Object);
}
