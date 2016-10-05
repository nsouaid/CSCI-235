
/** @file Node.h 
    Listing 4-1 */
#ifndef TEACH_CSCI235_LINKEDBAG_NODE_H_
#define TEACH_CSCI235_LINKEDBAG_NODE_H_

template<class ItemType>

class Node {

	private:

		ItemType exponent_, coefficient_;
		Node<ItemType>* next_; // Pointer to next node

	public:

		// default constructor, set to nullptr.
		Node();

		// @param coefficient_ and exponent_ given items.
		Node(const ItemType& an_item1, const ItemType& an_item2);

		// @param coefficient_ and exponent_ given items.
		// @param next_node pointer to next_node
		Node(const ItemType& an_item1, const ItemType& an_item2, Node<ItemType>* next_node);

		// @param sets coefficient_ to an_item
		void SetCoefficient(const ItemType& an_item);

		// @param sets exponent_ to an_item
		void SetExponent(const ItemType& an_item);

		// @param next_node pointer to next node.
		void SetNext(Node<ItemType>* next_node);

		// @return coefficient_.
		ItemType GetCoefficient() const;

		// @return coefficient_.
		ItemType GetExponent() const;

		// @return pointer to next node.
		Node<ItemType>* GetNext() const;
};

#include "Node.cpp"
#endif
