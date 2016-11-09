/** @file SudokuSolver.cpp */

#include "SudokuSolver.h"
#include "LinkedStack.h"
#include <cstddef>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


//private -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------------------------------------
template<class ItemType>
bool SudokuSolver<ItemType>::insert(int number, int row, int column, int index) {

	//push the number to the main stack 
	stack.Push(number);

	//push the index in the indexstack
	indexstack.Push(index);

	//put that number in the array
	theArray[row][column] = number;

	//check for invalid entries
	

	return true;
}

template <class ItemType>
bool SudokuSolver<ItemType>::SolvePuzzle(int maxBackSteps) {

//do this until the end
	while (maxBackSteps != 0) {
		
//declare a row and column and number variable
		int row, column, n;

//get the nextempty 0
		int index = nextEmpty();

//if we didn't find an index with a 0 then return puzzle solved
		if (index == 0) {
			cout << "Puzzle Solved" << endl;
			return true;
		}

//otherwise follow theses steps : TRYING A SQUARE WITH A 0:
		if (index !=0) {
			row = convertToRow(index);
			column = convertToColumn(index);

			cout << index << endl;

//create a temporary stack to try all the numbers : NUMBERS THAT GO WITH A SQUARE
			LinkedStack<int> theNumbersToTry(possibleDigits(row,column));

			//CASE 1: THERE ARE NO NUMBERS WITH THAT SQUARE
			if (theNumbersToTry.IsEmpty()) {
				
				//this is where we backtrack - because the numberstotry is empty, meaning it doesn't work.
				goBack();
				cout << "our first GOOOOOOO BACCCKKKKK!" << endl;
			}

			//CASE 2: THERE ARE NUMBERS THAT BELONG TO THE SQUARE
			//WHICH MEANS EITHER it's coming from past - what is in the stack is the previous cell
			//or coming from a future cell - is what we should be trying
			else if (!theNumbersToTry.IsEmpty()){

				//if the compare stack has an item in it we can compare to try the next number
				if (!comparestack.IsEmpty()) {

//number is < Compare
					if (theNumbersToTry.Peek() < comparestack.Peek()) {
						cout << "------------------------------------------------------------------case 1 (number is LESS than compare)" << endl;
						cout << "compare: " << comparestack.Peek() << endl;

						while (!(theNumbersToTry.Peek() == comparestack.Peek())) {
							if (!theNumbersToTry.IsEmpty()) {
								theNumbersToTry.Pop();
							}
						}

						if (!theNumbersToTry.IsEmpty()) {
							theNumbersToTry.Pop();
						}

						if (theNumbersToTry.IsEmpty()) {
							cout << "------------------------------------------------------------------1:a empty stack, GO bAcK" << endl;
							cout << "compare: " << comparestack.Peek() << endl;
							comparestack.Pop();
							goBack();
						}
						else {
							cout << "------------------------------------------------------------------1:b insert to grid" << endl;
							cout << "compare: " << comparestack.Peek() << endl;
							comparestack.Pop();
							n = theNumbersToTry.Peek();
							insert (n, row, column, index);
						}
					}

//number is == Compare
					else if (theNumbersToTry.Peek() == comparestack.Peek()) {
						cout << "------------------------------------------------------------------case 2 (number is SAME)" << endl;
					cout << "compare: " << comparestack.Peek() << endl;

							theNumbersToTry.Pop();
						
			//1. there are greater numbers remaining to try	
						if (!theNumbersToTry.IsEmpty()) {
								
							cout << "------------------------------------------------------------------3: more numbers exist" << endl;
					cout << "compare: " << comparestack.Peek() << endl;
							if (theNumbersToTry.Peek() == comparestack.Peek()) {
								goBack();
							}
							else {	
								n =theNumbersToTry.Peek();
								insert (n, row, column, index);
								comparestack.Pop();
							}
						}

			//2. that is the only data item in the numberstotry stack and should therefore GO BACK
						if (theNumbersToTry.IsEmpty()) {
								cout << "------------------------------------------------------------------5: second GO BACK!" << endl;
					cout << "compare: " << comparestack.Peek() << endl;
							comparestack.Pop();
							goBack();
						}
	
					}
							
				}
				//else the compare stack is empty.... so continue to add numbers
				else {
					n = theNumbersToTry.Peek();
					insert (n, row, column, index);

				}


			}//

		}
		maxBackSteps--;
	}
	return true;
}


