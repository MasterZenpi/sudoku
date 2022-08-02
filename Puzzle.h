#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <iostream>
#include <random>
#include <algorithm>

const int GRID_SIZE = 9;
const int easy = 3;
const int medium = 6;
const int hard = 9;

	struct Indx{						// this will be where all the blank spots are located
		std::vector<int>x;
		std::vector<int>y;
		std::vector<int>value;		
	};			

class Puzzle {
private:
	int userDiff;
	int puzzle[GRID_SIZE][GRID_SIZE];
	
	
	Indx indx;
public:
	Puzzle();
	~Puzzle();

	void instructions();
	void PrintPuzzle();
	void userCordnites();
	void setBlankIndex();
	void finishPuzzle();

	//bool isRowCompleted();
	//bool isColCompleted();
	bool isPuzzleCompleted();


};