The first project is designed to get started with C++ using arrays, pointers, dynamic memory allocation 
and deallocation, and with writing classes.

The task was to implement a class (Menu) that models menus used in text-based menu-driven programs, where 
the user is first presented with a list of options to choose from and is then prompted to enter a value 
corresponding to an option, very similar to menu-based voice interfaces.

A Menu object includes of six items:
	- the string literal "?->",
	- four Text items representing the top/bottom prompts and the opening/closing message, and
	- a dynamic list of Text items representing the menu's list of options,
where Text is a class that represents character string.

The string literal item "?->" provides the minimal string representation for a Menu object regardless of 
the presence or absence of the other five items.

General Requirements 
	- may not use the C++ "string" class, except for c_str() and data(),
	- may use only the function "strcpy" and "strlen" from the <cstring> header file, 
	- may use any "String conversion" function from <cstdlib> and any function from <cctype>.

Specific Requirements
	- must store the character string using raw C-arrays, which must be allocated dynamically using "new", 
	and deallocated using "delete".
	- must overload the insertion "operator<<".

The primary purpose of a menu object is to interact with the user: it displays the menu and expects the
 user to enter an input value. The range of input values acceptable by a menu object depends on the number 
 of options in a menu's option list.If the menu's option list is not empty, then the user must enter an 
 integer in the range 1 through the highest option number in the list. 
However, if the menu's option list is empty, then the user can enter any integer.

