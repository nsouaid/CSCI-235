/*
Natalie Souaid
November 8th 2016
Assignment 3

This program solves sudoku puzzles from a text file using backtracking and stacks.
*/

i. Which parts of the assignment were completed? Parts 1-4 were all completed. I (1) designed an ADT for the Sudoku solver. I (2) created a class called SudokuSolver that implemented all of the private methods listed, in addition to some others. Additionally, there were, for part (3), all of the public methods included. I then created the SudokuSolver object that called SolvePuzzle and then DisplayPuzzle.



ii. Any bugs encountered?

So many! It is coming to the point where I think I definitely need to learn how to use a debugger. Using cout statements was really time consuming and inefficient. I found that a lot of my trouble came from not knowing at which point was a stack empty or full, or what number it had at any given point (and not knowing up to how many numbers in a stack was included was also challenging). I had one segmentation fault in the beginning.

I was also stuck for a while because I had left in the main function the "maxbacksteps" to be roughly 100... which was not getting me anywhere. I eventually figured it out.

iii. Complete instructions on how to run the program:

1. make all
2. ./test

iv. text files for solving the puzzle
