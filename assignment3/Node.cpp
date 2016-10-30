/** @file Node.cpp 
    Listing 4-2 */

#include "Node.h"
#include <cstddef>

//constructors---------------------------------------------
template<class ItemType>
Node<ItemType>::Node() : next_node_(nullptr) {
}

template<class ItemType>
Node<ItemType>::Node(const ItemType& an_item) : item_(an_item), next_node_(nullptr) {
}

template<class ItemType>
Node<ItemType>::Node(const ItemType& an_item, Node<ItemType>* next_node) :
    item_(an_item), next_node_(next_node) {
}

//setters---------------------------------------------
template<class ItemType>
void Node<ItemType>::SetItem(const ItemType& an_item) {
	item_ = an_item;
}

template<class ItemType>
void Node<ItemType>::SetNext(Node<ItemType>* next_node) {
	next_node_ = next_node;
}

//getters---------------------------------------------
template<class ItemType>
ItemType Node<ItemType>::GetItem() const {
	return item_;
}

template<class ItemType>
Node<ItemType>* Node<ItemType>::GetNext() const {
	return next_node_;
}
