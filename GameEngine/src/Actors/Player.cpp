#include "Player.h"

#include <iostream>

#include "../BaseClasses/Core.h"
#include "../InputHandler/InputHandler.h"


Player::Player(
    SDL_Rect* rect,
    const char filePath[],
    int collisionRadius,
    float speed,
    float2 direction) : Actor(rect, filePath, collisionRadius), IVelocity(speed, direction)
{
}

Player::~Player()
{
    Core::RemoveBinding();
}

void Player::Fire(float2* mousePosition)
{
    float2 aimDirection = GetAimDirection();

    float2 spawnPosition = GetPosition() + aimDirection * 100;
    
    // Core::projectilePool->AcquireObject(spawnPosition, aimDirection);
}

void Player::Aim(float2* mousePosition)
{
    AimPosition = *mousePosition;
}

void Player::Move(float2* input)
{
    const float2 Position = GetPosition();
    SetPosition(Position + *input * DeltaTime);
}

void Player::Update(float DeltaTime)
{
    Actor::Update(DeltaTime);
}

float2 Player::GetAimDirection()
{
    return (AimPosition - GetPosition()).Normalize();
}
