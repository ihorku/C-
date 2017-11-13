#include <iostream>
#include <deque>
#include <string>

#include "MegaInt.h"

using namespace std;

MegaInt::MegaInt(){
	sign;
	mega_int.assign(1,'0');
}

MegaInt::MegaInt(MegaInt& megaInt){
	this->sign = megaInt.sign;
	this->mega_int = megaInt.mega_int;
}
//MegaInt accumulator;

/*MegaInt MegaInt::getAccumulator(){
	return MegaCalc::accumulator;
}*/

void MegaInt::setSign(char sign){
	this->sign = sign;
}

void MegaInt::setInputNumber(deque<char>& number){    
	for (size_t i = 0; i < number.size(); ++i){
		mega_int.push_back(number[i]);
	}
}

void MegaInt::setNumberFromString(string number){
	for (size_t i = 0; i < number.size(); ++i){
		this->mega_int.push_back(number[i]);
	}
	normalize(this->mega_int);

}

/*void MegaInt::getMegaInt(){
	cout << sign;
	for (size_t i = 0; i < mega_int.size(); ++i){
		cout<<mega_int[i];
	}
	cout << endl;
}*/

ostream& operator<<(ostream& output, const MegaInt& megaInt){
	output << megaInt.sign;
	for (size_t i = 0; i < megaInt.mega_int.size(); ++i){
		output << megaInt.mega_int[i];
	
	}
	return output;
}

void MegaInt::increment(){
	MegaInt one;
	one.sign = '+';
	one.mega_int.assign(1, '1');
	this->add(one);
}
void MegaInt::operator++(){
	this->increment();
}
void MegaInt::decrement(){
	MegaInt one;
	one.sign = '+';
	one.mega_int.assign(1, '1');
	this->substract(one);
}

void MegaInt::operator--(){
	this->decrement();
}

void MegaInt::add(MegaInt& B){  
	normalize(B.mega_int);
	
	MegaInt A,C;
	A.sign = this->sign;
	A.mega_int = this->mega_int;
	
	if (A.sign == B.sign){
		C = plus(A, B);
		C.sign = A.sign;
	}
	else {
		if (A.isGreater(B)){
			
			C = minus(A, B);
			C.sign = A.sign;
		} 
		else if (A.isLess(B)){
			C.sign = A.sign;
			C.negate();
			C = minus(B, A);
		}
		else {
			C.sign = '+';
			C.mega_int.clear();
			C.mega_int.push_back('0');
		}
	}
	normalize(C.mega_int);
	this->sign = C.sign;
	this->mega_int = C.mega_int;
}

MegaInt MegaInt::plus(MegaInt& A, MegaInt& B){
	
	MegaInt Z;
	int carry = 0;
	int i,j,p,k;
	string s;
	int t = 0;
	p = max(A, B)+1;
	
	Z.mega_int.resize(0);
	
	i = p - 1;
	j = A.mega_int.size()-1;
	k = B.mega_int.size()-1;
	
	while (j >= 0 && k >= 0){
		t = A[j] + B[k] + carry;
		s = to_string(t % 10);
		Z.mega_int.push_front(s[0]);
		carry = t / 10;
		--i;
		--j;
		--k;
	}
	
	while (j >= 0){
		t = A[j] + carry;
		s = to_string(t % 10);
		Z.mega_int.push_front(s[0]);
		carry = t / 10;
		--i;
		--j;
	}

	while (k >= 0){
		t = B[k] + carry;
		s = to_string(t % 10);
		Z.mega_int.push_front(s[0]);
		carry = t / 10;
		--i;
		--k;
	}
	s = to_string(carry);
	Z.mega_int.push_front(s[0]);
	
	return Z;
}

size_t MegaInt::max(MegaInt& a, MegaInt& b){
	int p;
	if (a.mega_int.size() > b.mega_int.size()){
		p = a.mega_int.size();
	}
	else {
		p = b.mega_int.size();
	}
	return p;
}

 void MegaInt::operator+=(MegaInt& B){
	 
	 this->add(B);
}

 void MegaInt::operator-=(MegaInt& B){

	 this->substract(B);
 }

