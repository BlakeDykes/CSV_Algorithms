#ifndef _BINARYSEARCHTREE_H_
#define _BINARYSEARCHTREE_H_

#include "Bid.h"

using namespace BidData;

namespace BST {

	struct Node {
		Node *parent;
		Node *left;
		Node *right;
		Bid bid;
		int key;

		Node(Bid bid)
		{
			this->parent = nullptr;
			this->left = nullptr;
			this->right = nullptr;
			this->key = stoi(bid.bidId);
			this->bid = bid;
		};

		void static DestroyRecursive(Node *node);
	};

	class BinarySearchTree {

	private:

		void addNode(Node* node, Bid bid);
		void inOrder(Node* node);

	public:

		Node* root;
		BinarySearchTree();
		virtual ~BinarySearchTree();
		void InOrder(Node * node);
		void Insert(Bid bid);
		Node * Remove(Node * node, int bidId);
		Bid * Search(int bidId);
		Node * findMinNode(Node * node);
	};
}


#endif // !_BINARYSEARCHTREE_H_
