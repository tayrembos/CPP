/*
Program to calculate ideal body weight given height input
EEL3834
Created by: Taylor Rembos
*/

#include <iostream>

using namespace std;

int main() {

//introduce variables to be used

	int height_ft;
	int height_in;
	int ideal_value;

	//Quesion to get height in feet as input 1
	cout << "What is your height in feet?" << endl;
	cin >> height_ft;

	//Question to get remaining height in inches as input 2
	cout << "what is the rest of your height in inches?" << endl;
	cin >> height_in;

	//conversion of input 1 and 2 height into weight calculation, assuming person is at least 5 ft tall
	// 110 pounds plus 5 pounds for each additional inch, 60 pounds for each additional foot

	if (height_ft >= 5) {
		ideal_value = 110 + ((height_ft - 5) * 60) + (height_in * 5);
		cout << "Your ideal body weight is " << ideal_value << " pounds." << endl;
	}
	//error if invalid entry (height less than 5 feet or wrong character)
	else {
		cout << "Invalid entry. Please try again with numerical values greater than or equal to 5 feet." << endl;
	}

	return 0;
}