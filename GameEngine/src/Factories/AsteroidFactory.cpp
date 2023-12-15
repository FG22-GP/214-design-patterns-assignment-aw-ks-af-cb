#include "AsteroidFactory.h"
#include "..\Actors\Asteroid.h"

AsteroidFactory::AsteroidFactory()
{
    filePath = "./img/asteroid.png";
}

Asteroid* AsteroidFactory::CreateAsteroid(float2 position, int size, float2 direction, float speed) const
{
    const int collisionRadius = size/2 - static_cast<int>(0.2f * static_cast<float>(size));
    auto* rect = new SDL_Rect{static_cast<int>(position.X), static_cast<int>(position.Y), size,size };
    return new Asteroid(rect, filePath, collisionRadius, speed, direction);
}
