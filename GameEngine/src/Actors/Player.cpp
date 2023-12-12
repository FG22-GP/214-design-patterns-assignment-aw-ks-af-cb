#include "Player.h"
#include "../BaseClasses/Core.h"

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
    SetPosition(Position + *input * DeltaTime * 300);
}

void Player::Update(float DeltaTime)
{
    Actor::Update(DeltaTime);
    float2 position = GetPosition();
    const float2 size = GetSize();

    float x = XLoopCheck(position, size);
    float y = YLoopCheck(position, size);
    
    SetPosition(float2(x,y));
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

float Player::YLoopCheck(float2 position, float2 size)
{
    float2 ScreenSize = Core::MidPoint * 2.f;
    if (position.Y <= -size.Y + 50)
    {
        return ScreenSize.Y + size.Y - 51;
    }

    if (position.Y >= ScreenSize.Y + size.Y - 50)
    {
        return -size.Y + 51;
    }

    return position.Y;
}

float Player::XLoopCheck(float2 position, float2 size)
{
    float2 ScreenSize = Core::MidPoint * 2.f;
    if (position.X <= -size.X + 50)
    {
        return ScreenSize.X + size.X - 51;
    }

    if (position.X >= ScreenSize.X + size.X - 50)
    {
        return -size.X + 51;
    }

    return position.X;
}
