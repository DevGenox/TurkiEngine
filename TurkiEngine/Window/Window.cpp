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
	SDL_Window* Window::getWindow()
	{
		return m_Window;
	}

	bool Window::init()
	{
		if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
		{
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
			m_Window = SDL_CreateWindow(m_Title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_Width, m_Height, SDL_WINDOW_OPENGL);
			SDL_GLContext gContext = SDL_GL_CreateContext(m_Window);
			glewExperimental = GL_TRUE;
			if (gContext != 0)
			{
				SDL_GL_MakeCurrent(m_Window, gContext);
			}
			else
			{
				std::cout << "Context oluşturulamadı,"  << SDL_GetError() << std::endl;
			}
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
			
			if (glewInit() != GLEW_OK)
			{
				std::cout << "GLEW bağlanılamadı " << glewGetErrorString(glewInit());
			}
			else
			{
				std::cout << "OPENGL : " << glGetString(GL_VERSION);
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