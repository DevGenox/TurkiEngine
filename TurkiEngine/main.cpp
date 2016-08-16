#include "Window/Window.h"
#include "Sound\SoundManager.h"
#include "ImageManager\ImageManager.h"
#include "Game.h"
#include <SDL.h>
int main(int argc, char* args[])
{
	using namespace Turki;
	setlocale(LC_ALL, "Turkish");

	Window window("Turki ENGINE", 800, 600, false);
	SoundManager soundmgr;
	ImageManager imageMgr;
	Game game;
	game.load(window.getRenderer());
	while (window.running())
	{
		game.update();
	}

	system("pause");
	return 0;
}