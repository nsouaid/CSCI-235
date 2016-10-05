#include <iostream>
#include "BigInteger.h"
using namespace std;



BigInteger<int>CreateBigIntegerFromInput() {

	//create an empty bag
	BigInteger<int>theInteger;
	int exponent, coefficient;	

	char exit = 'c';

	while (exit != 'q') {

	cout << "Enter the exponent: ";
	cin >> exponent;
	cout << "Enter the coefficient: ";
	cin >> coefficient;
	theInteger.Insert(exponent, coefficient);
	cout << "would you like to continue adding numbers? press q to quit, any other key to continue." << endl;
	cin >> exit;
	}

	return theInteger;
}

void TestBigInteger() {


//	BigInteger<testInteger(CreateBigIntegerFromInput());
}


int main () {

	CreateBigIntegerFromInput();

	return 0;
}
