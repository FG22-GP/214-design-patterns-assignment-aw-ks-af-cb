#include "ProjectilePool.h"

ProjectilePool::ProjectilePool(size_t poolSize)
{
    // Initialize the object pool with objects
    for (size_t i = 0; i < poolSize; ++i)
    {
        auto projectile = projectileFactory.CreateProjectile({0, 0}, {0, 0});
        pool.push_back(std::move(projectile));
    }
}

std::unique_ptr<Projectile> ProjectilePool::AcquireObject(float2 position, float2 direction)
{
    if (!pool.empty())
    {
        auto object = std::move(pool.back());
        pool.pop_back();
        object->SetPosition(position);
        object->direction = direction;
        return object;
    }
    return projectileFactory.CreateProjectile(position, direction);
}

void ProjectilePool::ReleaseObject(std::unique_ptr<Projectile> object)
{
    pool.push_back(std::move(object));
}
