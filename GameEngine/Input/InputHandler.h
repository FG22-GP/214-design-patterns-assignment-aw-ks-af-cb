#pragma once

#include <SDL.h>
#include <functional>

class InputHandler
{
public:
    using KeyPressEvent = std::function<void(SDL_Keycode)>;
    using MouseClickEvent = std::function<void(int, int)>;

    InputHandler(){}

    // Register function to handle key events
    void RegisterKeyPressEvent(KeyPressEvent callback)
    {
        keyPressEvent = callback;
    }
    // Register function to handle mouse event
    void ReigsterMousePressEvent(MouseClickEvent callback)
    {
        mouseClickEvent = callback;
    }

    void HandleEvents()
    {
        SDL_Event event;

        while(SDL_PollEvent(&event) != 0)
        {
            switch(event.type)
            {
            case SDL_KEYDOWN:
                if(keyPressEvent)
                {
                    keyPressEvent(event.key.keysym.sym);
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                if(event.button.button == SDL_BUTTON_LEFT && mouseClickEvent)
                {
                    mouseClickEvent(event.button.x, event.button.y);
                }
                break;
            }
        }
    }
private:
    KeyPressEvent keyPressEvent;
    MouseClickEvent mouseClickEvent;
};
