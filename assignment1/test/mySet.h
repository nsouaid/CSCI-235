/** ADT aet: Array-based implementation.
 @file mySet.h */

#ifndef TEACH_CSCI235_SETADT_SET_H_
#define TEACH_CSCI235_SETADT_SET_H_

#include "SetInterface.h"

template<class ItemType>
class Set : public SetInterface<ItemType> {
	private:
		static const int kDefaultSetSize_ = 6;
		ItemType items_[kDefaultSetSize_]; // array of set items
		int item_count_; // current count of set items 
		int max_items_; // max capacity of the set
  		//return the index of the target or return -1. don't change anything (const)
		int GetIndexOf(const ItemType& target) const;   

	public:
		Set();
		int GetCurrentSize() const;
		bool IsEmpty() const;
		bool Add(const ItemType& new_entry);
		bool Remove(const ItemType& an_entry);
		void Clear();
		bool Contains(const ItemType& an_ntry) const;
		vector<ItemType> ToVector() const;
};

#include "mySet.cpp"

#endif  // TEACH_CSCI235_SETADT_SET_H_
