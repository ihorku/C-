#include <iostream>
#include <string>
#include <iomanip>

#include "Shape.h"

using namespace std;

int Shape::id = 0;

Shape::Shape(){
	
}

Shape::Shape(const string& name, const string& descriptiveName){
	++id;
	this->name = name;
	this->descriptiveName = descriptiveName;
}

int Shape::getId() const{
	return id;
}

void Shape::setName(const string& name){
	this->name = name;
}

string Shape::getName(){
	return name;
}

string Shape::getDescriptiveName(){
	return descriptiveName;
}

string Shape::toString(){
	cout << *this;
	return " ";
}

ostream& operator<<(ostream& sout, const vector<vector<char>> &grid){
	for (size_t r = 0; r < grid.size(); ++r){
		for (size_t c = 0; c < grid[r].size(); ++c){
			sout << grid[r][c];
		}
		sout << '\n';
	}
	return sout;
}

ostream& operator<<(ostream& out, Shape& obj){
	out << "Shape Information" 
		<< "\n-----------------" 
		<< "\nStatic type:     " << typeid(&obj).name()
		<< "\nDynamic type:    " << typeid(obj).name()
		<< "\nGeneric name:    " << obj.getName()
		<< "\nDescription:     " << obj.getDescriptiveName()
		<< "\nid:              " << obj.getId()
		<< "\nB.box width:     " << obj.widthBoundBox()
		<< "\nB.box height:    " << obj.heightBoundBox()
		<< "\nScr. area:       " << obj.screenArea()
		<< "\nGeo area:        " << fixed << setprecision(2) << obj.area()
		<< "\nScr perimeter:   " << obj.screenPerimeter()
		<< "\nGeo perimeter:   " << fixed << setprecision(2) << obj.perimeter() << endl;
		
	
	return out;
}
void Shape::draw_on_screen(char penChar, char fillChar){
	cout << this->draw(penChar, fillChar) << endl;
}

void Shape::write_image_to_stream(ostream& cout, char penChar, char fillChar){
	cout << this->draw(penChar, fillChar) << endl;;
}