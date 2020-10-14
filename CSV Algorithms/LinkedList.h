#ifndef _LINKEDLIST_HPP_
#define	_LINKEDLIST_HPP_

#include "Bid.h"

using namespace BidData;

namespace LL {
	class LinkedList {
	private:
		struct Node
		{
			Bid bid;
			Node * next;

			Node()
			{
				next = nullptr;
			}

			Node(BidData::Bid bid)
			{
				this->bid = bid;
				next = nullptr;
			}
		};

		Node *head, *tail;
		int size = 0;
	public:
		LinkedList();
		virtual ~LinkedList();
		void Append(Bid bid);
		void Prepend(Bid bid);
		void PrintList();
		void Remove(std::string bidId);
		Bid Search(std::string bidId);
		int Size();
	};
}

#endif // !_LINKEDLIST_HPP_