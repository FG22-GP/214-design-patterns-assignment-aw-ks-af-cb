#include "ProjectileFactory.h"

Actor* ProjectileFactory::CreateActor()
{
    return new Projectile();
}