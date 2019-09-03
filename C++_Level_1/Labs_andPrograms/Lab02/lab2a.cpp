/* Winston Phillips
   T00212039
*/

#include <iostream>
#include <iomanip>
#include "functions.h"


using namespace std;

int main()
{
	
	double amountStock = 600;		// amount of stocks purchased
	double priceStock = 21.77;		// price of each stock
	double paidStock;				// total before commission
	double commPrice;				// price of commission
	double totPrice; 				// total amount to be payed
	
	calculateStock(amountStock , priceStock , paidStock);
	calculateComm(commPrice , paidStock);
	calculateTotal(paidStock , commPrice , totPrice);
	
	
	
/* Output */
	cout << setprecision(2) << fixed;		// ensure 2 decimal places
	cout << "Amount paid for the stock: $" << paidStock << endl;
	cout << "Commission paid on the sale: $" << commPrice << endl;
	cout << "Total amount paid for the stock: $" << totPrice << endl;

	return 0;
}

	