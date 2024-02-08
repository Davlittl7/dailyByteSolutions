#include<iostream>
#include<math.h>
#include<string>
#include<stack>
#include<cassert>
using namespace std;

/*
* Daily Byte Problem #5
*	This question is asked by Apple. Given two binary strings (strings
*   containing only 1s and 0s) return their sum (also as a binary string).
*   Note: neither binary string will contain leading 0s unless the string 
*   itself is 0
*/
/*
* Daily Byte: Add Binary Solution Idea 
*	Create a string function that takes in two string parameters.
*	First part changes the two string parameters into integers and adds them
*   together. Following that, the second part will convert this integer back 
*   into a binary number. Do this by creating a while loop that continues to
*   divide by 2 until the sum is less than 2/the resulting dividend of being 
*   divided by 2 is greater than 0 (even division with no rem = 0, rem = 1)
*	Store this in a string in reverse after putting it in a stack;
*/

string addBinaryStr(string binaryStrOne, string binaryStrTwo) {
	int decimalNumOne = 0, decimalNumTwo = 0; //Hold conversions of binary nums

	//Determines decimal num for first binary string
	for (int i = 0; i < binaryStrOne.length(); ++i) {
		if (binaryStrOne[i] == '1') 
			decimalNumOne += pow(2.0, binaryStrOne.length() - (i + 1));
		else continue;
	}

	//Determines decimal num for second binary string 
	for (int i = 0; i < binaryStrTwo.length(); ++i) {
		if (binaryStrTwo[i] == '1') 
			decimalNumTwo += pow(2.0, binaryStrTwo.length() - (i + 1));
		else continue;
	}

	//Add the two newly converted (binary to decimal) numbers together
	decimalNumOne += decimalNumTwo;

	//Convert this sum back into a binary number and hold it in a char stack
	stack<char> binaryNumsHolder;
	while (decimalNumOne != 0) {
		if (decimalNumOne % 2 != 0) binaryNumsHolder.push('1');
		else binaryNumsHolder.push('0');
		decimalNumOne /= 2;
	}
	
	//Convert stack of chars into a string (as we need to reverse the binary)
	//Add top of stack to beginning of string and then pop;
	string finalBinaryStr = "";
	int binarySumSize = binaryNumsHolder.size();
	for (int i = 0; i < binarySumSize; ++i) {
		finalBinaryStr += binaryNumsHolder.top();
		binaryNumsHolder.pop();
	}

	//Return final binary string after last for loop
	return finalBinaryStr;
}



int main() {
	
	{
		cout << "Test 1: \"100 + 1\"" << endl;
		assert(addBinaryStr("100", "1") == "101");
		cout << "Test 1 Passed! Answer was 101" << endl;
	} 
	{
		cout << "Test 2: \"11 + 1\"" << endl;
		assert(addBinaryStr("11", "1") == "100");
		cout << "Test 2 Passed! Answer was 101" << endl;
	}
	{
		cout << "Test 3: \"1 + 0\"" << endl;
		assert(addBinaryStr("1", "0") == "1");
		cout << "Test 3 Passed! Answer was 1" << endl;
	}

}