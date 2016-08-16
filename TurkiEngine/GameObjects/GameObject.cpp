#include "GameObject.h"
#include "../ImageManager/ImageManager.h"
namespace Turki {

	GameObject::GameObject()
	{
		
	}


	GameObject::~GameObject()
	{
	}
	void GameObject::load(SDL_Renderer* render, ImageManager &imgManager)
	{
		gameRenderer = render;

		Obj_imgMan = &imgManager;
		Obj_imgMan->load(ObjectID, AssetPath);
	}
	void GameObject::unload()
	{
		Obj_imgMan = NULL;
		gameRenderer = NULL;
	}
	void GameObject::draw(int PosX, int PosY, int img_Width, int img_Height)
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