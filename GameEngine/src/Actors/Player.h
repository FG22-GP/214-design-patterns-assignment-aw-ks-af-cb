#pragma once
#include "../BaseClasses/Actor.h"
#include "../Interfaces/IDamageable.h"
#include "../Interfaces/IVelocity.h"

class InputHandler;

class Player final : public Actor, IVelocity, IDamageable
{
public:
    Player(SDL_Rect* rect, const char filePath[], int collisionRadius, float speed, float2 direction);
    ~Player() override;
    
    void Fire(float2* mousePosition);
    void Aim(float2* mousePosition);
    void Move(float2* input);
    void Update(float DeltaTime) override;
    void TakeDamage(int health) override;

    int GetCurrentHealth();
    
protected:
    float2 AimPosition;

    float2 GetAimDirection();

    int MaxHealth = 3;
    int CurrentHealth;
};
