#pragma once
#include <SDL.h>
#include "ImageManager/ImageManager.h"
#include "Sound/SoundManager.h"
#include "Math\Math.h"
#include "Graphic\Shaders.h"
#include "Graphic\Camera.h"
namespace Turki {
	class  Game
	{
	public:
		 Game();
		 ~Game();
		 void load(SDL_Renderer* render, mat4& pr_mat, Shaders& shader, Camera& cam);
		 void renderer();
		 void update();
		 void EventHandle();
		 float camera_Angle;
	private:
		SDL_Renderer* gameRenderer;
		ImageManager imageMan;
		SoundManager soundMan;
		mat4* m_pr_mat;
		Shaders* m_Shader;
		Camera* m_Cam;

	};




}