﻿#pragma once
#include "../BaseClasses/Actor.h"
#include "../Interfaces/IVelocity.h"

class Player final : Actor, IVelocity
{
public:
    Player(SDL_Rect* rect, const char filePath[], float collisionRadius, float speed, float2 direction);
    ~Player() override = default;

    void Fire();
    void Aim();
    void Move(float2 input);
};
