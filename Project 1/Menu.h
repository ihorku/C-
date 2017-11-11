#ifndef MENU_H_
#define MENU_H_
#include "Text.h"
class Menu
{
private:
	Text* option_list{nullptr};
	int count;
	int max_list_size;
	Text top_prompt;
	Text bottom_prompt;
	Text top_text;
	Text bottom_text;
	Text* my_output;
	int entered_number;
	Text removed_item;


public:
	void double_capacity();
	Menu();
	Menu(const Menu& otherMenu);
	virtual ~Menu();
	const Menu& operator=(const Menu& m);
	void insert(int index, const Text& option);
	void push_back(char* pOption);
	void push_back(const Text& option);
	Text remove(int index);
	int size() const;
	int capacity() const;
	void pop_back();
	Text get(int k);
	Text toString() const;
	int read_option_number();
	void set_top_prompt(const Text& t);
	void set_bottom_prompt(const Text& t);
	void set_top_message(const Text& m);
	void set_bottom_message(const Text& m);
	void clear_top_prompt();
	void clear_bottom_prompt();
	void clear_top_message();
	void clear_bottom_message();
	bool isEmpty() const;
	friend ostream& operator<<(ostream&, const Menu &);
	bool isFull() const;
};



#endif /* MENU_H_ */