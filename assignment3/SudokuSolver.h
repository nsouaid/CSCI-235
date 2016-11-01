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
	int getMissingInBox(int row, int column);
	int getMissingInRow(int row);
	int getMissingInColumn(int column);
	bool readInputFile(string filename);
	LinkedStack<int> theStack;
	int theArray[10][10];

	public:

	SudokuSolver(string filename);
	bool SolvePuzzle(int maxBackSteps);
	void DisplayPuzzle();
};

#include "SudokuSolver.cpp"
#endif
