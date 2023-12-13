#pragma once
#include <SDL.h>
#include <functional>
#include <iostream>

class InputHandler
{
public:

    using MoveInputCallBack = std::function<void(float2*)>;
    using MouseInputCallBack = std::function<void(float2*)>;
    using MouseMotionInputCallBack = std::function<void(float2*)>;
    
    MoveInputCallBack MoveInput;
    MouseInputCallBack MouseInput;
    MouseMotionInputCallBack MouseMotion;
    
    float2* Input;
    float2* MousePosition;
    
    bool mouseClicked = false;

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
    
    void HandleKeyDownInputs(SDL_Keycode key_code)
    {
        switch (key_code)
        {
        case SDLK_w:
            UpKey = true;
            break;
        case SDLK_s:
            DownKey = true;
            break;
        case SDLK_a:
            LeftKey= true;
            break;
        case SDLK_d:
            RightKey = true;
            break;
        }
    }

    void HandleKeyUpInputs(SDL_Keycode key_code)
    {
        switch (key_code)
        {
        case SDLK_w:
            UpKey = false;
            break;
        case SDLK_s:
            DownKey = false;
            break;
        case SDLK_a:
            LeftKey = false;
            break;
        case SDLK_d:
            RightKey = false;
            break;
        }
    }

    void HandleMouseButtonDownInput(SDL_MouseButtonEvent MouseCode)
    {
        if (MouseCode.button == SDL_BUTTON_LEFT)
        {
            mouseClicked = true;
        }
    }
    
    void HandleMouseButtonUpInput(SDL_MouseButtonEvent MouseCode)
    {
        if (MouseCode.button == SDL_BUTTON_LEFT)
        {
            mouseClicked = false;
        }
    }

    void HandleMouseMotionInput(SDL_MouseMotionEvent MouseCode)
    {
        MousePosition->X = static_cast<float>(MouseCode.x);
        MousePosition->Y = static_cast<float>(MouseCode.y);
    }

    void HandleInputEvents()
    {
        Input->X = Input->Y = 0;
        
        if(UpKey)
            Input->Y += -1;
        if(DownKey)
            Input->Y += 1;
        if(LeftKey)
            Input->X += -1;
        if(RightKey)
            Input->X += 1;
        
        
        if(MoveInput)
            MoveInput(Input);
        
        if(MouseMotion)
            MouseMotion(MousePosition);

        if(MouseInput && mouseClicked)
            MouseInput(MousePosition);
    }
};