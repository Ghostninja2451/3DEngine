#include"Renderer.h"
#include"Math/MathUtils.h"
#include<SDL_ttf.h>
#include<SDL_image.h>
#include<iostream>
void henry::Renderer::Startup()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
	}
	IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
	TTF_Init();
}

void henry::Renderer::Shutdown()
{
	IMG_Quit();
	TTF_Quit();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

void henry::Renderer::Update(float dt)
{

}

void henry::Renderer::Create(const std::string& name, int width, int height)
{
	window = SDL_CreateWindow(name.c_str(), 100, 100, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	if (window == nullptr)
	{
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
}

void henry::Renderer::BeginFrame()
{
	SDL_RenderClear(renderer);
}

void henry::Renderer::EndFrame()
{
	SDL_RenderPresent(renderer);

}





