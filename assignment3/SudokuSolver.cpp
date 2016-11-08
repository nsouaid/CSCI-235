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
bool SudokuSolver<ItemType>::insert(int number, int row, int column) {

	//push the number to the main stack 
	stack.Push(number);

	//put that number in the array
	theArray[row][column] = number;

	//check for invalid entries

	return true;
}

template <class ItemType>
bool SudokuSolver<ItemType>::SolvePuzzle(int maxBackSteps) {

while (maxBackSteps !=0) {
		
		int row, column, n;
		int index = nextEmpty();

		//if we didn't find an index with a 0 then return puzzle solved
		if (index == 0) {
			cout << "Puzzle Solved" << endl;
			return true;
		}

		//otherwise follow theses steps
		if (index !=0) {

			cout << "how many times" << endl;
			row = convertToRow(index);
			column = convertToColumn(index);

			cout << row << endl;
			cout << column << endl;

			//create a temporary stack to try all the numbers
			LinkedStack<int> theNumbersToTry(possibleDigits(row,column));

			if (theNumbersToTry.IsEmpty()) {
				
				//this is where we backtrack - because the numberstotry is empty, meaning it doesn't work.	
				goBack();
			}

			else {

				//while the numbers to try is not empty
				while (!theNumbersToTry.IsEmpty()) {

						if (stack.IsEmpty()) {
							n = theNumbersToTry.Peek();
							//remove from the stack();
							theNumbersToTry.Pop();
							insert(n, row, column);
						}
			
						//if the number in the numberstotry is greater than what's in the stack
						if (!stack.IsEmpty() && !theNumbersToTry.IsEmpty()) {						
				
							if (theNumbersToTry.Peek() > stack.Peek()) {
					
							n = theNumbersToTry.Peek();
							theNumbersToTry.Pop();

							//then pop what's on the stack and insert the new number
							stack.Pop();
				
							//and the index
							insert(n, row, column);
							}
							else {
								theNumbersToTry.Pop();
							}
						}		
				}
			}
		
		}

		maxBackSteps--;
	}
	return true;
}



//------------------------------------------------------------------------------------------------------------------------------------------------
template<class ItemType>
bool SudokuSolver<ItemType>::remove(int row, int column) {

	theArray[row][column] = 0;
	//ifnotempy needed here?
	indexstack.Pop();
	return true;
}

//------------------------------------------------------------------------------------------------------------------------------------------------
template<class ItemType>
bool SudokuSolver<ItemType>::goBack() {

	int index, row, column;

	//find the index
	index = indexstack.Peek();

	//convert to row and column
	row = convertToRow(index);
	column = convertToColumn(index);

	//delete that row and column (from the array and the indexstack)
	remove(row,column);
	
return false;
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
				indexstack.Push(count);
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
	LinkedStack<int> commons;
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


	for (int i =0; i < c_size; i++) {

		cout << "c" << c_array[i];
	}
	cout << endl;
	for (int i =0; i < r_size; i++) {

		cout << "r" << r_array[i];
	}
	cout << endl;
	for (int i =0; i < b_size; i++) {

		cout << "b" << b_array[i];
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

					//Push it in the "return" stack - NOTE: this stack is ordered from smallest at the bottom to largest on top
					tempStack.Push(temp);
				}
			}
		}		
	}


	//put the stack in order
	while (!tempStack.IsEmpty()) {
		//transfer the data to the return stack
		commons.Push(tempStack.Peek());
		//be sure to remove from tempStack so it becomes empty!
		tempStack.Pop();
	}

return commons;
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
