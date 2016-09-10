// Created by Frank M. Carrano and Tim Henry.
// Copyright (c) 2013 __Pearson Education__. All rights reserved.
// Modified by Ioannis Stamos
/**	@file mySet.cpp (same as ArraySet) */

#include "mySet.h"
#include <cstddef>

//default constructor
template<class ItemType>
Set<ItemType>::Set() : item_count_(0), max_items_(kDefaultSetSize_) {
}

/*constructor addition to construct a Set for a single item
template<class ItemType>
Set<ItemType>::Set(const ItemType &an_Item) {
	items_[0]= an_Item;
}
*/

//obtains the current size 
template<class ItemType>
int Set <ItemType>::GetCurrentSize() const {
	return item_count_;
}

//is the Set empty?
template<class ItemType>
bool Set <ItemType>::IsEmpty() const {
	return (item_count_ == 0);
}

//add a certain new_entry
template<class ItemType>
bool Set <ItemType>::Add(const ItemType& new_entry) {
	bool has_room_to_add = item_count_ < max_items_;
	bool duplicate = false;
	bool retval = false;
		
	for (int i = 0; i < item_count_; i++) {
		if (items_[i] == new_entry) {
			duplicate = true;
		}
		else {
			duplicate = false;
		}
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
bool Set <ItemType>::Remove(const ItemType& an_entry) {
	int located_index = GetIndexOf(an_entry);
	bool can_remove_item = !IsEmpty() && (located_index > -1);
	if (can_remove_item) {
		item_count_--;
		items_[located_index] = items_[item_count_];
    	}
  	return can_remove_item;
}

//clear the entire Set
template<class ItemType>
void Set <ItemType>::Clear() {
	item_count_ = 0;
}

//does the Set contain a certain entry?
template<class ItemType>
bool Set <ItemType>::Contains(const ItemType& an_entry) const {
	return GetIndexOf(an_entry) > -1;
}

template<class ItemType>
vector<ItemType> Set <ItemType>::ToVector() const {
	vector<ItemType> set_contents;
	for (int i = 0; i < item_count_; i++) {
		set_contents.push_back(items_[i]);
	}
	return set_contents;
}

template<class ItemType> int Set <ItemType>::GetIndexOf(const ItemType& target) const {
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
