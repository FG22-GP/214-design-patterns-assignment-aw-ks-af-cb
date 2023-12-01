#include "Core.h"

#include <SDL_timer.h>

Core::Core()
{
    quit = false;
}

void Core::Start()
{
    Player = new Actor();
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

    Player->Rect->x += Input->X;
    Player->Rect->y += Input->Y;
}

void Core::Collision()
{
}

void Core::RenderPass(SDL_Renderer* renderer)
{
    for (Actor* actor : Actors)
    {
        actor->RenderPass(renderer);
    }
    Player->RenderPass(renderer);
}
