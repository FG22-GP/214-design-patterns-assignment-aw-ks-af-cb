#pragma once
#include <SDL.h>
#include <functional>

class InputHandler
{
public:

    using MoveInputCallBack = std::function<void(float2)>;

    MoveInputCallBack MoveInput;
    
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

    void HandleInputEvents(float2 Input)
    {
        if(UpKey)
            Input.Y += 1;
        else if(DownKey)
            Input.Y -= 1;
        else if(LeftKey)
            Input.X += 1;
        else if(RightKey)
            Input.X -= 1;
        
        if(MoveInput)
        MoveInput(Input);

        Input = float2(0, 0);
    }
    
};