/*
courtesy of Thordur E. Halldorsson, KIT as I work my way through examples to understand ADTs and the likes. copyright (c) 2013
any additional code is my own - Natalie Souaid
*/
#include <iostream>
#include <string>
using namespace std;

typedef int Item;

class LINKEDLIST {
	private:
		struct node {
			//two data fields
			Item item; 
			node * next;

			node(Item x, node * t) {
				item = x; next = t;
			}
		};
		typedef node * link;
		link head;		
	
	public:
		//constructor
		LINKEDLIST(){
			head = NULL;
		}

		//check to see if the head is pointing to a NULL address
		bool isEmpty() {
			return (head==NULL);
		}
	
		//insert node to the top of the list
		void AddHead(Item x){
			head = new node(x, head);
		}

		//obtain the item from the topr of the list, and return it, then delete the node. make sure the temporary node pointer is keeping track of the list
		Item RemoveHead() {
			Item v = head ->item;
			link t = head ->next; //because we are deleting what head is pointing to - we have to make sure we are keeping track of the rest of the list
			delete head; //thus "losing" the address of that first node
			head = t;
			return v;
		}

		//
		Item RemoveTail() {
			link t = head;
			link prev = NULL;
			
			//if the next's arrow is not pointing to a NULL address, have prev take the same address then move to the next node
			while (t->next !=NULL) {
				prev = t;
				t = t->next;
			}
			//now that the next's arrow is pointing to NULL, take the data fro that node
			Item v = t -> item;

			//this just means that if previous is NULL, it's its own NULL address which means it never moved in the first place so head just becomes NULL because there was only one node in the list
			if (prev == NULL) {
				head = NULL;
			}
			//otherwise the node that t is pointing to is forgotten
			else {
				prev->next = NULL;
			}
			delete t;
			return v;
		}

		removeNode(int nodeIdx) {
			link t = head;
			link prev = NULL;
	
			for (int i = 0; i < nodeIdx; i++) {


			}
		}
};

class STACK {

	//the first step is to create the "prototypes" for the methods we will use. We can then either place these in an "implementation" file or we can place them within the class function itself. If this class is in a header file, then we need to "#include" the header file in that implementation file.

	private:
		LINKEDLIST stackll; //this initializes in its constructor

	public:
		STACK(){
		} //basically, this is empty because WITHIN the private classifier, the linked list itself has a private identifier that is initialized once called.
		bool isEmpty() {
		return stackll.isEmpty(); //this is another function that has been "forwarded" to the data structure itself
		}

		//basically these "container" classes just allow us to forward messages to our data structure that already has some functions. draw this out later!!!
		void push(Item x) {
			stackll.AddHead(x);
		}
		Item Pop() {
			Item pop;
			pop = stackll.RemoveHead();
			return pop;
		}
};

class QUEUE {

	private:

		LINKEDLIST queuell;

	public:
		QUEUE() {
		}
		bool isEmpty() {
			return queuell.isEmpty();
		}
		void Enqueue(Item x) {
			queuell.AddHead(x);
		}
		Item Dequeue() {
			Item element = queuell.RemoveTail();
			return element;
		}
};

class Bag {

	private:
		LINKEDLIST bagll;
		item N;
	public:
		Bag() {
		N=0;
		}
		void Insert(Item x) {
			 bagll.AddHead(x);
		}
		Item Draw() {
			int r = rand() % N;
			item x = bagll.Remove(r);
			N = N - 1;			
		}
};


int main() {

	
	STACK myStack; //remember, if it's a default constructor, we should not have a pair of parenthesis when we declare it.

	myStack.push(8);
	myStack.push(3);

	int i = myStack.Pop(); //since this is a "stack" we should expect to see that the last "Item" (or, integer) that was given to the computer is the first "Item" we receive. We should, in this case, expect to see the number 3 written to the console.

	cout << "when we remove from the stack, we get the last number that we entered which was " << i << "." << endl;

	QUEUE myQueue;

	myQueue.Enqueue(8);
	myQueue.Enqueue(3);

	int p = myQueue.Dequeue();
	cout << "when we remove from the queue we get the first number that was entered which was " << p << "." << endl;
/*
	LINKED_LIST myList;
	
	myList.AddHead(10);
	myList.AddHead(12);
	
	int j = myList.RemoveHead();
	int k = myList.RemoveHead();
	

	cout << "the numbers:" << endl;
	cout << "j: " << j << endl;
	cout << "k: " << k << endl;
*/
	return 0;
}
