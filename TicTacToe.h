#pragma once
#include <iostream>
#include <vector>
#include <cctype>  //needed for toupper, islower

class TicTacToe
{
public:
	TicTacToe(unsigned dim = 3) : _dim(dim), free(_dim*_dim), grid(free, '-') {}
	~TicTacToe();
	bool Full() const { return free == 0; }
	void Display() const;
	void Turn(char);
	bool Win(char) const;
private:
	unsigned _dim;
	unsigned free;
	std::vector<char> grid;
	bool Apply(char, int);
};

