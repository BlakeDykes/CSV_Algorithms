
#include "Utils.h"
#include "LinkedList.h"
#include "CSVparser.hpp"

#include <string>
#include <algorithm>
#include <iostream>


/**
 * Converts a string to a double after stripping out unwanted char
 *
 * @param str - The string to convert
 * @param ch - The character to strip out
 */
double strToDouble(std::string str, char ch) {
	str.erase(remove(str.begin(), str.end(), ch), str.end());
	return atof(str.c_str());
}


/**
 * Load a CSV file containing bids into a linked list
 *
 * @param csvPath - The path to the CSV file which is to be loaded
 * @param list - The linked list to add the bids to
 */
std::vector<std::string> loadBids(std::string csvPath, LL::LinkedList *list) {
	std::cout << "Loading CSV file " << csvPath << std::endl;

	// initialize the CSV Parser
	csv::Parser file = csv::Parser(csvPath);

	// read and display header row - optional
	std::vector<std::string> header = file.getHeader();

	try {
		// loop to read rows of a CSV file
		for (int i = 0; i < file.rowCount(); i++) {

			// Create a bid structure and add to the collection of bids
			Bid bid;
			bid.title = file[i][0];
			bid.bidId = file[i][1];
			bid.department = file[i][2];
			bid.closeDate = file[i][3];
			bid.amount = strToDouble(file[i][4], '$');
			bid.inventoryID = file[i][5];
			bid.vehicleID = file[i][6];
			bid.receiptNum = file[i][7];
			bid.fund = file[i][8];

			// add this bid to the end
			list->Append(bid);
		}
	}
	catch (csv::Error &e) {
		std::cerr << e.what() << std::endl;
	}

	return header;
}

/**
 * Load a CSV file containing bids into a binary search tree
 *
 * @param csvPath - The path to the CSV file which is to be loaded
 * @param bst - The binary search tree to add the bids to
 */
std::vector<std::string> loadBids(std::string csvPath, BST::BinarySearchTree* bst) {
	std::cout << "Loading CSV file: " << csvPath << std::endl;
	std::cout << "This might take a while..." << std::endl;

	// initialize the CSV Parser using the given path
	csv::Parser file = csv::Parser(csvPath);

	// read and display header row - optional
	std::vector<std::string> header = file.getHeader();

	try {
		// loop to read rows of a CSV file
		for (unsigned int i = 0; i < file.rowCount(); i++) {

			// Create a bid and add to the collection of bids
			Bid bid;
			bid.title = file[i][0];
			bid.bidId = file[i][1];
			bid.department = file[i][2];
			bid.closeDate = file[i][3];
			bid.amount = strToDouble(file[i][4], '$');
			bid.inventoryID = file[i][5];
			bid.vehicleID = file[i][6];
			bid.receiptNum = file[i][7];
			bid.fund = file[i][8];

			// push this bid to the end
			bst->Insert(bid);
		}
	}
	catch (csv::Error &e) {
		std::cerr << e.what() << std::endl;
	}
	return header;
}

/**
 * Load a CSV file containing bids into a container
 *
 * @param csvPath the path to the CSV file to load
 * @param hashTable the hash table to store the bids in
 * @return a container holding all the bids read
 */
std::vector<std::string> loadBids(std::string csvPath, HT::HashTable* hashTable) {
	std::cout << "Loading CSV file " << csvPath << std::endl;

	// initialize the CSV Parser using the given path
	csv::Parser file = csv::Parser(csvPath);

	// read and display header row - optional
	std::vector<std::string> header = file.getHeader();


	try {
		// loop to read rows of a CSV file
		for (int i = 0; i < file.rowCount(); i++) {

			// Create a data structure and add to the collection of bids
			Bid bid;
			bid.title = file[i][0];
			bid.bidId = file[i][1];
			bid.department = file[i][2];
			bid.closeDate = file[i][3];
			bid.amount = strToDouble(file[i][4], '$');
			bid.inventoryID = file[i][5];
			bid.vehicleID = file[i][6];
			bid.receiptNum = file[i][7];
			bid.fund = file[i][8];

			// insert this bid into the hashTable
			hashTable->Insert(bid);
		}
	}
	catch (csv::Error &e) {
		std::cerr << e.what() << std::endl;
	}
	return header;
}

void CompareTime(clock_t * best, clock_t * worst, clock_t newT)
{
	if (*best == 0)
		*best = newT;
	else
		*best = (newT < *best) ? newT : *best;
	
	if (*worst == 0)
		*worst = newT;
	else
		*worst = (newT > *worst) ? newT : *worst;
}