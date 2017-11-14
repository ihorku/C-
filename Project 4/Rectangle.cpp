#include <iostream>
#include <string>
#include <iomanip>
#include <typeinfo>
#include <vector>
#include "Rectangle.h"

using namespace std;

Rectangle::Rectangle():Shape("Rectangle", "Generic Rectangle"){
	width = 0;
	height = 0;
}
Rectangle::Rectangle(const int& w, const int& h):Rectangle(){
	setWidth(w);
	setHeight(h);
}
Rectangle::Rectangle(const int& w, const int& h, const string& descriptiveName):Shape("Rectangle", descriptiveName){
	setWidth(w);
	setHeight(h);
}

void Rectangle::setWidth(const int w){
	if (w >= 1){
		width = w;
	}
	else {
		cout << "\n\n***************************************************************************************************************\n" << endl;
		cout << "You entered "<<w<< " It is not acceptable.The rectangle wigth should be more or equal to 1, try again please." << endl;
		cout << "\n***************************************************************************************************************\n\n\n" << endl;
	}
}

void Rectangle::setHeight(const int h){
	if (h >= 1){
		height = h;
	}
	else {
		cout << "\n\n********************************************************************************************************************\n" << endl;
		cout <<"You entered "<<h<< " It is not acceptable. The rectangle height should be more or eqial to 1, try again please." << endl;
		cout << "\n********************************************************************************************************************\n\n\n" << endl;
	}
}

void Rectangle::scale(int factor){
	if (((width + factor) >= 1) && ((height + factor) >= 1)){
		width += factor;
		height += factor;
	}
	else {
		cout << "n\n\n****************************************************************************************************************************" << endl;
		cout << "No scale was done as after scale the width and the height must be equal or greater than 1. Try another scale factor, please." << endl;
		cout << "****************************************************************************************************************************\n\n\n" << endl;
	}
}
double Rectangle::area(){
	return width*height;
}
double Rectangle::perimeter(){
	return 2 * (width + height);
}
vector<vector<char>> Rectangle::draw(char penChar, char fillChar){
	vector<vector<char>>grid;
	grid.resize(height);
	for (int i = 0; i < grid.size(); ++i){
		grid[i].resize(width);
	}
	for (int row = 0; row < height; ++row){
		for (int column = 0; column < width; ++column){
			grid[row][column] = penChar;
		}
	}
	return grid;
}
int Rectangle::heightBoundBox(){
	return height;
}
int Rectangle::widthBoundBox(){
	return width;
}

int Rectangle::screenArea(){
	return width*height;
}
int Rectangle::screenPerimeter(){
	if (width == 0 || height == 0){
		return 0;
	}
	else {
		return 2 * (height + width) - 4;
	}
}

