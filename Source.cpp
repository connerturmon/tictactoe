/**********************************************************\
| TIC TAC TOE v1.1                                         |
| Thank you for all the help r/programming! You guys rock! |
|                                                          |
\**********************************************************/

#include <iostream>

//-FUNCTION PROTOTYPES
void DrawBoard();		// Draws the board each turn!
void GetInput();		// Asks player for (valid) input and returns that value!
int CheckWinner();		// Checks for a winner!

//-CONSTANTS
const int FREE = 0;		// Board slot not taken
const int FALSE = 0;
const int X = 1;		// Player X
const int O = 2;		// Player Y
const int DRAW = -1;	// Game is a draw

//-GLOBAL VARS
char board[9] = { '1','2','3','4','5','6','7','8','9' };	// The board!
int player = X;			// The player!

//-MAIN
int main()
{
	int winner = FALSE;		// For winner: FALSE = 0, X = 1, O = 2

	// The Game //
	while (!winner)
	{
		DrawBoard();
		GetInput();
		winner = CheckWinner();

		if (player != O) player = O; else player = X;	// Switches player each turn
	}
	DrawBoard();
	if (winner == DRAW) 
		std::cout << "The game was a draw!\n";
	else 
		std::cout << "Congratulations Player " << winner << "!\nYou win!\n";	// Winner winner, chicken dinner

	// Used to hold program open after loop. May not be necessary on your system.
	std::cin.ignore();
	std::cin.get();
}

//-FUNCTION DEFININTIONS (View Prototypes for Info)
void DrawBoard()
{
	system("CLS");		// If you can't compile, remove this (not compatible with all systems)
	std::cout
		<< "Tic Tac Toe v1.1 : THANK YOU REDDIT! <3\n"
		<< " " << board[0] << " | " << board[1] << " | " << board[2] << " \n"
		<< "-----------\n"
		<< " " << board[3] << " | " << board[4] << " | " << board[5] << " \n"
		<< "-----------\n"
		<< " " << board[6] << " | " << board[7] << " | " << board[8] << " \n";
}

void GetInput()
{
	int position_input;

	// Checks Input Validity //
	while (true)
	{
		std::cout << "Player " << player << "\n" << "Enter a position (1-9):\n";
		std::cin >> position_input;
		position_input--;			// Decremement input since arrays begin at 0
		if (position_input < 0 || position_input > 8 || board[position_input] == 'X' || board[position_input] == 'O')
		{
			system("CLS");			// If you can't compile, remove this (not compatible with all systems)
			DrawBoard();			// Re-draw board since we just cleared screen
			std::cout << "INVALID POSITION, TRY AGAIN...\n";
			continue;
		}
		break;
	}
	// Updates Board Value //
	if (player != X) board[position_input] = 'O';
	else board[position_input] = 'X';
}

// DISCLAIMER: This function is still a spaghetti mess-- but higher quality spaghetti.
int CheckWinner()
{
	// Check Row Wins //
	if (board[0] == board[1] && board[1] == board[2]) return player;
	else if (board[3] == board[4] && board[4] == board[5]) return player;
	else if (board[6] == board[7] && board[7] == board[8]) return player;

	// Check Column Wins //
	else if (board[0] == board[3] && board[3] == board[6]) return player;
	else if (board[1] == board[4] && board[4] == board[7]) return player;
	else if (board[2] == board[5] && board[5] == board[8]) return player;

	// Check Diagonals //
	else if (board[0] == board[4] && board[4] == board[8]) return player;
	else if (board[2] == board[4] && board[4] == board[6]) return player;

	else return FALSE;
}
