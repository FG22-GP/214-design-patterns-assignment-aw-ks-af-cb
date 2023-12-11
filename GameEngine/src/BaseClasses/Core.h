#pragma once
#include <SDL_events.h>

#include "Actor.h"
#include "ProjectilePool.h"
#include "../Actors/Player.h"
#include "../InputHandler/InputHandler.h"
#include "UI.h"

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


    static inline AsteroidPool* asteroidPool;
    
    static inline InputHandler* input_handler;

    static inline SDL_Renderer* renderer;

    static inline std::unique_ptr<UI> ui;
    
    static void RemoveBinding();

    static inline std::unique_ptr<Player> player;
private:
    bool quit = false;
    float LastFrameTime;
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
};
