#pragma once
#include <list>
#include <SDL_events.h>

#include "Actor.h"
#include "ProjectilePool.h"
#include "../Actors/Player.h"
#include "../InputHandler/InputHandler.h"

class Core
{
public:
    Core();
    ~Core();

    SDL_Event e;

public:
    static inline std::vector<std::unique_ptr<Actor>> Actors;
    
    static inline ProjectilePool* projectilePool;
    
    static inline InputHandler* input_handler;

    static void RemoveBinding();
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
