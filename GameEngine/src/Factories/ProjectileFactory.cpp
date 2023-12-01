#include "ProjectileFactory.h"

Projectile* ProjectileFactory::CreateActor()
{
    return new Projectile();
}