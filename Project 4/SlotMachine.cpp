#include <iostream>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include "SlotMachine.h"
#include "Rectangle.h"
#include "Isosceles.h"
#include "Rhombus.h"
#include "RightTriangle.h"

using namespace std;

SlotMachine::~SlotMachine(){
	release_shapes();
}

void SlotMachine::run(){
	cout << "Welcome to this 3-Reel Slot Machine Game!" << endl;
	cout << "Each reel will randomly display one of four shapes, each in 25 sizes." << endl;
	cout << "To win 3 times your bet you  need 3 similar shapes of the same size." << endl;
	cout << "To win 2 times your bet you  need  3 similar shapes." << endl;
	cout << "To win or lose nothing you need 2 similar shapes." << endl;
	cout << "Otherwise, you lose your bet." << endl;
	cout << "You start with 10 free tokens !" << endl;
	cout << endl;

	// initialize random seed
	srand(time(NULL));

	while (tokens>0){
		cout << "How much would you like to bet (enter 0 to quit)? ";
		cin >> bet;
				
		while (((tokens - bet) < 0) || (bet < 0) || !cin){
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Your bet is invalid or you don't have sufficient amount of tokens. Check your input and try again." << endl;
			cin >> bet;
			}
		if (bet == 0){
			break; 
			}
		cin.clear();
		cin.ignore(100, '\n');
		make_shapes();
		display_shapes();
		report_status();

		if ((shape_reel[0]->getName() == shape_reel[1]->getName()) && (shape_reel[1]->getName() == shape_reel[2]->getName()) && (shape_reel[0]->widthBoundBox() == shape_reel[1]->widthBoundBox()) && (shape_reel[1]->widthBoundBox() == shape_reel[2]->widthBoundBox()) && (shape_reel[0]->heightBoundBox() == shape_reel[1]->heightBoundBox()) && (shape_reel[1]->widthBoundBox() == shape_reel[2]->widthBoundBox()) && (shape_reel[1]->heightBoundBox() == shape_reel[2]->heightBoundBox())){
			cout << "Congratulations!!! You win 3 times your bet: " << 3 * bet << endl;
			tokens = tokens + 3 * bet;
		}
		else if ((shape_reel[0]->getName() == shape_reel[1]->getName()) && (shape_reel[1]->getName() == shape_reel[2]->getName())){
			cout << "Congratulations! You win 2 times your bet: " << 2 * bet << endl;
			tokens = tokens + 2 * bet;
		} else if (shape_reel[0]->getName() == shape_reel[1]->getName() || shape_reel[0]->getName()==shape_reel[2]->getName() || shape_reel[1]->getName()==shape_reel[2]->getName()){
			cout << "You don't win, you don't lose, you are safe!" << endl;
		}
		else {
			cout << "You lose your bet." << endl;
			tokens -= bet;
		}
		cout << "You now have " << tokens << " tokens." << endl;
		cout << endl;
		//frees dynamic memory consumed by the reels, if tokens == 0 destructor will take care of it
		if (tokens != 0){
			release_shapes();
		}
	}
	cout << "Game over you now have "<<tokens<<" tokens!" << endl;
}

void SlotMachine::make_shapes(){
	for (int i = 0; i < shape_reel.size(); ++i){
		make_shape(i);
	}
}
void SlotMachine::make_shape(int r){
		
	int n = rand() % 4;          // generates random numbers from 0 to 3
	int w = rand() % 25 + 1;     // generates random numbers from 1 to 25
	
	switch (n){
	case 0: 
		shape_reel[r] = new Rhombus(w);
		break;
	case 1: shape_reel[r] = new Isosceles(w);
		break;
	case 2: shape_reel[r] = new RightTriangle(w);
		break;
	case 3:
		int h = rand() % 25 + 1;
		shape_reel[r] = new Rectangle(w, h);
		break;
			
	}
}

