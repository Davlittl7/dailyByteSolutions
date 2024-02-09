#include<iostream>
#include<string>
#include<cassert>
using namespace std;

/*
* Daily Byte Problem #6
*	This question is asked by Microsoft. Given an array of strings, return the 
*   longest common prefix that is shared amongst all strings. Note: you may 
*   assume all strings only contain lowercase alphabetical characters.
*/
/*
* Daily Byte: Longest Common Prefix Solution Idea
*	Make a string function that takes in a string array as a parameter
*	Along with an int parameter for the size of the array
*	Create a string at the top to hold what our prefix will be.
*	Find the shortest string length and set it to an int variable 
*	Use that length for a for loop that will go through each letter in each
*	This for loop will also have a nested for to ensure this process works
*	string of the array and compare them. If the chars are equal,
*	add it to the prefix string. Otherwise, simply return prefix at 
*	whatever part it stopped at (as unequalness shows the prefix is done).
*/

string longestCommonPrefix(string words[], int size) {
	//Determine the smallest string length in our words array
	int smallestStrLength = words[0].length();
	for (int i = 1; i < size; ++i) 
		if (words[i].length() < smallestStrLength)
			smallestStrLength = words[i].length();
	
	//Second part is to compare each char for each string and add it to the 
	//prefix if they are equal
	string prefix = "";
	for (int i = 0; i < smallestStrLength; ++i) {
		for (int j = 0; j < size; ++j) { //Nested for to jump to each char
			
			if (words[j][i] != words[0][i]) return prefix;
		}
		//Ensures that there are no out of bounds issues with if-else
		//Adding new character to prefix if they are at the end of one of the words
		//and still got passed the inner for loop
		if ((i + 1) < smallestStrLength) prefix += words[i][i];
		else prefix += words[size - 1][i];
	}
	return prefix;
}



int main() {
	{
		string arr[] = { "colorado", "color", "cold" };
		cout << "Test 1: \"[colorado, color, cold]\"" << endl;
		assert(longestCommonPrefix(arr, sizeof(arr) / sizeof(string)) == "col");
		cout << "Test 1 Passed! Answer was \"col\"" << endl;
	}
	{
		string arr[] = { "a", "b", "c" };
		cout << "Test 2: \"[a, b, c]\"" << endl;
		assert(longestCommonPrefix(arr, sizeof(arr) / sizeof(string)) == "");
		cout << "Test 2 Passed! Answer was \"\"" << endl;
	}
	{
		string arr[] = { "spot", "spotty", "spotted" };
		cout << "Test 3: \"[spot, spotty, spotted]\"" << endl;
		assert(longestCommonPrefix(arr, sizeof(arr) / sizeof(string)) == "spot");
		cout << "Test 3 Passed! Answer was \"spot\"" << endl;
	}
	
	
}