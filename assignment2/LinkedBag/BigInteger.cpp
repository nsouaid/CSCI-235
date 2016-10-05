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
				head_ptr_ = last_node_pointer_;
				item_count_++;
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

			//check to make sure the entry doesn't have the same coefficient
			if (exp1 != exp2) {
				travel_pointer_->SetNext(last_node_pointer_);
				item_count_++;
			}
			else {
				return false;
			}
		}
		return true;
	}
	else return false;
}

//---------------------------------------------------------------------------------------------------------------------------------------------

template<class ItemType>
void BigInteger<ItemType>::Clear() {

	Node<ItemType>* current_node_to_delete = head_ptr_;
	while (head_ptr_ != nullptr) {
		head_ptr_ = head_ptr_->GetNext();
		// Return node to the system
		current_node_to_delete->SetNext(nullptr);
		delete current_node_to_delete;
		current_node_to_delete = head_ptr_;  // Move to the next one.
	}
  item_count_ = 0;
}

//---------------------------------------------------------------------------------------------------------------------------------------------

template<class ItemType>
int BigInteger<ItemType>::GetFrequencyOf(const ItemType& an_entry) const {

	int frequency = 0;
	int counter = 0;
	Node<ItemType>* current_ptr = head_ptr_;
	while (current_ptr != nullptr){
		if (an_entry == current_ptr->GetCoefficient()) {
			frequency++;
		}
		counter++;
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
bool BigInteger<ItemType>::Contains(const ItemType& an_entry) const {
	return (GetPointerTo(an_entry) != nullptr);
}

//---------------------------------------------------------------------------------------------------------------------------------------------

//will return a nullptr unless it finds the entry given - in which case will return the pointer to that Node of that specific cofficient
template<class ItemType>
Node<ItemType>* BigInteger<ItemType>::GetPointerTo(const ItemType& an_entry) const {

	Node<ItemType> *current_ptr = head_ptr_;
	while (current_ptr != nullptr) {
		if (an_entry == current_ptr->GetCoefficient())
			return current_ptr;
		else
		current_ptr = current_ptr->GetNext();
	}

	return nullptr;
}

//---------------------------------------------------------------------------------------------------------------------------------------------

template<class ItemType>
void BigInteger<ItemType>::CopyNodesFrom(const BigInteger<ItemType> &a_bag) {
	
	item_count_ = a_bag.item_count_;
	Node<ItemType>* a_bag_current_pointer = a_bag.head_ptr_;  // Pointer to beginning of a_bag.
	if (a_bag_current_pointer == nullptr) {  // a_bag is empty.
		head_ptr_ = nullptr;
		return;
	}

	// Copy first node
	head_ptr_ = new Node<ItemType>();
	head_ptr_->SetCoefficient(a_bag_current_pointer->GetCoefficient());
	head_ptr_->SetExponent(a_bag_current_pointer->GetExponent());

	// Copy remaining nodes
	Node<ItemType>* last_pointer = head_ptr_;      // Points to last node in new chain
	a_bag_current_pointer = a_bag_current_pointer->GetNext();     // Advance original-chain pointer

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
	//doesnt this already have a nullpointer set from the constructor?
	last_pointer->SetNext(nullptr); 
}

//---------------------------------------------------------------------------------------------------------------------------------------------

template<class ItemType>
void BigInteger<ItemType>::DisplayBigInteger () const {

	Node<ItemType> * travel_pointer_ = new Node<ItemType>;
	travel_pointer_ = head_ptr_;

	int exp1, exp2, zerofill;

	while (travel_pointer_->GetNext() != nullptr) {

		//display the coefficient in current node
		cout <<travel_pointer_->GetCoefficient();
		//obtain its exponent
		exp1 = travel_pointer_->GetExponent();
		//move to next node
		travel_pointer_ = travel_pointer_->GetNext();
		//obtain its exponent
		exp2 = travel_pointer_->GetExponent();
		zerofill = exp1 - exp2;

		if (zerofill !=1) {			
			for (int i =1; i < zerofill; i++) {
				cout << "0";
			}
		}
	}
	cout << travel_pointer_->GetCoefficient();
	zerofill = travel_pointer_->GetExponent();
	for (int i =0; i < zerofill; i++) {
		cout << "0";
	}
}

//---------------------------------------------------------------------------------------------------------------------------------------------

//will return the coefficient of the given exponent
template<class ItemType>
int BigInteger<ItemType>::Coefficient (const int& exponent) const {

	//will return 0 if the exponent doesn't exist or if it's an exponent that wasn't inserted
	int coefficient = 0;

	Node<ItemType> * travelptr = head_ptr_;
	while (travelptr != (nullptr)) {
		if ((travelptr->GetExponent()) == (exponent)) {
			coefficient = travelptr->GetCoefficient(); 
		}
	}
	return coefficient;
}

//---------------------------------------------------------------------------------------------------------------------------------------------

template<class ItemType>
bool BigInteger<ItemType>::ChangeCoefficient(int expon_, int newCoefficient_) {

	Node<ItemType> * travelptr = head_ptr_;
	while ((travelptr->GetNext()) != (nullptr)) {
		if ((travelptr->GetExponent()) == (expon_)) {
			if ((travelptr->GetCoefficient()) == (newCoefficient_)) {
				return true;
			}
			else {
				travelptr->SetCoefficient(newCoefficient_);
				return true;
			}
		}
	}
	return false;
}

//---------------------------------------------------------------------------------------------------------------------------------------------

















































