#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <vector>
#include <fstream>
#include <map>
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <cctype>
#include <set>



using namespace std;

bool isNotALetter(char c){
	return !(isalpha(c));
}

bool is_palindrome(const string & phrase){
	string temp;
	
	string::iterator iter;
	insert_iterator<string> itt(temp,iter);

	remove_copy_if(phrase.begin(), phrase.end(), itt, isNotALetter); 

	transform(temp.begin(), temp.end(), temp.begin(), tolower);

	int halfSize = temp.size() / 2;
	
	return equal(temp.begin(), temp.end()-halfSize, temp.rbegin());
}

void test_is_palindrome(){
	string str_i = string("Was it a car or a cat I saw?");
	string str_u = string("Was it a car or a cat U saw?");
	cout << "the phrase \"" + str_i + "\" is " + (is_palindrome(str_i) ? "" : "not ") + "a palindrome\n";
	cout << "the phrase \"" + str_u + "\" is " + (is_palindrome(str_u) ? "" : "not ") + "a palindrome\n";
}



template <class Iterator>

pair<Iterator, bool> second_max(Iterator start, Iterator finish){
	Iterator max = start;
	Iterator secondMax = start;

	if (distance(start, finish)==0){
		return make_pair(finish, false);
	}
	else if (distance(start, finish) == 1){
		return make_pair(start, false);
	}
	else {
		
		for (Iterator iter = start; iter != finish; ++iter){
			
			if (*iter > *max){
				secondMax = max;
				max = iter;
			 }
			else if(*iter>*secondMax && *iter!=*max){
				secondMax = iter;
			}
			else if(*iter!=*max && *max==*secondMax)  {
				secondMax = iter;
			}
			
		}
		if (*max == *secondMax){
			return make_pair(start, false);
		}
		else{

			return make_pair(secondMax, true);
		}
	}
		
}

void test_second_max(){
	vector<int> int_vec{1,1,5,5,7,7};

	auto retval = second_max(int_vec.begin(), int_vec.end());

	if (retval.second){
		cout << "The second largest element in int_vec is " << *retval.first << endl;
	}
	else {
		if (retval.first == int_vec.end())
			cout << "List empty, no element\n";
		else
			cout << "Container's elements are all equal to  " << *retval.first << endl;
	}
}


string remove_leading_trailing_non_alpha(string word){

	
	while (!(isalpha(word.front()))){
		word.erase(word.begin());
	}

	while (!(isalpha(word.back()))){
		word.erase(word.end()-1);
	}
	return word;
}

void print_word_frequency_1(const string& filename){
	ifstream ifs = ifstream(filename);

	if (!ifs) throw invalid_argument(string("could not open file ") + filename );
     
	map<string, int> word_frequency_map;
	//map<string, int, MyCompare> word_frequency_map;

	string line;
	while (getline(ifs, line)){
		istringstream iss(line);
		
		string word;
		while (iss >> word){
			//++word_frequency_map[word];
			++word_frequency_map[remove_leading_trailing_non_alpha(word)];
		}
	}
	for (const auto& word : word_frequency_map){
		cout << setw(10) << word.first << " " << word.second << endl;
	}
}

class MyCompare {
public:
	bool operator()(string a, string b){
		transform(a.begin(), a.end(), a.begin(), ::tolower);
		transform(b.begin(), b.end(), b.begin(), ::tolower);

		if (a.compare(b)<0){
			return true;
		}
		else {
			return false;
		}
	}
};



void print_word_frequency_2(const string& filename){
	ifstream ifs = ifstream(filename);

	if (!ifs) throw invalid_argument(string("could not open file ") + filename);

	//map<string, int> word_frequency_map;
	map<string, int, MyCompare> word_frequency_map;

	string line;
	while (getline(ifs, line)){
		istringstream iss(line);

		string word;
		while (iss >> word){
			//++word_frequency_map[word];
			++word_frequency_map[remove_leading_trailing_non_alpha(word)];
		}
	}
	for (const auto& word : word_frequency_map){
		cout << setw(10) << word.first << " " << word.second << endl;
	}
}

// overload operator<< to be able to print set in the next function
ostream& operator<<(ostream& out, set<int> mySet){
	for (set<int>::iterator i = mySet.begin(); i != mySet.end(); ++i){
		out << *i << " ";
	}

	return out;
}

void print_word_index(const string& filename){
	ifstream ifs = ifstream(filename);

	if (!ifs) throw invalid_argument(string("could not open file ") + filename);

	//map<string, int> word_frequency_map;
	map<string, set<int>, MyCompare> word_frequency_map;
	int count = 0;
	string line;
	while (getline(ifs, line)){
		istringstream iss(line);

		string word;
		++count;
		while (iss >> word){
			
			word_frequency_map[remove_leading_trailing_non_alpha(word)].insert(count);
		}
	}
	for (const auto& word : word_frequency_map){
		cout << setw(10) << word.first << " " << word.second << endl;
	}
}

int main(){

	test_is_palindrome();
	cout << "-----------------------------------------------------" << endl;

	test_second_max();
	cout << "-----------------------------------------------------" << endl;

	string filename = "input.txt";
	
	try{
		print_word_frequency_1(filename);
	}
	catch (invalid_argument& error){
		cout << error.what() << endl;
	}
	cout << "-----------------------------------------------------" << endl;

	try{
		print_word_frequency_2(filename);
	}
	catch (invalid_argument& error){
		cout << error.what() << endl;
	}
	cout << "-----------------------------------------------------" << endl;

	try{
		print_word_index(filename);
	}
	catch (invalid_argument& error){
		cout << error.what() << endl;
	}
	
	return 0;
}

