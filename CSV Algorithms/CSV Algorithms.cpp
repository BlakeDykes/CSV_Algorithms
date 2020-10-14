//=====================================================================================================================================================================================================================
// Name        : CSV Algorithms.cpp
// Author      : Blake Dykes
// Version     : 1.0
// Description : An application that allows a user to load and manipulate a CSV file within a binary search tree, hash table, or linked list. Keeps time statistics for each manipulation with each algorithm
//=====================================================================================================================================================================================================================


#include "Bid.h"
#include "CSVparser.hpp"
#include "LinkedList.h"
#include "Utils.h"
#include "HashTable.h"

#include <time.h>

using namespace BidData;

#include <iostream>

LL::LinkedList bidList;
BST::BinarySearchTree * bst = nullptr;
HT::HashTable * bidTable = nullptr;

std::vector<std::string> header;

clock_t
	//Linked List time keepers
	llLoadBest,
	llLoadWorst,
	llAddBest,
	llAddWorst,
	llSearchBest,
	llSearchWorst,
	llDeleteWorst,
	llDeleteBest,
	
	//Binary Search Tree time keeprs
	bstLoadBest,
	bstLoadWorst,
	bstAddBest,
	bstAddWorst,
	bstSearchBest,
	bstSearchWorst,
	bstDeleteWorst,
	bstDeleteBest,

	//Hash Table time keepers
	htLoadBest,
	htLoadWorst,
	htAddBest,
	htAddWorst,
	htSearchBest,
	htSearchWorst,
	htDeleteWorst,
	htDeleteBest;

