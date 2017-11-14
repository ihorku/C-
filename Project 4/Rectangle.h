#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>
#include <string>

#include "Shape.h"

using namespace std;

class Rectangle : public Shape{
public:
	Rectangle();
	Rectangle(const int& w, const int& h);
	Rectangle(const int& h, const int& w, const string& descriptiveName);
	~Rectangle()=default;
	virtual void scale(int factor) override;
	virtual double area() override;
	virtual double perimeter() override;
	virtual vector<vector<char>> draw(char penChar = '*', char fillChar = ' ') override;
	virtual int heightBoundBox() override;
	virtual int widthBoundBox() override;
	virtual int screenArea() override;
	virtual int screenPerimeter() override;
	void setWidth(const int w);
	void setHeight(const int h);
	int getWidth();
	int getHeight();
	
private:
	int width = 0;
	int height = 0;
	
};

#endif