#include <iostream>
using namespace std;

typedef int Item; //only for linked lists of int data

/*we can use the linked list as an abstract data type

	imagine the LINKED_LIST to be a structure deep in memory land. it doesn't matter where the data goes, it only matters that we at least keep track of one part so that we don't

			lose


	any data.


*/

class LINKED_LIST {
	private:
		
		struct node {
			Item item;
			node * next;
			node(Item x, node * t) {
				item = x;
				next = t;
			}
		};

		//this creates a node pointer, and "link" is the name
		typedef node * link;

		//created the head of the LINKED_LIST
		link head;		
	
	public:
 
		//constructor for the head part as we've already filled the constructor for the node within the node
		LINKED_LIST(){
			head = NULL;
		}

		//now our functions....

		bool isEmpty() {
			return (head==NULL);
		}

		//remember what evaluates first. 
		//1. a new node is created
		//2. with the arguments x from the user and head as the
		// address that head is already pointing to
		//3. head now gets this #####new node!#####
		void AddHead(Item x){

			head = new node(x, head);
		}

		//returning an int
		Item RemoveHead() {
			//create a new int that gets the integer that head is pointing to
			Item v = head ->item;
			
			//create a new node pointer to get the address of the node after the 1st one
			link t = head ->next;
		
			//remove head (along with it the first node)
			delete head;
			
			//head now gets to be what t was pointing to
			head = t;
		
			//give us the integer that was part of that specific node
			return v;
		}

		Item RemoveTail() {
			//traverse the list to find the last node
			link t = head;
			link prev = NULL;

			while (t->next !=NULL) {
				prev = t;
				t = t->next;
			}
			Item v = t -> item;
	
			//did we remove the last node?
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

int main() {

	
	LINKED_LIST myList;
	
	myList.AddHead(10);
	myList.AddHead(12);
	myList.AddHead(12);
	myList.AddHead(12);
	myList.AddHead(12);

	int j = myList.RemoveHead();
	int k = myList.RemoveHead();
	int l = myList.RemoveHead();
	int m = myList.RemoveHead();
	int n = myList.RemoveHead();

	cout << "the numbers:" << endl;
	cout << "j: " << j << endl;
	cout << "k: " << k << endl;
	cout << "l: " << l << endl;
	cout << "m: " << m << endl;
	cout << "n: " << n << endl;
	return 0;
}
