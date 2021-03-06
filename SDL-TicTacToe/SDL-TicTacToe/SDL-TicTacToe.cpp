// SDL-TicTacToe.cpp : Defines the entry point for the console application.


//References
//Code done using the WEEK 11 lab session, SDL Christmas Break, 





#include "stdafx.h"
#include <vector>
#include <stdio.h>
#include <iostream>
#include <SDL.h>
#include "Sprites.h"

using namespace std;

#define SAFERELEASE(x) { if (x) { delete x; x = NULL;} }

//width and height of the window
const int W_height = 650;
const int W_width = 650;

/*
Width of the grid
Height = 660;
Width = 660
*/

/* A check for if a player has added a piece to the grid,
the default value of each grid will be 0.
*/
int PlayerCheck[3][3] = { 0,0,0,0,0,0,0,0,0 };

Sint32 mX, mY;

//The Window canvas which th surfaces will be drawn onto.
SDL_Surface *game_surface;

//Events for the window
SDL_Event window;
SDL_Event event;

//Blank Surface(destinations)
SDL_Surface *dst_surface = NULL;

//Pointer for the window
SDL_Window *_window;

bool BoxOccupied[9];
bool BoxPoint(int ID) {

	return BoxOccupied[ID];
}

//Images of each box on the 9 by 9 grid.
Sprite *BOX1;
Sprite *BOX2;
Sprite *BOX3;
Sprite *BOX4;
Sprite *BOX5;
Sprite *BOX6;
Sprite *BOX7;
Sprite *BOX8;
Sprite *BOX9;

Sprite *Player1;
Sprite *Player2;

//A vector which stores the sprites
vector<Sprite*> playerIcons;

int playerTurns = 0;

//Load the Grid using the sprites from box1 to 9 and set their position.
void LoadGrid() {
	BOX1 = new Sprite("Blank.bmp");
	BOX1->SetPosition(0, 0);

	BOX2 = new Sprite("Blank.bmp");
	BOX2->SetPosition(210, 0);

	BOX3 = new Sprite("Blank.bmp");
	BOX3->SetPosition(420, 0);

	BOX4 = new Sprite("Blank.bmp");
	BOX4->SetPosition(0, 210);

	BOX5 = new Sprite("Blank.bmp");
	BOX5->SetPosition(210, 210);

	BOX6 = new Sprite("Blank.bmp");
	BOX6->SetPosition(420, 210);

	BOX7 = new Sprite("Blank.bmp");
	BOX7->SetPosition(0, 420);

	BOX8 = new Sprite("Blank.bmp");
	BOX8->SetPosition(210, 420);

	BOX9 = new Sprite("Blank.bmp");
	BOX9->SetPosition(420, 420);

}



