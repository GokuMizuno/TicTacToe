/*G. Stangler
A simple TicTacToe game, optimized by SO, and me.*/
#include <iostream>
#include <vector>
#include "TicTacToe.h"

//Prototypes

//actual program
int main()
{
	TicTacToe ttt;
	const char players[2] = { 'X', 'O' };
	int player = 1;
	bool win = false;
	bool full = false;

	while (!win && !full)
	{
		player = 1 - player;
		ttt.Display();
		ttt.Turn(players[player]);
		win = ttt.Win(players[player]);
		full = ttt.Full();
	}

	ttt.Display();
	if (win)
	{
		std::cout << "\n" << players[player] << " is the winner.\n";
	}
	else
	{
		std::cout << "Tie game.\n";
	}

	return 0;
}