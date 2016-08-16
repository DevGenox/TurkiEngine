#include "ImageManager.h"


namespace Turki {
	ImageManager::ImageManager()
	{
	
	}


	ImageManager::~ImageManager()
	{
		SDL_DestroyTexture(m_Texture);
	}
	void ImageManager::setRenderer(SDL_Renderer* render)
	{
		m_Render = render;
	}
	bool ImageManager::load(const char* id, const char* path)
	{
		SDL_Surface* surface = IMG_Load(path);
		
		if (surface == 0)
		{
			return false;
		}
			m_Texture = SDL_CreateTextureFromSurface(m_Render, surface);
			SDL_FreeSurface(surface);

			if (m_Texture != 0)
			{

				m_TextureMap[id] = m_Texture;
				m_Texture = NULL;

				return true;
			}
			return false;
		
	}
	void ImageManager::draw(const char* id, int PosX, int PosY, int img_Width, int img_Height)
	{
		SDL_Rect m_SourceRec;
		SDL_Rect m_destinationRec;
		m_SourceRec.x = m_destinationRec.x = 0;
		m_SourceRec.y = m_destinationRec.y = 0;
		m_SourceRec.w = m_destinationRec.w = 0;
		m_SourceRec.h = m_destinationRec.h = 0;

		m_Texture = m_TextureMap[id];
		if (m_Texture != 0)
		{
			SDL_QueryTexture(m_Texture, NULL, NULL, &m_SourceRec.w, &m_SourceRec.h);

			m_SourceRec.x = 0;
			m_SourceRec.y = 0;
			m_SourceRec.w = m_destinationRec.w = img_Width;
			m_SourceRec.h = m_destinationRec.h = img_Height;
			m_destinationRec.x = PosX;
			m_destinationRec.y = PosY;

			SDL_RenderCopy(m_Render, m_Texture, &m_SourceRec, &m_destinationRec);
		}
	}

	
}