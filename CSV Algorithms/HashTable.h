#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

#include "Bid.h"

#include <vector>

using namespace BidData;

namespace HT {

	/**
	 * Define a class containing data members and methods to
	 * implement a hash table with chaining.
	 */
	class HashTable {

	private:
		// Structures to hold bids
		struct Node
		{
			int key;
			struct Bid bid;
			struct Node * next;

			Node()
			{
				key = NULL;
				bid.bidId = "";
				bid.amount = NULL;
				bid.fund = "";
				bid.title = "";
				bid.department = "";
				bid.closeDate = "";
				bid.inventoryID = "";
				bid.vehicleID = "";
				bid.receiptNum = "";
				next = nullptr;
			}

			Node(Bid aBid, int hash)
			{
				key = hash;
				bid = aBid;
				next = nullptr;
			}
		};

		Node* head;
		std::vector <Node> * table = new std::vector <Node>;
		unsigned int hash(int key);
		int size;


	public:
		HashTable();
		virtual ~HashTable();
		void Insert(Bid bid);
		void PrintAll();
		void Remove(std::string bidId);
		Bid Search(std::string bidId);
	};
}

#endif // !_HASHTABLE_H_

