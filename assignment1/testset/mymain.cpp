#include <iostream>
#include <string>
using namespace std;
#include "mySet.h"


int main() {

	//opening statement
	cout << endl << "Welcome to this TestSet experience." << endl << endl;
//-----------------------------------------------------------------------------------------------------------------------------------------------

	//first task	
	cout << "(i.) The first thing we will do is test to see if - when we create an";
	cout << " empty set that it is indeed the \"empty set\"." << endl;

 	//create empty set
	MYSET <string> set_of_strings;
	
	//output true flag for empty set
	cout << "If we apply the method \"IsEmpty()\" to our newly created set ";
	cout << "(with no elements added), we get a return value of ";
	cout << set_of_strings.IsEmpty() << " where 1 means true (the set is empty) ";
	cout << "and 0 is false (the set is not empty)." << endl;
	cout << "On the otherhand, we can create a set that has an element and test ";
	cout << "to see what its return value is." << endl;

	//create a set with 1 element
	MYSET <string> set_of_strings2("12");
	
	//output false flag for non-empty set
	cout << "When we call \"IsEmpty()\" for this newer set, we get a value of ";
	cout << set_of_strings2.IsEmpty() << " which of course indicates to us that ";
	cout << "the set is not empty. There should be an element in this newer set ";
	cout << "because we instantiated a set with one element in it." << endl;
//-----------------------------------------------------------------------------------------------------------------------------------------------

	//task 2, add a user inputted word into set_of_strings object
	string userword="";
	cout << endl << "(ii.) Now, we will add one element to our empty set. ";
	cout << "Since this set is a set of strings, please enter one word for the set: ";
	cin >> userword;
	set_of_strings.Add(userword);
	
	//search for the word to see if it exists
	cout << "Great, thanks. Now we will search for your entry. Your item is in the ";
	cout << "set if indicated by the number \"1\" : " ;
	cout << set_of_strings.Contains(userword) << endl;
//-----------------------------------------------------------------------------------------------------------------------------------------------

	//for max size of the specific set object
	int size =0;

	//task 3, add 6 2 4 8 2 5 2 to a set
	cout << endl << "(iii.) We can add multiple items to a set we create. ";
	cout << "We will add \"6\", \"2\", \"4\", \"8\", \"2\", \"5\", \"2\"." << endl;
	cout << endl << "(iv.) But of course we can't have the same item in a set. ";
	cout << "We should only see the number \"2\" succesfully added once. ";
	cout << "Success is, again, indicated by the number 1, and if we were unable ";
	cout << "to add a number to this set, then we'll see the number 0." << endl;
	
	//create set_of_numbers object and add to it, I chose one by one in this case
	MYSET<int>set_of_numbers;
	cout << set_of_numbers.Add(6) << "\t";
	cout << set_of_numbers.Add(2) << "\t";
	cout << set_of_numbers.Add(4) << "\t";
	cout << set_of_numbers.Add(8) << "\t";
	cout << set_of_numbers.Add(2) << "\t";
	cout << set_of_numbers.Add(5) << "\t";
	cout << set_of_numbers.Add(2) << endl;

	//task 4 - demonstrate that there are only 5 items
	cout << "We can see clearly in viewing the contents of the set that there ";
	cout << "are now only 5 elements in this set." << endl;

	//obtain the actual size of the set
	size = set_of_numbers.GetCurrentSize();

	//turn into vector for display purposes
	vector <int> displayVect;
	displayVect = set_of_numbers.ToVector();

	//iterate and console out the contents of the vector
	for (int i =0; i < size; i++ ) {
		cout << i+1 << ") ";
		cout << displayVect[i] << "\t";
	}

	cout << endl << endl;
//-----------------------------------------------------------------------------------------------------------------------------------------------

	//task five
	MYSET <float> set_of_floats;
	set_of_floats.Add(3.1415);
	set_of_floats.Add(0.011235813);
	set_of_floats.Add(2.718);
	set_of_floats.Add(0.57721);
	set_of_floats.Add(1.61803);
	
	float guess=0;

	cout << "(v.) Should we want to see if an element is in our set, ";
	cout << "we can call the method \"Contains()\". ";
	cout << "We will be notified by way of \"1\" or \"0\" if the element is in the set. ";
	cout << "Can you guess which floating point number is in my set? " << endl;
	cout << "I don't think you can: ";

	cin >> guess;

	cout << "Resulting return value is " << set_of_floats.Contains(guess);
	cout << " which means your guess is not in the set." << endl;
	cout << "We can, however, magically guess that \"0.57721\" is in our set. ";
	cout << "This is true, and so we should therefore see that our return ";
	cout << "value is \"1\": ";
	cout << set_of_floats.Contains(0.57721)  <<". Success." << endl << endl;
//-----------------------------------------------------------------------------------------------------------------------------------------------
	
	cout << "(vi.) Now we will attempt to add more elements to a set than the ";
	cout << "maximum items allowed (which, is currently \"6\")." << endl;

	MYSET <string> animals;

	cout << "We have a set of animals that we would like to add to. Let's see what ";
	cout << "the outcome is of each add of an animal:" << endl;


	string myanimals[] = {"elephant", "squirrel", "bird", "lion", 
	"sloth", "dog", "fox", "cat", "rabbit", "llama"};


	for(int i =0; i < 10; i++) {
		cout << i+1 << ". " << myanimals[i] << " results in: ";
		if (animals.Add(myanimals[i]) == 1) {
			cout << "successful add"<< endl;
		}
		else {
			cout << "fail" << endl;
		}
	}

	cout << endl;
//-----------------------------------------------------------------------------------------------------------------------------------------------

	cout << "(vii.)	Say we want to add an item that already exists in a set. ";
	cout << "We will see that, since it is a set after all, that we cannot add ";
	cout << "an item that already exists in the set." << endl;
	cout << "Do you remember the word you typed in earlier to put into a set ";
	cout << "of strings? That's okay, we remember. You inputted \"";
	cout << userword << "\"." << endl;
	cout << "We'll try to put \"" << userword << "\" in the same set of strings ";
	cout << "that we created before." << endl;

	cout << "The result of this action is: " << set_of_strings.Add(userword) << endl;
	cout << "Unsuccessful. Unable to add the same word to the set." << endl << endl;
//-----------------------------------------------------------------------------------------------------------------------------------------------
	
	cout << "(viii.) We now revisit our empty set of strings that we created earlier. ";
	cout << "What would happen if we tried to remove an item from that empty set? ";
	cout << "Let's take a look. " << endl;
	cout << "We will perform the action \"Remove()\" on the set of strings. If we have ";
	cout << "returned a \"1\" then we have removed an element. ";
	cout << "It should return \"0\"." << endl;
	cout << "Result: " << set_of_strings.Remove(" ") << endl;
	cout << "Unable to remove an element from the empty set." << endl;
//-----------------------------------------------------------------------------------------------------------------------------------------------	

	cout << "(ix.) Our last test will be to make sure we can remove a given item ";
	cout << "from a set. We will try to remove " << myanimals[2] << " from our ";
	cout << "set \"animals\" because we know that this item exists from our test ";
	cout << "number (vi). " << endl;
	cout << "The result of removing " << myanimals[2] << " from the set ";
	cout << "returns " << animals.Remove(myanimals[2]) << endl;
	cout << "If we convert this set to a vector, we will see a difference from ";
	cout << "the set it was before: " << endl;

	vector<string> animvector = animals.ToVector();

	size = animals.GetCurrentSize();

	for (int i=0; i < size; i++) {
		cout << i+1 << "." << animvector[i] << endl;
	}

	return 0;
};























