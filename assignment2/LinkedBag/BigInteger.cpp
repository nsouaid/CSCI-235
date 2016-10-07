/** ADT bag: Link-based implementation.
    @file BigInteger.cpp */

#include "BigInteger.h"
#include "Node.h"
#include <cstddef>


//---------------------------------------------------------------------------------------------------------------------------------------------

//templated constructor, default, to set the head pointer to nullptr
template<class ItemType>
BigInteger<ItemType>::BigInteger() : head_ptr_(nullptr), item_count_(0) {
}

//---------------------------------------------------------------------------------------------------------------------------------------------

//templated constructor, to take a BigInteger object and copy everything to make a new one
template<class ItemType>
BigInteger<ItemType>::BigInteger(const BigInteger<ItemType>& a_bag) {
//remember to check out the function for this one
	CopyNodesFrom(a_bag);
}

//---------------------------------------------------------------------------------------------------------------------------------------------

//templated operator overloader
template<class ItemType>
BigInteger<ItemType>& BigInteger<ItemType>::operator=(const BigInteger<ItemType>& right_hand_side) {

	if (this != &right_hand_side) {
	//deallocate all memory
		Clear();
	//copy everything
		CopyNodesFrom(right_hand_side);
	}
	
//return self
	return *this;
}

//---------------------------------------------------------------------------------------------------------------------------------------------

//destructor
template<class ItemType>
BigInteger<ItemType>::~BigInteger() {
	Clear();
}  

//---------------------------------------------------------------------------------------------------------------------------------------------

//return the truth value if item_count_ actually equals 0 (true) then it is empty
template<class ItemType>
bool BigInteger<ItemType>::IsEmpty() const {
	return item_count_ == 0;
}

//---------------------------------------------------------------------------------------------------------------------------------------------

//obtain an integer, the current size from the bag
template<class ItemType>
int BigInteger<ItemType>::GetCurrentSize() const {
	return item_count_;
}

//---------------------------------------------------------------------------------------------------------------------------------------------

//insert at the END of the list 
template<class ItemType>
bool BigInteger<ItemType>::Insert(const ItemType& new_entry1, const ItemType& new_entry2) {
//constraints
	if ((new_entry1 < 100 && new_entry1 >=0) && (new_entry2 < 10 && new_entry2 >= 0)) {
	//create a new node with given entries
		Node <ItemType> * last_node_pointer_ = new Node <ItemType> (new_entry1, new_entry2);
	//variables to store the comparative exponents	
		int exp1, exp2;
	//if the head pointer is pointing to NULL, then have it now point to the new Node with entries
		if (head_ptr_ == nullptr) {
		//check to make sure leading coefficient is not 0
			if (last_node_pointer_->GetCoefficient() != 0) {
			//add the first item in the list, and increment count
				head_ptr_ = last_node_pointer_;
				item_count_++;
				return true;
			}
		}

		else {
		//create a new node and point it to what head is pointing to
			Node <ItemType> * travel_pointer_ = head_ptr_;
		//while the next pointer's value is not NULL
			while(travel_pointer_ ->GetNext() != nullptr) {
			//move to the next node
				travel_pointer_ = travel_pointer_->GetNext();
			}
		//obtain the exponent of the last node
			exp1 = travel_pointer_ ->GetExponent();
		//obtain the exponent of the newly created node
			exp2 = last_node_pointer_ ->GetExponent();
		//check to make sure the entry doesn't have the same exponent
			if (exp1 != exp2) {
				travel_pointer_->SetNext(last_node_pointer_);
				item_count_++;
			}
			else {
			//if it has the same exponent, then do not insert
				return false;
			}
		}
	//insert occured
		return false;
	}
//insert didn't occur, coefficient and exponent were out of range
	else return false;
}

//---------------------------------------------------------------------------------------------------------------------------------------------

