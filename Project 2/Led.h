#ifndef LED_H
#define LED_H

#include <iostream>
#include <string>
#include "Command.h"

using namespace std;

class Led{
private:
	string fileName;
	size_t currentLine=0; //pointer to the current line
	size_t lastLine=0;    // points to the last line
	int lineAddress1 = 0;
	int lineAddress2 = 0;
	size_t count = 0;
	bool saved = true;
	void execute(Command cmd);
	void command_a();
	void command_i();
	void command_r();
	void command_p();
	void command_n();
	void command_c();
	void command_u();
	void command_d();
	void command_w();
	void command_equal_sign();
	void command_q();
	bool boundsCheck();
	
public:
	Led();
	Led(const string&);
	void run();

};

#endif
