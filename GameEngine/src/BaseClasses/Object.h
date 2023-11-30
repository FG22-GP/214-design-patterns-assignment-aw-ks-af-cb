#pragma once
#include <SDL_stdinc.h>

class Object
{
public:
    virtual ~Object();
    virtual void Update(float DeltaTime);
    
};
