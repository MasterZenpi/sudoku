#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <Time.h>
#include <iostream>
#include <random>
#include <utility>
#include <algorithm>

const int GRID_SIZE = 9;
const int easy = 3;
const int medium = 6;
const int hard = 9;
			

class Puzzle {
private:
	int userDiff;
	int puzzle[GRID_SIZE][GRID_SIZE];

	std::vector<int>value;	// this will be where all the blank spots are located
							// to get the the value into index, divide the number by 9 and the whole number is the row
							// and the remainder is the column	
	
	
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