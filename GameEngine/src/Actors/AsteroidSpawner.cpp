#include "AsteroidSpawner.h"
#include "../BaseClasses/AsteroidPool.h"
#include "../BaseClasses/Core.h"
#include <bit>

AsteroidSpawner::AsteroidSpawner(float minSpawnTime, float maxSpawnTime, float radius, float2 screenSize)
{
    this->minSpawnTIme = minSpawnTime;
    this->maxSpawnTime = maxSpawnTime;
    this->radius = radius;
    this->screenSize = screenSize;

    midPoint = screenSize / 2.f;

    std::random_device rd;
    gen = std::mt19937(rd());
    cooldownDistr = std::uniform_real_distribution<> (minSpawnTime, maxSpawnTime);
    angleDistr = std::uniform_real_distribution<> (0, 3.14159265358979323846264f * 2.f);
    rotationDistr = std::uniform_int_distribution<> (0, 359);
    rotationSpeedDistr = std::uniform_int_distribution<> (-100, 100);

    cooldown = cooldownDistr(gen);
    time = 0;
}

void AsteroidSpawner::Update(float DeltaTime)
{
    time += DeltaTime;

    if (time >= cooldown)
    {
        time = 0;
        cooldown = cooldownDistr(gen);
        SpawnNew();
    }
}

void AsteroidSpawner::SpawnNew()
{
    const double angle = angleDistr(gen);
    float2 position = {static_cast<float>(std::cos(angle)), static_cast<float>(std::sin(angle))};
    position = position.Normalize();

    position *= radius;
    position += midPoint;
    double xRand = static_cast<double>(rand()) / RAND_MAX;
    double yRand = static_cast<double>(rand()) / RAND_MAX;

    
    float x = std::lerp(100, screenSize.X - 100, xRand);
    float y = std::lerp(100, screenSize.Y - 100, yRand);
    float2 target = {x,y};

    float2 direction = (midPoint - position).Normalize();

    
    Asteroid* asteroid = Core::asteroidPool->AcquireObject(position, direction);
    asteroid->Rotation = static_cast<int>(rotationDistr(gen));
    asteroid->RotationSpeed = static_cast<int>(rotationSpeedDistr(gen));
}