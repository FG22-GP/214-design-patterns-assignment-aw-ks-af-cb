#include "ProjectileFactory.h"

ProjectileFactory::ProjectileFactory()
{
    defaultSize.X = 30.f;
    defaultSize.Y = 30.f;
    defaultFilePath = "./img/projectile.png";
    defaultCollisionRadius = static_cast<int>(defaultSize.X / 2.f);
    defaultSpeed = 500.f;
}

Projectile* ProjectileFactory::CreateProjectile(float2 position, float2 direction) const
{
    auto* rect = new SDL_Rect{static_cast<int>(position.X),static_cast<int>(position.Y),static_cast<int>(defaultSize.X), static_cast<int>(defaultSize.Y) };
    return new Projectile(rect, defaultFilePath, defaultCollisionRadius, defaultSpeed, direction);
}
