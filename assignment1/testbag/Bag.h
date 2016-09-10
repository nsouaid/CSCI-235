//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.
//  Modified by Ioannis Stamos.

/** ADT bag: Array-based implementation.
 @file Bag.h */


#ifndef TEACH_CSCI235_BAGADT_BAG_H_
#define TEACH_CSCI235_BAGADT_BAG_H_

#include "BagInterface.h"

template<class ItemType>
class Bag : public BagInterface<ItemType>
{
 public:
  Bag();
  int GetCurrentSize() const;
  bool IsEmpty() const;
  bool Add(const ItemType& new_entry);
  bool Remove(const ItemType& an_entry);
  void Clear();
  bool Contains(const ItemType& an_ntry) const;
  int GetFrequencyOf(const ItemType& an_entry) const;
  vector<ItemType> ToVector() const; 
  
 private:
  static const int kDefaultBagSize_ = 6;  
  ItemType items_[kDefaultBagSize_]; // array of bag items
  int item_count_;                    // current count of bag items 
  int max_items_;                 // max capacity of the bag
  
  // Returns either the index of the element in the array items that
  // contains the given target or -1, if the array does not contain 
  // the target.
  int GetIndexOf(const ItemType& target) const;   
};  // end Bag

#include "Bag.cpp"

#endif  // TEACH_CSCI235_BAGADT_BAG_H_
