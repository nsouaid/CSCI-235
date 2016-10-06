#include <iostream>
#include "BigInteger.h"
using namespace std;


BigInteger<int>CreateBigIntegerFromInput() {

	//create an empty bag
	BigInteger<int>theInteger;
	int exponent=0, coefficient, old=100;	
	char exit = 'c';

	cout << "Input your next big intger now." << endl;

	//gather input
	while (exit != 'q') {
	

		//maintain a sequential decrement with input
		if (exponent <= old ) {
			cout << "Enter the exponent: ";
			cin >> exponent;
			cout << "Enter the coefficient: ";
			cin >> coefficient;
			theInteger.Insert(exponent, coefficient);
			cout << "would you like to continue adding numbers? press q to quit, any other key to continue." << endl;
			cin >> exit;
			old = exponent;
			old--;
		}
		else {
			cout << "please enter a number for coefficient less than your previous exponent." << endl;
			cin >> exponent;
		}
	}
	return theInteger;
}

void TestBigInteger() {

	int exponent, newcoefficient;

	//use the copy constructor to create the bag we need
	BigInteger<int>testInteger(CreateBigIntegerFromInput());

	cout << "The big integer is ";
	testInteger.DisplayBigInteger();

	cout << "\nPlease enter an exponent and we'll tell you the coefficient: ";
	cin>> exponent;
	
	cout << "\nThe coefficient for " << exponent << " is "; 
	cout << testInteger.Coefficient(exponent) << endl;

	cout << "Now we'll change the coefficient. Please give a new number for the coefficient. Please only change a number that you have provided within the list: ";
	cin >> newcoefficient;

	testInteger.ChangeCoefficient(exponent, newcoefficient);

	cout << "The new Big Integer is "; 
	testInteger.DisplayBigInteger();
}

void TestEquals() {

	BigInteger<int>number1(CreateBigIntegerFromInput());
	BigInteger<int>number2(CreateBigIntegerFromInput());

	if (number1.EqualsBigInteger(number2)) {
		cout << "Your numbers are equal. TRUE" << endl;
	}
	else {
		cout << "The two numbers you entered are not equal. FALSE" << endl;
	}
}

int main () {

//	TestBigInteger();
	TestEquals();

	return 0;
}
