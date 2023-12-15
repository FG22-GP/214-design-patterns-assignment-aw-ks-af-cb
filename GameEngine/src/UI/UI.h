#pragma once

#include <SDL_ttf.h>
#include <string>

class UI
{
public:

    UI();
    ~UI();
    
    void RenderText(const std::string& text, int x, int y, SDL_Color color, int fontSize);

private:
    TTF_Font* _font;
};
