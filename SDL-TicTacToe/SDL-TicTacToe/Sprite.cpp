#include "stdafx.h"
#include "Sprites.h"

using namespace std;

/*
Each sprite will have a string loaded into memory and onto the surface variable we,
gave it, and feed the to make sure the image stays the same.
Also give a default rectangle position and size that equal the surface we have assigned.
*/
	Sprite::Sprite(string file) {
		this->surface = SDL_LoadBMP(file.c_str());
		if (this->surface == NULL) {
			printf("Unable to load image %s! SDL Error: %s\n");
		}
		this->rect.x = 0;
		this->rect.y = 0;
		this->rect.w = surface->w;
		this->rect.h = surface->h;
	}

	//Set the position of the sprite to the position of the screen.
	void Sprite::SetPosition(int x, int y) {
		this->rect.x = x;
		this->rect.y = y;
	}

	// if the surface is destroyed (destructor function),
	//then free surface. 
	Sprite::~Sprite()
	{
		if (surface != NULL) {
			SDL_FreeSurface(this->surface);
		}
	}

	//Render function to quickly render a surface to save typing.
	void Sprite::Render(SDL_Surface *game_surface) {
		SDL_BlitSurface(surface, NULL, game_surface, &rect);
	}

	//If the mouses region is
	bool Sprite::MousePressed(int position_X, int position_Y) const
	{
		if (position_X > rect.x && position_X < rect.x + rect.w) {
			if (position_Y > rect.y && position_Y < rect.y + rect.h) {
				return true;
			}
		}
		return false;
	}

