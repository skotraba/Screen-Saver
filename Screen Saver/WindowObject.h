
#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_

#include "Window.h"

#include <string>

class WindowObject {

public:
	WindowObject(SDL_Renderer* ren, int x, int y, bool x_dir, bool y_dir);
	~WindowObject();

	void Update();
	void Render();

private:

	int currentColor;
	const std::string path = "C:\\Users\\skotr\\Documents\\acoding stuff\\c++\\vs\\aMyProjects\\Screen Saver\\image\\";
	std::string images[4] = { "blue.png", "pink.png", "orange.png", "green.png" };
	int xpos;
	int ypos;
	bool pos_dir_x;
	bool pos_dir_y;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;

};


#endif#pragma once

