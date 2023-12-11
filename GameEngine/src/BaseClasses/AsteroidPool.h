#pragma once
#include <vector>

#include "../Actors/Asteroid.h"
#include "../Factories/AsteroidFactory.h"

class AsteroidPool
{
private:
    std::vector<Asteroid*> pool;
    AsteroidFactory projectileFactory;

public:
    AsteroidPool(size_t poolSize);

    Asteroid* AcquireObject(float2 position, float2 direction);
    void ReleaseObject(Asteroid* Object);
};
