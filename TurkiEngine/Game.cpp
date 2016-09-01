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

	void Game::load(SDL_Renderer* render, mat4& pr_mat, Shaders& shader, Camera& cam)
	{
		gameRenderer = render;
		imageMan.setRenderer(gameRenderer);
		m_pr_mat = &pr_mat;
		m_Shader = &shader;
		m_Cam = &cam;
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
				 m_Shader->UniformMatrix4("viewMat", m_pr_mat->mylookat(vec3(0, 0, 0), vec3(0, 0, -1.5f), vec3(0, 1, 0)));
				
				// m_Shader->UniformMatrix4("viewMat", );
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
			/*	case SDLK_LEFT:
					m_Cam->m_lookat.x -= 0.1f;
					m_Shader->UniformMatrix4("viewMat", m_Cam->getViewProj());
					break;
				case SDLK_RIGHT:
					m_Cam->m_lookat.x += 0.1f;
					m_Shader->UniformMatrix4("viewMat", m_Cam->getViewProj());
					break;
				case SDLK_UP:
					m_Cam->m_lookat.y += 0.1f;
					m_Shader->UniformMatrix4("viewMat", m_Cam->getViewProj());
					break;
				case SDLK_DOWN:
					m_Cam->m_lookat.y -= 0.1f;
					m_Shader->UniformMatrix4("viewMat", m_Cam->getViewProj());
					break;
				case SDLK_SPACE:
					m_Cam->m_eye.z -= 0.1f;
					m_Shader->UniformMatrix4("viewMat", m_Cam->getViewProj());
					break;
				case SDLK_LSHIFT:
					m_Cam->m_eye.z -= 0.1f;
					m_Shader->UniformMatrix4("viewMat", m_Cam->getViewProj());
					break;
				case SDLK_a:
					m_Cam->m_eye.x -= 0.1f;
					m_Shader->UniformMatrix4("viewMat", m_Cam->getViewProj());
					break;
				case SDLK_d:
					m_Cam->m_eye.x += 0.1f;
					m_Shader->UniformMatrix4("viewMat", m_Cam->getViewProj());
					break;

				case SDLK_w:
					m_Cam->m_eye.y += 0.1f;
					m_Shader->UniformMatrix4("viewMat", m_Cam->getViewProj());
					break;

				case SDLK_s:
					m_Cam->m_eye.y -= 0.1f;
					m_Shader->UniformMatrix4("viewMat", m_Cam->getViewProj());
					break;*/

				case SDLK_LEFT:
					m_Cam->setPosLook(vec3(m_Cam->m_lookat.x - 0.5f, m_Cam->m_lookat.y, m_Cam->m_lookat.z));
					break;
				case SDLK_RIGHT:
					m_Cam->setPosLook(vec3(m_Cam->m_lookat.x + 0.5f, m_Cam->m_lookat.y, m_Cam->m_lookat.z));
					break;
				case SDLK_UP:
					m_Cam->setPosLook(vec3(m_Cam->m_lookat.x , m_Cam->m_lookat.y + 0.5f, m_Cam->m_lookat.z));
					break;
				case SDLK_DOWN:
					m_Cam->setPosLook(vec3(m_Cam->m_lookat.x, m_Cam->m_lookat.y - 0.5f, m_Cam->m_lookat.z));
					break;
				case SDLK_SPACE:
					m_Cam->setPosLook(vec3(m_Cam->m_lookat.x, m_Cam->m_lookat.y, m_Cam->m_lookat.z + 0.5f));
					break;
				case SDLK_LSHIFT:
					m_Cam->setPosLook(vec3(m_Cam->m_lookat.x, m_Cam->m_lookat.y, m_Cam->m_lookat.z - 0.5f));
					break;
				case SDLK_a:
					m_Cam->setPosEye(vec3(m_Cam->m_eye.x - 0.5f, m_Cam->m_eye.y, m_Cam->m_eye.z));
					break;
				case SDLK_d:
					m_Cam->setPosEye(vec3(m_Cam->m_eye.x + 0.5f, m_Cam->m_eye.y, m_Cam->m_eye.z));
					break;
				case SDLK_w:
					m_Cam->setPosEye(vec3(m_Cam->m_eye.x , m_Cam->m_eye.y + 0.5f, m_Cam->m_eye.z));
					break;
				case SDLK_s:
					m_Cam->setPosEye(vec3(m_Cam->m_eye.x, m_Cam->m_eye.y - 0.5f, m_Cam->m_eye.z));
					break;
				case SDLK_KP_8:
					m_Cam->setPosUp(vec3(m_Cam->m_up.x, m_Cam->m_up.y + 0.5f, m_Cam->m_up.z));
					break;
				case SDLK_KP_5:
					m_Cam->setPosUp(vec3(m_Cam->m_up.x, m_Cam->m_up.y - 0.5f, m_Cam->m_up.z));
					break;
				case SDLK_KP_4:
					m_Cam->setPosUp(vec3(m_Cam->m_up.x - 0.5f, m_Cam->m_up.y, m_Cam->m_up.z));
					break;
				case SDLK_KP_6:
					m_Cam->setPosUp(vec3(m_Cam->m_up.x + 0.5f, m_Cam->m_up.y, m_Cam->m_up.z));
					
					break;

				default:
					break;
				}
				std::cout << SDL_GetKeyName(event.key.keysym.sym) << " Basýldý" << std::endl;
				break;
		    case SDL_MOUSEWHEEL:
				if (event.wheel.y < 0)
				{
					m_Cam->setPosEye(vec3(m_Cam->m_eye.x, m_Cam->m_eye.y, m_Cam->m_eye.z + 0.5f));
				}
				else
				{
					m_Cam->setPosEye(vec3(m_Cam->m_eye.x, m_Cam->m_eye.y, m_Cam->m_eye.z - 0.5f));
				}
				break;
			case SDL_QUIT:

				break;
			default:
				break;
			}
		}

	}

}