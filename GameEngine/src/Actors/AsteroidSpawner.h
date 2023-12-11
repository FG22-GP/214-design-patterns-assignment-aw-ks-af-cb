﻿#pragma once
#include <random>

#include "../BaseClasses/Actor.h"

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

    std::uniform_real_distribution<> cooldownDistr;
    std::uniform_real_distribution<> angleDistr;
    std::mt19937 gen;

protected:

    void SpawnNew();
public:
    void Update(float DeltaTime);
};
