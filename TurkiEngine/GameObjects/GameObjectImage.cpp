#include "GameObjectImage.h"
#include "../ImageManager/ImageManager.h"
namespace Turki {

	GameObjectImage::GameObjectImage()
	{
		
	}


	GameObjectImage::~GameObjectImage()
	{
	}
	void GameObjectImage::load(SDL_Renderer* render, ImageManager &imgManager)
	{
		gameRenderer = render;

		Obj_imgMan = &imgManager;
		Obj_imgMan->load(ObjectID, AssetPath);
	}
	void GameObjectImage::unload()
	{
		Obj_imgMan = NULL;
		gameRenderer = NULL;
	}
	void GameObjectImage::draw(int PosX, int PosY, int img_Width, int img_Height)
	{
		ObjectX = PosX;
		ObjectY = PosY;
		ObjectWidth = img_Width;
		ObjectHeight = img_Height;
		if (Obj_imgMan != NULL)
		{
			Obj_imgMan->draw(ObjectID, ObjectX, ObjectY, ObjectWidth, ObjectHeight);
		}
	}
}