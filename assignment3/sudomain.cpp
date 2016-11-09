#include <iostream>
#include "SudokuSolver.h"

using namespace std;

int main() {

	SudokuSolver<int>mySudoku("sudokutry2.txt");

	mySudoku.SolvePuzzle(100);
	mySudoku.DisplayPuzzle();
	return 0;
}
