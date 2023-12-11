﻿#pragma once
#include <memory>

#include "../Actors/Asteroid.h"

class AsteroidFactory
{
private:
    const char* filePath;
    
public:
    AsteroidFactory();
    ~AsteroidFactory() = default;
    
    Asteroid* CreateAsteroid(float2 position, float2 size, float2 direction, float speed) const;
};
