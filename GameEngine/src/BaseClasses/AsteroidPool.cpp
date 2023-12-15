#include "AsteroidPool.h"

#include <iostream>

AsteroidPool::AsteroidPool(size_t poolSize)
{
    // Initialize the object pool with objects
    for (size_t i = 0; i < poolSize; ++i)
    {
        const auto asteroid = asteroidFactory.CreateAsteroid({0, 0}, 50, {0,0}, 400);
        asteroid->Enabled = false;
        pool.push_back(asteroid);
    }
}

auto AsteroidPool::AcquireObject(const float2 position, const int size, const float2 direction, const float speed) -> Asteroid*
{
    if (!pool.empty())
    {
        const auto asteroid = pool.back();
        pool.pop_back();
        asteroid->SetPosition(position);
        asteroid->direction = direction;
        asteroid->speed = speed;
        asteroid->SetSize({static_cast<float>(size), static_cast<float>(size)});
        asteroid->Enabled = true;
        return asteroid;
    }
    const auto asteroid = asteroidFactory.CreateAsteroid(position, size, direction, speed);
    asteroid->Enabled = true;
    return asteroid;
}

void AsteroidPool::ReleaseObject(Asteroid* Object)
{
    Object->Enabled = false;
    pool.push_back(Object);
}
