#include "Random.h"

#include <chrono>

Random::Random()
{
    std::default_random_engine eng;
    long long int t = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    eng.seed(t);
    gen = std::mt19937(eng);
    distribution = std::uniform_real_distribution<float> (0, 1);
}

float Random::GetFloatInRange(float MinInclusive, float MaxInclusive)
{
    return std::lerp(MinInclusive, MaxInclusive, distribution(gen));
}

int Random::GetIntInRange(int MinInclusive, int MaxInclusive)
{
    return static_cast<int>(std::round(std::lerp(MinInclusive, MaxInclusive, distribution(gen)))); 
}
