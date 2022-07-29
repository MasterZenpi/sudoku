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
	int userDiff;
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


bool Puzzle::isPuzzleCompleted() {
	(this->indx.x.size() >1)? true: false;
}

void Puzzle::userCordnites() {
	//this is going to ask the user to enter coordinates (as a string) then it will be split into ints.
	// input should be "(x,y) value"
	
	int x = 0;
	int y = 0;
	int value = 0;

	std::cout << "Please enter x and y coordnites and value. Example: x y value: ";
	std::cin >> x>> y>> value;
	//if		the x value is found in the x vector				and 		the y value is found in the y vector
	if ((std::find(indx.x.begin(), indx.x.end(), x)!= indx.x.end()) && (std::find(indx.y.begin(), indx.y.end(), y)!= indx.y.end())) {
 			 // not found
			 indx.x.push_back(x);
			 indx.y.push_back(y);
			 indx.value.push_back(value);
			} else {
  			// found
				printf("Oops! the coordnite (%i,%i) has already has a value\n", x,y);
			}//end else

}//end userCordnintes 

void Puzzle::setBlankIndex() {
	//this is going to get random values for x and y to be used in printpuzzle to tell where the blanks go
	int x;
	int y;
	
	srand(time(NULL));
	while((this->indx.x.size() <= this->userDiff) && (this->indx.y.size() <= this->userDiff))
	{
		x = rand() % 10;
		y = rand() % 10;
		if ((std::find(this->indx.x.begin(), this->indx.x.end(), x)) != this->indx.x.end() && (this->indx.x.size() <= this->userDiff))
			this->indx.x.push_back(x);
	

		if ((std::find(this->indx.y.begin(), this->indx.y.end(), x)) != this->indx.y.end() && (this->indx.y.size() <= this->userDiff))
			this->indx.y.push_back(y);
	}//end while 
}

void Puzzle::finishPuzzle()
{
	this->PrintPuzzle();
	this->userCordnites();	
}