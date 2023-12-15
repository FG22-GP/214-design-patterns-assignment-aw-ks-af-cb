#pragma once
#include <random>

#include "../BaseClasses/Actor.h"
#include "../BaseClasses/Random.h"

class AsteroidSpawner
{
public:
    AsteroidSpawner(float minSpawnTime, float maxSpawnTime, float radius, float2 screenSize);
private:
    float radius;
    float maxSpawnTime;
    float minSpawnTIme;

    float time;

    float cooldown;

    float2 screenSize;

    float2 midPoint;

    float totalElapsedTime;
    
    Random random;

protected:

    void SpawnNew();
public:
    void Update(float DeltaTime);
};
