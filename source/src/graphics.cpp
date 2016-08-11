#include <SDL.h>
#include <SDL_image.h>

#include "graphics.h"
#include "globals.h"
#include <iostream>

/* Graphics class
Holds all information dealing with graphics for the game
*/

Graphics::Graphics() {
	SDL_CreateWindowAndRenderer(globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT, 0, &this->_window, &this->_renderer);
	SDL_SetWindowTitle(this->_window, "Cavestory");
}

Graphics::~Graphics() {
	SDL_DestroyWindow(this->_window);
	SDL_DestroyRenderer(this->_renderer);
}

SDL_Surface* Graphics::loadImage(const std::string &filePath) {
	if (this->_spriteSheets.count(filePath) == 0) {
		this->_spriteSheets[filePath] = IMG_Load(filePath.c_str());
		if (this->_spriteSheets[filePath] == NULL) {
			std::cout << "Unable to load image " << filePath.c_str() << std::endl << "Error: " << SDL_GetError() << std::endl;
		}
	}
	return this->_spriteSheets[filePath];
}

void Graphics::blitSurface(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationAngle) {
	SDL_RenderCopy(this->_renderer, texture, sourceRectangle, destinationAngle);
}

void Graphics::flip() {
	SDL_RenderPresent(this->_renderer);
}

void Graphics::clear() {
	SDL_RenderClear(this->_renderer);
}

SDL_Renderer* Graphics::getRenderer() const {
	return this->_renderer;
}