#pragma once
#include <SDL.h>
#include "../ImageManager/ImageManager.h"
namespace Turki {
	class GameObjectImage
	{
	public:
		GameObjectImage();
		~GameObjectImage();
		int ObjectX;
		int ObjectY;
		int ObjectWidth;
		int ObjectHeight;
		const char* ObjectID;
		const char* AssetPath;
		ImageManager* Obj_imgMan;
		SDL_Renderer* gameRenderer;
		void load(SDL_Renderer * render, ImageManager &imgManager);
		void unload();
		void draw(int PosX, int PosY, int img_Width, int img_Height);
	private:

	};

}