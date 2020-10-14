
#include "Bid.h"
#include "Utils.h"

#include <iostream>


using namespace BidData;

/**
* Default Constructor
*/
Bid::Bid() { amount = 0.0; }


/**
* Prompt a user to create a Bid
*
* return created Bid
*/
Bid Bid::CreateBid() {
	Bid bid;

	std::cout << "Enter title: ";
	std::cin.ignore();
	getline(std::cin, bid.title);

	std::cout << "Enter Id: ";
	getline(std::cin, bid.bidId);

	std::cout << "Enter department: ";
	getline(std::cin, bid.department);

	std::cout << "Enter close date (MM/DD/YYYY): ";
	getline(std::cin, bid.closeDate);

	std::cout << "Enter winning bid amount: ";
	std::string strAmount;
	getline(std::cin, strAmount);
	bid.amount = strToDouble(strAmount, '$');

	std::cout << "Enter inventory ID: ";
	getline(std::cin, bid.inventoryID);

	std::cout << "Enter Vehicle ID: ";
	getline(std::cin, bid.vehicleID);

	std::cout << "Enter Receipt Number: ";
	getline(std::cin, bid.receiptNum);

	std::cout << "Enter fund: ";
	std::cin >> bid.fund;

return bid;
}

/**
 * Display the bid information
 *
 * @param bid struct containing the bid info
 */
void Bid::displayBid(Bid bid) {
	std::cout << bid.title << " | " << bid.bidId << " | " << bid.department << " | " << bid.closeDate << " | $" << bid.amount << " | "
		<< bid.inventoryID << " | " << bid.vehicleID << " | " << bid.receiptNum << " | " << bid.fund << std::endl;

	return;
}

