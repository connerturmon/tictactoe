#include <iostream>

void GetPlayerInput(int[], int);		// Checks the validity of player input and assigns to board
void DrawBoard();		// Clears screen & draws the board to the screen
bool CheckWin();		// Checks if there is a winner

int position[9]{};		// The board!
char board[9]{ '1', '2', '3','4','5','6','7','8','9' };		// The visible board
bool game_draw = false;
const short FREE_SLOT = 0;
const short X = 1;
const short O = 2;

int main()
{
	bool game_won = false;
	int player = X;
	int player_input;

	while (!game_won)
	{
		DrawBoard();
		GetPlayerInput(position, player);
		game_won = CheckWin();

		if (player != O) player = O; else player = X;
	}
	DrawBoard();
	if (game_draw) std::cout << "The game was a draw!" << std::endl;
	else if (player != X) std::cout << "Congratulations Player X! You Win!" << std::endl;
	else std::cout << "Congratulations Player O! You Win!" << std::endl;

	std::cin.ignore();
	std::cin.get();
}

void DrawBoard()
{
	system("CLS");
	std::cout << std::endl
		<< " " << board[0] << " | " << board[1] << " | " << board[2] << " " << std::endl
		<< "-----------" << std::endl
		<< " " << board[3] << " | " << board[4] << " | " << board[5] << " " << std::endl
		<< "-----------" << std::endl
		<< " " << board[6] << " | " << board[7] << " | " << board[8] << " " << std::endl;

}

void GetPlayerInput(int position[], int player)
{
	int position_input;
	while (true)
	{
		std::cout << "Player ";
		if (player == X) std::cout << "X\n"; else std::cout << "O\n";
		std::cout << "Enter a position from 1-9: " << std::endl;
		std::cin >> position_input;
		if (position_input < 1 || position_input > 9)
		{
			DrawBoard();
			std::cout << "Invalid input! Choose another..." << std::endl;
			continue;
		}
		if (position[position_input - 1] != FREE_SLOT)
		{
			DrawBoard();
			std::cout << "Space already taken! Choose another..." << std::endl;
			continue;
		}
		break;
	}
	position[position_input - 1] = player;		// Player will either be 1 or 2 (X or O respectively) which gets stored at the position
	if (player != X) board[position_input - 1] = 'O'; else board[position_input - 1] = 'X';
}

bool CheckWin()
{
	// X Win Conditions
	if (position[0] == X && position[1] == X && position[2] == X) return true;
	else if (position[3] == X && position[4] == X && position[5] == X) return true;
	else if (position[6] == X && position[7] == X && position[8] == X) return true;
	else if (position[0] == X && position[3] == X && position[6] == X) return true;
	else if (position[1] == X && position[4] == X && position[7] == X) return true;
	else if (position[2] == X && position[5] == X && position[8] == X) return true;
	else if (position[0] == X && position[4] == X && position[8] == X) return true;
	else if (position[2] == X && position[4] == X && position[6] == X) return true;	
	
	// O Win Conditions
	else if (position[0] == O && position[1] == O && position[2] == O) return true;
	else if (position[3] == O && position[4] == O && position[5] == O) return true;
	else if (position[6] == O && position[7] == O && position[8] == O) return true;
	else if (position[0] == O && position[3] == O && position[6] == O) return true;
	else if (position[1] == O && position[4] == O && position[7] == O) return true;
	else if (position[2] == O && position[5] == O && position[8] == O) return true;
	else if (position[0] == O && position[4] == O && position[8] == O) return true;
	else if (position[2] == O && position[4] == O && position[6] == O) return true;

	else return false;
}