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

    Actor* Player;

    float2* Input = new float2(0,0);
private:
    bool quit = false;
    float LastFrameTime;
public:
    void Start();
    void Inputs();
    void UpdateObjects();
    void Collision();
    void RenderPass(SDL_Renderer* renderer);

    bool Quit()
    {
        return quit;
    }
};
