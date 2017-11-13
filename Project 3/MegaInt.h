#ifndef MEGAINT_H
#define MEGAINT_H
#include <iostream>

using namespace std;

class MegaInt{

public:
	MegaInt();
	MegaInt(char sign, deque<char> deque_char);
	MegaInt(MegaInt& megaInt);
	//MegaInt getAccumulator();
	//MegaInt setMegaInt(string input);
	//void getMegaInt();
	//void execute(char command, string input);
	friend ostream& operator<<(ostream& output, const MegaInt& megaInt);
	void increment();
	void decrement();
	void add(MegaInt& B);
	void substract(MegaInt& inputMegaInt);
	void multiply(MegaInt& inputMegaInt);
	void divide(MegaInt&inputMegaInt);
	MegaInt modulus(MegaInt& inputMegaInt);
	void reset(MegaInt& inputMegaInt);
	void clear();
	void setSign(char sign);
	void setInputNumber(deque<char>& number);
	void setNumberFromString(string number);
	void normalize(deque<char>& number);
	void operator+=(MegaInt& B);
	void operator-=(MegaInt& B);
	bool operator>(MegaInt& B);
	bool operator<(MegaInt& B);
	void operator=(MegaInt& megaInt);
	void operator*=(MegaInt& B);
	void operator/=(MegaInt& B);
	MegaInt operator%=(MegaInt& B);
	void operator++();
	void operator--();
	bool operator==(MegaInt& B);
	bool operator>=(MegaInt& B);
	bool operator<=(MegaInt& B);
	void negate();

private:
	//MegaInt *accumulator;
	deque<char> mega_int;
	char sign = '+';
	MegaInt plus(MegaInt& A, MegaInt&B);
	MegaInt minus(MegaInt& A, MegaInt&B);
	MegaInt product(MegaInt& A, MegaInt& B);
	MegaInt quotient(MegaInt& A, MegaInt& B);
	MegaInt mod(MegaInt& A, MegaInt& B);
	MegaInt divedeM1(MegaInt& A, MegaInt& B);
	MegaInt modM1(MegaInt& A, MegaInt& B);
	size_t max(MegaInt& a, MegaInt& b);
	int operator[](int i);
	bool isGreater(MegaInt& B);
	bool isLess(MegaInt& B);
};


#endif