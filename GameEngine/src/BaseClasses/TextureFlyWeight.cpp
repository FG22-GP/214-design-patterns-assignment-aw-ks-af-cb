#include "TextureFlyWeight.h"

#include <SDL_image.h>

#include "Core.h"

TextureFlyWeight::TextureFlyWeight(const char* asteroidFilePath, const char* projectileFilePath, const char* playerFilePath)
{
    Instance = this;
    
    AsteroidTexture = std::shared_ptr<SDL_Texture>(CreateTexture(asteroidFilePath));
    ProjectileTexture = std::shared_ptr<SDL_Texture>(CreateTexture(projectileFilePath));
    PlayerTexture = std::shared_ptr<SDL_Texture>(CreateTexture(playerFilePath));
}

SDL_Texture* TextureFlyWeight::CreateTexture(const char* filePath)
{
    SDL_Surface* surface = IMG_Load(filePath);

    SDL_Texture* texture = SDL_CreateTextureFromSurface(Core::renderer, surface);

    SDL_FreeSurface(surface);

    return texture;
}
