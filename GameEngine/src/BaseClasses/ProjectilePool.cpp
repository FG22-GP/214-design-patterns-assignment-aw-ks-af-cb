#include "ProjectilePool.h"

ProjectilePool::ProjectilePool(size_t poolSize)
{
    // Initialize the object pool with objects
    for (size_t i = 0; i < poolSize; ++i)
    {
        auto projectile = projectileFactory.CreateProjectile({0, 0}, {0, 0});
        projectile->speed = 0;
        pool.push_back(projectile);
    }
}

Projectile* ProjectilePool::AcquireObject(float2 position, float2 direction)
{
    if (!pool.empty())
    {
        auto object = pool.back();
        pool.pop_back();
        object->SetPosition(position);
        object->direction = direction;
        object->speed = projectileFactory.defaultSpeed;
        return object;
    }
    return projectileFactory.CreateProjectile(position, direction);
}

void ProjectilePool::ReleaseObject(Projectile* object)
{
    object->Reset();
    pool.push_back(object);
}
