#pragma once
#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include <SDL_image.h>
#include "Window.h"

class TextureManager {

public:
	static SDL_Texture* LoadTexture(const char* fileName, SDL_Renderer* ren);

};

#endif

