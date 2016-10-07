#include <iostream>
#include "BigInteger.h"
using namespace std;


BigInteger<int>CreateBigIntegerFromInput() {

//create an empty bag
	BigInteger<int>theInteger;
//variables
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
//variables
	int exponent, oldcoefficient, newcoefficient;
//use the copy constructor to create the bag we need
	BigInteger<int>testInteger(CreateBigIntegerFromInput());
//display the integer
	cout << "The big integer is ";
	testInteger.DisplayBigInteger();
//obtain exponent
	cout << "\nPlease enter an exponent and we'll tell you the coefficient: ";
	cin>> exponent;	
	cout << "\nThe coefficient for " << exponent << " is "; 
//display the soon-to-be-changed coefficient
	oldcoefficient = testInteger.Coefficient(exponent);
	cout << oldcoefficient;
//obtain new coefficient
	cout << "\nNow we'll change the coefficient. Please give a new number for the coefficient. Please only change a number that you have provided within the list: ";
	cin >> newcoefficient;
//change the coefficient
	testInteger.ChangeCoefficient(exponent, newcoefficient);
//display the new integer
	cout << "The new Big Integer is "; 
	testInteger.DisplayBigInteger();
}

void TestEquals() {
//create two integers using the copy constructor and other client function
	BigInteger<int>number1(CreateBigIntegerFromInput());
	BigInteger<int>number2(CreateBigIntegerFromInput());
//if the numbers are equal, output true
	if (number1.EqualsBigInteger(number2)) {
		cout << "Your numbers are equal. TRUE" << endl;
	}
//else false
	else {
		cout << "The two numbers you entered are not equal. FALSE" << endl;
	}
}

int main () {

	cout << "\nFirst we will TestBigInteger():" << endl;
	TestBigInteger();
	cout << "\nNow we will TestEquals():" << endl;
	TestEquals();

	return 0;
}
