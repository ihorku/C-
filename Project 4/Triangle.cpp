#include <iostream>
#include <string>

#include "Triangle.h"

Triangle::Triangle() :Shape(){

}

Triangle::Triangle(const string& name, const string& dname) : Shape(name, dname){

}

void Triangle::setBase(const int& b){
	if (b >= 1){
		base = b;
	}
	else {
		cout << "\n\n****************************************************************" << endl;
		cout << "\n* The base should be equal or greater than 1, try again please *\n" << endl;
		cout << "****************************************************************\n\n\n" << endl;
	}
}

void Triangle::setHeight(const int& h){
	if (h >= 1){
		height = h;
	}
	else {
		cout << "\n\n****************************************************************" << endl;
		cout << "\n* The base should be equal or greater than 1, try again please *\n" << endl;
		cout << "****************************************************************\n\n\n" << endl;
	}
}

int Triangle::getBase(){
	return base;
}

int Triangle::getHeight(){
	return height;
}


double Triangle::area(){
	return getHeight()*getBase() / 2.0;
}


int Triangle::heightBoundBox(){
	return getHeight();
}
int Triangle::widthBoundBox(){
	return getBase();
}