bool Update() {

	SDL_Event event;

	//Implement a loop to check all SDL events
	while (SDL_PollEvent(&event) != 0) {

		//Handle the X button at top right
		//of the window
		if (event.type == SDL_QUIT) {
			return false;

		}
	}

	//[13] detect mouse events
	if (event.type == SDL_MOUSEBUTTONDOWN) {
		//Read the mosition of the mouses x and y data
		mX = event.motion.x;
		mY = event.motion.y;
		printf("Mouse pressed at position %i, %i \n", mX, mY);


		if (BOX1->MousePressed(mX, mY)) {
			if (BoxPoint(0) == false) {
				string spriteName = "";
				//If the number of the player turns,is even then render the image of player 1.
				//else render the image of player 2 and mark the player check
				if (playerTurns % 2 == 0) {
					//player 1 turn
					spriteName = "Player1.bmp";
					PlayerCheck[0][0] = 1;
					if (PlayerCheck[0][0] = 1) {
						printf("Player 1 has filled box 1.\n");
					}
				}
				else {
					//player 2 turn
					spriteName = "Player2.bmp";
					PlayerCheck[0][0] = -1;
					if (PlayerCheck[0][0] = -1) {
						printf("Player 2 has filled box 1.\n");
					}

				}
				Sprite  *player = new Sprite(spriteName);
				player->SetPosition(0, 0);
				playerIcons.push_back(player);
				playerTurns += 1;
				BoxOccupied[0] = true;
			}
		}




		if (BOX2->MousePressed(mX, mY)) {
			if (BoxPoint(1) == false) {
				string spriteName = "";
				if (playerTurns % 2 == 0) {
					//player 1 turn
					spriteName = "Player1.bmp";
					PlayerCheck[1][0] = 1;
					if (PlayerCheck[1][0] = 1) {
						printf("Player 1 has filled box 2.\n");
					}
				}
				else {
					//player 2 turn
					spriteName = "Player2.bmp";
					PlayerCheck[1][0] = -1;
					if (PlayerCheck[1][0] = -1) {
						printf("Player 2 has filled box 2.\n");
					}
				}
				Sprite  *player = new Sprite(spriteName);
				player->SetPosition(210, 0);
				playerIcons.push_back(player);
				playerTurns += 1;
				BoxOccupied[1] = true;
			}
		}


		if (BOX3->MousePressed(mX, mY)) {
			if (BoxPoint(2) == false) {
				string spriteName = "";
				if (playerTurns % 2 == 0) {
					//player 1 turn
					spriteName = "Player1.bmp";
					PlayerCheck[2][0] = 1;
					if (PlayerCheck[2][0] = 1) {
						printf("Player 1 has filled box 3.\n");
					}
				}
				else {

					//player 2 turn
					spriteName = "Player2.bmp";
					PlayerCheck[2][0] = -1;
					if (PlayerCheck[2][0] = -1) {
						printf("Player 2 has filled box 3.\n");
					}
				}
				Sprite  *player = new Sprite(spriteName);
				player->SetPosition(420, 0);
				playerIcons.push_back(player);
				playerTurns += 1;
				BoxOccupied[2] = true;
			}
		}



		if (BOX4->MousePressed(mX, mY)) {
			if (BoxPoint(3) == false) {

				string spriteName = "";
				if (playerTurns % 2 == 0) {
					//player 1 turn
					spriteName = "Player1.bmp";
					PlayerCheck[0][1] = 1;
					if (PlayerCheck[0][1] = 1) {
						printf("Player 1 has filled box 4.\n");
					}
				}
				else {
					//player 2 turn
					spriteName = "Player2.bmp";
					PlayerCheck[0][1] = -1;
					if (PlayerCheck[0][1] = -1) {
						printf("Player 2 has filled box 4.\n");
					}
				}
				Sprite  *player = new Sprite(spriteName);
				player->SetPosition(0, 210);
				playerIcons.push_back(player);
				playerTurns += 1;
				BoxOccupied[3] = true;
			}
		}



		if (BOX5->MousePressed(mX, mY)) {
			if (BoxPoint(4) == false) {
				string spriteName = "";
				if (playerTurns % 2 == 0) {
					//player 1 turn
					spriteName = "Player1.bmp";
					PlayerCheck[1][1] = 1;
					if (PlayerCheck[1][1] = 1) {
						printf("Player 1 has filled box 5.\n");
					}
				}
				else {

					//player 2 turn
					spriteName = "Player2.bmp";
					PlayerCheck[1][1] = -1;
					if (PlayerCheck[1][1] = -1) {
						printf("Player 2 has filled box 5.\n");
					}
				}
				Sprite  *player = new Sprite(spriteName);
				player->SetPosition(210, 210);
				playerIcons.push_back(player);
				playerTurns += 1;
				BoxOccupied[4] = true;

			}
		}

		if (BOX6->MousePressed(mX, mY)) {
			if (BoxPoint(5) == false) {
				string spriteName = "";
				if (playerTurns % 2 == 0) {
					//player 1 turn
					spriteName = "Player1.bmp";
					PlayerCheck[2][1] = 1;
					if (PlayerCheck[2][1] = 1) {
						printf("Player 1 has filled box 6.\n");
					}
				}
				else {
					//player 2 turn
					spriteName = "Player2.bmp";
					PlayerCheck[2][1] = -1;
					if (PlayerCheck[2][1] = -1) {
						printf("Player 2 has filled box 6.\n");
					}
				}
				Sprite  *player = new Sprite(spriteName);
				player->SetPosition(420, 210);
				playerIcons.push_back(player);
				playerTurns += 1;
				BoxOccupied[5] = true;

			}
		}

		if (BOX7->MousePressed(mX, mY)) {
			if (BoxPoint(6) == false) {
				string spriteName = "";
				if (playerTurns % 2 == 0) {
					//player 1 turn
					spriteName = "Player1.bmp";
					PlayerCheck[0][2] = 1;
					if (PlayerCheck[0][2] = 1) {
						printf("Player 1 has filled box 7.\n");
					}
				}
				else {

					//player 2 turn
					spriteName = "Player2.bmp";
					PlayerCheck[0][2] = -1;
					if (PlayerCheck[0][2] = -1) {
						printf("Player 2 has filled box 7.\n");
					}
				}
				Sprite  *player = new Sprite(spriteName);
				player->SetPosition(0, 420);
				playerIcons.push_back(player);
				playerTurns += 1;
				BoxOccupied[6] = true;

			}
		}

		if (BOX8->MousePressed(mX, mY)) {
			if (BoxPoint(7) == false) {
				string spriteName = "";
				if (playerTurns % 2 == 0) {
					//player 1 turn
					spriteName = "Player1.bmp";
					PlayerCheck[1][2] = 1;
					if (PlayerCheck[1][2] = 1) {
						printf("Player 1 has filled box 8.\n");
					}
				}
				else {

					//player 2 turn
					spriteName = "Player2.bmp";
					PlayerCheck[1][2] = -1;
					if (PlayerCheck[1][2] = -1) {
						printf("Player 2 has filled box 8.\n");
					}
				}
				Sprite  *player = new Sprite(spriteName);
				player->SetPosition(210, 420);
				playerIcons.push_back(player);
				playerTurns += 1;
				BoxOccupied[7] = true;

			}
		}

		if (BOX9->MousePressed(mX, mY)) {
			if (BoxPoint(8) == false) {
				string spriteName = "";
				if (playerTurns % 2 == 0) {
					//player 1 turn
					spriteName = "Player1.bmp";
					PlayerCheck[2][2] = 1;
					if (PlayerCheck[2][2] = 1) {
						printf("Player 1 has filled box 9.\n");
					}
				}
				else {

					//player 2 turn
					spriteName = "Player2.bmp";
					PlayerCheck[2][2] = -1;
					if (PlayerCheck[2][2] = -1) {
						printf("Player 2 has filled box 9.\n");
					}
				}
				Sprite  *player = new Sprite(spriteName);
				player->SetPosition(420, 420);
				playerIcons.push_back(player);
				playerTurns += 1;
				BoxOccupied[8] = true;

			}
		}
	}
	

	return true;
}



