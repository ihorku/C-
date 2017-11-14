#ifndef RHOMBUS_H
#define RHOMBUS_H
#include <string>
#include "Triangle.h"

class Rhombus : public Shape{
public:
	Rhombus();
	Rhombus(const int d);
	Rhombus(const int d, const string& dname);
	~Rhombus() = default;
	virtual void scale(int factor) override;
	virtual double area() override;
	virtual double perimeter() override;
	virtual vector<vector<char>> draw(char penChar = '*', char fillChar = ' ') override;
	virtual int heightBoundBox() override;
	virtual int widthBoundBox() override;
	virtual int screenArea() override;
	virtual int screenPerimeter() override;
	void setDiagonal(const int d);
	int getDiagonal();
	
private:
	int diagonal=0;
};


#endif