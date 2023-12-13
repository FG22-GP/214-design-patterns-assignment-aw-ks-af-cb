#pragma once
#include <SDL_events.h>

#include "Actor.h"
#include "ProjectilePool.h"
#include "ScoreManager.h"
#include "TextureFlyWeight.h"
#include "../Actors/Player.h"
#include "../InputHandler/InputHandler.h"
#include "UI.h"
#include "../Actors/AsteroidSpawner.h"

class AsteroidPool;

class Core
{
public:
    Core(SDL_Renderer* renderer);
    ~Core();

    SDL_Event e;

public:
    static inline std::vector<std::unique_ptr<Actor>> Actors;
    
    static inline ProjectilePool* projectilePool;

    static inline float2 MidPoint = float2(1024/2, 768/2);

    static inline AsteroidPool* asteroidPool;
    
    static inline InputHandler* input_handler;

    static inline SDL_Renderer* renderer;

    static inline std::unique_ptr<UI> ui;

    static inline TextureFlyWeight* TextureFlyWeight;

    static inline std::unique_ptr<ScoreManager> score_manager;
    
    static void RemoveBinding();

    static inline Player* player;
private:
    bool quit = false;
    bool restart = false;
    float LastFrameTime;

    SDL_Color whiteColor = {255, 255, 255, 255};

    AsteroidSpawner* asteroidSpawner;
public:
    void Start();
    void Inputs();
    void UpdateObjects();
    void Collision();
    void RenderPass(SDL_Renderer* renderer);
    void Cleanup();
    bool Quit()
    {
        return quit;
    }
    bool Restart()
    {
        return player->GetCurrentHealth() <= 0;
    }
    
};