int Win() {
	
	//Player1
	if (PlayerCheck[0][0] == 1 && PlayerCheck[0][1] == 1 && PlayerCheck[0][2] == 1)
		return 1;
	if (PlayerCheck[1][0] == 1 && PlayerCheck[1][1] == 1 && PlayerCheck[1][2] == 1)
		return 1;
	if (PlayerCheck[2][0] == 1 && PlayerCheck[2][1] == 1 && PlayerCheck[2][2] == 1)
		return 1;

	if (PlayerCheck[0][0] == 1 && PlayerCheck[1][0] == 1 && PlayerCheck[2][0] == 1)
		return 1;
	if (PlayerCheck[0][1] == 1 && PlayerCheck[1][1] == 1 && PlayerCheck[2][1] == 1)
		return 1;
	if (PlayerCheck[0][2] == 1 && PlayerCheck[1][2] == 1 && PlayerCheck[2][2] == 1)
		return 1;

	if (PlayerCheck[0][0] == 1 && PlayerCheck[1][1] == 1 && PlayerCheck[2][2] == 1)
		return 1;
	if (PlayerCheck[2][0] == 1 && PlayerCheck[1][1] == 1 && PlayerCheck[0][2] == 1)
		return 1;

	//Player2
	if (PlayerCheck[0][0] == -1 && PlayerCheck[0][1] == -1 && PlayerCheck[0][2] == -1)
		return -1;
	if (PlayerCheck[1][0] == -1 && PlayerCheck[1][1] == -1 && PlayerCheck[1][2] == -1)
		return -1;
	if (PlayerCheck[2][0] == -1 && PlayerCheck[2][1] == -1 && PlayerCheck[2][2] == -1)
		return -1;

	if (PlayerCheck[0][0] == -1 && PlayerCheck[1][0] == -1 && PlayerCheck[2][0] == -1)
		return -1;
	if (PlayerCheck[0][1] == -1 && PlayerCheck[1][1] == -1 && PlayerCheck[2][1] == -1)
		return -1;
	if (PlayerCheck[0][2] == -1 && PlayerCheck[1][2] == -1 && PlayerCheck[2][2] == -1)
		return -1;

	if (PlayerCheck[0][0] == -1 && PlayerCheck[1][1] == -1 && PlayerCheck[2][2] == -1)
		return -1;
	if (PlayerCheck[2][0] == -1 && PlayerCheck[1][1] == -1 && PlayerCheck[0][2] == -1)
		return -1;
	
	return 0;
}

