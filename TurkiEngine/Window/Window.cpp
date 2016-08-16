#include "Window.h"


namespace Turki {
	Window::Window(const char* Title, int Height, int Width, bool fullscreen)
	{
		m_Title = Title;
		m_Width = Height;
		m_Height = Width;

		

		if (fullscreen)
			m_Flags = SDL_WINDOW_FULLSCREEN;
		else
			m_Flags = SDL_WINDOW_SHOWN;
		init();
		m_Running = true;
	}


	Window::~Window()
	{
		SDL_DestroyRenderer(m_Renderer);
		SDL_DestroyWindow(m_Window);
		SDL_Quit();
	}
	SDL_Renderer* Window::getRenderer()
	{
		return m_Renderer;
	}

	bool Window::init()
	{
		if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
		{

			m_Window = SDL_CreateWindow(m_Title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_Width, m_Height, m_Flags);

			if (m_Window != 0)
			{
				std::cout << "Pencere oluşturuldu" << std::endl;
				m_Renderer = SDL_CreateRenderer(m_Window, -1, 0);
			}
			else
			{
				std::cout << "Pencere oluşturulamadı" << std::endl;
				return false;
			}
		}
		else
		{
			std::cout << "Init başarısız!!!" << std::endl;
			return false;
		}

		return true;
	}
}