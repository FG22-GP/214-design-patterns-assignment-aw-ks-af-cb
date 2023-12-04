#include "ProjectileFactory.h"

ProjectileFactory::ProjectileFactory()
{
    defaultSize.X = 30;
    defaultSize.Y = 30;
    defaultFilePath = "./img/pikachu.png";
    defaultCollisionRadius = static_cast<int>(defaultSize.X / 2);
    defaultSpeed = 50;
}

Projectile* ProjectileFactory::CreateProjectile(float2 position, float2 direction) const
{
    auto* rect = new SDL_Rect{position.X,position.Y,defaultSize.X,defaultSize.Y };
    return new Projectile(rect, defaultFilePath, defaultCollisionRadius, defaultSpeed, direction);
}
