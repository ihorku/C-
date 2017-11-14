#ifndef SLOTMACHINE_H
#define SLOTMACHINE_H
#include <array>
#include "Shape.h"


using namespace std;

class SlotMachine{
public:
	SlotMachine() = default;
	SlotMachine(const SlotMachine&) = delete;
	SlotMachine& operator=(const SlotMachine&)=delete;
	void run();
	virtual ~SlotMachine();
private:
	array<Shape*, 3> shape_reel;
	void make_shapes();
	void make_shape(int r);
	void display_shapes();
	void report_status();
	void release_shapes();
	int bet;
	int tokens = 10;
	vector<vector<char>>newGrid;
};


#endif