#include "Game.h"
#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))
#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 768
namespace Turki {
	Game::Game()
	{

	}

	Game::~Game()
	{
	}

	void Game::load(SDL_Renderer* render, mat4& pr_mat, Shaders& shader)
	{
		gameRenderer = render;
		imageMan.setRenderer(gameRenderer);
		m_pr_mat = &pr_mat;
		m_Shader = &shader;
		camera_Angle = 45.0f;

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
				camera_Angle += 10;
				*m_pr_mat = m_pr_mat->perspective(camera_Angle, (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT, 0.1f, 10000.0f);
		//         m_Shader->UniformMatrix4("prMat", *m_pr_mat);
				 m_Shader->UniformMatrix4("viewMat", m_pr_mat->mylookat(vec3(0, 0, 0), vec3(0, 0, -1.5f), vec3(0, 1, 0), vec3(0, 0, 0)));
				
				// m_Shader->UniformMatrix4("viewMat", );
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
				case SDLK_LEFT:

					camX += 0.1f;
					m_Shader->UniformMatrix4("viewMat", m_pr_mat->mylookat(vec3(eyeX, eyeY, eyeZ), vec3(camX, camY, -1.5f), vec3(0, 1, 0),vec3(0, 0,0)));
					break;
				case SDLK_RIGHT:
					camX -= 0.1f;
					m_Shader->UniformMatrix4("viewMat", m_pr_mat->mylookat(vec3(eyeX, eyeY, eyeZ), vec3(camX, camY, -1.5f), vec3(0, 1, 0), vec3(0, 0, 0)));
					break;
				case SDLK_UP:
					camY += 0.1f;
					m_Shader->UniformMatrix4("viewMat", m_pr_mat->mylookat(vec3(eyeX, eyeY, eyeZ), vec3(camX, camY, -1.5f), vec3(0, 1, 0), vec3(0, 0, 0)));
					break;
				case SDLK_DOWN:
					camY -= 0.1f;
					m_Shader->UniformMatrix4("viewMat", m_pr_mat->mylookat(vec3(eyeX, eyeY, eyeZ), vec3(camX, camY, -1.5f), vec3(0, 1, 0), vec3(0, 0, 0)));
					break;
				case SDLK_SPACE:
					eyeY += 0.1f;
					m_Shader->UniformMatrix4("viewMat", m_pr_mat->mylookat(vec3(eyeX, eyeY, eyeZ), vec3(camX, camY, -1.5f), vec3(0, 1, 0), vec3(0, 0, 0)));
					break;
				case SDLK_LSHIFT:
					eyeY -= 0.1f;
					m_Shader->UniformMatrix4("viewMat", m_pr_mat->mylookat(vec3(eyeX, eyeY, eyeZ), vec3(camX, camY, -1.5f), vec3(0, 0.5f, 0), vec3(0, 0, 0)));
					break;
				case SDLK_a:
					eyeX -= 1.0f;
					m_Shader->UniformMatrix4("viewMat", m_pr_mat->mylookat(vec3(eyeX, eyeY, eyeZ), vec3(camX, camY, -1.5f), vec3(0, 0.5f, 0), vec3(0, 0, 0)));
					break;
				case SDLK_d:
					eyeX += 1.0f;
					m_Shader->UniformMatrix4("viewMat", m_pr_mat->mylookat(vec3(eyeX, eyeY, eyeZ), vec3(camX, camY, -1.5f), vec3(0, 0.5f, 0), vec3(0, 0, 0)));
					break;

				case SDLK_w:
					eyeY += 1.0f;
					m_Shader->UniformMatrix4("viewMat", m_pr_mat->mylookat(vec3(eyeX, eyeY, eyeZ), vec3(camX, camY, camZ), vec3(0, 0.5f, 0), vec3(0, 0, 0)));
					break;

				case SDLK_s:
					eyeY -= 1.0f;
					m_Shader->UniformMatrix4("viewMat", m_pr_mat->mylookat(vec3(eyeX, eyeY, eyeZ), vec3(camX, camY, camZ), vec3(0, 0.5f, 0), vec3(0, 0, 0)));
					break;

				default:
					break;
				}
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