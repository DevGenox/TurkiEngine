#pragma once
#include <SDL.h>
#include "ImageManager/ImageManager.h"
#include "Sound/SoundManager.h"

namespace Turki {
	class  Game
	{
	public:
		 Game();
		 ~Game();
		 void load(SDL_Renderer* render);
		 void renderer();
		 void update();
		 void EventHandle();


	private:
		SDL_Renderer* gameRenderer;
		ImageManager imageMan;
		SoundManager soundMan;

	};




}