#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Shape{
private:
	static int id;
	string name;
	string descriptiveName = "Generic ";
public:
	Shape();
	Shape(const string& name, const string& descriptiveName);
	virtual ~Shape() = default;
	int getId() const;
	void setName(const string& name);
	string getName();
	string getDescriptiveName();
	void setDescriptiveName(string& descriptiveName);
	virtual string toString();
	virtual void scale(int factor) = 0;
	virtual double area() = 0;
	virtual double perimeter() = 0;
	virtual vector<vector<char>> draw(char penChar = '*', char fillChar = ' ') = 0;
	virtual int heightBoundBox() = 0;
	virtual int widthBoundBox() = 0;
	virtual int screenArea() = 0;
	virtual int screenPerimeter() = 0;
	virtual void draw_on_screen(char penChar = '*', char fillChar = ' ');
	friend ostream& operator<<(ostream& sout, const vector<vector<char>>& grid);
	friend ostream& operator<<(ostream& out, Shape& obj);
	virtual void write_image_to_stream(ostream& cout, char penChar = '*', char fillChar = ' ');
};





#endif
