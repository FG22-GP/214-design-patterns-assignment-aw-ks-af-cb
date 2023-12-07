#include "UI.h"

#include <iostream>
#include <string>
#include <SDL_ttf.h>

#include "Core.h"

UI::UI() 
{
   _font = TTF_OpenFont("./font/Minecraft.ttf", 42);
   if (!_font)
   {
      std::cout << "Failed to load font: " << TTF_GetError() << std::endl;
   }
}

UI::~UI()
{
   
}

void UI::RenderHealth(int health)
{
   std::string healthText = "Health: " + std::to_string(health);

   SDL_Surface* Surface = TTF_RenderText_Solid_Wrapped(_font, healthText.c_str(), {255, 255, 255, 1}, 100);
   SDL_Texture* Texture = SDL_CreateTextureFromSurface(Core::renderer, Surface);

   
   SDL_Rect healthRect = {10, 10, Surface->w, Surface->h};
   
   SDL_RenderCopy(Core::renderer, Texture, nullptr, &healthRect);

   if (SDL_RenderCopy(Core::renderer, Texture, NULL, &healthRect) != 0)
   {
      std::cout << "Failed to render text: " << SDL_GetError() << std::endl;
   }
   SDL_FreeSurface(Surface);
   SDL_DestroyTexture(Texture);
}
