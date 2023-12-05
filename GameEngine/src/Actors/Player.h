#pragma once
#include "../BaseClasses/Actor.h"
#include "../Interfaces/IVelocity.h"

class InputHandler;

class Player final : public Actor, IVelocity
{
public:
    Player(SDL_Rect* rect, const char filePath[], int collisionRadius, float speed, float2 direction);
    ~Player() override = default;
    
    void Fire(float2* mousePosition);
    void Aim(float2* mousePosition);
    void Move(float2* input);
    void Update(float DeltaTime) override;
};
