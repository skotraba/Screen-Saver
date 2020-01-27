#include <iostream>
#include <SDL.h>
#include "Window.h"

int main(int argc, char *argv[]) {
	//change 500 back to 1000 to make it slower
	const int FPS = 60;
	const int frameDelay = 500 / FPS;

	Uint32 frameStart;
	int frameTime;

	Window *mainWindow = nullptr;

	mainWindow = new Window();

	mainWindow->init("Screen Saver", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	while (mainWindow->running()) {

		frameStart = SDL_GetTicks();

		mainWindow->handleEvents();
		mainWindow->update();
		mainWindow->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}

	}

	mainWindow->clean();

	return 0;
}