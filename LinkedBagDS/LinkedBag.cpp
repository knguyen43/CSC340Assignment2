//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT bag: Link-based implementation.
	 @file LinkedBag.cpp */

#include "LinkedBag.h"
#include "Node.h"
#include <cstddef>



// Assignment 2 functions -------------------------------------------
template<class ItemType>
bool LinkedBag<ItemType>::appendK(const ItemType& newEntry, const int& k) {
    // Create a new node to store the entry
    Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
    
    // Case 1: Empty bag or k <= 1 (add to beginning)
    if (isEmpty() || k <= 1) {
        newNodePtr->setNext(headPtr);  // New node points to chain
        headPtr = newNodePtr;          // New node is now first node
        itemCount++;
        return true;
    }
    
    // Case 2: k is within range or Case 3: k > itemCount (add at the end)
    Node<ItemType>* curPtr = headPtr;
    int position = 1;  // Start at position 1 (head)
    
    // Find the (k-1)th node or the last node if k > itemCount
    while (position < k-1 && curPtr->getNext() != nullptr) {
        curPtr = curPtr->getNext();
        position++;
    }
    
    // Insert the new node
    newNodePtr->setNext(curPtr->getNext());
    curPtr->setNext(newNodePtr);
    itemCount++;
    
    return true;
}

template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::findKthItem(const int& k) const {
    // Invalid input: empty bag or k <= 0 or k > itemCount
    if (isEmpty() || k <= 0 || k > itemCount) {
        return nullptr;
    }
    
    // Find the kth item (1-indexed)
    Node<ItemType>* curPtr = headPtr;
    int position = 1;  // Start at position 1 (head)
    
    // Move to the kth position
    while (position < k) {
        curPtr = curPtr->getNext();
        position++;
    }
    
    return curPtr;
}


// ------------------------------------------------------------------

template<class ItemType>
LinkedBag<ItemType>::LinkedBag() : headPtr(nullptr), itemCount(0){}  // end default constructor

template<class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& aBag){
	itemCount = aBag.itemCount;
	Node<ItemType>* origChainPtr = aBag.headPtr;  // Points to nodes in original chain
	
	if (origChainPtr == nullptr)
		headPtr = nullptr;  // Original bag is empty
	else{
		// Copy first node
		headPtr = new Node<ItemType>();
		headPtr->setItem(origChainPtr->getItem());
		
		// Copy remaining nodes
		Node<ItemType>* newChainPtr = headPtr;		// Points to last node in new chain
		origChainPtr = origChainPtr->getNext();	  // Advance original-chain pointer
		
		while (origChainPtr != nullptr){
			// Get next item from original chain
			ItemType nextItem = origChainPtr->getItem();
				  
			// Create a new node containing the next item
			Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
			
			// Link new node to end of new chain
			newChainPtr->setNext(newNodePtr);
			
			// Advance pointer to new last node
			newChainPtr = newChainPtr->getNext();

			// Advance original-chain pointer
			origChainPtr = origChainPtr->getNext();
		}  // end while
		
		newChainPtr->setNext(nullptr);				  // Flag end of chain
	}  // end if
}  // end copy constructor

template<class ItemType>
LinkedBag<ItemType>::~LinkedBag(){
	clear();
}  // end destructor


template<class ItemType>
bool LinkedBag<ItemType>::isEmpty() const{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const{
	return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool LinkedBag<ItemType>::add(const ItemType& newEntry){
	// Add to beginning of chain: new node references rest of chain;
	// (headPtr is null if chain is empty)		  
	Node<ItemType>* nextNodePtr = new Node<ItemType>();
	nextNodePtr->setItem(newEntry);
	nextNodePtr->setNext(headPtr);  // New node points to chain
	headPtr = nextNodePtr;			// New node is now first node
	itemCount++;
	
	return true;
}  // end add

template<class ItemType>
std::vector<ItemType> LinkedBag<ItemType>::toVector() const{
	std::vector<ItemType> bagContents;
	Node<ItemType>* curPtr = headPtr;
	int counter = 0;
	while ((curPtr != nullptr) && (counter < itemCount)){
		bagContents.push_back(curPtr->getItem());
		curPtr = curPtr->getNext();
		counter++;
	}  // end while
	
	return bagContents;
}  // end toVector

template<class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& anEntry){
	Node<ItemType>* entryNodePtr = getPointerTo(anEntry);
	bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);
	if (canRemoveItem){
		// Copy data from first node to located node
		entryNodePtr->setItem(headPtr->getItem());
		
		// Delete first node
		Node<ItemType>* nodeToDeletePtr = headPtr;
		headPtr = headPtr->getNext();
		
		// Return node to the system
		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
		nodeToDeletePtr = nullptr;
		
		itemCount--;
	} // end if
	
	return canRemoveItem;
}  // end remove

template<class ItemType>
void LinkedBag<ItemType>::clear(){
	Node<ItemType>* nodeToDeletePtr = headPtr;
	while (headPtr != nullptr){
		headPtr = headPtr->getNext();

		// Return node to the system
		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
		
		nodeToDeletePtr = headPtr;
	}  // end while
	// headPtr is nullptr; nodeToDeletePtr is nullptr
	
	itemCount = 0;
}  // end clear

template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const{
	int frequency = 0;
	int counter = 0;
	Node<ItemType>* curPtr = headPtr;
	while ((curPtr != nullptr) && (counter < itemCount)){
		if (anEntry == curPtr->getItem()){
			frequency++;
		} // end if
		
		counter++;
		curPtr = curPtr->getNext();
	} // end while
	
	return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const{
	return (getPointerTo(anEntry) != nullptr);
}  // end contains



// private
// Returns either a pointer to the node containing a given entry 
// or the null pointer if the entry is not in the bag.
template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::getPointerTo(const ItemType& anEntry) const{
	bool found = false;
	Node<ItemType>* curPtr = headPtr;
	
	while (!found && (curPtr != nullptr)){
		if (anEntry == curPtr->getItem())
			found = true;
		else
			curPtr = curPtr->getNext();
	} // end while
	
	return curPtr;
} // end getPointerTo

// This section has already been implemented above
// This function is already implemented above

