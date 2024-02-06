#include<iostream>
#include<string>
#include<cassert>
#include <algorithm>
using namespace std;

/*
* Daily Byte #2: Valid Palindrome Idea
*	Create a boolean function that takes a string as a parameter
*	Immedieately turn that string into one that is all lowercase
*	As well as removing all non-alphabetical characters from the string
*	Go into a for loop that goes for string's length 
*	Just have an if statement if the string index i does not equal
*	string index of str.length() - (i + 1), return false
*	If the function passes the for loop then just have a return true at the end
*/

bool isValidPalindrome(string str) {
	//Make the entire string lowercase
	transform(str.begin(), str.end(), str.begin(), tolower);

	//Remove non-alphabetical characters from the string 
	string onlyAlpha = "";
	for (auto i : str) 
		if (isalpha(i)) onlyAlpha += i;
	

	//For loop to test if it is a palindrome
	for (int i = 0; i < onlyAlpha.length(); ++i) {
		if (onlyAlpha[i] != onlyAlpha
			[onlyAlpha.length() - (i + 1)]) return false;
	}

	//Returns true if for loop does not find inconsistency w/ palindrome
	return true;
}

int main() {
	{
		cout << "Test Case 1: level (is a palindrome)" << endl;
		assert(isValidPalindrome("level"));
		cout << "Test 1 Passed!" << endl;
	}
	{
		cout << "Test Case 2: algorithm (is not a palindrome)" << endl;
		assert(!isValidPalindrome("algorithm"));
		cout << "Test 2 Passed!" << endl;
	}
	{
		cout << "Test Case 3: A man, a plan, a canal: Panama. (is a palindrome)" << endl;
		assert(isValidPalindrome("A man, a plan, a canal: Panama."));
		cout << "Test 3 Passed!" << endl;
	}
}