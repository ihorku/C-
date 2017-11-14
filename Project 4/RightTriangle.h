#ifndef RIGHTTRIANGLE_H
#define RIGHTTRIANGLE_H
#include <string>
#include "Triangle.h"

class RightTriangle : public Triangle{
public:
	RightTriangle();
	RightTriangle(const int& b);
	RightTriangle(const int& b, const string& dname);
	~RightTriangle()=default;
	virtual void scale(int factor) override;
	virtual double perimeter() override;
	virtual vector<vector<char>> draw(char penChar = '*', char fillChar = ' ') override;
	virtual int screenArea() override;
	virtual int screenPerimeter() override;
	
};


#endif