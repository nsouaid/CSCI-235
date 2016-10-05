/** @file Node.cpp 
    Listing 4-2 */

#include "Node.h"
#include <cstddef>

//default constructor - if we declare an object with no arguments, we will get an object pointing to nullptr
template<class ItemType>
Node<ItemType>::Node() 
: next_(nullptr) {
}

//two parameter constructor, setting next_ to nullptr
template<class ItemType>
Node<ItemType>::Node(const ItemType& an_item1, const ItemType& an_item2) 
: exponent_(an_item1), coefficient_(an_item2), next_(nullptr) {
}

//three parameter constructor, setting next_ to what another pointer is pointing to
template<class ItemType>
Node<ItemType>::Node(const ItemType& an_item1, const ItemType& an_item2, Node<ItemType>* next_node) 
: exponent_(an_item1), coefficient_(an_item2), next_(next_node) {
}

//change the coefficient
template<class ItemType>
void Node<ItemType>::SetCoefficient(const ItemType& an_item) {
coefficient_ = an_item;
}

//change the exponent
template<class ItemType>
void Node<ItemType>::SetExponent(const ItemType& an_item) {
exponent_ = an_item;
}

//change the pointer
template<class ItemType>
void Node<ItemType>::SetNext(Node<ItemType>* next_node) {
next_ = next_node;
}

//gives us the coefficient 
template<class ItemType>
ItemType Node<ItemType>::GetCoefficient() const {
   return coefficient_;
}

//gives us the exponent 
template<class ItemType>
ItemType Node<ItemType>::GetExponent() const {
   return exponent_;
}

//returns what the next_ is pointing to
template<class ItemType>
Node<ItemType>* Node<ItemType>::GetNext() const {
   return next_;
}
