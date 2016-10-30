/** @file SudokuSolver.cpp */

#include "SudokuSolver.h"
#include "linkedStack.h"
#include <cstddef>


template<class ItemType>
bool SudokuSolver<ItemType>::insert(int number, int row, int column){

	theArray[row][column] = number;
	theStack.push(number);
}

template<class ItemType>
bool SudokuSolver<ItemType>::remove(int row, int column){

	theArray[row][column] = 0;
	//ifnotempy needed here?
	theStack.pop();

}

template<class ItemType>
bool SudokuSolver<ItemType>::goBack() {
	

}

template<class ItemType>
int SudokuSolver<ItemType> nextEmpty() {

}

template<class ItemType>
int SudokuSolver<ItemType>::getMissingInBox(int row, int column) {

	//return value
	int retval=0;	

	//create an array to hold the digits to check
	int theDigits[] = {1,2,3,4,5,6,7,8,9};


	for (int p = 0; p < 9; p++) {

		for (int i = column; i < column+3; i++) {
			for (int j=0; j <9; j++) {
				//if there exists such a value in the array of digits, then replace it with a 0
				if (theArray[row][i] ==theDigits[j]) {
					theDigits[j] =0;
				}
			}
		}
		row = row+1;
	}


	//now that we have a digit array that has our missing numbers, we can turn it into an int.
	for (int i = 0; i < 9; i++) {
		if (theDigits[i] != 0) {
			//move the digit to its correct place in the return number
			retval = (retval*10)+theDigits[i];
		}
	}

	//return
	return retval;

}

template<class ItemType>
int SudokuSolver<ItemType>::getMissingInRow(int row) {

	//return value
	int retval=0;	

	//create an array to hold the digits to check
	int theDigits[] = {1,2,3,4,5,6,7,8,9};

	//travel the array hortzontally
	for (int i=0; i < 9; i++) {

		//if we find a number that is not equal to 0	
		if (theArray[row][i] != 0) {

			//travel the digit array
			for (int j=0; j <9; j++) {
				
				//see if that number exists in the digit array and replace it with 0 if so
				if (theArray[row][i] == theDigits[j]) {
					theDigits[j] = 0;
				}
			}
		}
	}

	//now that we have a digit array that has our missing numbers, we can turn it into an int.
	for (int i = 0; i < 9; i++) {
		if (theDigits[i] != 0) {
			//move the digit to its correct place in the return number
			retval = (retval*10)+theDigits[i];
		}
	}

	//return
	return retval;
}

template<class ItemType>
int SudokuSolver<ItemType>::getMissingInColumn(int column) {

	//return value
	int retval=0;	

	//create an array to hold the digits to check
	int theDigits[] = {1,2,3,4,5,6,7,8,9};

	//travel the array vertically
	for (int i=0; i < 9; i++) {

		//if we find a number that is not equal to 0	
		if (theArray[i][column] != 0) {

			//travel the digit array
			for (int j=0; j <9; j++) {
				
				//see if that number exists in the digit array and replace it with 0 if so
				if (theArray[i][column] == theDigits[j]) {
					theDigits[j] = 0;
				}
			}
		}
	}

	//now that we have a digit array that has our missing numbers, we can turn it into an int.
	for (int i = 0; i < 9; i++) {
		if (theDigits[i] != 0) {
			//move the digit to its correct place in the return number
			retval = (retval*10)+theDigits[i];
		}
	}

	//return
	return retval;
}


