#include<iostream>
#include<string>
#include<cassert>
using namespace std;

/*
* Daily Byte #3 Problem
*	This question is asked by Amazon. Given a string representing the 
*   sequence of moves a robot vacuum makes, return whether or not it will 
*   return to its original position. The string will only contain L, R, U, and D 
*   characters, representing left, right, up, and down respectively.
*/
/*
* Daily Byte: Vacuum Cleaner Route Solution Idea
*	Make a boolean function that takes a string as a parameter
*	Inside make an x and y int variables, and init to 0 (act as coordinates)
*	Use a range based for that goes through string argument/actual parameter
*	Inside for is a switch case that increments/decrements for the following
*	+1 to x if R, -1 to x if L
*	+1 to y if U, -1 to y if R
*	After for loop, have an if-else statement check if x and y are equal to 0
*	If they are, return true. Else, return false
*/
bool doesVacuumReturn(string route) {
	int x = 0, y = 0; //Coordinates for vacuum

	for (char dir : route) { //Incrementing/decrementing entire route for coord
		switch (dir) {
		case 'U':
			++y;
			break;
		case 'L':
			--x;
			break;
		case 'R':
			++x;
			break;
		case 'D':
			--y;
			break;
		default:
			cout << "INVALID CHARACTER" << endl;
			break;
		}
	}

	//If coordinates return back to origin, true. Otherwise, false.
	if (x == 0 && y == 0) return true;
	else return false;
}

int main() {
	{
		cout << "Test 1: \"LR\"" << endl;
		assert(doesVacuumReturn("LR"));
		cout << "Passed Test 1: it was true!" << endl;
	}
	{
		cout << "Test 2: \"URURD\"" << endl;
		assert(!doesVacuumReturn("URURD"));
		cout << "Passed Test 2: it was false!" << endl;
	}
	{
		cout << "Test 3: \"RUULLDRD\"" << endl;
		assert(doesVacuumReturn("RUULLDRD"));
		cout << "Passed Test 3: it was true!" << endl;
	}
}