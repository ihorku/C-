#include <iostream>
#include <string>
#include <math.h>
#include <vector>

#include "RightTriangle.h"

using namespace std;

RightTriangle::RightTriangle() :Triangle("RightTriangle", "Generic RightTriangle"){
	
}

RightTriangle::RightTriangle(const int& b) : RightTriangle(){
	setBase(b);
	setHeight(b);
}

RightTriangle::RightTriangle(const int& b, const string& dname) : Triangle("RightTriangle", dname){
	setBase(b);
	setHeight(b);
}

void RightTriangle::scale(int factor){
	if ((getBase() + factor) >= 1){
		setBase(getBase() + factor);
		setHeight(getHeight() + factor);
	}
	else {
		cout << "\n\n\n*********************************************************************************************************************************************" << endl;
		cout << "Scale was not done as after scale value would be less than 1 (" << (getBase() + factor) << "), adjust your scale factor and try again, please" << endl;
		cout << "*********************************************************************************************************************************************\n\n\n" << endl;
	}
}

double RightTriangle::perimeter(){
	return (2.0+sqrt(2.0))*getHeight();
}
vector<vector<char>> RightTriangle::draw(char penChar, char fillChar){
	vector<vector<char>>grid;
	int h = this->getHeight();
	int w = this->getBase();
	grid.resize(h);
	for (int i = 0; i < grid.size(); ++i){
		grid[i].resize(w);
	}
	for (int row = 0; row < h; ++row){
		for (int column = 0; column <= row; ++column){
			grid[row][column] = penChar;
		}
		for (int column = row+1; column < w; ++column){
			grid[row][column] = fillChar;
		}
	}
	return grid;
}

int RightTriangle::screenArea(){
	return getHeight()*(getHeight()+1)/2;
}
int RightTriangle::screenPerimeter(){
	if (getBase() == 0){
		return 0;
	}
	else {
		return 3 * (getHeight() - 1);
	}
}