void SlotMachine::display_shapes(){
	
	vector<vector<char>>firstShape = shape_reel[0]->draw();
	vector<vector<char>>secondShape = shape_reel[1]->draw();
	vector<vector<char>>thirdShape = shape_reel[2]->draw();
	
	// calculating maximum (what shape has a maximun length)
	int maxHeight;
	int gridWidth = 0;
	maxHeight = shape_reel[0]->heightBoundBox();
	for (int i = 0; i < shape_reel.size(); ++i){
		if (maxHeight < shape_reel[i]->heightBoundBox()){
			maxHeight = shape_reel[i]->heightBoundBox();
		}
		gridWidth += shape_reel[i]->widthBoundBox();
	}

	// height and width of a new grid
	int gridHeight = maxHeight+4;     
	gridWidth += 10;
	
	
	// Creating newGrid
	newGrid.resize(gridHeight);

	for (int k = 0; k < newGrid.size(); ++k){
		newGrid[k].resize(gridWidth);
	}

	// coordinates of inside borders between shapes
	int widthObj1 = shape_reel[0]->widthBoundBox()+3;
	int widthObj2 = widthObj1+shape_reel[1]->widthBoundBox() + 3;
	
	
	//draw the frame from here *********************************************
	for (int k = 0; k < gridWidth; ++k){
		if (k == 0 || k==gridWidth-1 || k==widthObj1 || k==widthObj2){
			newGrid[0][k] = '+';                                        //cout << '+';
		}
		else {
			newGrid[0][k] = '-';                                       //cout << '-';
		}
	}
	
	for (int l = 1; l < gridHeight - 1; ++l){
		for (int k = 0; k < gridWidth; ++k){
			if (k == 0 || k == gridWidth - 1 || k == widthObj1 || k == widthObj2){
				newGrid[l][k] = '|';                                                    //cout << '|';
			}
			else {
				newGrid[l][k] = ' ';                                                     //cout << ' ';
			}
		}
		
	}
	for (int k = 0; k < gridWidth; ++k){
		if (k == 0 || k == gridWidth - 1 || k == widthObj1 || k == widthObj2){
			newGrid[gridHeight-1][k] = '+';                                                       //cout << '+';
		}
		else {
			newGrid[gridHeight-1][k] = '-';                                                      //  cout << '-';
		}
	}
	
	// until here*****************************************************


	// insertin first Shape

	for (int i = 0; i < shape_reel[0]->heightBoundBox(); ++i){
		for (int j = 0; j < shape_reel[0]->widthBoundBox(); ++j){
			newGrid[i + 2][j + 2] = firstShape[i][j];
		}
	
	}

	// insersion second Shape
	for (int i = 0; i < shape_reel[1]->heightBoundBox(); ++i){
		for (int j = 0; j < shape_reel[1]->widthBoundBox(); ++j){
			newGrid[i + 2][(widthObj1 + 2)+j] = secondShape[i][j];
		}
		
	}

	// insertion third Shape
	for (int i = 0; i < shape_reel[2]->heightBoundBox(); ++i){
		for (int j = 0; j < shape_reel[2]->widthBoundBox(); ++j){
			newGrid[i + 2][(widthObj2 + 2)+j] = thirdShape[i][j];
		}
		
	}

	// final output
	for (int r = 0; r < gridHeight; ++r){
		for (int c = 0; c < gridWidth; ++c){
			cout << newGrid[r][c];
		}
		cout << endl;
	}

}

void SlotMachine::report_status(){
	cout << "(" << shape_reel[0]->getName() << ", " << shape_reel[0]->widthBoundBox() << ", " << shape_reel[0]->heightBoundBox() << ") ";
	cout << "(" << shape_reel[1]->getName() << ", " << shape_reel[1]->widthBoundBox() << ", " << shape_reel[1]->heightBoundBox() << ") ";
	cout << "(" << shape_reel[2]->getName() << ", " << shape_reel[2]->widthBoundBox() << ", " << shape_reel[2]->heightBoundBox() << ") "<<endl;
}

void SlotMachine::release_shapes(){
	delete[] shape_reel[0];
	delete[] shape_reel[1];
	delete[] shape_reel[2];
	
}


/*SlotMachine& SlotMachine::operator=(const SlotMachine& sm){
	if (this == &sm){
		return *this;
	}
	else {
		delete[] shape_reel[0];
		delete[] shape_reel[1];
		delete[] shape_reel[2];

		for (int i = 0; i < shape_reel.size(); ++i){
			shape_reel[i] = sm.shape_reel[i];
		}

	}
}*/

