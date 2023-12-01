#pragma once
#include "../BaseClasses/Factory.h"
#include "..\Actors\Asteroid.h"

class AsteroidFactory : public Factory<Asteroid>
{
public:
    ~AsteroidFactory() override = default;
    Asteroid* CreateActor() override;
};
