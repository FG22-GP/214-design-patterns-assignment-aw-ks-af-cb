#include "Player.h"

#include <iostream>

#include "../InputHandler/InputHandler.h"


Player::Player(
    SDL_Rect* rect,
    const char filePath[],
    int collisionRadius,
    float speed,
    float2 direction) : Actor(rect, filePath, collisionRadius), IVelocity(speed, direction)
{
}

void Player::Fire()
{
    
}

void Player::Aim()
{
    
}

void Player::Move(float2* input)
{
    Rect->x += input->X;
    Rect->y += input->Y;
}

void Player::Update(float DeltaTime)
{
    Actor::Update(DeltaTime);

}
