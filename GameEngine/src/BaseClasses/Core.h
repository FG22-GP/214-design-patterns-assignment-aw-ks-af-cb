#pragma once
#include <list>
#include <SDL_events.h>

#include "Actor.h"
#include "ProjectilePool.h"

class Core
{
public:
    Core();
    ~Core();

    SDL_Event e;

public:
    std::vector<Actor*> Actors;

    Actor* Player;

    ProjectilePool* projectilePool;

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
