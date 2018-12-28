//Reference https://www.youtube.com/watch?annotation_id=annotation_148122517&feature=iv&src_vid=_WpQpLL49y0&v=xwwl8TgkwgU assessed 10th november, Published on Jul 23 2014
//Reference https://www.youtube.com/watch?v=_WpQpLL49y0 assessed 10th november, Published on Jul 26 2014
#include <iostream>
#include <string>
#include "stdafx.h"

using namespace std;

char Game[3][3] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char Player = 'X';
int PLAYER1_SCORE = 0;
int PLAYER2_SCORE = 0;

//Game counter
int counter;

void Board()
{
	//'cls' clear the screen and save the update state
	system("cls");
	cout << "Tic-Tac-Toe Progression" << endl;
	cout << " " << endl;
	cout << "PLayer1 score: " << PLAYER1_SCORE;
	cout << " //// Player2 score: " << PLAYER2_SCORE << endl;


	//Draw the number into a game board of 3 by 3
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			cout << Game[x][y] << "|";
		}
		cout << endl;
	}
}


//The input that the player is putting in, in this case, it would be the number on the board.
void Input()
{
	int number;
	cout << "Player " << Player << " should now place their marker\n" "Select a number on the board:  ";
	cin >> number;

	//If the number is lower or higher than the input boundary, display message.
	if (number <= 0 || number >= 10) {
		cout << "Wrong......number....... " << endl;
		Input();
	}



	//Locate the numbers on the board and mark it with the current player
	if (number == 1)
	{
		//if the character is equal to the number and a player is already on the character, display message.
		if (Game[0][0] == '1')
			Game[0][0] = Player;
		else
		{
			cout << "The slot has already been selected hardhead!" << endl;
			Input();
		}
	}
	else if (number == 2)
	{
		if (Game[0][1] == '2')
			Game[0][1] = Player;
		else
		{
			cout << "The slot has already been selected hardhead!" << endl;
			Input();
		}
	}
	else if (number == 3)
	{
		if (Game[0][2] == '3')
			Game[0][2] = Player;
		else
		{
			cout << "The slot has already been selected hardhead!" << endl;
			Input();
		}
	}
	else if (number == 4)
	{
		if (Game[1][0] == '4')
			Game[1][0] = Player;
		else
		{
			cout << "The slot has already been selected hardhead!" << endl;
			Input();
		}
	}
	else if (number == 5)
	{
		if (Game[1][1] == '5')
			Game[1][1] = Player;
		else
		{
			cout << "The slot has already been selected hardhead!" << endl;
			Input();
		}
	}
	else if (number == 6)
	{
		if (Game[1][2] == '6')
			Game[1][2] = Player;
		else
		{
			cout << "The slot has already been selected hardhead!" << endl;
			Input();
		}
	}
	else if (number == 7)
	{
		if (Game[2][0] == '7')
			Game[2][0] = Player;
		else
		{
			cout << "The slot has already been selected hardhead!" << endl;
			Input();
		}
	}
	else if (number == 8)
	{
		if (Game[2][1] == '8')
			Game[2][1] = Player;
		else
		{
			cout << "The slot has already been selected hardhead!" << endl;
			Input();
		}
	}
	else if (number == 9)
	{
		if (Game[2][2] == '9')
			Game[2][2] = Player;
		else
		{
			cout << "The slot has already been selected hardhead!" << endl;
			Input();
		}
	}
}



//Function to change the players turn
void Change()
{
	if (Player == 'X') {
		Player = 'O';
	}

	else
		Player = 'X';
}

//Check the conditions of the board.
char Win()
{
	//Player1
	if (Game[0][0] == 'X' && Game[0][1] == 'X' && Game[0][2] == 'X')
		return 'X';
	if (Game[1][0] == 'X' && Game[1][1] == 'X' && Game[1][2] == 'X')
		return 'X';
	if (Game[2][0] == 'X' && Game[2][1] == 'X' && Game[2][2] == 'X')
		return 'X';

	if (Game[0][0] == 'X' && Game[1][0] == 'X' && Game[2][0] == 'X')
		return 'X';
	if (Game[0][1] == 'X' && Game[1][1] == 'X' && Game[2][1] == 'X')
		return 'X';
	if (Game[0][2] == 'X' && Game[1][2] == 'X' && Game[2][2] == 'X')
		return 'X';

	if (Game[0][0] == 'X' && Game[1][1] == 'X' && Game[2][2] == 'X')
		return 'X';
	if (Game[2][0] == 'X' && Game[1][1] == 'X' && Game[0][2] == 'X')
		return 'X';

	//Player2
	if (Game[0][0] == 'O' && Game[0][1] == 'O' && Game[0][2] == 'O')
		return 'O';
	if (Game[1][0] == 'O' && Game[1][1] == 'O' && Game[1][2] == 'O')
		return 'O';
	if (Game[2][0] == 'O' && Game[2][1] == 'O' && Game[2][2] == 'O')
		return 'O';

	if (Game[0][0] == 'O' && Game[1][0] == 'O' && Game[2][0] == 'O')
		return 'O';
	if (Game[0][1] == 'O' && Game[1][1] == 'O' && Game[2][1] == 'O')
		return 'O';
	if (Game[0][2] == 'O' && Game[1][2] == 'O' && Game[2][2] == 'O')
		return 'O';

	if (Game[0][0] == 'O' && Game[1][1] == 'O' && Game[2][2] == 'O')
		return 'O';
	if (Game[2][0] == 'O' && Game[1][1] == 'O' && Game[0][2] == 'O')
		return 'O';

	return '/';


}


int main()
{
	counter = 0;
	Board();
	while (1)
	{
		counter++;
		//check the input and draw a new board
		Input();
		Board();
		Change();

		//If a player has won, terminate the while loop.
		if (Win() == 'X')
		{
			cout << "X wins!" << endl;
			PLAYER1_SCORE++;
			main();
		}
		else if (Win() == 'O')
		{
			cout << "O wins!" << endl;
			PLAYER2_SCORE++;
			main();
		}
		else if (Win() == '/' && counter == 9) {
			cout << " Nobody wins!" << endl;
			main();
		}

	}

	string y;
	getline(cin, y);
	system("pause");
	return 0;
}
