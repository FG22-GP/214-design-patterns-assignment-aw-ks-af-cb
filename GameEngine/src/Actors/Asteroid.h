﻿#pragma once

#include "../BaseClasses/Actor.h"
#include "../Interfaces/IVelocity.h"

class Asteroid final : public Actor, public IVelocity
{
public:
    Asteroid(float speed, float2 direction);
    ~Asteroid() override = default;

    void Update(float DeltaTime) override;
    
};
