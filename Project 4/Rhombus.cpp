#include <iostream>
#include <string>
#include <math.h>
#include <vector>

#include "Rhombus.h"

using namespace std;

Rhombus::Rhombus() :Shape("Rhombus", "Generic Rhombus"){
	
}

Rhombus::Rhombus(const int d) : Shape("Rhombus", "Generic Rhombus"){
	setDiagonal(d);
}

Rhombus::Rhombus(const int d, const string& dname) : Shape("Rhombus", dname){
	setDiagonal(d);
}

void Rhombus::setDiagonal(const int d){
	if (d >= 1){
		if (d % 2 == 0){
			diagonal = d + 1;
		}
		else {
			diagonal = d;
		}
	}
	else {
		cout << "\n\n*******************************************************************************************\n" << endl;
		cout << "The rhombus diagonal should be greater or equal to 1, try to enter different value, please." << endl;
		cout << "\n*******************************************************************************************\n\n\n" << endl;
	}
}

int Rhombus::getDiagonal(){
	return diagonal;
}
void Rhombus::scale(int factor){
	if ((diagonal + 2 * factor) >= 1){
		setDiagonal(diagonal + 2 * factor);
	}
	else {
		cout << "\n\n\n**********************************************************************************************************************************************" << endl;
		cout << "Scale was not done as after scale value would be less than 1 (" << diagonal + 2 * factor << "), adjust your scale factor and try again, please" << endl;
		cout << "**********************************************************************************************************************************************\n\n\n" << endl;
	}
}
double Rhombus::area(){
	return diagonal*diagonal/2.0;
}
double Rhombus::perimeter(){
	if (diagonal == 0)return 0.0;
	return (2.0*sqrt(2))*diagonal;
}
vector<vector<char>> Rhombus::draw(char penChar, char fillChar){
	vector<vector<char>>grid;
	int h = diagonal/2;
	int w = diagonal;
	grid.resize(diagonal);
	for (int i = 0; i < grid.size(); ++i){
		grid[i].resize(w);
	}
	int row = 1;
	for (row; row <= h; ++row){
		int currentBase = 2 * row - 1;
		int currentFill = (w - currentBase) / 2;
		int column = 0;
		
		for (column; column < currentFill; ++column){
			grid[row - 1][column] = fillChar;
		}
		for (column; column < currentBase + currentFill; ++column){
			grid[row - 1][column] = penChar;
		}
		for (column; column <w; ++column){
			grid[row - 1][column] = fillChar;
		}
		
	}
	
	for (int k=0; k < w; ++k){
		
		grid[row-1][k] = penChar;
	}
	row=h+2;
	for (row; row <=w; ++row){
		
		int currentFill = row-h-1;
		int currentPen = w - 2*currentFill;
		int column = 0;
		
		for (column; column < currentFill; ++column){
			grid[row-1][column] = fillChar;
		}
		for (column; column < currentPen + currentFill; ++column){
			grid[row-1][column] = penChar;
		}
		for (column; column <w; ++column){
			grid[row-1][column] = fillChar;
		}
	}
	return grid;
}
int Rhombus::heightBoundBox(){
	return diagonal;
}
int Rhombus::widthBoundBox(){
	return diagonal;
}
int Rhombus::screenArea(){
	if (diagonal == 0) return 0;
	int n = diagonal / 2;

	return 2*n*(n+1)+1;
}
int Rhombus::screenPerimeter(){
	if (diagonal == 0)return 0;
	return 2*(diagonal-1);
}



