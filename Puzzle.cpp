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
	int userDiff;
	std::cout << "Chose your Difficulty Level: (1)Easy (2)Medium (3)Hard ";
	std::cin >> userDiff;

	while (userDiff > 3) {
		std::cin.clear();
		std::cout << "Invalid Difficulty level. Please enter a numer between 1 -3 ";
		std::cin >> userDiff;
	}

	switch(userDiff){
		case 1:
			userDiff *= easy;
			break;
		case 2:
			userDiff *= medium;
			break;
		case 3:
			userDiff *= hard;
			break;
	}
	this->userDiff = userDiff;
	//this->setBlankIndex();
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


bool Puzzle::isPuzzleCompleted() {
	 return (this->x.size() <1)? true: false;
}

void Puzzle::userCordnites() {
	
	int x = 0;
	int y = 0;
	int value = 0;

	std::cout << "Please enter x and y coordnites and value. Example: x y value: ";
	std::cin >> x>> y>> value;
	//if		the x value is found in the x vector				and 		the y value is found in the y vector
	if ((std::find(this->x.begin(), this->x.end(), x)!= this->x.end()) && (std::find(this->y.begin(), this->y.end(), y)!= this->y.end())) {
 			 // not found
			 this->x.push_back(x);
			 this->y.push_back(y);
			 this->value.push_back(value);
			} else {
  			// found
				printf("Oops! the coordnite (%i,%i) has already has a value\n", x,y);
			}//end else

}//end userCordnintes 

void Puzzle::setBlankIndex() {
	//this is going to get random values for x and y to be used in printpuzzle to tell where the blanks go
	int x;
	int y;
	
}

void Puzzle::finishPuzzle()
{
	this->PrintPuzzle();
	this->userCordnites();
		
}