﻿#pragma once
#include "../BaseClasses/Actor.h"
#include "../Interfaces/IVelocity.h"

class InputHandler;

class Player final : Actor, IVelocity
{
public:
    Player(SDL_Rect* rect, const char filePath[], int collisionRadius, float speed, float2 direction);
    ~Player() override = default;

    InputHandler* input_handler;

    void Fire();
    void Aim();
    void Move(float2 input);
};
