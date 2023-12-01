#pragma once
#include <list>
#include <SDL_events.h>

#include "Actor.h"

class Core
{
public:
    Core();

    SDL_Event e;

public:
    std::list<Actor*> Actors;


private:
    bool quit = false;
    float LastFrameTime;
public:
    void Start();
    void Inputs();
    void UpdateObjects();
    void Collision();

    bool Quit()
    {
        return quit;
    }
};
