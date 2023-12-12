#include "Player.h"

#include <iostream>

#include "../BaseClasses/Core.h"
#include "../BaseClasses/UI.h"
#include "../InputHandler/InputHandler.h"


Player::Player(
    SDL_Rect* rect,
    const char filePath[],
    int collisionRadius,
    float speed,
    float2 direction) : Actor(rect, collisionRadius), IVelocity(speed, direction)
{
    CurrentHealth = MaxHealth;
}

Player::~Player()
{
    Core::RemoveBinding();
}

void Player::Fire(float2* mousePosition)
{
    float2 aimDirection = GetAimDirection();

    float2 spawnPosition = GetPosition() + aimDirection * 40;

    Core::projectilePool->AcquireObject(spawnPosition, aimDirection);
}

void Player::Aim(float2* mousePosition)
{
    AimPosition = *mousePosition;
}

void Player::Move(float2* input)
{
    const float2 Position = GetPosition();
    SetPosition(Position + *input * DeltaTime * 100);
}

void Player::Update(float DeltaTime)
{
    Actor::Update(DeltaTime);
}

void Player::TakeDamage(int health)
{
    CurrentHealth -= health;

    if(CurrentHealth <= 0)
    {
        Destroy();
    }
}

std::shared_ptr<SDL_Texture> Player::GetTexture()
{
    return TextureFlyWeight::Instance->PlayerTexture;
}

int Player::GetCurrentHealth()
{
    if(CurrentHealth >= 0)
    {
        return CurrentHealth;
    }
    return 0;
}

float2 Player::GetAimDirection()
{
    return (AimPosition - GetPosition()).Normalize();
}
