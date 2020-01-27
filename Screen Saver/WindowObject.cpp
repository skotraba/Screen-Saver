#include "WindowObject.h"
#include "TextureManager.h"

#include <ctime>


//create an object
WindowObject::WindowObject(SDL_Renderer* ren, int x, int y, bool x_dir, bool y_dir) {

	renderer = ren;
	std::srand(std::time(0));
	int randIndex = rand() % 4;
	currentColor = randIndex;
	auto temp = path + images[randIndex];
	objTexture = TextureManager::LoadTexture(temp.c_str(), renderer);
	xpos = x;
	ypos = y;
	pos_dir_x = x_dir;
	pos_dir_y = y_dir;

}

void WindowObject::Update() {

	srcRect.h = 64;
	srcRect.w = 64;
	srcRect.x = 0;
	srcRect.y = 0;

	// if a collision occurs, change the direction
	//
	// case 1: hit bottom wall
	if (ypos > 600 - srcRect.h * 2) {
		std::cout << "Hit bottom wall!" << std::endl;
		pos_dir_y = false;

		std::srand(std::time(0));
		int randIndex = rand() % 4;
		while (randIndex == currentColor)
		{
			randIndex = rand() % 4;
		}
		currentColor = randIndex;
		auto temp = path + images[randIndex];
		objTexture = TextureManager::LoadTexture(temp.c_str(), renderer);

	}
	// case 2: hit right wall
	if (xpos > 800 - srcRect.w * 2) {
		std::cout << "Hit right wall!" << std::endl;
		pos_dir_x = false;

		std::srand(std::time(0));
		int randIndex = rand() % 4;
		while (randIndex == currentColor)
		{
			randIndex = rand() % 4;
		}
		currentColor = randIndex;
		auto temp = path + images[randIndex];
		objTexture = TextureManager::LoadTexture(temp.c_str(), renderer);
	}
	// case 3: hit top wall
	if (ypos < 0) {
		std::cout << "Hit top wall!" << std::endl;
		pos_dir_y = true;

		std::srand(std::time(0));
		int randIndex = rand() % 4;
		while (randIndex == currentColor)
		{
			randIndex = rand() % 4;
		}
		currentColor = randIndex;
		auto temp = path + images[randIndex];
		objTexture = TextureManager::LoadTexture(temp.c_str(), renderer);
	}
	// case 4: hit left wall
	if (xpos < 0) {
		std::cout << "Hit left wall!" << std::endl;
		pos_dir_x = true;

		std::srand(std::time(0));
		int randIndex = rand() % 4;
		while (randIndex == currentColor)
		{
			randIndex = rand() % 4;
		}
		currentColor = randIndex;
		auto temp = path + images[randIndex];
		objTexture = TextureManager::LoadTexture(temp.c_str(), renderer);
	}

	// if x direction is positive
	if (pos_dir_x) {
		xpos++;
	}
	// if x direction is negative
	else {
		xpos--;
	}
	// if y direction is positive
	if (pos_dir_y) {
		ypos++;
	}
	else {
		ypos--;
	}


	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;
}

void WindowObject::Render() {

	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}