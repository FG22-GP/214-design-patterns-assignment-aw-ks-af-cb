#include "AsteroidFactory.h"
#include "..\Actors\Asteroid.h"

AsteroidFactory::AsteroidFactory()
{
    filePath = "Assets/Textures/Projectile.png";
}

std::unique_ptr<Asteroid> AsteroidFactory::CreateAsteroid(float2 position, float2 size, float2 direction, float speed) const
{
    const float collisionRadius = static_cast<int>(size.X / 2);
    auto* rect = new SDL_Rect{position.X, position.Y,size.X,size.Y };
    return std::make_unique<Asteroid>(rect, filePath, collisionRadius, speed, direction);
}