/*
* Main
*/
int main()
{
	//CSV file to load
	std::string csvPath = "eBid_Monthly_Sales.csv", bidKey;

	clock_t ticks;

	Bid bid;
	Bid * bidPtr = new Bid();

	int bstKey = 0;
	int choice = 0;

	while (choice != 5)
	{
		std::cout << std::endl;
		std::cout << "***** CSV Algorithms Main Menu *****" << std::endl;
		std::cout << "  1. Linked List Menu" << std::endl;
		std::cout << "  2. Binary Search Tree Menu" << std::endl;
		std::cout << "  3. Hash Table Menu" << std::endl;
		std::cout << "  4. Print Time Statistics" << std::endl;
		std::cout << "  5. Exit " << std::endl << std::endl;
		std::cout << "  Enter Choice: ";
		std::cin >> choice;
		
		switch (choice) {

		/********************************** Linked List Menu *********************************/
		case 1: 
			//App menu
			while (choice != 9) {
				std::cout << std::endl;
				std::cout << "***** Linked List Menu: *****" << std::endl;
				std::cout << "  1. Create Linked List" << std::endl;
				std::cout << "  2. Add a Bid" << std::endl;
				std::cout << "  3. Display All Bids" << std::endl;
				std::cout << "  4. Find Bid" << std::endl;
				std::cout << "  5. Remove Bid" << std::endl;
				std::cout << "  9. Back to Main Menu" << std::endl;
				std::cout << "Enter choice: ";
				std::cin >> choice;

				switch (choice) {

				//Linked List - Load bids into a linked list
				case 1:

					ticks = clock();

					header = loadBids(csvPath, &bidList);

					ticks = clock() - ticks;

					CompareTime(&llLoadBest, &llLoadWorst, ticks);
					std::cout << "Time: " << ticks << " clock ticks" << std::endl << std::endl;

					break;

				//Linked List - Add a bid
				case 2:

					bid = Bid::CreateBid();

					ticks = clock();
					bidList.Append(bid);
					ticks = clock() - ticks;

					Bid::displayBid(bid);

					std::cout << std::endl;
					std::cout << "Time: " << ticks << " clock ticks" << std::endl << std::endl;
					CompareTime(&llAddBest, &llAddWorst, ticks);
					break;

				//Linked List - Print all
				case 3:

					for (auto const& c : header) {
						std::cout << c << " | ";
					}

					bidList.PrintList();
					std::cout << std::endl;

					break;

				//Linked List - Search
				case 4:

					std::cout << "Enter Auction ID: ";
					std::cin >> bidKey;

					ticks = clock();

					bid = bidList.Search(bidKey);

					ticks = clock() - ticks; // current clock ticks minus starting clock ticks

					if (!bid.bidId.empty()) {

						for (auto const& c : header) {
							std::cout << c << " | ";
						}
						std::cout << std::endl;
						Bid::displayBid(bid);

					}
					else {
						std::cout << "Bid Id: " << bidKey << " not found." << std::endl;
					}

					std::cout << "Time: " << ticks << " clock ticks" << std::endl << std::endl;
					CompareTime(&llSearchBest, &llSearchWorst, ticks);

					break;

				//Linked List - Delete a bid
				case 5:

					std::cout << "Enter Auction ID: ";
					std::cin >> bidKey;

					ticks = clock();

					bidList.Remove(bidKey);

					ticks = clock() - ticks; // current clock ticks minus starting clock ticks

					bid = bidList.Search(bidKey);

					if (bid.bidId.empty())
						std::cout << "Bid Removed Successfully" << std::endl;
					else
						std::cout << "ERROR: Bid Not Removed" << std::endl;

					std::cout << "Time: " << ticks << " clock ticks" << std::endl << std::endl;
					CompareTime(&llDeleteBest, &llDeleteWorst, ticks);

					break;
				}
			}
			break;

		/********************************** Binary Search Tree Menu *********************************/
		case 2:
			while (choice != 9) {
				std::cout << std::endl;
				std::cout << "***** Binary Search Tree Menu: *****" << std::endl;
				std::cout << "  1. Create Binary Search Tree" << std::endl;
				std::cout << "  2. Add a Bid" << std::endl;
				std::cout << "  3. Display All Bids" << std::endl;
				std::cout << "  4. Find Bid" << std::endl;
				std::cout << "  5. Remove Bid" << std::endl;
				std::cout << "  9. Exit" << std::endl;
				std::cout << "Enter choice: ";
				std::cin >> choice;

				switch (choice) {

				// Binary Search Tree - Load bids into a binary search tree
				case 1:
					bst = new BST::BinarySearchTree();

					// Initialize a timer variable before loading bids
					ticks = clock();

					// Complete the method call to load the bids
					header = loadBids(csvPath, bst);
					std::cout << "Successful!" << std::endl;

					// Calculate elapsed time and display result
					ticks = clock() - ticks; 
					std::cout << "Successful!" << std::endl;
					std::cout << "Time: " << ticks << " clock ticks" << std::endl;
					CompareTime(&bstLoadBest, &bstLoadWorst, ticks);
					break;

				// Binary Search Tree - Add a bid
				case 2:

					bid = Bid::CreateBid();

					ticks = clock();
					bst->Insert(bid);


					ticks = clock() - ticks; 

					// Display Bid and Time taken to insert
					Bid::displayBid(bid);
					std::cout << "Time: " << ticks << " clock ticks" << std::endl;
					CompareTime(&bstAddBest, &bstAddWorst, ticks);
					std::cout << std::endl;

					break;

				// Binary Search Tree - Display all bids
				case 3:

					for (auto const& c : header) {
						std::cout << c << " | ";
					}
					std::cout << std::endl;
					bst->InOrder(bst->root);
					break;

				// Binary Search Tree - Search
				case 4:

					std::cout << "Enter Auction ID: ";
					std::cin >> bidKey;

					bstKey = stoi(bidKey);

					ticks = clock();

					bidPtr = bst->Search(bstKey);

					ticks = clock() - ticks; // current clock ticks minus starting clock ticks

					if (!bidPtr->bidId.empty()) {

						for (auto const& c : header) {
							std::cout << c << " | ";
						}

						std::cout << std::endl;
						Bid::displayBid(*bidPtr);
					}
					else {
						std::cout << "Bid Id: " << bidKey << " not found." << std::endl;
					}

					//Print time elapsed
					std::cout << "Time: " << ticks << " clock ticks" << std::endl;
					CompareTime(&bstSearchBest, &bstSearchWorst, ticks);

					break;

				// Binary Search Tree - Delete a Bid
				case 5:

					std::cout << "Enter Auction ID: ";
					std::cin >> bidKey;

					bstKey = stoi(bidKey);

					ticks = clock();

					BST::Node * removed = bst->Remove(bst->root, bstKey);

					ticks = clock() - ticks; // current clock ticks minus starting clock ticks

					if (bst->Search(bstKey)->bidId == "")
						std::cout << "Bid Removed Successfully";
					else
						std::cout << "ERROR: Bid Not Removed";

					//print time elapsed
					std::cout << "Time: " << ticks << " clock ticks" << std::endl;
					CompareTime(&bstDeleteBest, &bstDeleteWorst, ticks);
					break;
				}
			}
			break;

		/********************************** Hash Table Menu *********************************/
		case 3:
			while (choice != 9) {
				std::cout << std::endl;
				std::cout << "***** Hash Table Menu: *****" << std::endl;
				std::cout << "  1. Create Hash Table" << std::endl;
				std::cout << "  2. Add a Bid" << std::endl;
				std::cout << "  3. Display All Bids" << std::endl;
				std::cout << "  4. Find Bid" << std::endl;
				std::cout << "  5. Remove Bid" << std::endl;
				std::cout << "  9. Exit" << std::endl;
				std::cout << "Enter choice: ";
				std::cin >> choice;

				switch (choice) {

				// Hash Table - Create Hash Table
				case 1:
					bidTable = new HT::HashTable();

					// Initialize a timer variable before loading bids
					ticks = clock();

					// Complete the method call to load the bids
					header = loadBids(csvPath, bidTable);
					std::cout << "Successful!" << std::endl;

					// Calculate elapsed time and display result
					ticks = clock() - ticks; // current clock ticks minus starting clock ticks
					std::cout << "Time: " << ticks << " clock ticks" << std::endl;
					CompareTime(&htLoadBest, &htLoadWorst, ticks);


					break;

				// Hash Table - Add a bid
				case 2:

					bid = Bid::CreateBid();

					ticks = clock();
					bidTable->Insert(bid);


					ticks = clock() - ticks;

					// Display Bid and Time taken to insert
					Bid::displayBid(bid);
					std::cout << "Time: " << ticks << " clock ticks" << std::endl;
					CompareTime(&htAddBest, &htAddWorst, ticks);
					std::cout << std::endl;

					break;

				// Hash Table - Print all
				case 3:

					for (auto const& c : header) {
						std::cout << c << " | ";
					}

					std::cout << std::endl;
					bidTable->HashTable::PrintAll();
					break;

				// Hash Table - Search
				case 4:

					std::cout << "Enter Auction ID: ";
					std::cin >> bidKey;

					ticks = clock();

					bid = bidTable->HashTable::Search(bidKey);

					ticks = clock() - ticks; // current clock ticks minus starting clock ticks

					if (!bid.bidId.empty()) {
						Bid::displayBid(bid);
					}
					else {
						std::cout << "Bid Id " << bidKey << " not found." << std::endl;
					}

					std::cout << "Time: " << ticks << " clock ticks" << std::endl;
					CompareTime(&htSearchBest, &htSearchWorst, ticks);

					break;

				// Hash Table - Delete
				case 5:

					std::cout << "Enter Auction ID: ";
					std::cin >> bidKey;

					ticks = clock();

					bidTable->HashTable::Remove(bidKey);

					ticks = clock() - ticks; // current clock ticks minus starting clock ticks
					std::cout << "Time: " << ticks << " clock ticks" << std::endl;
					CompareTime(&htDeleteBest, &htDeleteWorst, ticks);

					break;
				}
			}
			break;

		//Print time statistics
		case 4:
			
			std::cout << std::endl;
			std::cout << "******************** Best/Worst Times For Each Operation Performed ********************" << std::endl << std::endl;
			std::cout << "Best Loading Times ->    Linked List: " << llLoadBest << " | Binary Search Tree: " << bstLoadBest << " | Hash Table: " << htLoadBest << std::endl;
			std::cout << "Worst Loading Times ->   Linked List: " << llLoadWorst << " | Binary Search Tree: " << bstLoadWorst << " | Hash Table: " << htLoadWorst << std::endl << std:: endl;
			
			std::cout << "Best Adding Times ->     Linked List: " << llAddBest << " | Binary Search Tree: " << bstAddBest << " | Hash Table: " << htAddBest << std::endl;
			std::cout << "Worst Adding Times ->    Linked List: " << llAddWorst << " | Binary Search Tree: " << bstAddWorst << " | Hash Table: " << htAddWorst << std::endl << std::endl;

			std::cout << "Best Searching Times ->  Linked List: " << llSearchBest << " | Binary Search Tree: " << bstSearchBest << " | Hash Table: " << htSearchBest << std::endl;
			std::cout << "Worst Searching Times -> Linked List: " << llSearchWorst << " | Binary Search Tree: " << bstSearchWorst << " | Hash Table: " << htSearchWorst << std::endl << std::endl;

			std::cout << "Best Deletion Times ->   Linked List: " << llDeleteBest << " | Binary Search Tree: " << bstDeleteBest << " | Hash Table: " << htDeleteBest << std::endl;
			std::cout << "Worst Deletion Times ->  Linked List: " << llDeleteWorst << " | Binary Search Tree: " << bstDeleteWorst << " | Hash Table: " << htDeleteWorst << std::endl << std::endl;
		}

	}
	return 0;
}