void MegaInt::substract(MegaInt& B){
	
	normalize(B.mega_int);

	MegaInt A, C;
	A.sign = this->sign;
	A.mega_int = this->mega_int;
	if (A.sign != B.sign){
		C = plus(A, B);
		C.sign = A.sign;
	}
	else {
		if (A.isGreater(B)){
			C = minus(A, B);   
			C.sign = A.sign;
		}
		else if (A.isLess(B)){                     
			C = minus(B, A);
			C.sign = A.sign;
			C.negate();
			
		}
		else {
			
			C.mega_int.clear();
			C.mega_int.push_back('0'); 
			C.sign = '+';				
		}
	}
	normalize(C.mega_int);
	this->sign = C.sign;
	this->mega_int = C.mega_int;
}

MegaInt MegaInt::minus(MegaInt& A, MegaInt& B){
	
	MegaInt Z;
	int borrow = 0;
	int i, j, p, k;
	string s;
	int t = 0;
	p = max(A, B);

	Z.mega_int.resize(0);

	i = p - 1;
	j = A.mega_int.size() - 1;
	k = B.mega_int.size() - 1;

	while (j >= 0 && k >= 0){
		t = A[j] - (B[k] + borrow);
		borrow = 0;
		if (t < 0){
			borrow = 1;
			t = 10 + t;
		}
		s = to_string(t);
		Z.mega_int.push_front(s[0]);
		
		--i;
		--j;
		--k;
	}

	while (j >= 0){
		t = A[j] - borrow;
		borrow = 0;
		if (t < 0){
			borrow = 1;
			t = 10 + t;
		}
		s = to_string(t);
		Z.mega_int.push_front(s[0]);
		--i;
		--j;
	}
	
	if (borrow == 1 || k >= 0){
		cout << "X cannot be less than Y in (X - Y)" << endl;
	}
	else {
		
        return Z;
	}
		
}


void MegaInt::multiply(MegaInt& B){
	MegaInt C,A;
	A.sign = this->sign;
	A.mega_int = this->mega_int;
	if (A.sign == B.sign){
		if (A.isGreater(B)){
			C = product(A, B);
		}
		else {
			C = product(B, A);
		}
		C.sign = '+';
	}
	else {
		if (A.isGreater(B)){
			C = product(A, B);
		}
		else {
			C = product(B, A);
		}
		C.sign = '-';
	}
	normalize(C.mega_int);
	this->sign = C.sign;
	this->mega_int = C.mega_int;
}

MegaInt MegaInt::product(MegaInt& A, MegaInt& B){
	MegaInt Z;
	MegaInt temp;
	int carry = 0;
	int i, j, k;
	string s;
	int t = 0;
	
	Z.mega_int.resize(0);
		
	k = B.mega_int.size() - 1;
	i = 0;           

	while (k >= 0){
    j = A.mega_int.size() - 1;
	carry = 0;
    
	temp.clear();
	temp.mega_int.assign(i, '0');                           //this shifts one (i) position left when calculating every next partial sum
	while (j >= 0) {
			t = A[j] * B[k] + carry;
			s = to_string(t % 10);
			temp.mega_int.push_front(s[0]);
			carry = t / 10;
			
			--j;
		}
		++i;
		s = to_string(carry);
		temp.mega_int.push_front(s[0]);
		normalize(temp.mega_int);
		Z = plus(Z, temp);
		--k;
	} 
	
	return Z;
}

void MegaInt::operator*=(MegaInt& B){

	this->multiply(B);
}

void MegaInt::operator/=(MegaInt& B){

	this->divide(B);
}


void MegaInt::divide(MegaInt& B){
	MegaInt A, C;
	A.sign = this->sign;
	A.mega_int = this->mega_int;
	if (A.isLess(B)){
		cout << "Sorry, devident(accumulator) must be greater than divisor(input number), try again" << endl;
	}
	else {
		if (A.sign == B.sign){
			A.setSign('+');
			B.setSign('+');
			C = divedeM1(A, B);           //C = quotient(A, B);
			C.sign = '+';
		}
		else {
			C = divedeM1(A, B);            //C = quotient(A, B);
            C.sign = '-';
		}
	}
	normalize(C.mega_int);
	this->sign = C.sign;
	this->mega_int = C.mega_int;
}

