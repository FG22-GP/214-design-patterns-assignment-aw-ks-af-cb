#include "Core.h"

#include <SDL_timer.h>

Core::Core()
{
    quit = false;
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
        case SDL_QUIT: {
                quit = true;
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
}

void Core::Collision()
{
}
