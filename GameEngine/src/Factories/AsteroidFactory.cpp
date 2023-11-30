#include "AsteroidFactory.h"

Asteroid* AsteroidFactory::CreateActor()
{
    return new Asteroid();
}