MegaInt MegaInt::divedeM1(MegaInt& A, MegaInt& B){
	MegaInt Z, r,zero, count;
	zero.setNumberFromString("0");
	count.setNumberFromString("0");
	while (A >= zero && A>=B){
		A -= B;
		++count;

		r = A;
		
	}

	return count;
}
MegaInt MegaInt::modM1(MegaInt& A, MegaInt& B){
	MegaInt Z, r, zero, count;
	zero.setNumberFromString("0");
	count.setNumberFromString("0");
	while (A >= zero && A >= B){
		A -= B;
		++count;

		r = A;

	}

	return r;
}
MegaInt MegaInt::quotient(MegaInt& A, MegaInt& B){
	MegaInt Z;
	MegaInt temp,tempB, r, one;
	int j, k, n;
	string s;
	int q = 0;
	n = B.mega_int.size();
	
	tempB = B;
	j = 0;
	Z.mega_int.resize(0);

	for (size_t i = 0; i < n; ++i){
		temp.mega_int.push_back(A.mega_int.at(i));
	}
	normalize(temp.mega_int);
	k = (A.mega_int.size() - B.mega_int.size())+1;

	while (k >= 0){
		
		if (temp < tempB){

			one.setNumberFromString("0");
			tempB.multiply(one);
			temp.substract(tempB);
			r = temp;
				if ((n+1) >= A.mega_int.size()){
					
					temp.mega_int.push_back(one.mega_int.front());
					--j;
				}
				else{
			while (r>one && j > 0){
				
					temp.mega_int.push_back(A.mega_int.at(n));
					++n;
					--j;
				}
			
				temp.mega_int.push_back(A.mega_int.at(n));
				Z.mega_int.push_back(one.mega_int.front());
				
				++n;
			}
		}
		else {
			
			one.setNumberFromString("1");
			for (size_t i = 1; i <= 10; ++i){
				tempB = B;
				tempB.multiply(one);
				
				
				
				if (tempB == temp){
					break;
				}
				if (tempB>temp){
					--one;
					break;
				}
				
				++one;
				
			}
			normalize(one.mega_int);
			Z.mega_int.push_back(one.mega_int.front());
			tempB = B;
			tempB.multiply(one);
			temp.substract(tempB);
			
			r = temp;
			
			++j;
		}
		tempB = B;
		
		one.clear();
		--k;
		
	}
	
	return Z;
}

MegaInt MegaInt::modulus(MegaInt& B){
	MegaInt A, C;
	A.sign = this->sign;
	A.mega_int = this->mega_int;
	if (A.isLess(B)){
		C.mega_int = this->mega_int;
		C.sign = this->sign;
	}
	else {
		if (A.sign == B.sign){
			A.setSign('+');
			B.setSign('+');
			C = modM1(A, B);
			C.sign = '+';
		}
		else {
			C = modM1(A, B);
			C.sign = '-';
		}
	}
	normalize(C.mega_int);
	this->sign = C.sign;
	this->mega_int = C.mega_int;

	return *this;
}

MegaInt MegaInt::mod(MegaInt& A, MegaInt& B){
	MegaInt Z;
	MegaInt temp, tempB, r, one;
	int j, k, n;
	string s;
	int q = 0;
	n = B.mega_int.size();

	tempB = B;
	j = 0;
	Z.mega_int.resize(0);

	for (size_t i = 0; i < n; ++i){
		temp.mega_int.push_back(A.mega_int.at(i));
	}
	normalize(temp.mega_int);
	k = (A.mega_int.size() - B.mega_int.size()) + 1;

	while (k >= 0){

		if (temp < tempB){

			one.setNumberFromString("0");
			tempB.multiply(one);
			temp.substract(tempB);
			r = temp;
			if ((n + 1) >= A.mega_int.size()){

				temp.mega_int.push_back(one.mega_int.front());
				--j;
			}
			else{
				while (r>one && j > 0){

					temp.mega_int.push_back(A.mega_int.at(n));
					++n;
					--j;
				}

				temp.mega_int.push_back(A.mega_int.at(n));
				Z.mega_int.push_back(one.mega_int.front());

				++n;
			}
		}
		else {

			one.setNumberFromString("1");
			for (size_t i = 1; i <= 10; ++i){
				tempB = B;
				tempB.multiply(one);



				if (tempB == temp){
					break;
				}
				if (tempB>temp){
					--one;
					break;
				}

				++one;

			}
			normalize(one.mega_int);
			Z.mega_int.push_back(one.mega_int.front());
			tempB = B;
			tempB.multiply(one);
			temp.substract(tempB);

			r = temp;

			++j;
		}
		tempB = B;

		one.clear();
		--k;

	}

	return r;
}

