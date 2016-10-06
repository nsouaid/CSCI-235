/** Listing 1-1.
    @file BagInterface.h */
#ifndef TEACH_CSCI235_LINKEDBAG_BAGINTERFACE_H_
#define TEACH_CSCI235_LINKEDBAG_BAGINTERFACE_H_

#include <vector>
using namespace std;

template<class ItemType>
class BagInterface {

	public:
	
		/** Gets the current number of entries in this bag.
		@return The integer number of entries currently in the bag. */
		virtual int GetCurrentSize() const = 0;

		/** Sees whether this bag is empty.
		@return True if the bag is empty, or false if not. */
		virtual bool IsEmpty() const = 0;

		/** Adds a new entry to this bag.
		@post If successful, newEntry is stored in the bag and
		the count of items in the bag has increased by 1.
		@param new_entry  The object to be added as a new entry.
		@return True if addition was successful, or false if not. */
		virtual bool Insert(const ItemType& new_entry1, const ItemType& new_entry2) = 0;
		
		/** Removes all entries from this bag.
		@post Contains no items, and the count of items is 0. */
		virtual void Clear() = 0;

		/** Counts the number of times a given entry appears in bag.
		@param an_entry  The entry to be counted.
		@return The number of times an_entry appears in the bag. */
		virtual int GetFrequencyOf(const ItemType& an_entry) const = 0;
		
		/** Tests whether this bag contains a given entry.
		@param an_entry1 and an_entry2 The entries to locate.
		@return True if bag contains anEntry, or false otherwise. */
		virtual bool Contains(const ItemType& an_entry1, const ItemType& an_entry2) const = 0;

		/** Displays to screen the integer.
		@post Will display the number in its entirety, with 0s for nodes that do not exist in between. */
		virtual void DisplayBigInteger() const = 0;

		/** Obtains the coefficient of a given exponent.
		@param exponent The entry to locate.
		@return The number that is associated with the entry, "exponent" */
		virtual int Coefficient(const int& exponent) const = 0;

		/** Alters the integer, if the number already exists in the list
		@pre expon_ must already exist in the list, user must keep track.
		@param expon_ and newCoefficient_ The entries to locate and change.
		@post will have changed the coefficient data member to given.
		@return True if alteration occured, false otherwise. */
		virtual bool ChangeCoefficient(int expon_, int newCoefficient_) = 0;

};
#endif
