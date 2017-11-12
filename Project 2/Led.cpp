
#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include "Led.h"

using namespace std;

list<string>buffer;
list<string>::iterator it;
list<string>::iterator it2;


Led::Led(){
	cout << "?" <<" [New File]" << endl;
	currentLine = 0;
	lastLine = 0;
}


Led::Led(const string& file){
	
	fileName = file;

	ifstream openedFile(file);
	if (openedFile){
		string line;
		if (openedFile.is_open()){
			while (getline(openedFile, line)){
				buffer.push_back(line);
				++lastLine;
			}
			currentLine = buffer.size();
		}
		cout << "\"" << file << "\" " << currentLine << " lines" << endl;
	}
	else {
		if (file == "") {
			Led();
		}
		else {

			cout << "\"" << file << "\" " << " [New File]" << endl;
			currentLine = 0;
		}
	}
}


void Led::run(){
	
	cout << "Entering command mode." << endl;
	
	string commandLine;
	Command cmd;
	do{
		cout << ": ";
		getline(cin, commandLine);
		cmd.parse(commandLine, currentLine, lastLine);
		lineAddress1 = cmd.getLineAddress1();
		lineAddress2 = cmd.getLineAddress2();

		execute(cmd);
	} while (cmd.getCommand() != 'q');
		
}

void Led::execute(Command cmd){
	switch (cmd.getCommand()){
		case 'a':
			command_a();
			break;
		case 'i':
			command_i();
			break;
		case 'r':
			command_r();
			break;
		case 'p':
			command_p();
			break;
		case 'n':
			command_n();
			break;
		case 'c':
			command_c();
			break;
		case 'u':
			command_u();
			break;
		case 'd':
			command_d();
			break;
		case 'w':
			command_w();
			break;
		case '=':
			command_equal_sign();
			break;
		case 'q':
			command_q();
			break;
		case ' ':
			break;
	
	default:
		cout << "Verify your entry and try again, please." << endl;
		break;
	}
}


void Led::command_q(){
	string response;
	if (!saved){
		if (fileName == ""){
			cout << "Save changes to your new file (y/n)? "<<endl;
		}
		else{
			cout << "Save changes to \"" << fileName << "\" (y/n)? "<<endl;
		}
		
		cin>> response;
		
		while ((response.compare("y")!=0) && (response.compare("n")!=0)){
			cin.clear();
			cin.ignore(100, '\n');
			
			cout << "invalid answer " << response << "\nenter y for yes and n for no." << endl;
			cout << "Save changes to \"" << fileName << "\" (y/n)? "<<endl;
			cin>>response;
			
		}
		if (response.compare("y")==0){
			cin.clear();
			cin.ignore(100, '\n');
			command_w();
		}
		
	}
	cout << "quitting led . . . bye." << endl;
}


void Led::command_a(){
	if (lineAddress1<0 || lineAddress2>lastLine){
		cout << "line address is out of bounds" << endl;
		return;
	}
	
	string line;
	getline(cin, line);
	
	it = buffer.begin();
	if (lineAddress2 < 0){     
		lineAddress2 = 0;
	}
    advance(it, lineAddress2);
	while (cin.good() && line != "."){
		buffer.insert(it,line);
		getline(cin, line);
		++count;
		saved = false;
	}
	currentLine =lineAddress2 + count;
	lastLine += count;
	count = 0;
	
}

void Led::command_i(){

	if (lineAddress1<0 || lineAddress2>lastLine){
		cout << "line address is out of bounds" << endl;
		return;
	}

	string line;
	getline(cin, line);

	it = buffer.begin();
	
	if (lineAddress2 < 0){      
		lineAddress2 = 0;
	}
	else if (lineAddress2>0){
		lineAddress2--;
	}
	advance(it, lineAddress2);              
	while (cin.good() && line != "."){
		buffer.insert(it, line);
		getline(cin, line);
		++count;
		saved = false;
	}
	currentLine =lineAddress2 + count;
	lastLine += count;
	count = 0;
	
}

