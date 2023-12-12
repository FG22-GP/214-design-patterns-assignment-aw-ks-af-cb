#pragma once
#include <memory>
#include <SDL_render.h>

class TextureFlyWeight
{
public:
    TextureFlyWeight(const char* asteroidFilePath, const char* projectileFilePath, const char* playerFilePath);

    static inline TextureFlyWeight* Instance;

    std::shared_ptr<SDL_Texture> AsteroidTexture;
    std::shared_ptr<SDL_Texture> ProjectileTexture;
    std::shared_ptr<SDL_Texture> PlayerTexture;

    SDL_Texture* CreateTexture(const char* filePath);
};
