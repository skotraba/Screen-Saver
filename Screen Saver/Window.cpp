#include "Window.h"
#include "TextureManager.h"
#include "WindowObject.h"
#include "SDL_image.h"

#include <SDL_image.h>
#include <cstdlib>
#include <ctime>

//C:\\Users\\skotr\\Documents\\acoding stuff\\c++\\vs\\gametest\\image\\player.png"


WindowObject* box;

Window::Window() {

}

Window::~Window() {

}

void Window::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) {

	//Makes window fullscreen by passing in certain arguments
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	//Checks to make sure SDL is initialized
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystem Inititalized" << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window) {
			std::cout << "Window created" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			std::cout << "Renderer created" << std::endl;
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		}

		isRunning = true;
	}
	std::srand(std::time(0));
	int rand_x = rand() % (800 - 64 * 2);
	int rand_y = rand() % (600 - 64 * 2);
	std::cout << rand_y;
	bool rand_x_dir = rand() % 2;
	bool rand_y_dir = rand() % 2;
	box = new WindowObject(renderer, rand_x, rand_y, rand_x_dir, rand_y_dir);
}

void Window::handleEvents() {
	//When you click the 'x' the game quits
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;

	default:
		break;
	}
}

void Window::update() {

	box->Update();

}

void Window::render() {
	SDL_RenderClear(renderer);
	//add stuff to renderer
	box->Render();
	SDL_RenderPresent(renderer);

}

void Window::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned" << std::endl;
}

