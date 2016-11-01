/** @file SudokuSolver.cpp */

#include "SudokuSolver.h"
#include "LinkedStack.h"

#include <cstddef>
#include <fstream>
#include <string>

using namespace std;

//private:
template<class ItemType>
bool SudokuSolver<ItemType>::insert(int number, int row, int column) {

	theArray[row][column] = number;
	theStack.Push(number);
	return true;
}

template<class ItemType>
bool SudokuSolver<ItemType>::remove(int row, int column) {

	theArray[row][column] = 0;
	//ifnotempy needed here?
	theStack.Pop();
	return true;
}

template<class ItemType>
bool SudokuSolver<ItemType>::goBack() {
	
return false;
}

template<class ItemType>
int SudokuSolver<ItemType>::nextEmpty() {

return 2;
}

template<class ItemType>
int SudokuSolver<ItemType>::getMissingInBox(int row, int column) {

	//return value
	int retval=0;	

	//create an array to hold the digits to check
	int theDigits[] = {1,2,3,4,5,6,7,8,9};


	//from the first row to the last
	for (int p = 1; p < 4; p++) {

		//for each column
		for (int i = column; i < column+3; i++) {
	
			//and for each digit within the digit array
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
	for (int i=1; i < 10; i++) {

		//if we find a number that is not equal to 0	
		if (theArray[row][i] != 0) {

			//travel the digit array
			for (int j=0; j < 9; j++) {
				
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
	for (int i=1; i < 10; i++) {

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

template<class ItemType>
bool SudokuSolver<ItemType>::readInputFile(string filename) {

	ifstream Fin(filename);
	int x;
	int row = 1;

	if (Fin.is_open()) {

		//while the file has not reached its end
		while (!Fin.eof()) {
		
			//loop through each square in the grid
			for(int i = 1; i <10; i++) {
				//obtain digit from file
				Fin >> x;
				//place in the array position
				theArray[row][i] = x;
			}
			//increment row
			row++;
		}
	}
	//close the file that Fin opened
	Fin.close();
	return true;
}

template <class ItemType>
SudokuSolver<ItemType>::SudokuSolver(string filename) {

	readInputFile(filename);

}

/*
391	286	574
487	359	126
652	714	839

875	431	692
213	967	485
964	528	713

149	673	258
538	142	967
726	895	341
*/

//public:


template <class ItemType>
bool SudokuSolver<ItemType>::SolvePuzzle(int maxBackSteps) {
return false;
}

template<class ItemType>
void SudokuSolver<ItemType>::DisplayPuzzle() {
	for (int i = 1; i < 10; i++) {
		for (int j=1; j <10; j++) {
			cout << theArray[i][j] << " ";
		}
		cout << endl;
	}
}

