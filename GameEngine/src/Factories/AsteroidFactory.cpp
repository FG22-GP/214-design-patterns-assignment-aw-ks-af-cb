#include "AsteroidFactory.h"
#include "..\Actors\Asteroid.h"

Asteroid* AsteroidFactory::CreateActor()
{
    return new Asteroid();
}