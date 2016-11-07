#include <iostream>
#include "SudokuSolver.h"

using namespace std;

int main() {

	SudokuSolver<int>mySudoku("sudokutry1.txt");
	mySudoku.DisplayPuzzle();

	mySudoku.SolvePuzzle(3);
	return 0;
}

