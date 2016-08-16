#include "Window/Window.h"
#include "Sound\SoundManager.h"
#include <SDL.h>
int main(int argc, char* args[])
{
	using namespace Turki;
	setlocale(LC_ALL, "Turkish");

	Window window("Turki ENGINE", 800, 600, false);
	SoundManager soundmgr;
	while (window.running())
	{
		window.render();
	}

	system("pause");
	return 0;
}