template<class ItemType>
void BigInteger<ItemType>::Clear() {
//create a pointer that points to the beginning of the list
	Node<ItemType> * current_node_to_delete = head_ptr_;
	while (head_ptr_ != nullptr) {
		head_ptr_ = head_ptr_->GetNext();
	// Return node to the system
		current_node_to_delete->SetNext(nullptr);
		delete current_node_to_delete;
	//move to next one
		current_node_to_delete = head_ptr_;
	}
//reset the counter	
	item_count_ = 0;
}

//---------------------------------------------------------------------------------------------------------------------------------------------

template<class ItemType>
int BigInteger<ItemType>::GetFrequencyOf(const ItemType& an_entry) const {

//declare variables
	int frequency = 0;
	int counter = 0;
//current gets what head is pointing to
	Node<ItemType> * current_ptr = head_ptr_;
	while (current_ptr != nullptr){
	//increase frequency if the entry is in the list (obtain coefficient from the current pointer in current node)
		if (an_entry == current_ptr->GetCoefficient()) {
			frequency++;
		}
	//increase counter
		counter++;
	//move to next node
		current_ptr = current_ptr->GetNext();

	// Check for possible serious error.
		if (counter > item_count_) {
			cout << "Serious error in BigInteger<ItemType>::GetFrequencyOf" << endl;
			return frequency;
		}
	}
	return frequency;
}

//---------------------------------------------------------------------------------------------------------------------------------------------

template<class ItemType>
bool BigInteger<ItemType>::Contains(const ItemType& an_entry1, const ItemType& an_entry2) const {
	return (GetPointerTo(an_entry1, an_entry2) != nullptr);
}

//---------------------------------------------------------------------------------------------------------------------------------------------

//will return a nullptr unless it finds the entry given - in which case will return the pointer to that Node of that specific cofficient
template<class ItemType>
Node<ItemType>* BigInteger<ItemType>::GetPointerTo(const ItemType& an_entry1, const ItemType& an_entry2) const {
//create a current pointer
	Node<ItemType> * current_ptr = head_ptr_;
//move through the list
	while (current_ptr != nullptr) {
	//find the pointer to a node that has the exponent and coefficient equal to the entered exponent and 
		if ((an_entry1 == current_ptr->GetExponent()) && (an_entry2 == current_ptr->GetCoefficient()))
		//send back the pointer
			return current_ptr;
		else
	//advance to next
		current_ptr = current_ptr->GetNext();
	}

	return nullptr;
}

//---------------------------------------------------------------------------------------------------------------------------------------------

template<class ItemType>
void BigInteger<ItemType>::CopyNodesFrom(const BigInteger<ItemType> &a_bag) {

//copy the item_count_
	item_count_ = a_bag.item_count_;
//pointer to beginning of a_bag
	Node<ItemType>* a_bag_current_pointer = a_bag.head_ptr_;
//if the bag is empty
	if (a_bag_current_pointer == nullptr) {
	//set the list to null
		head_ptr_ = nullptr;
		return;
	}

//copy first node
	head_ptr_ = new Node<ItemType>();
	head_ptr_->SetCoefficient(a_bag_current_pointer->GetCoefficient());
	head_ptr_->SetExponent(a_bag_current_pointer->GetExponent());

//copy remaining nodes - Points to last node in new chain
	Node<ItemType>* last_pointer = head_ptr_;
//advance original-chain pointer
	a_bag_current_pointer = a_bag_current_pointer->GetNext();
//while not end of list
	while (a_bag_current_pointer != nullptr) {
	// Create a new node holding the item of a_bag_current_pointer.
		Node<ItemType> * new_node_pointer = new Node<ItemType>(a_bag_current_pointer->GetCoefficient(), a_bag_current_pointer->GetExponent());
		// Link new node to end of new chain
		last_pointer->SetNext(new_node_pointer);
		// Advance pointer to new last node
		last_pointer = last_pointer->GetNext();
		// Advance original-chain pointer
		a_bag_current_pointer = a_bag_current_pointer->GetNext();
	}
	//doesnt this already have a nullpointer set from the node constructor?
	last_pointer->SetNext(nullptr); 
}

