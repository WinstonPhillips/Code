/* Passing by Reference */

#include <iostream>

using namespace std;

void calculateStock(double &amountStock, double &priceStock, double &paidStock )
{
	paidStock = amountStock * priceStock; // total price untaxed
}

void calculateComm(double &commPrice , double &paidStock)
{
	commPrice = paidStock * .02;	// commission to be payed
}

void calculateTotal (double &paidStock, double &commPrice, double &totPrice)
{
	totPrice = commPrice + paidStock;
}
