#include <iostream>
#include "SudokuSolver.h"

using namespace std;

int main() {

	SudokuSolver<int>mySudoku("sudokutry3.txt");

	mySudoku.SolvePuzzle(100);
	mySudoku.DisplayPuzzle();
	return 0;
}
