#include "AsteroidFactory.h"
#include "..\Actors\Asteroid.h"

Actor* AsteroidFactory::CreateActor()
{
    return new Asteroid();
}