#include <iostream>
#include <stdlib.h>
#include "Menu.h"

using namespace std;



Menu::Menu()
{
	count = 0;
	max_list_size = 1;
	my_output = new Text();
	option_list = new Text[max_list_size];
}


Menu::Menu(const Menu& otherMenu)
{
	count = otherMenu.count;
	max_list_size = otherMenu.max_list_size;
	top_prompt = otherMenu.top_prompt;
	bottom_prompt = otherMenu.bottom_prompt;
	top_text = otherMenu.top_text;
	bottom_text = otherMenu.bottom_text;
	my_output = otherMenu.my_output;
	entered_number = otherMenu.entered_number;
	removed_item = otherMenu.removed_item;
	option_list = new Text[max_list_size + 1];
	for (int i = 0; i < max_list_size; i++)
	{
		option_list[i] = otherMenu.option_list[i];
	}
}


Menu::~Menu()
{
	delete my_output;
	delete[] option_list;
	option_list = nullptr;
}


Text Menu::toString() const 
{
	*my_output = "";
	char number[10]{};             //to convert int to char I use char *  itoa ( int value, char * str, int base )
	Text number_str{};             // function from <stdlib.h>. I inisialize an char array and Text variable to store the result 
	my_output->append(top_text);
	my_output->append("\n");
	my_output->append(top_prompt);
	my_output->append("\n");

	if (count!=0)
	{
		my_output->append("\n");
		for (int i = 0; i < size(); i++)
		{
			my_output->append("  (");
			number_str = itoa(i+1, number, 10);  //itoa function mentioned above
			my_output->append(number_str);
			my_output->append(") ");
			my_output->append(option_list[i]);
			my_output->append("\n");
		}
		my_output->append("\n");
	}
	my_output->append(bottom_text);
	my_output->append("\n");
	my_output->append("?-> ");
	my_output->append(bottom_prompt);

	return *my_output;
}


int Menu::read_option_number()
{
	cout<<toString()<<flush;
	cin >> entered_number;
	if (cin.fail()){                      // checks whether numerical value was entered
		cout << "\nYour input is not an integer, try again\n" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		this->read_option_number();
	}
	
	if (isEmpty())
	{
		return entered_number;
	}
	else if(entered_number<1 || entered_number>size())
		{	
			cout << "\nInvalid choice " << entered_number << ". It must be in the range [1, " << size() << "]\n" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			this->read_option_number();
		}
	else
		{
			return entered_number;
		}
}


const Menu& Menu:: operator=(const Menu& m)
{
	if (this == &m)
		return *this;

	{
		delete[] option_list;
		count = m.count;
		max_list_size = m.max_list_size;
		top_prompt = m.top_prompt;
		bottom_prompt = m.bottom_prompt;
		top_text = m.top_text;
		bottom_text = m.bottom_text;
		my_output = m.my_output;
		entered_number = m.entered_number;
		removed_item = m.removed_item;
		option_list = new Text[max_list_size + 1];
		for (int i = 0; i < max_list_size; i++)
		{
			option_list[i] = m.option_list[i];
		}
	}
	return *this;
}

ostream& operator<<(ostream& out, const Menu& m)
{
	out << m.toString() << flush;
	return out;
}


bool Menu::isEmpty() const
{
	return count == 0;
}


int Menu:: size() const
{
	return count;
}


int Menu:: capacity() const
{
	return max_list_size;
}


void Menu::double_capacity()
{
	int newSize = 2 * max_list_size;
	Text *temp = new Text[newSize];
	for (int i = 0; i < max_list_size; i++)
	{
		temp[i] = option_list[i];
	}
	delete[] option_list;
	option_list = temp;
	max_list_size = newSize;
}


void Menu:: push_back(char* pOption)
{
	if (isFull())
	{
		double_capacity();

	}
	option_list[count] = pOption;
	count++;
}


void Menu::push_back(const Text& option)
{
	if (isFull()){
		double_capacity();
	}
	option_list[count] = option;
	count++;
}


bool Menu:: isFull() const
{
	return count == max_list_size;
}


void Menu::set_top_prompt(const Text& t)
{
	top_prompt = t;
}


void Menu::set_bottom_prompt(const Text& t)
{
	bottom_prompt = t;
}


void Menu::set_top_message(const Text& m)
{
	top_text = m;
}


void Menu::set_bottom_message(const Text& m)
{
	bottom_text = m;
}


void Menu::pop_back()
{
	if (isEmpty())
	{
		cout<< "There is no elements to pop"<<endl;
	}
	else 
	{
		--count;
	}
	
}


void Menu:: insert(int index, const Text& option)
{
	if (isFull()){
		double_capacity();
	}
	if (index > count)
	{
		cout << "****************************************************" << endl;
		cout << "* Cannot insert an item its index is out of scope  *" <<endl;
		cout << "****************************************************" << endl;
	} 
	else
	{
		++count;
		Text* temp = new Text[count];
		for (int k = 0; k < index; k++)
		{
			temp[k] = option_list[k];
		}
		temp[index] = option;
		for (int k = index + 1; k < count; k++)
		{
			temp[k] = option_list[k - 1];
		}
		
		for (int i = 0; i < count; i++)
		{
			option_list[i] = temp[i];
		}
	}
}

Text Menu::remove(int index)
{
	if (isEmpty())
	{
		cout << "******************************************************" << endl;
		cout << "* The array is empty, there is no elements to remove *" << endl;
		cout << "******************************************************" << endl;
		return "Oops!!!";
	}
	else
	{
		removed_item = option_list[index];
		--count;
		Text* temp = new Text[count];
		for (int k = 0; k < index; k++)
		{
			temp[k] = option_list[k];
		}
		
		for (int k = index + 1; k <=count; k++)
		{
			temp[k-1] = option_list[k];
		}
		for (int i = 0; i < count; i++)
		{
			option_list[i] = temp[i];
		}
	}
	return removed_item;
}


Text Menu::get(int k)
{
	if (k>=(count+1) || k<0){
		return Text("Entered option is not in the provided list of options, sorry");
	}
	else
	{
		return option_list[k - 1];
		
	}
}


void Menu::clear_top_prompt()
{
	top_prompt = "";
}
void Menu::clear_bottom_prompt()
{
	bottom_prompt = "";
}
void Menu::clear_top_message()
{
	top_text = "";
}
void Menu::clear_bottom_message()
{
	bottom_text = "";
}
