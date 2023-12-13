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

    random = Random();

    cooldown = random.GetFloatInRange(minSpawnTime, maxSpawnTime);
    time = 0;
}

void AsteroidSpawner::Update(float DeltaTime)
{
    time += DeltaTime;

    if (time >= cooldown)
    {
        time = 0;
        cooldown = random.GetFloatInRange(minSpawnTIme, maxSpawnTime);
        SpawnNew();
    }
}

void AsteroidSpawner::SpawnNew()
{
    const double angle = random.GetFloatInRange(0, 3.14159265358979323846264f * 2.f);
    float2 position = {static_cast<float>(std::cos(angle)), static_cast<float>(std::sin(angle))};
    position = position.Normalize();

    position *= radius;
    position += midPoint;
    float xRand = random.GetFloatInRange(0.f,1.f);
    float yRand = random.GetFloatInRange(0.f,1.f);

    
    float x = std::lerp(100.f, screenSize.X - 100.f, xRand);
    float y = std::lerp(100.f, screenSize.Y - 100.f, yRand);
    float2 target = {x,y};

    float2 direction = (target - position).Normalize();
    const int size = random.GetIntInRange(50, 100);
    const float speed = random.GetFloatInRange(325.f, 425.f);
    
    Asteroid* asteroid = Core::asteroidPool->AcquireObject(position, size, direction, speed);
    asteroid->Rotation = random.GetFloatInRange(0, 360);
    asteroid->RotationSpeed = random.GetFloatInRange(-150, 150);
}