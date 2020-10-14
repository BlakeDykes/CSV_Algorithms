#include "LinkedList.h"
#include <string>
#include <iostream>

using namespace LL;
using namespace BidData;

/**
 * Default constructor
 */
LinkedList::LinkedList() {
	head = nullptr;
	tail = nullptr;
}

/**
 * Destructor
 */
LinkedList::~LinkedList() {
	Node * current = head;
	Node * temp;

	while (current != nullptr)
	{
		temp = current;
		current = current->next;
		delete temp;
	}
}

/**
 * Append a new bid to the end of the list
 *
 * @param bid - The bid to add
 */
void LinkedList::Append(Bid bid) {
	// Assign new bid's address to n
	Node * n = new Node(bid);

	// If no head exists list is empty
	// assign n to head and tail
	// else add it to the end of the list
	if (head == NULL)
	{
		head = n;
		tail = n;
	}
	else
	{
		tail->next = n;
		tail = n;
	}
	++size;
}

/**
 * Prepend a new bid to the start of the list
 *
 * @param bid - The bid to add
 */
void LinkedList::Prepend(Bid bid) {
	// Assign new bid's address to n
	Node* n = new Node(bid);

	// If no head exists list is empty
	// assign n to head and tail
	// else add it to the front of the list
	if (head == NULL)
	{
		head = n;
		tail = n;

	}
	else
	{
		n->next = head;
		head = n;
	}
	++size;
}

/**
 * Print all bids in the list
 */
void LinkedList::PrintList() {
	Node * currentNode = head;

	// Iterate through each node, starting at head
	while (currentNode != nullptr)
	{
		std::cout << currentNode->bid.title << " | " << currentNode->bid.bidId << " | " << currentNode->bid.department << " | " << currentNode->bid.closeDate << " | $" << currentNode->bid.amount << " | "
			<< currentNode->bid.inventoryID << " | " << currentNode->bid.vehicleID << " | " << currentNode->bid.receiptNum << " | " << currentNode->bid.fund << " | " << std::endl;

		currentNode = currentNode->next;
	}
}

/**
 * Remove a specified bid
 *
 * @param bidId - The bid id to remove from the list
 */
void LinkedList::Remove(std::string bidId) {
	Node* current = head;
	Node * temp;

	// If size is one, remove only list item
	if (size = 1)
	{
		head = nullptr;
		tail = nullptr;
	}
	// If the bidId matches the head, delete it
	else if (current->bid.bidId == bidId && current == head)
	{
		temp = current;
		head = current->next;
		delete temp;

	}
	// If the next node is the bid to delete, delete it
	else if (current->next->bid.bidId == bidId)
	{
		temp = current->next;
		current->next = current->next->next;
		delete temp;
		// If the next node is the tail, make the current node the tail
		if (current->next == 0)
		{
			tail = current;
		}

	}
	--size;
}

/**
 * Search for the specified bidId
 *
 * @param bidId - The bid id to search for
 */
Bid LinkedList::Search(std::string bidId) {
	Node* current = head;
	Bid bidRet;
	Bid * emptyBid = new Bid();

	//Iterate through list of bids
	while (current != nullptr)
	{
		if (current->bid.bidId == bidId)
		{
			bidRet = current->bid;
			return bidRet;
		}
		else
		{
			current = current->next;
		}
	}
	return *emptyBid;
}

/**
 * Returns the current size (number of elements) in the list
 */
int LinkedList::Size() {
	return size;
}

