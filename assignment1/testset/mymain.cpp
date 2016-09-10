#include <iostream>
#include <string>
using namespace std;
#include "mySet.h"


int main() {

MYSET<int> a_set;
cout << "This is the empty set, and IsEmpty() returns " << a_set.IsEmpty() <<
endl;

a_set.Add(4);
a_set.Add(2);
a_set.Add(31);


MYSET<int> another_set(9);
cout << "This set has an element in it. To view its contents we need to convert it into a vector." << endl;


vector <int> myVector = a_set.ToVector();
vector <int> yourVector = another_set.ToVector();

	for (int i = 0; i < 3; i++) {
		cout << myVector[i] << endl;
	}

	cout << yourVector[0] << endl;
	return 0;
};
