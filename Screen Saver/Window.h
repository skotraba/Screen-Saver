
#ifndef _WINDOW_H_
#define _WINDOW_H_

#include<SDL.h>
#include<iostream>


class Window {
public:
	Window();
	~Window();

	void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	void render();
	void clean();

	bool running() { return isRunning; }

private:
	int cnt;
	bool isRunning;
	SDL_Window *window;
	SDL_Renderer *renderer;

};


#endif