/** @file SudokuSolver.h */
#ifndef _SUDOKU_SOLVER
#define _SUDOKU_SOLVER

#include "SudokuInterface.h"
#include "LinkedStack.h"

template<class ItemType>
class SudokuSolver : public SudokuInterface<ItemType> {

	private:
	
	bool insert(int number, int row, int column);
	bool remove(int row, int column);
	bool goBack();
	int nextEmpty();
	void getStartOfBoxCoordinates(int& row, int& column);

	int arraycount(int number);

	void createArray(int thearray[], int size, int num);


	LinkedStack<int> possibleDigits(int row, int column);

	int getMissingInBox(int row, int column);
	int getMissingInRow(int row);
	int getMissingInColumn(int column);

	int convertToRow(int index);
	int convertToColumn(int index);
	bool readInputFile(string filename);
	LinkedStack<int> stack;
	LinkedStack<int> indexstack;
	int theArray[10][10];

	public:

	SudokuSolver(string filename);
	bool SolvePuzzle(int maxBackSteps);
	void DisplayPuzzle();
};

#include "SudokuSolver.cpp"
#endif
