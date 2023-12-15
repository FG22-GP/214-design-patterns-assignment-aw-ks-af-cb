#include "UI.h"

#include <iostream>
#include <string>
#include <SDL_ttf.h>
#include <SDL_surface.h>

#include "Core.h"

UI::UI() 
{
   _font = TTF_OpenFont("./font/Minecraft.ttf", 24);
}

UI::~UI()
{
   TTF_CloseFont(_font);
}

void UI::RenderText(const std::string& text, int x, int y, SDL_Color color, int fontSize)
{
   TTF_SetFontSize(_font, fontSize);
   if(!_font)
   {
      std::cout << "Failed to load font: " << TTF_GetError() << std::endl;
      return;
   }

   SDL_Surface* surface = TTF_RenderText_Blended(_font, text.c_str(), color);
   SDL_Texture* texture = SDL_CreateTextureFromSurface(Core::renderer, surface);

   SDL_Rect destRect = { x, y, surface->w, surface->h };
   SDL_RenderCopy(Core::renderer, texture, nullptr, &destRect);

   SDL_FreeSurface(surface);
   SDL_DestroyTexture(texture);
}
