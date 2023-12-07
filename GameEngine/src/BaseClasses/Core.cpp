#include "Core.h"

#include <iostream>
#include <SDL_timer.h>

#include "../Actors/Asteroid.h"
#include "../Collision/CollisionHandler.h"


Core::Core(SDL_Renderer* renderer): e(), LastFrameTime(0)
{
    quit = false;

    projectilePool = new ProjectilePool(10);
    
    input_handler = new InputHandler();

    Core::renderer = renderer;
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
    const Uint32 CurrentTime = SDL_GetTicks();

    const float DeltaTime = (CurrentTime - LastFrameTime) / 1000.0f;
    
    LastFrameTime = CurrentTime;
    
    for (int i = 0; i < Actors.size(); i++)
    {
        // std::cout <<  << std::endl;
        if (!Actors[i]->Enabled) continue;
        Actors[i]->Update(DeltaTime * 100);
    }
}

void Core::Collision()
{
    for (int i = 0; i < Actors.size(); ++i)
    {
        Asteroid* asteroid = dynamic_cast<Asteroid*>(Actors[i].get());

        if (!asteroid) continue;
        
        for (int j = 0; j < Actors.size(); ++j)
        {
            Player* player = dynamic_cast<Player*>(Actors[j].get());
            
            if (!player) continue;

            if (CollisionHandler::Collided(player->GetPosition(), player->CollisionRadius, asteroid->GetPosition(), asteroid->CollisionRadius))
            {
                player->TakeDamage(1);
                //Destroy asteroid as well
            }
        }

        for (int k = 0; k < Actors.size(); ++k)
        {
            Projectile* projectile = dynamic_cast<Projectile*>(Actors[k].get());

            if(!projectile) continue;

            if(CollisionHandler::Collided(projectile->GetPosition(), projectile->CollisionRadius, asteroid->GetPosition(), asteroid->CollisionRadius))
            {
                //Destroy both projectiles and the asteroid? 
            }
        }
    }
}

void Core::RenderPass(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 120, 60, 255, 255);
    SDL_RenderClear(renderer);
    
    for (int i = 0; i < Actors.size(); i++)
    {
        if (!Actors[i]->Enabled) continue;
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
