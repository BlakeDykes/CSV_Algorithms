#ifndef     _UTILS_HPP_
# define    _UTILS_HPP_

#include "LinkedList.h"
#include "BinarySearchTree.h"
#include "HashTable.h"

#include <vector>
#include <time.h>

double strToDouble(std::string str, char ch);                                          // Convert a string to a double, while stripping out an unwanted character
std::vector<std::string> loadBids(std::string csvPath, LL::LinkedList *list);          // Load a CSV file containing bids into a linked list, returns CSV header
std::vector<std::string> loadBids(std::string csvPath, BST::BinarySearchTree* bst);    // Load a CSV file containing bids into a binary search tree, returns CSV header
std::vector<std::string> loadBids(std::string csvPath, HT::HashTable* hashTable);      // Load a CSV file containing bids into a hash table, returns CSV header
void CompareTime(clock_t * best, clock_t * worst, clock_t newT);                       // Compares a new time with previous best and worst case scenarios, setting best and worst case as needed

#endif	 /*!_UTILS_HPP_*/