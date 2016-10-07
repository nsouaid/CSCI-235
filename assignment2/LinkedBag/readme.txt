/*
Natalie Souaid
October 7th 2016
Assignment 2

This program implements big integers using linked lists. The program will do a number of tests, including but not limited to, inserting, changing coefficients, and displaying the number.
*/

i. which parts of the assignment were completed:

-part 1, modify Node class
-part 2, modify LinkedBag class
	>Rename
	>Delete functions
	>Modify Insert function
	>Create 3 new member functions
	, create client functions to test implementations
-part 3, create member function to test equality
	, create client functions to test implementations

ii. any bugs encountered:

-segmentation faults when writing the insert
-usability bugs - making sure that input was appropriate.
-when outputting the 0s, there was a discrepancy between the number that was formulated and the output.
-changing the first node didn't change

iii. Complete instructions on how to run the program:

1. make all
2. ./testmain
3. start of TestBigInteger();
	a) enter exponent
	b) enter coefficient
	-either enter 'q' to quit or repeat a) and b) with an exponent less than previous

	c) enter an exponent of an >>existing node<< to obtain coefficient
	d) provide a new coefficient


