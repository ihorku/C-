#include <iostream>
#include <string>
#include <algorithm>
#include "Command.h"

using namespace std;

Command::Command(){
	lineAddress1;
	lineAddress2;
	command;

}

void Command::parse(string& commandLine, size_t& currentLine, size_t& lastLine){
	
	trim(commandLine);

		//find possition of the comma
		int commaPos = commandLine.find(',');
		
		
		// if there is no input but enter was pressed
	if (commandLine.size()==0){
		command = 'd';
		lineAddress1 = 1;
		lineAddress2 = 1;
	}
	else {
		// the part before comma, greater than zero means there is at least one charachtere before comma
		if (commaPos > 0){
			//extracting content before comma which is line address 1 in requirements
			string firstPart = commandLine.substr(0, commaPos);
			
			if (firstPart == "."){
				lineAddress1 = currentLine;
			} else if(firstPart == "$"){
				lineAddress1 = lastLine;
			}
			else {
				// if we are here a number is expected
				// if not numerical(or other legal input entred before comma an exception is thrown
				try{
					lineAddress1 = stoi(firstPart);
				}
				catch (const std::invalid_argument& ia) {
					lineAddress1 = currentLine;
					std::cerr << errorMessage() << '\n'; /*<< ia.what()*/
				}
				if (lineAddress1<1 || lineAddress1>lastLine){
					cout << errorMessage() << commandLine << endl;
					lineAddress1 = lineAddress2 = currentLine;
					command = ' ';
					return;
				}
			}
		}
		else if (commaPos == 0){                  
			lineAddress1 = currentLine;
		}
		else {
			lineAddress1 = -1;                    
		}
		//the second part after comma
		string secondPart;
		if (commaPos >= 0){
			secondPart = commandLine.substr(commaPos + 1, commandLine.size() - 1);
			lineAddress2 = currentLine;           //?      
		}
		else {
			secondPart = commandLine;
			lineAddress2 = currentLine;                
		}
		
		
		if (secondPart.size() == 0){
			if (lineAddress1 != -1){
				lineAddress2 = currentLine;					
			}
			else {
				lineAddress1 = lineAddress2 = currentLine;
			}
			command = 'p';
		}
		else if(secondPart[0]=='.'){ 
			if (secondPart.size() > 2){
				cout << errorMessage() << commandLine << endl;
				lineAddress2 = currentLine;
				command = ' ';
				return;
			}
			lineAddress2 = currentLine;
			if (secondPart.size()==1){
				command = 'p';
				}
			else {
				command = secondPart[1];
			}
		}
		else if (secondPart[0] == '$'){
			if (secondPart.size() > 2){
				cout << errorMessage()<<commandLine << endl;
				lineAddress2 = lastLine;
				command = ' ';
				return;
			}
			lineAddress2 = lastLine;
			if (secondPart.size()==1){
				command = 'p';
				
			}
			else {
				command = secondPart[1];
			}
		}
		else {
			string addressLine2 = "";
			int count = 0;

			for (size_t i = 0; i < secondPart.size(); ++i){
				if (isdigit(secondPart[i])){
					addressLine2 += secondPart[i];
					++count;
					lineAddress2 = stoi(addressLine2);
					
				}
				else if (i==secondPart.size()-1)
					{
						command = secondPart[i];
						if (secondPart.size() == 1 && command == 'u'){
							lineAddress2 = 1;
						}
						
					}
					else {
						cout << errorMessage() << commandLine << endl;
						lineAddress2 = currentLine;
						command = ' ';
						return;
					}
				
			}
			if (count == secondPart.size()){
				command = 'p';
			}
			                    
		}
		
		if (lineAddress1 == -1){
			lineAddress1 = lineAddress2;
		}
		if (lineAddress2 == -1){
			lineAddress2 = lineAddress1;
		}
	}
	

}


string Command::trim(string& commandToTrim){

	commandToTrim.erase(remove_if(commandToTrim.begin(), commandToTrim.end(), isspace), commandToTrim.end());
	
	return commandToTrim;
}

char Command::getCommand(){
	return command;
}

int Command::getLineAddress1(){
	return lineAddress1;
}

int Command::getLineAddress2(){
	return lineAddress2;
}

string Command::errorMessage(){
	return "invalid line address : ";
}
