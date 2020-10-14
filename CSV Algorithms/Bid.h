#ifndef     _BID_HPP_
# define    _BID_HPP_

# include <string>

namespace BidData {

	struct Bid {

		std::string bidId; // unique identifier
		std::string title;
		std::string department;
		std::string closeDate;
		std::string inventoryID;
		std::string vehicleID;
		std::string receiptNum;
		std::string fund;
		double amount;

		Bid();
		static Bid CreateBid();
		static void displayBid(Bid bid);
	};
}
#endif /*!_BID_HPP_*/