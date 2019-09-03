#include <iostream>


using namespace std;

int main()
{
	
	double amountStock = 600;		// amount of stocks purchased
	
	double priceStock = 21.77;		// price of each stock
	
	double paidStock = amountStock * priceStock; // total price untaxed
	
	double commPrice = paidStock * .02;	// commission to be payed
	
	double totPrice = commPrice + paidStock; 	// total amount to be payed with commission
	
/* Output */

	cout << "Amount paid for the stock: " << paidStock << endl;
	cout << "Commission paid on the sale: " << commPrice << endl;
	cout << "Total amount paid for the stock: " << totPrice << endl;

	return 0;
}

	