MegaInt MegaInt::operator%=(MegaInt& B){
	return this->modulus(B);
}

void MegaInt::reset(MegaInt& inputMegaInt){
	this->sign = inputMegaInt.sign;
	this->mega_int = inputMegaInt.mega_int;
	normalize(this->mega_int);
}

void MegaInt::clear(){
	sign = '+';
	mega_int.clear();
	mega_int.assign(1, '0');
}

void MegaInt::normalize(deque<char>& number){
	
	while ((number.size() > 1) && (number[0] == '0')){
		number.pop_front();
	}
}

// This function compares two mega_int without considering the sign

bool MegaInt::isGreater(MegaInt& B){
	normalize(B.mega_int);
	normalize(this->mega_int);

	if (this->mega_int.size() > B.mega_int.size()){
		return true;
	}
	else if (this->mega_int.size() == B.mega_int.size()){
		for (size_t i = 0; i < this->mega_int.size(); ++i){
			if (this->mega_int[i] == B.mega_int[i]){
				continue;
			}
			else if (this->mega_int[i]>B.mega_int[i]){
				return true;
			}
			else {
				return false;
			}
		}
		return false;
	}
	else {
		return false;
	}
}

// As previous function compares two mega_int without considering the sign

bool MegaInt::isLess(MegaInt& B){
	MegaInt A;
	A.sign = this->sign;
	A.mega_int = this->mega_int;
	return B.isGreater(A);
}

bool MegaInt::operator>(MegaInt& B){
	normalize(B.mega_int);
	normalize(this->mega_int);
		
	if (this->sign == '-' && B.sign == '+'){
		return false;
	}
	else if (this->sign == '+' && B.sign == '-'){
		return true;
	}
	else if(this->sign == '+' && B.sign=='+') {

		this->isGreater(B);
		
	}
	else if (this->sign == '-' && B.sign == '-'){
		if (this->mega_int.size() < B.mega_int.size()){
			return true;
		}
		else if (this->mega_int.size()>B.mega_int.size()){
			return false;
		}
		else {    //sizes are equal
			for (size_t i = 0; i < this->mega_int.size(); ++i){
				if (this->mega_int[i] == B.mega_int[i]){
					continue;
				}
				else if (this->mega_int[i] < B.mega_int[i]){
					return true;
				}
				else {                 // else if (this->mega_int[i]>B.mega_int[i]){
					return false;
				}
				/*else {
					return true;
				}*/
			} 
			return false;
		}
	}
	else {
		return false;                                 
	}
}

bool MegaInt::operator<(MegaInt& B){

	MegaInt A;
	A.sign = this->sign;
	A.mega_int = this->mega_int;
	return B>A;
}

bool MegaInt::operator==(MegaInt& B){
	normalize(this->mega_int);
	normalize(B.mega_int);
	if (this->sign != B.sign){
		return false;
	}
	else if(this->mega_int.size() != B.mega_int.size()){
		return false;
	}
	else {
		for (size_t i = 0; i < this->mega_int.size(); ++i){
			if (this->mega_int[i] != B.mega_int[i]){
				return false;
			}
			
		}
		return true;
	}
}

bool MegaInt::operator>=(MegaInt& B){
	MegaInt A;
	A.sign = this->sign;
	A.mega_int = this-> mega_int;
	return !(A < B);
}

bool MegaInt::operator<=(MegaInt& B){
	return !(*this>B);
}
void MegaInt::negate(){
	if (this->sign == '-'){
		this->sign = '+';
	}
	else {
		this->sign = '-';
	}
}

int MegaInt::operator[](int i){
	int x;
	x = this->mega_int[i]-'0';
	return x;
}


void MegaInt::operator=(MegaInt& megaInt){
	this->sign = megaInt.sign;
	this->mega_int = megaInt.mega_int;
}