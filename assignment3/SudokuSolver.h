/ ** @file SudokuSolver.h */
#ifndef _SUDOKU_SOLVER
#define _SUDOKU_SOLVER

class SudokuSolver {

	private:
	
	bool insert(int number, int row, int column);
	bool remove(int row, int column);
	bool goBack();
	int nextEmpty();
	int getMissingInBox(int row, int column);
	int getMissingInRow(int row);
	int getMissingInColumn(int column);
	bool readInputFile(string filename);
	LinkedStack<int> stack;

	public:




};
