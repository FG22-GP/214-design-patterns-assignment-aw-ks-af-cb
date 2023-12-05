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
    std::cout << "Fire" << std::endl;
}

void Player::Aim(float2* mousePosition)
{
    std::cout << " " << mousePosition->X << " : " << mousePosition->Y << std::endl; 
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
