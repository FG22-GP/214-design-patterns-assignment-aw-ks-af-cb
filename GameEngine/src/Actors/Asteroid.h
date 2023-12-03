#pragma once

#include "../BaseClasses/Actor.h"
#include "../Interfaces/IVelocity.h"

class Asteroid final : public Actor, public IVelocity
{
public:
    Asteroid(SDL_Rect* rect, const char fielPath[], float collisionRadius, float speed, float2 direction);
    ~Asteroid() override = default;

    void Update(float deltaTime) override;
};
