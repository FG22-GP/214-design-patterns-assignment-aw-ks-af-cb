#include "Core.h"

#include <iostream>
#include <SDL_timer.h>

Core::Core(): e(), LastFrameTime(0)
{
    quit = false;

    projectilePool = new ProjectilePool(10);

    auto projectile = projectilePool->AcquireObject({10, 10}, {10, 10});
    Actors.push_back(projectile);

    SDL_Rect* Rect = new SDL_Rect();

    Rect->x = 100;
    Rect->y = 100;
    Rect->w = 100;
    Rect->h = 100;
    
    Player = new Actor(Rect, "./img/pikachu.png", 10.f);
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
            }
        case SDL_KEYDOWN:
            {
                switch (e.key.keysym.sym)
                {
                case SDLK_DOWN:
                    {
                        Input->Y = 1;
                    }
                case SDLK_UP:
                    {
                        Input->Y = -1;
                    }
                case SDLK_RIGHT:
                    {
                        Input->X = 1;
                    }
                case SDLK_LEFT:
                    {
                        Input->X = -1;
                    }
                    break;
                }
            }
            break;
            
        }
    }
}

void Core::UpdateObjects()
{
    float Time = static_cast<float>(SDL_GetTicks()) / 1000.f;
    
    float deltaTime = Time - LastFrameTime;
    LastFrameTime = Time;
    
    for (Actor* actor : Actors)
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
