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