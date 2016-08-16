#pragma once
#include <iostream>
#include <map>
#include <SDL.h>
#include <SDL_Image.h>
#define LOG(x) std::cout << x << std::endl
namespace Turki {
	class ImageManager
	{
	public:
		ImageManager();
		~ImageManager();
		void setRenderer(SDL_Renderer* render);
		bool load(const char* id, const char* path);
		void draw(const char* id, int PosX, int PosY, int img_Width, int img_Height);
	private:
		SDL_Renderer* m_Render;
		SDL_Texture* m_Texture;
		std::map<const char*, SDL_Texture*> m_TextureMap;
	};

}