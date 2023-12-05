#include "Core.h"

#include <iostream>
#include <SDL_timer.h>


Core::Core(): e(), LastFrameTime(0)
{
    quit = false;

    projectilePool = new ProjectilePool(10);
    
    Actors.push_back(std::move(projectilePool->AcquireObject({10, 10}, {100, 10})));
    
    input_handler = new InputHandler();
}

Core::~Core()
{
    delete projectilePool;
}

void Core::RemoveBinding()
{
    input_handler->MouseInput = NULL;
    input_handler->MoveInput = NULL;
    input_handler->MouseMotion = NULL;
}

void Core::Start()
{
    SDL_Rect* Rect = new SDL_Rect();

    Rect->x = 100;
    Rect->y = 100;
    Rect->w = 100;
    Rect->h = 100;

    Player* Player = new class Player(Rect, "./img/charmander.png", 10, 1, float2(0,0));
    input_handler->MoveInput = std::bind(&Player::Move, Player, std::placeholders::_1);
    input_handler->MouseInput = std::bind(&Player::Fire, Player, std::placeholders::_1);
    input_handler->MouseMotion = std::bind(&Player::Aim, Player, std::placeholders::_1);
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
                input_handler->HandleKeyDownInputs(e.key.keysym.sym);
                break;
            }
        case SDL_KEYUP:
            {
                input_handler->HandleKeyUpInputs(e.key.keysym.sym);
                break;
            }
        case SDL_MOUSEBUTTONDOWN:
            {
                input_handler->HandleMouseButtonDownInput(e.button);
                break;
            }
        case SDL_MOUSEBUTTONUP:
            {
                input_handler->HandleMouseButtonUpInput(e.button);
                break;
            }
        case SDL_MOUSEMOTION:
            {
                input_handler->HandleMouseMotionInput(e.motion);
                break;
            }
            
        }
    }
    input_handler->HandleInputEvents();
}

void Core::UpdateObjects()
{
    float Time;
    
    Time = (SDL_GetTicks()) / 1000.f;

    float deltaTime = Time - LastFrameTime;
    LastFrameTime = Time;
    
    for (int i = 0; i < Actors.size(); i++)
    {
        Actors[i].get()->Update(deltaTime);
    }
}

void Core::Collision()
{
}

void Core::RenderPass(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 120, 60, 255, 255);
    SDL_RenderClear(renderer);
    
    for (int i = 0; i < Actors.size(); i++)
    {
        Actors[i]->RenderPass(renderer);
    }


    SDL_RenderPresent(renderer);
}

void Core::Cleanup()
{
    for (int i = 0; i < Actors.size(); i++)
    {
        if (Actors[i]->ShouldBeDestroyed)
        {
            Actors.erase(Actors.begin() + i);
            
        }
    }
}
