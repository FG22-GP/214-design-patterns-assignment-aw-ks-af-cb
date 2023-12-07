#pragma once

#include <SDL_ttf.h>

class UI
{
public:

    UI();
    ~UI();
    
    void RenderHealth(int health);

private:
    TTF_Font* _font;
};
