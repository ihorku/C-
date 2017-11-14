#include <iostream>
#include "Shape.h"
#include "Triangle.h"
#include "Isosceles.h"
#include "RightTriangle.h"
#include "Rectangle.h"
#include "Rhombus.h"
#include "SlotMachine.h"

using namespace std;

int main(){

	Rectangle shape1(10, 3);
	cout << shape1 << endl;

	Rhombus ace(16, "Ace of diamond");
	cout << ace.toString() << endl;
	cout << ace << endl;

	Isosceles iso(17);
	cout << iso << endl;
	Shape* isoptr = &iso;
	cout << *isoptr << endl;
	Shape& isoref = iso;
	cout << isoref << endl;

	RightTriangle rt(10, "Carpenter's square");
	cout << rt << endl;

	cout << shape1.draw() << endl;

	cout << ace.draw('o') << endl;

	cout << iso.draw('\\', '.') << endl;

	cout << rt.draw('+', '-');

	ace.draw_on_screen(' ', 'o');

	ace.scale(-4);

	ace.write_image_to_stream(cout, '1');

	ace.scale(2);
	ace.write_image_to_stream(cout, 'A', '.');

	SlotMachine one;
	one.run();


	return 0;
}