//------------------------------------------------------------------------------------------------------------------------------------------------
template<class ItemType>
bool SudokuSolver<ItemType>::remove(int row, int column) {

	theArray[row][column] = 0;
	comparestack.Push(stack.Peek());
	indexstack.Pop();
	stack.Pop();

	return true;
}

//------------------------------------------------------------------------------------------------------------------------------------------------
template<class ItemType>
bool SudokuSolver<ItemType>::goBack() {

	int index, row, column;

	//find the index of previous
	index = indexstack.Peek();

	//convert to row and column
	row = convertToRow(index);
	column = convertToColumn(index);

	//delete that row and column (from the array)
	remove(row,column);

return true;
}

//------------------------------------------------------------------------------------------------------------------------------------------------
template<class ItemType>
int SudokuSolver<ItemType>::nextEmpty() {

int count=0;

	for (int i =1; i < 10; i++) {
		for (int j =1; j <10; j++) {
			count++;
			if (theArray[i][j] == 0) {

				//place the index number in the indexstack
				return count;
			}
		}
	}

return 0;
}

//------------------------------------------------------------------------------------------------------------------------------------------------
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

//------------------------------------------------------------------------------------------------------------------------------------------------
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

//------------------------------------------------------------------------------------------------------------------------------------------------
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

//------------------------------------------------------------------------------------------------------------------------------------------------
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

//------------------------------------------------------------------------------------------------------------------------------------------------
template<class ItemType>
LinkedStack<int> SudokuSolver<ItemType>::possibleDigits(int row, int column) {

	//for holding the int values
	int c, r, b, temp;
	//for storing the common digits
	int c_size, r_size, b_size;
	LinkedStack<int> tempStack;

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


	cout << "c size: " << c_size << endl;
	cout << "c:" << c << endl;

	cout << "r size: " << r_size << endl;
	cout << "r:" << r << endl;

	cout << "b size: " << b_size << endl;
	cout << "b:" << b << endl;



	//place value
	createArray(c_array, c_size, c);
	createArray(r_array, r_size, r);
	createArray(b_array, b_size, b);

	cout << "c: ";
	for (int i =0; i < c_size; i++) {

		cout << c_array[i];
	}
	cout << endl;
	cout << "r: ";
	for (int i =0; i < r_size; i++) {

		cout << r_array[i];
	}
	cout << endl;
	cout << "b: ";
	for (int i =0; i < b_size; i++) {

		cout << b_array[i];
	}
	cout << endl;
	



	//check all three arrays to see which are all three common
	for (int i = 0; i < c_size; i++) {
		for (int j = 0; j < r_size; j++) {
			for (int k = 0; k < b_size; k++) {
				//if there is a common number among all the arrays
				if ((c_array[i] == r_array[j])  && (r_array[j]== b_array[k])) {
					//get the number

					temp = c_array[i];
					cout << "what's in temp currently: " << temp << endl;
					//Push it in the "return" stack
					tempStack.Push(temp);
				}
			}
		}		
	}

return tempStack;
}

//------------------------------------------------------------------------------------------------------------------------------------------------
template<class ItemType>
int SudokuSolver<ItemType>::arraycount(int number){

	int digitcount=0;
	while (number !=0) {
		number= number /10;
		digitcount++;
	}

	return digitcount;
}

//------------------------------------------------------------------------------------------------------------------------------------------------
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

//------------------------------------------------------------------------------------------------------------------------------------------------
template<class ItemType>
void SudokuSolver<ItemType>::createArray(int thearray[], int size, int num) {

	int value=0;

	//while we have a number that has digits
	for (int y = 0; y <size; y++) {
		//obtain a digit
		value = num % 10;

		//cast off that same digit
		num = num / 10;

		//put in the array
		thearray[y] = value;
	}
}

//------------------------------------------------------------------------------------------------------------------------------------------------
template <class ItemType>
SudokuSolver<ItemType>::SudokuSolver(string filename) {

	readInputFile(filename);

}

//------------------------------------------------------------------------------------------------------------------------------------------------
template<class ItemType>
int SudokuSolver<ItemType>::convertToRow(int index) {

	int row;

	//for the row:
	row = (((index-1)/(9))+(1));

return row;
}

//------------------------------------------------------------------------------------------------------------------------------------------------
template<class ItemType>
int SudokuSolver<ItemType>::convertToColumn(int index) {

	int column;

	//for the column:

	if( index % 9 == 0) {
		column = 9;
	}

	else column = index % 9;

return column;
}


//public -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------------------------------------


//------------------------------------------------------------------------------------------------------------------------------------------------
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
