#include "Puzzle.h"

Puzzle::Puzzle(void) {
	std::cout << "Welcome to Sudoku" << std::endl;
		//these next lines will fill out the 2d puzzle array for the game 
		//variable initiaztion
	std::vector<int> numberLine;
	for (int i = 1; i <= 9; i++) { numberLine.push_back(i); }

	//To Do: make sure that the puzzle is random
	//		i think create two more mumberline vectors and shift threw them in the loop below

	//fills in the puzzle
	for (int row = 0; row < 9; row++) {
		for (int col = 0; col < 9; col++) {
			puzzle[row][col] = numberLine.at(col);
		}
		
	}
}

Puzzle::~Puzzle(void) {
	std::cout << "Thanks for playing\n";
}

void Puzzle::instructions() {
	std::cout << "Chose your Difficulty Level: (1)Easy (2)Medium (3)Hard ";

	std::cin >> userDiff;

	while (userDiff > 3) {
		std::cin.clear();
		std::cout << "Invalid Difficulty level. Please enter a numer between 1 -3 ";
		std::cin >> userDiff;
	}

	switch(userDiff){
		case 1:
			userDiff *= 3;
			break;
		case 2:
			userDiff *= 6;
			break;
		case 3:
			userDiff *= 9;
			break;
	}
	this->userDiff = userDiff;
}

void Puzzle::PrintPuzzle() {
	//***TO-DO***
	//print the blanks from this function. the positions of the blanks will be in the map variable 
	//prints the puzzle 
	for (int row = 0; row < 9; row++) {
		for (int col = 0; col < 9; col++) {
			std::cout << puzzle[row][col] << " ";
		}
		std::cout << std::endl;
	}

}

bool Puzzle::isRowCompleted() {
	return true;
}
bool Puzzle::isColCompleted() {
	return true;
}
bool Puzzle::isPuzzleCompleted() {
	return true;
}

void Puzzle::userCordnites() {
	//this is going to ask the user to enter coordinates (as a string) then it will be split into ints.
	// input should be "(x,y) value"
	
	int x = 0;
	int y = 0;
	int value = 0;
	char throwaway = ' ';

	std::cout << "Please enter x and y coordnites and value. Example: x y value: ";
	std::cin >> x>> y>> value;

	if (this->indx.find(x) == indx.end()){
		if(this->indx[x] == value)
			std::cout << "interted";
	}//end if
}

void Puzzle::setBlankIndex() {
	int x;
	int y;
	srand(time(NULL));
	while(this->indx.size() <= this->userDiff)
	{
		x = rand() % 10;
		y = rand() % 10;
		if (this->indx.find(x) == indx.end()) {
 			 // not found
			 this->indx.insert(std::pair<int, int>(x, y));
			} else {
  			// found
				continue;
			}//end else
	}//end while 
}

void Puzzle::finishPuzzle()
{
	this->userCordnites();	
}