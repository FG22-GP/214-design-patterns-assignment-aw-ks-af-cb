#include "ProjectileFactory.h"

ProjectileFactory::ProjectileFactory()
{
    defaultSize.X = 30;
    defaultSize.Y = 30;
    defaultFilePath = "./img/pikachu.png";
    defaultCollisionRadius = static_cast<int>(defaultSize.X / 2);
    defaultSpeed = 50;
}

std::unique_ptr<Projectile> ProjectileFactory::CreateProjectile(float2 position, float2 direction) const
{
    auto* rect = new SDL_Rect{0,0,static_cast<int>(defaultSize.X), static_cast<int>(defaultSize.Y) };
    return std::make_unique<Projectile>(rect, defaultFilePath, defaultCollisionRadius, defaultSpeed, direction);
}
