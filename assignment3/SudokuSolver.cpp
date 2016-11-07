/** @file SudokuSolver.cpp */

#include "SudokuSolver.h"
#include "LinkedStack.h"

#include <cstddef>
#include <fstream>
#include <string>
#include <vector>
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

int count=0;

	for (int i =1; i < 10; i++) {
		for (int j =1; j <10; j++) {
			count++;
			if (theArray[i][j] == 0) {
				return count;
			}
		}
	}


return 0;
}

template<class ItemType>
int SudokuSolver<ItemType>::getMissingInBox(int row, int column) {

	//return value
	int retval=0;	

	//create an array to hold the digits to check
	int theDigits[] = {1,2,3,4,5,6,7,8,9};

	//obtain the beginning of the box that we are getting the numbers of
	getStartOfBoxCoordinates(row, column);

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

	if (Fin.is_open()) {

		for (int j = 1; j < 10; j++) {
			//loop through each square in the grid
			for(int i = 1; i <10; i++) {
				//obtain digit from file
				Fin >> x;
				//place in the array position
				theArray[j][i] = x;
			}
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

	cout << nextEmpty();

	LinkedStack<int> theNumbersToTry(possibleDigits(5,2));


return true;
}

template<class ItemType>
void SudokuSolver<ItemType>::DisplayPuzzle() {

	cout << endl << "Your completed puzzle!:" << endl;
	cout << endl;
	for (int i = 1; i < 10; i++) {
		for (int j=1; j <10; j++) {
			cout << theArray[i][j];
			if (j %3 == 0) {
				cout << " ";
			}
		}
		if (i% 3 ==0 ) {
			cout << endl;
		}
		cout << endl;
	}
}


template<class ItemType>
LinkedStack<int> SudokuSolver<ItemType>::possibleDigits(int row, int column) {

	//for holding the int values
	int c, r, b, temp;
	//for storing the common digits
	int c_size, r_size, b_size;
	LinkedStack<int> commons;

	//obtain the number
	c = getMissingInColumn(column);
	r = getMissingInRow(row);
	b = getMissingInBox(row, column);

	//obtain the size of each array
	c_size = arraycount(c);
	r_size = arraycount(r);
	b_size = arraycount(b);

	//create the array
	int c_array[c_size];
	int r_array[r_size];
	int b_array[b_size];

	//place value
	createArray(c_array, c_size, c);
	createArray(r_array, r_size, r);
	createArray(b_array, b_size, b);

	//check all three arrays to see which are all three common
	for (int i = 0; i < c_size; i++) {
		for (int j = 0; j < r_size; j++) {
			for (int k = 0; k < b_size; k++) {
				if ((c_array[i] == r_array[j]) && (c_array[i] == b_array[k])) {
					//get the number
					temp = c_array[i];

					//Push it in the return stack
					commons.Push(temp);
				}
			}
		}		
	}

return commons;
}

template<class ItemType>
int SudokuSolver<ItemType>::arraycount(int number){

	int digitcount=0;
	while (number !=0) {
		number= number /10;
		digitcount++;
	}

	return digitcount;
}


template<class ItemType>
void SudokuSolver<ItemType>::createArray(int thearray[], int size, int num) {

	int value=0, i=0, remaining = 9;

	//while we have a number that has digits
	while (num !=0) {
		//obtain a digit
		value = num % 10;

		//cast off that same digit
		num = num / 10;

		//put in the array
		thearray[i] = value;

		//move to next index
		i++;

		//reduce remaining cells in the array
		remaining--;
	}

	//if we have cells left in the array, 
	if (remaining > 0) {
		for (int j =i; j < remaining; j++) {
			thearray[j] = 0;
		}
	}
}



template<class ItemType>
void SudokuSolver<ItemType>::getStartOfBoxCoordinates(int& row, int& column) {

	//while the row is not equal to the end equivalent of its box
	while ((row % 3) != 0) {
		row++;
	}

	//while the column is not equal to the end equivalent of its box
	while ((column % 3) != 0) {
		column++;
	}

	row = row - 2;
	column = column - 2;
}

/*
template<class ItemType>
int SudokuSolver<ItemType>::convertToIndex(int row, int column) {



}
*/
