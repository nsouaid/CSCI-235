//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.
//  Modified by Ioannis Stamos.

/** Listing 1-1.
    @file BagInterface.h */
#ifndef TEACH_CSCI235_BAGADT_BAGINTERFACE_H_
#define TEACH_CSCI235_BAGADT_BAGINTERFACE_H_

#include <vector>
using namespace std;

template<class ItemType>
class BagInterface
{
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
   virtual bool Add(const ItemType& new_entry) = 0;
   
   /** Removes one occurrence of a given entry from this bag,
       if possible.
    @post  If successful, anEntry has been removed from the bag
       and the count of items in the bag has decreased by 1.
    @param an_entry  The entry to be removed.
    @return  True if removal was successful, or false if not. */
   virtual bool Remove(const ItemType& an_entry) = 0;
   
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
   
   /** Empties and then fills a given vector with all entries that
       are in this bag.
    @return  A vector containing all the entries in the bag. */
   virtual vector<ItemType> ToVector() const = 0;
}; // end BagInterface
#endif  // TEACH_CSCI235_BAGADT_BAGINTERFACE_H_
