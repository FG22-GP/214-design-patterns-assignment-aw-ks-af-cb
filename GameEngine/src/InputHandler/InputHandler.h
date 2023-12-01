#pragma once
#include <SDL.h>
#include <functional>

class InputHandler
{
public:

    using MoveInputCallBack = std::function<void(float2)>;
    using MouseInputCallBack = std::function<void(float2)>;
    MoveInputCallBack MoveInput;
    MouseInputCallBack MouseInput;
    float2* Input;
    float2* MousePosition;
    
    bool mouseClicked;

    bool LeftKey = false;
    bool RightKey = false;
    bool UpKey = false;
    bool DownKey = false;
    
    InputHandler()
    {
        Input = new float2();
        MousePosition = new float2();
        mouseClicked = false;
    }
    
    void HandleKeyInputs(SDL_KeyCode key_code)
    {
        const Uint8* keyboardState = SDL_GetKeyboardState(NULL);

        switch (key_code)
        {
        case SDLK_w:
            if(keyboardState[SDLK_w])
            {
                UpKey = true;
            }
            break;
        case SDLK_s:
            if(keyboardState[SDLK_s])
            {
                DownKey = true;
            }
            break;
        case SDLK_a:
            if(keyboardState[SDLK_a])
            {
                LeftKey= true;
            }
            break;
        case SDLK_d:
            if(keyboardState[SDLK_d])
            {
                RightKey = true;
            }
            break;
        }
    }

    void HandleMouseInput(float2* MouseInput)
    {
        switch (MouseInput)
        {
        case SDL_MOUSEBUTTONDOWN:
            mouseClicked = true;
            break;
        case SDL_MOUSEBUTTONUP:
            mouseClicked = false;
            break;
        case SDL_MOUSEMOTION:
            MousePosition->X = MouseInput->X;
            MousePosition->Y = MouseInput->Y;
            break;
        }
    }

    void HandleInputEvents(float2 keyInput, float2 mouseInput)
    {
        if(UpKey)
            keyInput.Y += 1;
        else if(DownKey)
            keyInput.Y -= 1;
        else if(LeftKey)
            keyInput.X += 1;
        else if(RightKey)
            keyInput.X -= 1;
        
        if(MoveInput)
            MoveInput(keyInput);

        if(MouseInput)
            MouseInput(mouseInput);
        
        UpKey = false;
        DownKey = false;
        LeftKey = false;
        RightKey = false;

        keyInput = float2(0, 0);
    }
};