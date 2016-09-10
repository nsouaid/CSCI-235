// Created by Frank M. Carrano and Tim Henry.
// Copyright (c) 2013 __Pearson Education__. All rights reserved.
// Modified by Ioannis Stamos
/** @file Bag.cpp (same as ArrayBag) */

#include "Bag.h"
#include <cstddef>

template<class ItemType>
Bag<ItemType>::Bag() : item_count_(0), max_items_(kDefaultBagSize_)
{
}  // end default constructor

template<class ItemType>
int Bag<ItemType>::GetCurrentSize() const
{
  return item_count_;
}  // end getCurrentSize

template<class ItemType>
bool Bag<ItemType>::IsEmpty() const
{
  return item_count_ == 0;
}  // end isEmpty

template<class ItemType>
bool Bag<ItemType>::Add(const ItemType& new_entry)
{
  bool has_room_to_add = item_count_ < max_items_;
  if (has_room_to_add)
    {
      items_[item_count_] = new_entry;
      item_count_++;
    }  // end if
  return has_room_to_add;
}  // end add

template<class ItemType>
bool Bag<ItemType>::Remove(const ItemType& an_entry)
{
  int located_index = GetIndexOf(an_entry);
  bool can_remove_item = !IsEmpty() && (located_index > -1);
  if (can_remove_item)
    {
      item_count_--;
      items_[located_index] = items_[item_count_];
    }  // end if
  return can_remove_item;
}  // end remove

template<class ItemType>
void Bag<ItemType>::Clear()
{
  item_count_ = 0;
}  // end clear

template<class ItemType>
int Bag<ItemType>::GetFrequencyOf(const ItemType& an_entry) const
{
  int frequency = 0;
  int search_index = 0;
  while (search_index < item_count_)
    {
      if (items_[search_index] == an_entry)
	{
	  frequency++;
	}  // end if
      
      search_index++;
    }  // end while
  
   return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool Bag<ItemType>::Contains(const ItemType& an_entry) const
{
  return GetIndexOf(an_entry) > -1;
}  // end contains

template<class ItemType>
vector<ItemType> Bag<ItemType>::ToVector() const
{
  vector<ItemType> bag_contents;
  for (int i = 0; i < item_count_; i++)
    bag_contents.push_back(items_[i]);
  return bag_contents;
}  // end toVector

template<class ItemType>
int Bag<ItemType>::GetIndexOf(const ItemType& target) const
{
  bool found = false;
  int result = -1;
  int search_index = 0;
  // if the bag is empty, item_count is zero, so loop is skipped
  while (!found && (search_index < item_count_))
    {
      if (items_[search_index] == target)
	{
	  found = true;
	  result = search_index;
	} 
      else
	{
	  search_index++;
	}  // end if
    }  // end while
  return result;
}  // end getIndexOf
