/** @file SudokuInterface.h */
#ifndef SUDOKU_INTERFACE_H_
#define SUDOKU_INTERFACE_H_
using namespace std;

template<class ItemType>
class SudokuInterface {

	public:
	virtual bool SolvePuzzle(int maxBackSteps) = 0;
	virtual void DisplayPuzzle() = 0;
};

#endif
