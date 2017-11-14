In this project there were three, unrelated tasks.

###1.### 
Write a function named **isPalindrom** that receives a string as parameter and determines whether the 
received string is a palindrome.
The implementation may *not* use
- any loops explicitly; that is no **for**, **while** or **do/while** loops
- more than one local **string** object
- raw arrays, STL container classes

###2.###
Write a function template named **second_max** to find the second largest element in a container within a given
range **[start, finish)**, where **start** and **finish** are iterators that provide properties of forward iterators.
The function template may *not* use
- STL algorithms or containers.

| If the range *[start, finish) | *second_max* should return|
--------------------------------|---------------------------|
| is empty | *std::make_pair(finish,false)* |
| contains all equal elements | *std::make_pair(start,false)* |
| contains at least two distinct elements | *std::make_pair(iter,true)* |
| *iter* is an *Iterator* referring to the 2nd largest element in the range |

###3.###
Write a function that extracts the words from a given input text file and outputs a sorted list of words together 
with their frequency of occurrence within a given text. A "word" is taken to be any sequency of characters except
whitespace characters.

####3a####
Now, define a "word" to be a sequence of any non-whitespace characters that begins and ends with a letter. For
example, the sequence of characters **Sam-I-am** defines a word but the sequence **Sam-I-am.** does not.
We need a function that takes a word as argument and returns that word with its leading and trailing 
non-alphabetic characters removed.

####3b####
Write the function that sorts the words alpabetically (not separating capitalized and non-capitalized words) and
counts those words together (meaning "not" is the same as "Not").

####3c####
Write a function that accepts the name of a text file as parameter and reads the words in that file. The function should
create a print a **std::map** object that stores (*key*, *value*) elements in which the *keys* are the words and the
*values* are a set containing the line number in  the file where the words appear.
#####Sample text file named input.txt#####
1. Not in a box. Not with a fox.
2. Not in a house. Not with a mouse.
3. I would not eat them here or there.
4. I would not eat them anywhere.
5. I would not eat green eggs and ham.
6. I do not like them, Sam-I-am. Dr. Seiss

#####Words followed by list of line numbers in the file where they appear#####
```
a          1 2 
and        5
anywhere   4   
box        1
do         6
Dr         6
eat        3 4 5 
eggs       5
fox        1
green      5
ham        5
here       3
house      2 
I          3 4 5 6
in         1 2
like       6 
mouse      2 
Not        1 2 3 4 5 6
or         3
Sam-I-am   6
Seuss      6
them       3 4 6
there      3 
with       1 2
would      3 4 5
```
**Note 1:** If there are more than one version of a word, such as **Not** and **not**, then only the 
first version should be stored in the map.
**Note 2:** If a word appears more than once in a line, the number of that line should be listed only
once.