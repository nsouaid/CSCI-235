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
		@post  If successful, newEntry is stored in the bag and
		the count of items in the bag has increased by 1.
		@param new_entry  The object to be added as a new entry.
		@return  True if addition was successful, or false if not. */
		virtual bool Insert(const ItemType& new_entry1, const ItemType& new_entry2) = 0;
		
		/** Removes all entries from this bag.
		@post  Bag contains no items, and the count of items is 0. */
		virtual void Clear() = 0;

		/** Counts the number of times a given entry appears in bag.
		@param an_entry  The entry to be counted.
		@return  The number of times anEntry appears in the bag. */
		virtual int GetFrequencyOf(const ItemType& an_entry) const = 0;
		
		/** Tests whether this bag contains a given entry.
		@param an_entry  The entry to locate.
		@return  True if bag contains anEntry, or false otherwise. */
		virtual bool Contains(const ItemType& an_entry) const = 0;

		virtual void DisplayBigInteger() const = 0;

		virtual int Coefficient(const int& exponent) const = 0;

		virtual bool ChangeCoefficient(int expon_, int newCoefficient_) = 0;

};
#endif
