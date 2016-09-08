/*
courtesy of Thordur E. Halldorsson, KIT as I work my way through examples to understand ADTs and the likes. copyright (c) 2013

any additional code is my own
*/

#include <iostream>
using namespace std;

typedef int Item;

class LINKED_LIST {
	private:
		struct node {
			Item item; node * next;
			node(Item x, node * t) {
				item = x; next = t;
			}
		};
		typedef node * link;
		link head;		
	
	public:
		LINKED_LIST(){
			head = NULL;
		}
		bool isEmpty() {
			return (head==NULL);
		}
		void AddHead(Item x){
			head = new node(x, head);
		}
		Item RemoveHead() {
			Item v = head ->item;
			link t = head ->next;
			delete head;
			head = t;
			return v;
		}
		Item RemoveTail() {
			link t = head;
			link prev = NULL;

			while (t->next !=NULL) {
				prev = t;
				t = t->next;
			}
			Item v = t -> item;
			if (prev == NULL) {
				head = NULL;
			}
			else {
				prev->next = NULL;
			}
			delete t;
			return v;
		}
};

class STACK {

	//the first step is to create the "prototypes" for the methods we will use. We can then either place these in an "implementation" file or we can place them within the class function itself. If this class is in a header file, then we need to "#include" the header file in that implementation file.

	private:
		LINKED_LIST stackll; //this initializes in its constructor

	public:
		STACK(){
		} //basically, this is empty because WITHIN the private classifier, the linked list itself has a private identifier that is initialized once called.
		bool isEmpty() {
		return stackll.isEmpty(); //this is another function that has been "forwarded"
		}
		void push(Item x);
		Item Pop();
};


int main() {

	
	STACK myStack; //remember, if it's a default constructor, we should not have a pair of parenthesis when we declare it.

	myStack.push(8);
	myStack.push(3);

	int i = myStack.pop(); //since this is a "stack" we should expect to see that the last "Item" (or, integer) that was given to the computer is the first "Item" we receive. We should, in this case, expect to see the number 3 written to the console.

	cout << "the last number that we put in the computer is " << i << "." << endl;

	LINKED_LIST myList;
	
	myList.AddHead(10);
	myList.AddHead(12);
	
	int j = myList.RemoveHead();
	int k = myList.RemoveHead();
	

	cout << "the numbers:" << endl;
	cout << "j: " << j << endl;
	cout << "k: " << k << endl;

	return 0;
}
