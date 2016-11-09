/** @file SudokuSolver.h */
#ifndef _SUDOKU_SOLVER
#define _SUDOKU_SOLVER

#include "SudokuInterface.h"
#include "LinkedStack.h"

template<class ItemType>
class SudokuSolver : public SudokuInterface<ItemType> {

	private:
	
	bool insert(int number, int row, int column, int index);
	bool remove(int row, int column);
	bool goBack();
	int nextEmpty();
	int getMissingInRow(int row);
	int getMissingInColumn(int column);
	int getMissingInBox(int row, int column);
	bool readInputFile(string filename);

	void getStartOfBoxCoordinates(int& row, int& column);
	int arraycount(int number);
	void createArray(int thearray[], int size, int num);
	LinkedStack<int> possibleDigits(int row, int column);
	int convertToRow(int index);
	int convertToColumn(int index);

	LinkedStack<int> stack;
	LinkedStack<int> indexstack;
	LinkedStack<int> comparestack;
	int theArray[10][10];

	public:

	SudokuSolver(string filename);
	bool SolvePuzzle(int maxBackSteps);
	void DisplayPuzzle();
};

#include "SudokuSolver.cpp"
#endif
