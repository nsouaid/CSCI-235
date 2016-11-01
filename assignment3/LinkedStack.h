/** ADT stack: Link-based implementation.
    Listing 7-3.
    @file LinkedStack.h */
 
#ifndef _LINKEDSTACK_H
#define _LINKEDSTACK_H

#include "StackInterface.h"
#include "Node.h"
#include "PreconditionViolatedException.h"

template<class ItemType>
class LinkedStack : public StackInterface<ItemType> {

	private:
	Node<ItemType>* top_ptr_; // Pointer to first node in the chain;
                           // this node contains the stack's top

	public:
	// Constructors and destructor:
	LinkedStack();                                   // Default constructor
	LinkedStack(const LinkedStack<ItemType>& a_stack);// Copy constructor
	virtual ~LinkedStack();                          // Destructor

	// Stack operations:
	bool IsEmpty() const;
	bool Push(const ItemType& new_item);
	bool Pop();
	ItemType Peek() const throw(PreconditionViolatedException);
};

#include "LinkedStack.cpp"
#endif
