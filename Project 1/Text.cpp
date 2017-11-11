
#include <iostream>
#include <cstring>
#include "Text.h"

using namespace std;



Text::~Text(){
	delete[] text;
	text = nullptr;
}


Text::Text() : text{ new char[1]{'\0'} }{}


Text::Text(const Text& t) : Text(t.text){}


Text::Text(const char *t)
{
	text = new char[strlen(t) + 1];
	strcpy(text, t);
}


void Text::set(char *t)
{
	text = new char[strlen(t) + 1];
	strcpy(text, t);
}


void Text::set(const Text &t)
{
	text = new char[strlen(t.text) + 1];
	strcpy(text, t.text);
}


const Text& Text:: operator=(const Text &t)
{
	if (this == &t)
	{
		return *this;
	}
	{
		delete[] text;
		text = new char[strlen(t.text) + 1];
		strcpy(text, t.text);
	}
	return *this;
}


void Text::append(const char* t)
{
	int len = strlen(this->text) + strlen(t) + 1;
	char* temp = new char[len];
	strcpy(temp, text);
	delete[] text;
	text = temp;
	strcat(text, t);
}


void Text::append(const Text& t)
{
	append(t.text);
}


int Text::length() const
{
	return strlen(this->text);
}


bool Text::isEmpty() const{
	return strlen(this->text);
}


ostream& operator<<(ostream& out, const Text& t)
{
	out << t.text;
	return out;
}


