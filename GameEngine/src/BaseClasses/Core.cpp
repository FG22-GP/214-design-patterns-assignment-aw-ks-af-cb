#include "Core.h"

#include <iostream>
#include <SDL_timer.h>

#include "AsteroidPool.h"
#include "TextureFlyWeight.h"
#include "../Actors/Asteroid.h"
#include "../Collision/CollisionHandler.h"


Core::Core(SDL_Renderer* renderer): e(), LastFrameTime(0)
{
    Core::renderer = renderer;
    quit = false;

    projectilePool = new ProjectilePool(10);

    asteroidPool = new AsteroidPool(10);
    
    input_handler = new InputHandler();

    asteroidSpawner = new AsteroidSpawner(.2f, .7f, 800, MidPoint*2);

    TextureFlyWeight = new class TextureFlyWeight("./img/asteroid.png", "./img/projectile.png", "./img/Player.png");
}

Core::~Core()
{
    delete projectilePool;
    delete asteroidPool;
    delete asteroidSpawner;
    delete input_handler;
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
    
    player = std::make_unique<Player>(Rect, "./img/Player.png", 10, 1, float2(0,0));
    ui = std::make_unique<UI>();
    score_manager = std::make_unique<ScoreManager>();
    input_handler->MoveInput = std::bind(&Player::Move, player.get(), std::placeholders::_1);
    input_handler->MouseInput = std::bind(&Player::Fire, player.get(), std::placeholders::_1);
    input_handler->MouseMotion = std::bind(&Player::Aim, player.get(), std::placeholders::_1);
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
        if (!Actors[i]->Enabled) continue;
        Actors[i]->Update(DeltaTime);
    }

    asteroidSpawner->Update(DeltaTime);
}

void Core::Collision()
{
    if (!player) return;
    for (int i = 0; i < Actors.size(); ++i)
    {
        Asteroid* asteroid = dynamic_cast<Asteroid*>(Actors[i].get());

        if (!asteroid) continue;
        if (!asteroid->Enabled) continue;

        if (CollisionHandler::Collided(player->GetPosition(), player->CollisionRadius, asteroid->GetPosition(), asteroid->CollisionRadius))
        {
            asteroid->Destroy();
            player->TakeDamage(1);
            continue;
        }   
        
        for (int j = 0; j < Actors.size(); ++j)
        {
            if (!Actors[j]->Enabled) continue;
            if (Actors[i] == Actors[j]) continue;
            if (dynamic_cast<Player*>(Actors[j].get())) continue;
            if (dynamic_cast<Asteroid*>(Actors[j].get())) continue;
            
            Projectile* projectile = dynamic_cast<Projectile*>(Actors[j].get());
            
            if (!projectile) continue;
            if (CollisionHandler::Collided(projectile->GetPosition(), projectile->CollisionRadius, asteroid->GetPosition(), asteroid->CollisionRadius))
            {
                asteroid->Destroy();
                projectile->Destroy();
                score_manager->IncreaseScore(1);
            }
        }
    }
}

void Core::RenderPass(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 55, 66, 89, 255);
    SDL_RenderClear(renderer);
    
    ui->RenderText("Health: " + std::to_string(player->GetCurrentHealth()), 0, 0, { 255, 255, 255, 255 }, 24);
    ui->RenderText("Score: " + std::to_string(score_manager->GetCurrentScore()), 500, 0, {255, 255, 255, 255}, 24);
    ui->RenderText("HighScore: " + std::to_string(score_manager->GetHighScore()), 800, 0, {255, 255, 255, 255}, 24);
    
    if(player->GetCurrentHealth() <= 0)
    {
        ui->RenderText("GAME OVER!", MidPoint.X - 50, MidPoint.Y - 50, { 255, 255, 255, 255 }, 100);
    }
    
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

    if(player->GetCurrentHealth() <= 0)
    {
        score_manager->UpdateHighScore();
    }
}
