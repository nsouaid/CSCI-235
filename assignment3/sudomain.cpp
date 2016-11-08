#include <iostream>
#include "SudokuSolver.h"

using namespace std;

int main() {

	SudokuSolver<int>mySudoku("sudokutry1.txt");

	mySudoku.SolvePuzzle(100);
	mySudoku.DisplayPuzzle();
	return 0;
}


/*
391	286	574
487	359	126
652	714	839

875	431	692
213	967	485
964	528	713

149	673	258
538	142	967
726	895	341
*/

