#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
#include <random>
#include <algorithm>

const int GRID_SIZE = 9;


class Puzzle {
private:
	int userDiff = 0;
	int puzzle[GRID_SIZE][GRID_SIZE] = { 0,0 };
	
	struct Indx{						// this will be where all the blank spots are located
		std::vector<int>x;
		std::vector<int>y;
		std::vector<int>value;		
	};			
	
	Indx indx;
public:
	Puzzle();
	~Puzzle();

	void instructions();
	void PrintPuzzle();
	void userCordnites();
	void setBlankIndex();
	void finishPuzzle();

	bool isRowCompleted();
	bool isColCompleted();
	bool isPuzzleCompleted();


};