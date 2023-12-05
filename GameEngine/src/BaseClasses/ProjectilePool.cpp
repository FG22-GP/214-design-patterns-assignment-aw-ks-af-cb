#include "ProjectilePool.h"

ProjectilePool::ProjectilePool(size_t poolSize)
{
    // Initialize the object pool with objects
    for (size_t i = 0; i < poolSize; ++i)
    {
        auto projectile = projectileFactory.CreateProjectile({0, 0}, {0, 0});
        projectile->Enabled = false;
        pool.push_back(std::move(projectile));
    }
}

std::unique_ptr<Projectile> ProjectilePool::AcquireObject(float2 position, float2 direction)
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
    auto projectile = projectileFactory.CreateProjectile(position, direction);
    projectile->Enabled = true;
    return projectile;
}

void ProjectilePool::ReleaseObject(std::unique_ptr<Projectile> projectile)
{
    projectile->Enabled = false;
    pool.push_back(std::move(projectile));
}
