#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <string>
#include <vector>
#include "Shape.h"

class Triangle : public Shape{
public:
	Triangle();
	Triangle(const string& name, const string& dname);
	virtual ~Triangle()=default;
	virtual double area() override;
	virtual int heightBoundBox() override;
	virtual int widthBoundBox() override;
	void setBase(const int& b);
	void setHeight(const int& h);
	int getBase();
	int getHeight();
private:
	int base = 0;
	int height = 0;
};

#endif