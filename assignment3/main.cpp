//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

#include <iostream>
#include <string>
#include "LinkedStack.h"

using namespace std;

void copyConstructorTester()
{
  LinkedStack<string> stack;
   string items[] = {"zero", "one", "two", "three", "four", "five"};
   for (int i = 0; i < 6; i++)
   {
     cout << "Pushing " << items[i] << endl;
     bool success = stack.Push(items[i]);
      if (!success)
	cout << "Failed to Push " << items[i] << " onto the stack." << endl;
   }
   cout << "Stack contains, from top to bottom, five four three two one zero." << endl;

   LinkedStack<string> copyOfStack(stack);
   cout << "Copy of stack contains, from top to bottom, ";
	for (int i = 0; i < 6; i++)
   {
      cout << " " << copyOfStack.Peek();
      copyOfStack.Pop();
   }
   cout << "." << endl;
   
   cout << "Original stack contains, from top to bottom,";
	for (int i = 0; i < 6; i++)
   {
      cout << " " << stack.Peek();
      stack.Pop();
   }
   cout << "." << endl;
}  // end copyConstructorTester

void stackTester()
{
  StackInterface<string>* stackPtr = new LinkedStack<string>();
  cout << "\nTesting the Link-Based Stack:" <<endl;
  
  string items[] = {"zero", "one", "two", "three", "four", "five"};
  cout << "Empty: " << stackPtr->IsEmpty() << endl;
  for (int i = 0; i < 6; i++)
    {
      cout<<"Pushing " << items[i] << endl;
      bool success = stackPtr->Push(items[i]);
      if (!success)
	cout << "Failed to Push " << items[i] << " onto the stack." << endl;
    }
  
  
  cout << "Empty?: " << stackPtr->IsEmpty() << endl;
  
  for (int i = 0; i < 5; i++)  // NEEDS TO BE 5 TO AVOID ASSERT ERROR
    {
      cout << "Loop " << i << endl;
      cout << "Peek1: " << stackPtr->Peek() << endl;
      cout << "Pop: " << stackPtr->Pop() << endl;
      cout << "Empty: " << stackPtr->IsEmpty() << endl;
    }
  cout << "Empty: " << stackPtr->IsEmpty() << endl;
  
  cout << "Pop an empty stack: " << endl;
  cout << "Pop: " << stackPtr->Pop() << endl; // nothing to Pop!
  
  cout << "Peek into an empty stack: " << endl;
  cout << "Peek: " << stackPtr->Peek() << endl; // nothing to Peek!
}  // end stackTester

int main()
{
  copyConstructorTester();
    try {
    stackTester();
    }
    catch (PreconditionViolatedException the_exception) {
    cout << the_exception.what();
    }
    cout << endl << "After tester" << endl;
  return 0;
}