//---------------------------------------------------------------------------------------------------------------------------------------------

template<class ItemType>
void BigInteger<ItemType>::DisplayBigInteger () const {
//create a current pointer and set to beginning of list
	Node<ItemType> * travel_pointer_ = new Node<ItemType>;
	travel_pointer_ = head_ptr_;
//variables
	int exp1, exp2, zerofill;
//while not the end of list
	while (travel_pointer_->GetNext() != nullptr) {
	//display the coefficient in current node
		cout <<travel_pointer_->GetCoefficient();
	//obtain its exponent
		exp1 = travel_pointer_->GetExponent();
	//move to next node
		travel_pointer_ = travel_pointer_->GetNext();
	//obtain its exponent
		exp2 = travel_pointer_->GetExponent();
	//obtain the exponent gap		
		zerofill = exp1 - exp2;
	//if the gap is greater than 1
		if (zerofill !=1) {
		//display the remaining 0s	
			for (int i =1; i < zerofill; i++) {
				cout << "0";
			}
		}
	}
//then display the remaining coefficient
	cout << travel_pointer_->GetCoefficient();
//check to see how many 0s should follow the last node
	zerofill = travel_pointer_->GetExponent();
	for (int i =0; i < zerofill; i++) {
		cout << "0";
	}
}

//---------------------------------------------------------------------------------------------------------------------------------------------

//will return the coefficient of the given exponent
template<class ItemType>
int BigInteger<ItemType>::Coefficient (const int& exponent) const {

//variable for the return value
	int coefficient;

//create a traversal Node pointer, set to what head points to
	Node<ItemType> * travelptr = head_ptr_;

//while not the end of the list
	while (travelptr->GetNext() != nullptr) {

	//check to see in each node if its exponent is equal to the given exponent
		if ((travelptr->GetExponent()) == (exponent)) {
			coefficient = travelptr->GetCoefficient(); 
		}
	//advance the pointer to next node
		travelptr = travelptr->GetNext();
	}
//for the last node
	if ((travelptr->GetExponent()) == (exponent)) {
			coefficient = travelptr->GetCoefficient(); 
	}
	return coefficient;
}

//---------------------------------------------------------------------------------------------------------------------------------------------

template<class ItemType>
bool BigInteger<ItemType>::ChangeCoefficient(int exponent, int newCoefficient) {

	//current node pointer points to head
		Node<ItemType> * travelptr = head_ptr_;

	//while not end of list
		while (travelptr->GetNext() != nullptr) {
		//if we find the exponent, set the coefficient to new
			if (travelptr->GetExponent() == exponent) {
				travelptr->SetCoefficient(newCoefficient);
				return true;
			}
		//advance pointer
			travelptr = travelptr->GetNext();
		}

		return true;
}

//---------------------------------------------------------------------------------------------------------------------------------------------

template<class ItemType>
bool BigInteger<ItemType>::EqualsBigInteger (const BigInteger <ItemType>& number) const {

//create a pointer to access the first element
	Node<ItemType> * peek = new Node <ItemType>;
//point to what head points to
	peek = head_ptr_;
	int exponent, coefficient, size2;
//to obtain size of the given bag
	size2 = number.GetCurrentSize();
//only if the given bag is less than or equal to the current bag
	if (size2 <= item_count_) {
	//until the last node is reached
		while (peek->GetNext() != nullptr) {
			
		//for each node, obtain co and ex
			coefficient = peek ->GetCoefficient();
			exponent = peek ->GetExponent();
	
		//check if not in the given bag, return false
			if (!number.Contains(exponent, coefficient)) {
				return false;
			}
		//advance to next node
			peek = peek ->GetNext();
		}

	}
	else {
	//in case they are of different lengths
		return false;
	}
	return true;
}









































