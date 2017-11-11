#ifndef TEXT_H_
#define TEXT_H_

#include <iostream>

using namespace std;
using std::ostream;

class Text
{
private:

	char *text{ nullptr };


public:
	virtual ~Text();
	Text();
	Text(const Text& t);
	Text(const char* t);
	void set(char * t);
	void set(const Text & t);
	const Text& operator=(const Text& t);
	void append(const char* t);
	void append(const Text& t);
	int length() const;
	bool isEmpty() const;
	friend ostream& operator<<(ostream&, const Text &);
	
};



#endif /* TEXT_H_ */