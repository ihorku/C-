
#include <iostream>
#include <string>
#include "Led.h"

using namespace std;



int main(int argc, char* argv[])
{
	string filename;
		
	switch (argc){
	case 1:
		break;
	case 2:
		filename = argv[1];
		
		break;
	default: 
		cout << "too many arguments - discarded" << endl;
		break;
	}
	
	Led led(filename);
	led.run();

	
	

	
	


	return 0;
}

