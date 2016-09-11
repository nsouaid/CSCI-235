/**	@file mySet.cpp (same as ArraySet) */

#include <cstddef>

//default constructor
template<class ItemType>
MYSET<ItemType>::MYSET() : item_count_(0), max_items_(kDefaultSetSize_) {
}

//constructor addition to construct a Set for a single item
template<class ItemType>
MYSET<ItemType>::MYSET(const ItemType &an_Item) {
	items_[0]= an_Item;
	item_count_ ++;
}

//obtains the current size 
template<class ItemType>
int MYSET<ItemType>::GetCurrentSize() const {
	return item_count_;
}

//is the Set empty?
template<class ItemType>
bool MYSET<ItemType>::IsEmpty() const {
	return (item_count_ == 0);
}

//add a certain new_entry
template<class ItemType>
bool MYSET<ItemType>::Add(const ItemType& new_entry) {
	bool has_room_to_add = item_count_ < max_items_;
	bool duplicate = false;
	bool retval = false;

	if (Contains(new_entry)) {
		duplicate = true;
	}
	else {
		duplicate = false;
	}
	
	if ((has_room_to_add) && (duplicate == false)) {
		items_[item_count_] = new_entry;
		item_count_++;
		retval = true;
	}
	else {
		retval = false;
	}
	return retval;
}

//remove a certain entry
template<class ItemType>
bool MYSET<ItemType>::Remove(const ItemType& an_entry) {
	int located_index = GetIndexOf(an_entry);
	bool can_remove_item = !IsEmpty() && (located_index > -1);
	if (can_remove_item) {
		item_count_--;
		items_[located_index] = items_[item_count_];
    	}
  	return can_remove_item;
}

//how exactly does this "clear" - ask
template<class ItemType>
void MYSET<ItemType>::Clear() {
	item_count_ = 0;
}

//does the set contain a certain entry?
template<class ItemType>
bool MYSET<ItemType>::Contains(const ItemType& an_entry) const {
	return GetIndexOf(an_entry) > -1;
}

template<class ItemType>
vector<ItemType> MYSET<ItemType>::ToVector() const {
	vector<ItemType> set_contents;
	for (int i = 0; i < item_count_; i++) {
		set_contents.push_back(items_[i]);
	}
	return set_contents;
}

template<class ItemType> 
int MYSET<ItemType>::GetIndexOf(const ItemType& target) const {
	bool found = false;
	int result = -1;
	int search_index = 0;
	
	// if the set is empty, item_count is zero, so loop is skipped (search indx can't be negative)
	while (!found && (search_index < item_count_)) {
		if (items_[search_index] == target) {
			found = true;
			result = search_index;
		}
		else {
			search_index++;
		}
	}
	return result;
}

//templated client functions below
template<class ItemType>
void DisplaySet(const MYSET<ItemType> &theSet) {

	//create vector for displaying
	vector<ItemType> dvector;
	int size;	

	//obtain set contents and size
	dvector = theSet.ToVector();
	size = theSet.GetCurrentSize();

	//
	for(int i=0; i < size; i++) {
		cout << dvector[i] << endl;
	}
}

template <class ItemType>
MYSET<ItemType> IntersectSets(const MYSET<ItemType> &set1, MYSET<ItemType> &set2) {

	//create the return set
	MYSET <ItemType> returnSet;

	//the vectors get the contents of each set respectively
	vector <ItemType> one = set1.ToVector();
	vector <ItemType> two = set2.ToVector();

	//sizes of the vectors
	int size1 = set1.GetCurrentSize();
	int size2 = set2.GetCurrentSize();

	//if one or both are empty sets then we must return an empty set (that is its intersection)
	if (set1.IsEmpty() || set2.IsEmpty()) {
		cout << "Empty Set." << endl;
		return returnSet;
	}

	//as we go through each combination of indexes between the two vectors, check to see if
	//any of the items are equal to each other. If they are, then add the item to the vector. 
	for (int i = 0; i < size1; i++) {
		for(int j = 0; j < size2; j++) {
			if (one[i] == two[j]) {
				returnSet.Add(one[i]);
			}
		}
	}
	//this is for test case, when both sets have elements but not the same ones
	if (returnSet.IsEmpty()) {
		cout << "Empty Set." << endl;	
	}
	return returnSet;
}

void TestIntersectSets() {

	//objects creation
	MYSET <int> empty1, empty2, elmt1, elmt2, uncommon, newset;
	MYSET <string> e1, e2, str1, str2, un, ne;
	
	//add elements to the int sets
	elmt1.Add(9); elmt1.Add(8); elmt1.Add(7); elmt1.Add(6);
	elmt2.Add(9); elmt2.Add(8); elmt2.Add(20); elmt2.Add(50);
	uncommon.Add(-2); uncommon.Add(100); uncommon.Add(200); uncommon.Add(0);

	//add elements to the string sets
	str1.Add("abc"); str1.Add("bcd"); str1.Add("cde"); str1.Add("def");
	str2.Add("abc"); str2.Add("vwx"); str2.Add("uvw"); str2.Add("def");
	un.Add("wxy"); un.Add("xyz"); un.Add("yza"); un.Add("zab");


	//test cases:
	newset = IntersectSets(elmt1, elmt2);
	ne = IntersectSets(str1, str2);	
	cout << endl;

	//intersection of 2empty sets == empty set
	cout << "Two empty integer sets produces the ";
	IntersectSets(empty1, empty2);
	cout << "Similarly, two empty string sets also produces the ";
	IntersectSets(e1, e2);

	//intersection of 1empty set + 1set with elements == empty set
	cout << "If at least one integer set is empty, the intersection of the two sets is the ";
 	IntersectSets(empty1, elmt1);
	cout << "The intersection of at least one string set with another set results in the ";
	IntersectSets(e1, str1);

	//intersection of 2sets with no elements in common == empty set
	cout << "Should there be no integer elements in common (bust still elements int both sets), the intersection of two integer sets produces the ";
	IntersectSets(elmt1, uncommon);
	cout << "The same applies for string sets. Their intersection is the ";
	IntersectSets(str1, un);

	//intersection of common elements
	cout << "If an integer set contains:" << endl;
	DisplaySet(elmt1);
	cout << "and another set contains the elements:" << endl;
	DisplaySet(elmt2);
	cout << "then their intersection is: " << endl;
	DisplaySet(newset);
	cout << endl;
	cout << "If a string set contains:" << endl;
	DisplaySet(str1);
	cout << "and another string set contains the elements:" << endl;
	DisplaySet(str2);
	cout << "then their intersection is: " << endl;
	DisplaySet(ne);
	cout << endl;
}

void pleasepause() {

	int x = 1;
	while(x != 0) {
		cout << "Please type \"0\" to continue ";
		cin >> x;
		cout << endl;
	}
}





