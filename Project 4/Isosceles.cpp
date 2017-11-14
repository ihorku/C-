#include <iostream>
#include <string>
#include <vector>
#include <math.h>

#include "Isosceles.h"

using namespace std;

Isosceles::Isosceles() :Triangle("Isosceles", "Generic Isosceles"){
	
}

Isosceles::Isosceles(const int& b) : Isosceles(){
	if (b % 2 == 0){
		setBase(b + 1);
	}
	else {
		setBase(b);
	}
	setHeight((getBase() + 1) / 2);
}

Isosceles::Isosceles(const int& b, const string& dname) : Triangle("Isosceles", dname){

	if (b % 2 == 0){																		
		setBase(b+1);
	}
	else {
		setBase(b);
	}
	setHeight((getBase() + 1) / 2);
}

void Isosceles::scale(int factor){
	if ((getBase() + 2 * factor) >= 1){
		setBase(getBase() + 2 * factor);
		setHeight((getBase() + 1) / 2);
	}
	else {
		cout << "\n\n\n*************************************************************************************************************************************************" << endl;
		cout << "Scale was not done as after scale value would be less than 1 (" << (getBase() + 2 * factor) << "), ajust your scale factor and try again, please." << endl;
		cout << "*************************************************************************************************************************************************\n\n\n" << endl;
	}
}

double Isosceles::perimeter(){
	
		return getBase() + 2 * sqrt(0.25*getBase()*getBase() + getHeight()*getHeight());
	
}
vector<vector<char>> Isosceles::draw(char penChar, char fillChar){
	vector<vector<char>>grid;
	int h = this->getHeight();
	int w = this->getBase();
	grid.resize(h);
	for (int i = 0; i < grid.size(); ++i){
		grid[i].resize(w);
	}
	for (int row = 1; row <= h; ++row){
		int currentBase = 2 * row - 1;
		int currentFill = (w - currentBase) / 2;
		int column = 0;
		
		for (column; column < currentFill; ++column){
			grid[row-1][column] = fillChar;
		}
		for (column; column < currentBase+currentFill; ++column){
			grid[row-1][column] = penChar;
		}
		for (column; column <w; ++column){
			grid[row-1][column] = fillChar;
		}
	}
	return grid;
}

int Isosceles::screenArea(){
	return getHeight()*getHeight();
}
int Isosceles::screenPerimeter(){
	if (getBase() == 0){
		return 0;
	}
	else {
		return 4 * (getHeight() - 1);
	}
}

