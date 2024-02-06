#include<iostream>
#include<string>
#include<cassert>
#include<stack>
using namespace std;

/*
* Daily Byte #1 - Reverse a string
* Solution Idea: 
*	Create a function that takes in a string and returns a string
*	Inside func, create a string variable to hold the reversed string
*	Use a for loop to go through said string based on its length
*	Use indexing to take from the end of the string (str.length() - (i + 1))
*	Put that index of orginal str to the current for loop's i index for rev str
*	Return reversed string at the end
*/

string reverseAString(string str) {
	string reversedStr = str;
	for (int i = 0; i < str.length(); ++i) 
		reversedStr[i] = str[str.length() - (i + 1)];
	return reversedStr;
}

string reverseAStringWithStack(string str) {
	stack<char> strHolder;

	//Copy str's character into a stack
	for (auto i : str) strHolder.push(i);

	//Reverse the str and put into the original str by 
	//retrieving the value of the top and then popping from the stack
	for (int i = 0; i < str.length(); ++i) {
		str[i] = strHolder.top();
		strHolder.pop();
	}

	return str;

}

int main() {
	//Test Cases
	{
		string str1 = "Cat";
		string str2 = reverseAString(str1);
		string str3 = reverseAStringWithStack(str1);
		assert(str2 == str3);
		assert(str2 == "taC");
		assert(str3 == "taC");
		cout << "Test 1 successful!" << endl;
		cout << "Orginal string: " + str1 + ", Reversed: " + str2 << endl;
	}
	{
		string str1 = "The Daily Byte";
		string str2 = reverseAString(str1);
		string str3 = reverseAStringWithStack(str1);
		assert(str2 == str3);
		assert(str2 == "etyB yliaD ehT");
		assert(str3 == "etyB yliaD ehT");
		cout << "Test 2 successful!" << endl;
		cout << "Orginal string: " + str1 + ", Reversed: " + str2 << endl;
	}
	{
		string str1 = "civic";
		string str2 = reverseAString(str1);
		string str3 = reverseAStringWithStack(str1);
		assert(str2 == str3);
		assert(str2 == "civic");
		assert(str3 == "civic");
		cout << "Test 3 successful!" << endl;
		cout << "Orginal string: " + str1 + ", Reversed: " + str2 << endl;
	}
}