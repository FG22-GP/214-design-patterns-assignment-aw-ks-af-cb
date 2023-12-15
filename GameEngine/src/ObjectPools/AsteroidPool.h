#pragma once
#include <vector>

#include "../Actors/Asteroid.h"
#include "../Factories/AsteroidFactory.h"

class AsteroidPool
{
private:
    std::vector<Asteroid*> pool;
    AsteroidFactory asteroidFactory;

public:
    AsteroidPool(size_t poolSize);

    Asteroid* AcquireObject(const float2 position, const int size, const float2 direction, const float speed);
    void ReleaseObject(Asteroid* Object);
};
