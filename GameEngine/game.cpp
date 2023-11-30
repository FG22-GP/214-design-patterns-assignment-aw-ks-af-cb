//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

//Screen dimension constants
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

int main(int argc, char* args[])
{
#pragma region Setup
	//The window we'll be rendering to
	SDL_Window* window{};
	SDL_Renderer* renderer; // the window's rendering surface

	// initialize SDL_Image for image loading
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
	}

	// initialize SDL_ttf for font loading
	if (TTF_Init() == -1)
	{
		printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
	}

	//Start up SDL and create window
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO))
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return -1;
	}

	// Create Window and Renderer
	SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE, &window, &renderer);
	if (!window)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return -1;
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");  // make the scaled rendering look smoother.
	SDL_RenderSetLogicalSize(renderer, 1024, 768);
#pragma endregion

	SDL_Event e;
	bool quit = false;

	// while the user doesn't want to quit
	while (quit == false)
	{
		Uint32 time = SDL_GetTicks(); // can be used, to see, how much time in ms has passed since app start


		// loop through all pending events from Windows (OS)
		while (SDL_PollEvent(&e))
		{
			// check, if it's an event we want to react to:
			switch (e.type) {
				case SDL_QUIT: {
					quit = true;
				} break;
			}
		}
		
		// present screen (switch buffers)
		SDL_RenderPresent(renderer);

		SDL_Delay(0); // can be used to wait for a certain amount of ms
	}

	return 0;
}