#include "BinarySearchTree.h"
#include "Bid.h"
#include "Utils.h"

#include <iostream>
#include <time.h>
#include <algorithm>
#include <string>

using namespace BST;
using namespace BidData;

/**
 * Default constructor for BST
 */
BinarySearchTree::BinarySearchTree() {
	root = nullptr;
}

/**
* Used by the desturctor to delete the BST nodes
*
* @param node - The root node
*/
void BST::Node::DestroyRecursive(Node *node)
{
	if (node)
	{
		DestroyRecursive(node->left);
		DestroyRecursive(node->right);
		delete node;
	}
}

/**
 * Destructor
 */
BinarySearchTree::~BinarySearchTree() {
	// recurse from root deleting every node
	Node::DestroyRecursive(root);
}

/*
* Returns the farthest left node in a tree
*
* @param node - The node to begin searching from
*/
BST::Node* BinarySearchTree::findMinNode(Node * node)
{
	Node * current = node;

	while (current != nullptr && current->left != nullptr)
		current = current->left;

	return current;
}

/**
 * Traverse the tree in order
 *
* @param node - The root node
 */
void BinarySearchTree::InOrder(Node * node) {

	if (node == nullptr)
		return;

	InOrder(node->left);

	std::cout << node->bid.title << " | " << node->bid.bidId << " | " << node->bid.department << " | " << node->bid.closeDate << " | $" << node->bid.amount << " | "
		<< node->bid.inventoryID << " | " << node->bid.vehicleID << " | " << node->bid.receiptNum << " | " << node->bid.fund << std::endl;

	InOrder(node->right);
}

/**
 * Insert a bid
 *
* @param bid - The bid to be inserted
 */
void BinarySearchTree::Insert(Bid bid) {
	// Inserts a bid into the tree
	Node * node = new Node(bid);

	if (root == nullptr)
	{
		root = node;
	}
	else
		addNode(root, bid);
}

/**
 * Remove a bid
 *
* @param node - The root node
* @param bidId - The key of the node to remove
 */
BST::Node* BinarySearchTree::Remove(Node * node, int bidId) {

	//Return if empty tree
	if (node == NULL) return node;

	if (bidId < node->key)
	{
		node->left = Remove(node->left, bidId);
	}
	if (bidId > node->key)
	{
		node->right = Remove(node->right, bidId);
	}
	else
	{
		//Delete node with one child
		if (node->left == NULL)
		{
			Node * tmp = node->right;
			delete node;
			return tmp;
		}
		else if (node->right == NULL)
		{
			Node * tmp = node->left;
			delete node;
			return tmp;
		}
		else
		{
			//Delete Node with two children
			Node* tmp = findMinNode(node->right);
			node = tmp;
			node->right = Remove(node->right, node->key);
		}
	}
	return node;
}

/**
 * Search for a bid
 *
* @param bidId - The key of the node to search for
 */
Bid * BinarySearchTree::Search(int bidId) {
	Bid * bid = new Bid();
	Node * current = root;

	while (bid->bidId == "")
	{
		if (current == nullptr)
			return bid;
		else {
			if (current->key == bidId)
				*bid = current->bid;

			else if (bidId > current->key)
				current = current->right;

			else if (bidId < current->key)
				current = current->left;
		}
	}

	return bid;
}

/**
 * Add a bid to a node (recursive)
 *
 * @param node - The root node
 * @param bid - The bid to be added
 */
void BinarySearchTree::addNode(Node* node, Bid bid) {
	// Insert a bid into the tree
	if (node->bid.bidId.compare(bid.bidId) > 0)
	{
		if (node->left == nullptr)
		{
			Node * newNode = new Node(bid);
			node->left = newNode;
			newNode->parent = node;
		}
		else
			this->addNode(node->left, bid);
	}
	else
	{
		if (node->right == nullptr)
		{
			Node * newNode = new Node(bid);
			node->right = newNode;
			newNode->parent = node;
		}
		else
			this->addNode(node->right, bid);
	}
}