#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>

using namespace std;

class Command{
private:
	
	
	int lineAddress1 = -1;             // first charachtere in command line 
	int lineAddress2 = -1;			  // second charachtere in command line
	char command = 'p';			  // command, last symbol in command line if any
	string trim(string& commandReceived);
	
public:
	Command();
	void parse(string& commandLine, size_t& currentLine, size_t& lastLine);
	string errorMessage();
	char getCommand();
	int getLineAddress1();
	int getLineAddress2();
};



#endif