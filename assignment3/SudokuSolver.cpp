/** @file SudokuSolver.cpp */

#include "SudokuSolver.h"
#include "LinkedStack.h"
#include <cstddef>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


//private

//------------------------------------------------------------------------------------------------------------------------------------------------
template<class ItemType>
bool SudokuSolver<ItemType>::insert(int number, int row, int column, int index) {

	//push the number to the main stack 
	stack.Push(number);

	//push the index in the indexstack
	indexstack.Push(index);

	//put that number in the array
	theArray[row][column] = number;	

	return true;
}

//------------------------------------------------------------------------------------------------------------------------------------------------
template<class ItemType>
bool SudokuSolver<ItemType>::remove(int row, int column) {

	//set array square to 0
	theArray[row][column] = 0;

	//make sure the compare stack gets the most recent number in the main stack
	comparestack.Push(stack.Peek());

	//remove from the indexstack
	indexstack.Pop();

	//remove from the main stack
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

	//delete that row and column from the array, stack, and index, and store the compare number
	remove(row,column);

return true;
}

//------------------------------------------------------------------------------------------------------------------------------------------------
template<class ItemType>
int SudokuSolver<ItemType>::nextEmpty() {

int count=0;

	//loop through all the rows
	for (int i =1; i < 10; i++) {

		//and all the columns
		for (int j =1; j <10; j++) {
	
			//obtain the index number
			count++;

			//if we find a 0
			if (theArray[i][j] == 0) {

				//return that index
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
		//increase row
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

					//replace with 0
					theDigits[j] = 0;
				}
			}
		}
	}

	//now that we have a digit array that has our missing numbers, we can turn it into an int.
	for (int i = 0; i < 9; i++) {

		//only if we come across a number that is not a 0 should we:
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
void SudokuSolver<ItemType>::getStartOfBoxCoordinates(int& row, int& column) {

	//while the row is not equal to the end equivalent of its box
	while ((row % 3) != 0) {
		row++;
	}

	//while the column is not equal to the end equivalent of its box
	while ((column % 3) != 0) {
		column++;
	}

	//subtract 2 from the last position in the row
	row = row - 2;

	//subtract two from the last position in the column
	column = column - 2;
}

//------------------------------------------------------------------------------------------------------------------------------------------------
template<class ItemType>
int SudokuSolver<ItemType>::arraycount(int number){

	//to keep track of the number of digits in the number
	int digitcount=0;

	while (number !=0) {

		//shrink the number
		number= number /10;

		//add to the count each time
		digitcount++;
	}

	return digitcount;
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

	//place value
	createArray(c_array, c_size, c);
	createArray(r_array, r_size, r);
	createArray(b_array, b_size, b);

	//check all three arrays to see which are all three common
	for (int i = 0; i < c_size; i++) {
		for (int j = 0; j < r_size; j++) {
			for (int k = 0; k < b_size; k++) {

				//if there is a common number among all the arrays
				if ((c_array[i] == r_array[j])  && (r_array[j]== b_array[k])) {

					//get the number
					temp = c_array[i];

					//Push it in the return stack
					tempStack.Push(temp);
				}
			}
		}		
	}

return tempStack;
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


//public

//------------------------------------------------------------------------------------------------------------------------------------------------
template <class ItemType>
SudokuSolver<ItemType>::SudokuSolver(string filename) {

	readInputFile(filename);
}

//------------------------------------------------------------------------------------------------------------------------------------------------
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

		//otherwise - until then - follow theses steps : TRYING A SQUARE WITH A 0:
		if (index !=0) {

			//obtain the row conversion
			row = convertToRow(index);

			//obtain the column conversion
			column = convertToColumn(index);


			//create a temporary stack to try all the numbers
			LinkedStack<int> theNumbersToTry(possibleDigits(row,column));

			//case 1: there do not exist any numbers for the square in question
			if (theNumbersToTry.IsEmpty()) {

				//this is where we backtrack, because the check has failed - there are no possibiliites for that square
				goBack();
			}

			//case 2: there do exist numbers for the square in question
			//WHICH MEANS EITHER it's coming from past - what is in the stack is the previous cell
			//or coming from a future cell - is what we should be trying
			else if (!theNumbersToTry.IsEmpty()){

				//if the compare stack has an item in it we can compare to try the next number
				if (!comparestack.IsEmpty()) {

					//number is < Compare
					if (theNumbersToTry.Peek() < comparestack.Peek()) {
	
						//as we continue to pop digits from the numberstotry stack we check to see if it reaches an equality
						while (!(theNumbersToTry.Peek() == comparestack.Peek())) {
							if (!theNumbersToTry.IsEmpty()) {
								theNumbersToTry.Pop();
							}
						}
		
						//so long as thenumberstotry is still not empty, pop because we want to check the higher number
						if (!theNumbersToTry.IsEmpty()) {
							theNumbersToTry.Pop();
						}

						//if we have a stack that is empty then we should go back 
						if (theNumbersToTry.IsEmpty()) {
							comparestack.Pop();
							goBack();
						}

						//if it's not empty, then insert that number into the grid and appropriate stacks
						else {
							//clear the comparestack
							comparestack.Pop();
		
							//obtain the top of the stack
							n = theNumbersToTry.Peek();

							//insert
							insert (n, row, column, index);
						}
					}

					//number is == Compare
					else if (theNumbersToTry.Peek() == comparestack.Peek()) {

							//pop that first number
							theNumbersToTry.Pop();
						
							//1. if it's not empty, there are greater numbers remaining to try	
							if (!theNumbersToTry.IsEmpty()) {

								//check to make sure in the case that the numbers end up equal								
								if (theNumbersToTry.Peek() == comparestack.Peek()) {
	
									//in which case goes back
									goBack();
								}
								else {	
									//otherwise that number is the next in line to be tried
									n =theNumbersToTry.Peek();

									//insert to grid and remaining appropriate stacks
									insert (n, row, column, index);

									//clear the comparestack
									comparestack.Pop();
								}
							}

						//2. if the numberstotry is empty,  that is the only data item in the numberstotry stack, then we should therefore backtrack
						if (theNumbersToTry.IsEmpty()) {

							//clear the comparestack
							comparestack.Pop();
	
							//goback
							goBack();
						}
	
					}
							
				}

				//else the compare stack is empty.... so continue to add numbers
				else {
					n = theNumbersToTry.Peek();
					insert (n, row, column, index);

				}

			}

		}
		maxBackSteps--;
	}
	return true;
}

//------------------------------------------------------------------------------------------------------------------------------------------------
template<class ItemType>
void SudokuSolver<ItemType>::DisplayPuzzle() {

	cout << endl << "Your completed puzzle!:" << endl;
	cout << endl;

	//go through each row
	for (int i = 1; i < 10; i++) {

		//and column
		for (int j=1; j <10; j++) {

			//output the grid numbers
			cout << theArray[i][j];
			
			//if the column mod 3 is 0 then we can create a buffer between the sets of three columns
			if (j %3 == 0) {
				cout << " ";
			}
		}

		//same for outlining the main sets of three rows
		if (i% 3 ==0 ) {
			cout << endl;
		}
		cout << endl;
	}
}
