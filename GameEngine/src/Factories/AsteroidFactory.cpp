#include "AsteroidFactory.h"
#include "..\Actors\Asteroid.h"

AsteroidFactory::AsteroidFactory()
{
    filePath = "Assets/Textures/Projectile.png";
}

Asteroid* AsteroidFactory::CreateAsteroid(float2 position, float2 size, float2 direction, float speed) const
{
    int collisionRadius = static_cast<int>(size.X / 2);
    auto* rect = new SDL_Rect{0, 0, (int)size.X,(int)size.Y };
    return new Asteroid(rect, filePath, collisionRadius, speed, direction);
}
