#ifndef MEGACALC_H_
#define MEGACALC_H_
#include <iostream>
#include <deque>
#include <string>

using namespace std;

class MegaCalc{
private:
	string input;
	char command;
	char sign;
	deque<char>number;
	deque<char> inputNotDigitPart;
	std::string trim(std::string&);
	void anylize(string s);
	void oneCharCommand(char oneChar);
public:
	
	void run();
	static void factorial();
	static void hailstone();
};


#endif