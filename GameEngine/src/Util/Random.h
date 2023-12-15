#pragma once
#include <random>

class Random
{
public:
    Random();

    std::mt19937 gen;
    std::uniform_real_distribution<float> distribution;

    float GetFloatInRange(float MinInclusive, float MaxInclusive);
    int GetIntInRange(int MinInclusive, int MaxInclusive);
};
