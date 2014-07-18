#include "TicTacToe.h"

/*
TicTacToe::TicTacToe(unsigned dim = 3) : _dim(dim), free(_dim*_dim), grid(free, '-')
{
}
*/

TicTacToe::~TicTacToe()
{
}

bool TicTacToe::Apply(char player, int position)
{
	if (grid[position] != '-')  return false;
	grid[position] = player;
	--free;
	return true;
}

void TicTacToe::Display() const
{
	//creating the grid
	std::cout << "  ";
	for (unsigned i = 1; i <= _dim; ++i)
		std::cout << "  " << i;
	for (unsigned i = 0; i < _dim; i++)
	{
		std::cout << "\n" << static_cast<char>('A' + i) << " ";
		for (unsigned j = 0; j < _dim; j++)
			std::cout << " " << grid[i*_dim + j] << " ";
	}
	std::cout << "\n\n";
}

void TicTacToe::Turn(char player)
{
	char row = 0;
	char column = 0;
	unsigned position = 0;
	bool applied = false;
	std::cout << "\n" << player << ": Please play.\n";

	while (!applied)
	{
		std::cout << "Row(1,2,3,...): ";
		std::cin >> row;
		std::cout << player << ": column(A,B,C,...): ";
		std::cin >> column;
		if (islower(column))
			column = toupper(column);
		position = _dim*(column - 'A') + (row - '1');
		if (position < grid.size())
		{
			applied = Apply(player, position);
			if (!applied)
				std::cout << "Already used.  Please try again.\n";
		}
		else
		{
			std::cout << "Invalid position.  Please try again.\n";
		}
	}
	std::cout << "\n\n";
}

bool TicTacToe::Win(char player) const
{
	unsigned i = 0;
	//check for row and column wins
	for (; i < _dim; ++i)
	{
		bool rowwin = true;
		bool colwin = true;
		for (unsigned j = 0; j < _dim; ++j)
		{
			rowwin &= grid[i*_dim + j] == player;
			colwin &= grid[j*_dim + i] == player;
		}
		if (colwin || rowwin)
			return true;
	}

	//diagonal wins
	bool diagwin = true;
	for (i = 0; i < _dim; ++i)
		diagwin &= grid[i*_dim + i] == player;
	if (diagwin)
		return true;
	diagwin = true;
	for (unsigned i = 0; i < _dim; ++i)
		diagwin &= grid[i*_dim + (_dim-i-1)] == player;
	return diagwin;
}