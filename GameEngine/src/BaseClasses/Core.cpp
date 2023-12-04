#include "Core.h"

#include <iostream>
#include <SDL_timer.h>

Core::Core(): e(), LastFrameTime(0)
{
    quit = false;

    projectilePool = new ProjectilePool(1);
    
    projectile = projectilePool->AcquireObject({10, 10}, {0, 10});
    Actors.push_back(projectile);

    SDL_Rect* Rect = new SDL_Rect();

    Rect->x = 100;
    Rect->y = 100;
    Rect->w = 100;
    Rect->h = 100;
    
    Player = new Actor(Rect, "./img/charmander.png", 10);
}

Core::~Core()
{
    delete Player;
    delete projectilePool;
}

void Core::Start()
{

}

void Core::Inputs()
{
    // loop through all pending events from Windows (OS)
    while (SDL_PollEvent(&e))
    {
        // check, if it's an event we want to react to:
        switch (e.type) {
        case SDL_QUIT:
            {
                quit = true;
                break;
            }
        case SDL_KEYDOWN:
            {
                switch (e.key.keysym.sym)
                {
                case SDLK_DOWN:
                    {
                        Input->Y = 1;
                        break;
                    }
                case SDLK_UP:
                    {
                        Input->Y = -1;
                        break;
                    }
                case SDLK_RIGHT:
                    {
                        Input->X = 1;
                        break;
                    }
                case SDLK_LEFT:
                    {
                        Input->X = -1;
                        break;
                    }
                }
            }
            break;
            
        }
    }
}

void Core::UpdateObjects()
{
    float Time;
    
    Time = (SDL_GetTicks()) / 1000.f;

    float deltaTime = Time - LastFrameTime;
    LastFrameTime = Time;
    
    for (auto actor : Actors)
    {
        actor->Update(deltaTime);
    }
    
    Player->Update(deltaTime);
    
    Player->Rect->x += Input->X;
    Player->Rect->y += Input->Y;
}

void Core::Collision()
{
}

void Core::RenderPass(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 120, 60, 255, 255);
    SDL_RenderClear(renderer);
    
    for (Actor* actor : Actors)
    {
        actor->RenderPass(renderer);
    }
    Player->RenderPass(renderer);

    SDL_RenderPresent(renderer);
}
