#include<iostream>
#include<string>
#include<cassert>
using namespace std;

/*
* Daily Byte Problem #4
*	This question is asked by Google. Given a string, return whether or not it 
*   uses capitalization correctly. A string correctly uses capitalization if 
*   all letters are capitalized, no letters are capitalized, or only the first 
*   letter is capitalized.
*/
/*
* Daily Byte: Correct Capitialization Solution Idea
* Create a boolean function that takes in a string parameter.
* First two parts of func check if it all lowercase or all uppercase w/ fors
* If it makes it through the entire for loop(s) and it is all upper or lower
* the function returns true (based on int var used to count correctness).
* If not, func will continue to third part of function 
* Will ignore first letter since it is irrelevant at this point in for loop.
* check to see if there is any uppercase letters within the rest of the string.
* If so, return false. Otherwise, for loop will finish and return true
* in the statement/line following that loop.
*/

bool isCorrectCapitialization(string capitalCheck) {
	//Variable used to check correctness of first two for loops
	//Will see if count matches length of string to return true or not
	int correctCount = 0;

	//First for loop to check if all uppercase
	for (char letter : capitalCheck) {
		if (isupper(letter)) ++correctCount;
		else break;
	}
	if (correctCount == capitalCheck.length()) return true;

	//Second for loop to check if all lowercase
	correctCount = 0; //reset correct count so there are no inaccuracies
	for (char letter : capitalCheck) {
		if (islower(letter)) ++correctCount;
		else break;
	}
	if (correctCount == capitalCheck.length()) return true;

	//Third for loop to check if there is an uppercase char anywhere
	//but the beginning, and will return false if there is. 
	for (int i = 1; i < capitalCheck.length(); ++i) 
		if (isupper(capitalCheck[i])) return false;

	//Return true if it makes it through the final for loop w/ no issue.
	//As that will show correct capitialization.
	return true; 
}

int main() {
	{
		cout << "Test 1: \"USA\"" << endl;
		assert(isCorrectCapitialization("USA"));
		cout << "Passed test 1! It was true!" << endl;
	}
	{
		cout << "Test 2: \"Calvin\"" << endl;
		assert(isCorrectCapitialization("Calvin"));
		cout << "Passed test 2! It was true!" << endl;
	}
	{
		cout << "Test 3: \"compUter\"" << endl;
		assert(!isCorrectCapitialization("compUter"));
		cout << "Passed test 3! It was false!" << endl;
	} 
	{
		cout << "Test 4: \"coding\"" << endl;
		assert(isCorrectCapitialization("coding"));
		cout << "Passed test 4! It was true!" << endl;
	}
}