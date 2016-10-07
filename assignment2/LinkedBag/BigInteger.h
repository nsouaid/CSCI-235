//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.
//  Modified by Ioannis Stamos.

/** ADT bag: Link-based implementation.
    @file BigInteger.h 
    Listing 4-3 */
#ifndef TEACH_CSCI235_BIGINTEGER_BIGINTEGER_H_
#define TEACH_CSCI235_BIGINTEGER_BIGINTEGER_H_

#include "BagInterface.h"
#include "Node.h"

template<class ItemType>
class BigInteger : public BagInterface<ItemType> {

	private:
		
		//this points to the FIRST Node
		Node<ItemType>* head_ptr_;

		//tally of current items in the bag
		int item_count_;

		// @return either a pointer to the node containing a given entry
		// or the null pointer if the entry is not in the bag.
		Node<ItemType>* GetPointerTo(const ItemType& an_entry1, const ItemType& an_entry2) const;

		// @param a_bag a given bag.
		// Allocates space and copies all the nodes from a_bag.
		// The function does not check whether this bag contains
		// any items, but it assumes that it is empty.
		void CopyNodesFrom(const BigInteger<ItemType> &a_bag);

	public:

		//will not take arguments
		BigInteger();
		
		//this copy constructor will take a BigInteger object and make another BigInteger object with the same contents
		BigInteger(const BigInteger<ItemType>& a_bag);

		//overloaded operater "="
		BigInteger<ItemType>& operator=(const BigInteger<ItemType>& right_hand_side);

		//virtual destructor so that other classes are responsible for their own objects
		virtual ~BigInteger();

		//checks for empty bag
		bool IsEmpty() const;

		//obtains item count
		int GetCurrentSize() const;

		//insert new node/number	
		bool Insert(const ItemType& new_entry1, const ItemType& new_entry2);

		//emtpies bag
		void Clear();

		//determines frequency of given number (coefficient)
		int GetFrequencyOf(const ItemType& an_entry) const;

		//checks to see if a number (exponent and its coefficient) exist in the list
		bool Contains(const ItemType& an_entry1, const ItemType& an_entry2) const;

		//displays the number
		void DisplayBigInteger () const;

		//obtains the coefficient of a given exponent
		int Coefficient (const int& exponent) const;

		//changes the coefficient of a given exponent
		bool ChangeCoefficient(int exponent, int oldCoefficient, int newCoefficient);

		//checks to see if two numbers are equal
		bool EqualsBigInteger (const BigInteger <ItemType>& number) const;
};

#include "BigInteger.cpp"
#endif
