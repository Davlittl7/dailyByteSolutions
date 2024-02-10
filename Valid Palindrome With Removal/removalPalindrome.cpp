#include<iostream>
#include<string>
#include<cassert>
using namespace std;


/*
* Daily Byte Problem #7
*	This question is asked by Facebook. Given a string and the ability to 
*   delete at most one character, return whether or not it can form a 
*   palindrome.
*   Note: a palindrome is a sequence of characters that reads the same 
*   forwards and backwards.
*/
/*
* Daily Byte Valid Palindrome With Removal Solution Idea 
*	Create a boolean function that takes a string parameter.
*	Declare and init two ints to hold beginning and end indices for string.
*	Use a while loop that goes until begin is equal or greater than end.
*	Check if str[begin] is equal to str[end] and if so, increment and continue.
*	If not, check to see if the next one for the begin index and/or end index
*	is equal to the current one the begin/end index is on. If it is, then
*	increment to the proper spot according for either one and continue w/ loop.
*	Otherwise, return false. (Have a bool var to ensure check one time only)
*	At the end of this function, if str makes it past while loop, return true.
*/

bool isValidPalindromeWithRemoval(string str) {
	int begin = 0, end = str.length() - 1;

	//making sure that the func is only allowed to skip one character
	bool hasCharBeenIgnored = false; 
	//While loop to determine if string is a palindrome
	//if one character is allowed to be removed/ignored
	while (begin <= end) {
		if (str[begin] == str[end]) {
			++begin; --end;
		}
		//Make sure checking the next character isn't out of bounds
		else if ((begin + 1) <= str.length() - 1 && (end - 1) >= 0) {
			if (str[begin + 1] == str[end] && !hasCharBeenIgnored) { 
				++begin; 
				hasCharBeenIgnored = true;
			}
			else if (str[end - 1] == str[begin] && !hasCharBeenIgnored) {
				--end;
				hasCharBeenIgnored = true;
			}
			else return false;
			
		}
	}
	return true;
}

int main() {
	{
		cout << "Test 1: \"abcba\"" << endl;
		assert(isValidPalindromeWithRemoval("abcba"));
		cout << "Test 1 passed! It was true!" << endl;
	}
	{
		cout << "Test 2: \"foobof\"" << endl;
		assert(isValidPalindromeWithRemoval("foobof"));
		cout << "Test 2 passed! It was true!" << endl;
	}
	{
		cout << "Test 3: \"abccab\"" << endl;
		assert(!isValidPalindromeWithRemoval("abccab"));
		cout << "Test 3 passed! It was false!" << endl;
	}
}