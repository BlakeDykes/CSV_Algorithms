#include "HashTable.h"
#include "CSVparser.hpp"
#include "Utils.h"

#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <time.h>


using namespace BidData;
using namespace HT;

const unsigned int DEFAULT_SIZE = 35876;

/**
 * Default constructor
 */
HashTable::HashTable() {
	// Initialize the structures used to hold bids
	head = nullptr;
	table->resize(DEFAULT_SIZE);
	for (int i = 0; i < table->size(); ++i)
		table->at(i) = Node();
}

/**
 * Destructor
 */
HashTable::~HashTable() {
	// Logic to free storage when class is destroyed
	for (int i = 0; i < table->size(); ++i)
	{
		delete table->at(i).next;
	}
}

/**
 * Calculate the hash value of a given key.
 * Note that key is specifically defined as
 * unsigned int to prevent undefined results
 * of a negative list index.
 *
 * @param key The key to hash
 * @return The calculated hash
 */
unsigned int HashTable::hash(int key) {
	// Logic to calculate a hash value, using %DEFAULT_SIZE
	int i = key * 37;
	int index = i % DEFAULT_SIZE;
	return index;
}

/**
 * Insert a bid
 *
 * @param bid The bid to insert
 */
void HashTable::Insert(Bid bid) {

	bool added = false;
	int index = hash(stoi(bid.bidId));

	// Logic to insert a bid
	Node * current = new Node(bid, index);


	while (added == false)
	{
		if (table->at(index).bid.bidId == "")
		{
			table->at(index) = *current;
			if (head == nullptr)
			{
				head = &table->at(index);
			}
			else if (head->key > table->at(index).key)
			{
				table->at(index).next = head;
				head = &table->at(index);
			}
			else
			{
				table->at(index).next = &table->at(index + 1);
				table->at(index - 1).next = &table->at(index);
			}
			added = true;
		}
		else
		{
			index = (index + 1) % DEFAULT_SIZE;
		}
	}
}

/**
 * Print all bids
 */
void HashTable::PrintAll() {
	// Logic to print all bids

	for (int i = 0; i < table->size(); ++i)
	{
		if (table->at(i).bid.title != "")
		{
			std::cout << table->at(i).bid.title << " | " << table->at(i).bid.bidId << " | " << table->at(i).bid.department << " | " << table->at(i).bid.closeDate << " | $" << table->at(i).bid.amount << " | " <<
				table->at(i).bid.inventoryID << " | " << table->at(i).bid.vehicleID << " | " << table->at(i).bid.receiptNum << " | " << table->at(i).bid.fund << std::endl;
		}
	}
}

/**
 * Remove a bid
 *
 * @param bidId The bid id to search for
 */
void HashTable::Remove(std::string bidId) {
	// Logic to remove a bid
	int index = hash(stoi(bidId));

	if (table->at(index).bid.bidId == bidId)
	{
		if (head == &table->at(index))
		{
			int i = 1;
			while (&table->at(index + i) == NULL)
				++i;

			head = &table->at(index + i);
			table->at(index) = Node();
			std::cout << "Auction ID: " << bidId << " removed." << std::endl;
		}
		else
		{
			int i = 1, k = 1;
			while (&table->at(index - i) == NULL)
				--i;
			while (&table->at(index + k) == NULL)
				++k;

			table->at(index - i).next = &table->at(index + k);
			table->at(index) = Node();

			std::cout << "Auction ID: " << bidId << " removed." << std::endl;
		}
	}
}

/**
 * Search for the specified bidId
 *
 * @param bidId The bid id to search for
 */
Bid HashTable::Search(std::string bidId) {
	Bid bid;
	bool found = false;
	// Logic to search for and return a bid
	int startingPoint = hash(stoi(bidId));
	int index = startingPoint;
	while (found == false)
	{
		if (table->at(index).bid.bidId == bidId)
		{
			bid = table->at(index).bid;
			found = true;
		}
		else
		{
			index++;

			// Bid not found, return empty bid
			if (hash(stoi(table->at(index).bid.bidId)) != startingPoint)
			{
				return bid;
			}
		}
	}
	return bid;
}