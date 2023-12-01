#pragma once
#include "../BaseClasses/Factory.h"
#include "../Actors/Projectile.h"

class ProjectileFactory : public Factory<Projectile>
{
public:
    ~ProjectileFactory() override = default;
    
    Projectile* CreateActor() override;
};
