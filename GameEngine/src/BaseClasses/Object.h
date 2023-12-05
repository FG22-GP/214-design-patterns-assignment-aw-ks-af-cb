#pragma once
#include <SDL_stdinc.h>

class Object
{
public:
    virtual ~Object() = default;
    virtual void Update(float DeltaTime);
    
};
