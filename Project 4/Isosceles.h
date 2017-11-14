#ifndef ISOSCELES_H
#define ISOSCELES_H
#include <string>
#include "Triangle.h"

class Isosceles : public Triangle{
public:
	Isosceles();
	Isosceles(const int& b);
	Isosceles(const int& b, const string& dname);
	~Isosceles() = default;
	virtual void scale(int factor) override;
	virtual double perimeter() override;
	virtual vector<vector<char>> draw(char penChar = '*', char fillChar = ' ') override;
	virtual int screenArea() override;
	virtual int screenPerimeter() override;
	
};


#endif