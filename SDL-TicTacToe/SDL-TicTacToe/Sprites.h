#pragma once

#include <SDL.h>
#include <string>

using namespace std;

class Sprite {
private:

	SDL_Rect rect;

public:

	//Function for the sprite characteristics
	Sprite(string file);

	//position of the sprite
	void SetPosition(int x, int y);

	// if the surface is destroyed (destructor function),
	//then free surface. 
	virtual ~Sprite();

	//Render function to quickly render a surface to save typing.
	void Render(SDL_Surface *game_surface);

	bool MousePressed(int position_X, int position_Y) const;

	SDL_Surface * surface;
};