#pragma once
#include "../BaseClasses/Factory.h"
#include "..\Actors\Asteroid.h"

class AsteroidFactory : public Factory
{
public:
    ~AsteroidFactory() override = default;
    Actor* CreateActor() override;
};
