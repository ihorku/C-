#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
#include <deque>
#include "MegaCalc.h"
#include "MegaInt.h"

using namespace std;


MegaInt accumulator;
MegaInt inputNumber;

void MegaCalc::run(){
	
	cout << "Welcome to MegaCalculator" << endl;
	cout << "=========================" << endl;
	do{
		cout << "\nAccumulator: " << accumulator<< endl;
		cout << "Enter input: ";
		cin.sync();
		input.clear();
		cin.clear();
		inputNumber.clear();
		getline(cin, input);
		trim(input);
		
		anylize(input);
		
	
	} while (command != 'q');

	//accumulator.getMegaInt();
}



string MegaCalc::trim(string& input){

	input.erase(remove_if(input.begin(), input.end(), isspace), input.end());

	return input;
}

void MegaCalc::anylize(string input){
	inputNotDigitPart.clear();
	number.clear();
	if (input.size() == 0){         // The idea is if the "enter" pressed without any command all values from previous input are kept
		command = this->command;
		sign = this->sign;
		number = this->number;
	}
	else {
		for (size_t i = 0; i < input.size(); ++i){
			if (!isdigit(input[i])){
				inputNotDigitPart.push_back(input[i]);      // here I read input before number that means command and sign (one, two or three characteres)
			}
			else {
				number.push_back(input[i]);                // after reading command and sign (if any) we get number
			}
		}

		if (number.empty()){                               // this is the case when we get a sigle charactere command or unary operator (++ or --)
			if (inputNotDigitPart.size() == 2){
				if (inputNotDigitPart[0] == '+' && inputNotDigitPart[1] == '+'){
					accumulator.increment();
				}
				else if (inputNotDigitPart[0] == '-' && inputNotDigitPart[1] == '-'){
					accumulator.decrement();
				}
				else {
					cout << "Something went wrong it is not ++ or --, not empty, not number but unary command" << endl;
				}
			}
			else {
				switch (inputNotDigitPart[0])
				{
				case 'q':
					command = 'q';
					cout << "Bye-bye, hope you enjoyed working with the program!" << endl;
					break;
				case 'c':
					accumulator.clear();
					break;
				case 'n':
					accumulator.negate();
					break;
					case 'f':
						factorial();
						break;
					case 'h':
						hailstone();
						break;
				default:
					cout << "Unrecognized command could you verify and try again please" << endl;
					break;
				}
			}
		}
		else {
			if (inputNotDigitPart.size() == 0){
				cout << "Please enter a command first and then a number" << endl;
				return;
			}
			inputNumber.setInputNumber(number); 
			if (inputNotDigitPart.size() == 1){
				inputNumber.setSign('+');
				oneCharCommand(inputNotDigitPart[0]);
				
			}
			else if (inputNotDigitPart.size() == 2 && inputNotDigitPart[1] == '='){
				inputNumber.setSign('+');
				oneCharCommand(inputNotDigitPart[0]);
			}
			else {
				inputNumber.setSign(inputNotDigitPart[1]);
				oneCharCommand(inputNotDigitPart[0]);
			}
		}
	}
	
}

void MegaCalc::factorial(){
	MegaInt one;
	one.setSign('+');
	one.setNumberFromString("1");
	MegaInt mega_fact(one);
	for (MegaInt mega_k = one; mega_k <= accumulator; ++mega_k){
		mega_fact *= mega_k;
		cout << mega_k << "! = " << mega_fact << endl;
	}
}

void MegaCalc::hailstone(){
	MegaInt one, zero, two, temp, three, temp2;
	temp = accumulator;
	temp2 = accumulator;
	zero.setNumberFromString("0");
	one.setSign('+');
	one.setNumberFromString("1");
	two.setNumberFromString("2");
	three.setNumberFromString("3");
	MegaInt mega_fact(one);
	int count = 1;
	cout << "> " << temp << endl;
	while (temp > one){
		if ((temp %= two) == zero){
			temp2 /= two;
			
			++count;
		}
		else {
			temp2 *= three;
			temp2 += one;
			

			++count;
		}
		temp = temp2;
		cout <<"> "<< temp << endl;
	}

	cout << "length of the hailstone (" << accumulator << ") sequence: " << count << endl;

	
}

void MegaCalc::oneCharCommand(char oneChar){
	switch (oneChar)
	{

	case '+': accumulator += inputNumber;              //accumulator.add(inputNumber);
		break;
	case '-': accumulator -= inputNumber;              //accumulator.substract(inputNumber);
		break;
	case '*': accumulator *= inputNumber;              //accumulator.multiply(inputNumber);
		break;
	case '/': accumulator /= inputNumber;              //accumulator.divide(inputNumber);
		break;
	case '%': accumulator %= inputNumber;             //accumulator.modulus(inputNumber);
		break;
	case '=': accumulator.reset(inputNumber);
		break;
	default:
		break;
	}
}