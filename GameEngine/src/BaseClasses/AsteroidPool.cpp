#include "AsteroidPool.h"

#include <iostream>

AsteroidPool::AsteroidPool(size_t poolSize)
{
    // Initialize the object pool with objects
    for (size_t i = 0; i < poolSize; ++i)
    {
        const auto asteroid = asteroidFactory.CreateAsteroid({0, 0}, {50, 50}, {0,0}, 400);
        asteroid->Enabled = false;
        pool.push_back(asteroid);
    }
}

Asteroid* AsteroidPool::AcquireObject(float2 position, float2 direction)
{
    if (!pool.empty())
    {
        const auto asteroid = pool.back();
        pool.pop_back();
        asteroid->SetPosition(position);
        asteroid->direction = direction;
        asteroid->Enabled = true;
        return asteroid;
    }
    const auto asteroid = asteroidFactory.CreateAsteroid(position, float2(1,1), direction, 400);
    asteroid->Enabled = true;
    return asteroid;
}

void AsteroidPool::ReleaseObject(Asteroid* Object)
{
    Object->Enabled = false;
    pool.push_back(Object);
}