void Led::command_r(){

	if (boundsCheck()){
		return;
	}

	it = it2 = buffer.begin();
	advance(it, lineAddress1-1);                
	advance(it2, lineAddress2);

	buffer.erase(it, it2);
	saved = false;
	if (lineAddress2 == lastLine){
		currentLine = lineAddress1 - 1;
	}
	else {
		currentLine = lineAddress1;
	}
	
	lastLine = lastLine - (lineAddress2 - lineAddress1)-1;

	
}

void Led::command_p(){

	if (currentLine == 0){
		cout << "There is nothing to print the file is empty try another command." << endl;
		return;
	}

	if (boundsCheck()){ 
		return; 
	}


	it = it2 = buffer.begin();
	advance(it, lineAddress1 - 1);              
	advance(it2, lineAddress2);

	for (it; it != it2; ++it){
		cout << *it << endl;
	}
	currentLine = lineAddress2;
}

void Led::command_n(){
	if (currentLine == 0){
		cout << "There is nothing to print the file is empty try another command." << endl;
		return;
	}
	if (boundsCheck()){
		return;
	}

	it = it2 = buffer.begin();
	advance(it, lineAddress1 - 1);
	advance(it2, lineAddress2);

	count = lineAddress1;

	for (it; it != it2; ++it){
		cout <<count<<"	"<< *it << endl;
		++count;
	}
	currentLine = lineAddress2;
	count = 0;
}

void Led::command_c(){

	if (boundsCheck()){
		return;
	}

	cout << "change what? ";
	string changeWhat;
	getline(cin, changeWhat);
	
	cout << "    to what? ";
	string toWhat;
	getline(cin, toWhat);
		
	it = it2 = buffer.begin();
	advance(it, lineAddress1 - 1);
	advance(it2, lineAddress2);
	    
	for (it; it != it2; ++it){
		
		string temp = *it;
		
		size_t found= temp.find(changeWhat);
		
		while (found != string::npos){
			
			

			if (found != string::npos){
				temp.replace(found, changeWhat.length(), toWhat);
				saved = false;
			}
			found = temp.find(changeWhat, found+toWhat.size());
		}
		*it = temp;
	}
	currentLine = lineAddress2;
	
}


void Led::command_u(){
	if (currentLine <= 1){
		cout << "BOF reached" << endl;
		return;
	}
	if (currentLine <= lineAddress2){
		cout << "BOF reached" << endl;
		currentLine = 1;
	}
	else {
		currentLine = currentLine - lineAddress2;
	}
	
	it = buffer.begin();
	advance(it, currentLine-1);
	cout << *it << endl;

	
}

void Led::command_d(){
	if (lastLine == 0){
		cout << "EOF reached" << endl;
		return;
	}
	if ((currentLine + lineAddress2) > lastLine){
		cout << "EOF reached" << endl;
		currentLine = lastLine;
	}
	else {
		currentLine = currentLine + lineAddress2;
	}

	it = buffer.begin();
	advance(it, currentLine - 1);
	cout << *it << endl;
}

void Led::command_w(){
	if (fileName == ""){
		cout << "Write the full name of the file you want to save: "<<endl;
		getline(cin, fileName);
		
	}
	ofstream fileToSave;
	fileToSave.open(fileName);
	it = buffer.begin();
	for (it; it != buffer.end(); ++it){
		fileToSave << *it<<"\n";
	}
	fileToSave.close();
	cout << "\"" << fileName << "\" " << lastLine << " lines written" << endl;
	saved = true;
}

void Led::command_equal_sign(){
	
	if (currentLine == 0){
		cout << "There is nothing to print the file is empty try another command." << endl;
		return;
	}

	it = it2 = buffer.begin();
	advance(it2, currentLine);
	cout <<distance(it, it2)  << endl;
}

bool Led::boundsCheck(){
	if (lineAddress2>lastLine || lineAddress1 < 1){
		cout << "\nYou are trying to go beyond the existing list.\nVerify your entry and try again." << endl;
		
		return true;
	}
	else {
		return false;
	}
}