void Draw() {

	//Fill the screen with a grey colour
	SDL_FillRect(game_surface, NULL, SDL_MapRGB(game_surface->format, 0, 50, 50));

	BOX1->Render(game_surface);
	BOX2->Render(game_surface);
	BOX3->Render(game_surface);
	BOX4->Render(game_surface);
	BOX5->Render(game_surface);
	BOX6->Render(game_surface);
	BOX7->Render(game_surface);
	BOX8->Render(game_surface);
	BOX9->Render(game_surface);

	for (auto &s : playerIcons) {
		s->Render(game_surface);

	}

	//Load and freeze the window for a few seconds
	SDL_UpdateWindowSurface(_window);

}

void Exit() {
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

void FreeMemory() {
	SAFERELEASE(BOX1);
	SAFERELEASE(BOX2);
	SAFERELEASE(BOX3);
	SAFERELEASE(BOX4);
	SAFERELEASE(BOX5);
	SAFERELEASE(BOX6);
	SAFERELEASE(BOX7);
	SAFERELEASE(BOX8);
	SAFERELEASE(BOX9);
	SAFERELEASE(Player1);
	SAFERELEASE(Player2);
}

void Main() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL could not be initialise! SDL Error: " << SDL_GetError() << endl;
	}
	else {
		//Within the pointer, store the parameter for creating a window along with its width and height
		_window = SDL_CreateWindow("TicTacToeGame",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			W_width,
			W_height,
			SDL_WINDOW_OPENGL);
		if (_window == NULL) {
			cout << "Window could not be created! SDL_Error: %s\n" << SDL_GetError() << endl;
			return;
		}
		else {
			//Create a surface the size og the window.
			game_surface = SDL_GetWindowSurface(_window);
		}


	}

	for (int i = 0; i < 9; i++) {
		BoxOccupied[i] = false;
	}

}

int main(int argc, char* argv[])
{
	//SDL_Point mouse_position;
	Main();
	LoadGrid();


	bool gameloop = true;


	while (gameloop) {

		gameloop = Update();
		Draw();
		if (Win() == 1) {
			printf("Player X has won! \n");
			
		}
		else if (Win() == -1) {
			printf("Player O has won! \n");
		}
		
		SDL_Delay(20);
	}

	FreeMemory();

	Exit();

	return 0;
}