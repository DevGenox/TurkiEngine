#include "Game.h"
#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))
namespace Turki {
	Game::Game()
	{

	}

	Game::~Game()
	{
	}

	void Game::load(SDL_Renderer* render)
	{
		gameRenderer = render;
		imageMan.setRenderer(gameRenderer);
	


	}
	void Game::renderer()
	{
		/*	int x, y; //Mouse Pozisyonunu al.
			SDL_GetMouseState(&x, &y);

			SDL_SetRenderDrawColor(gameRenderer, 183, 183, 183, 255);
			SDL_RenderClear(gameRenderer);
			*/
		
		EventHandle();

		
		//	SDL_RenderPresent(gameRenderer);

		//	SDL_Delay(5);

		}
	
	
	void Game::update()
	{
		renderer();
	}
	void Game::EventHandle()
	{
		SDL_Event event;
		if (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_MOUSEBUTTONDOWN:
				if (SDL_BUTTON(SDL_BUTTON_LEFT))
					std::cout << " SOL týklandý" << std::endl;
		
				break;
			case SDL_KEYDOWN:
				std::cout << SDL_GetKeyName(event.key.keysym.sym) << " Basýldý" << std::endl;
				break;
			case SDL_QUIT:

				break;
			default:
				break;
			}
		}

	}

}