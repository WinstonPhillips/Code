/*
	Winston Phillips
	11/21/2017
	T00212039
*/
#include <fstream>
#include <iostream>
#include <string>
#include <ctime>
#include "time.h"


using namespace std;

long int sumInSequential(int minNum, int maxNum)
{
	int x; // for calculating total of all prime number
	long int sum = 0;
	ifstream writeFrom;
	ofstream writeTo;

	
	for (int i = minNum ; i < maxNum; i++)
	{
		if (i == 1 || i == 3 || i == 5)		// to go ahead and save 1,3, or 5 as primes
		{
			sum = sum + i;
		}
		else if(i%2 != 0 && i%3 != 0 && i%5 != 0)	// handles all other primes
		{
			sum = sum + i;
		}
	}

	return sum;


}


long int sumInParallel(int minNum, int maxNum)
{
	int x; // for calculating total of all prime number
	long int sum = 0;

	#pragma omp parallel for reduction (+:sum)
	for (int i = minNum ; i < maxNum; i++)
	{
		if (i == 1 || i == 3 || i == 5)		// to go ahead and save 1,3, or 5 as primes
		{
			sum = sum + i;
		}
		else if(i%2 != 0 && i%3 != 0 && i%5 != 0)	// handles all other primes
		{
			
			sum = sum + i;
		}
	}

	return sum;

}

int main()
{
	int maxNum, minNum, primeNum;
	long int sumOfPrimes;
	int userChoice=0;	// inout from user
	time_t start,end;
	ifstream writeFrom;
	ofstream writeTo;

	writeFrom.open("range.txt");

	writeFrom >> minNum;
	writeFrom >> maxNum;

	writeFrom.close();

	cout << "Please choose an option below.\n" << endl;


	do{						// input validation for user
		cout << "1. Calculate the sum of all the primes sequentially.\n";
		cout << "2. Calculate the sum of all the primes using parallel programming.\n";
		cout << "3. Quit\n";

		cin >> userChoice;
		while (userChoice > 3 || userChoice < 1)
		{
				
					cout << "Invalid input. Please try again." << endl;
					cin >> userChoice;
				
		}
	

	switch(userChoice)
	{
		case 1: start = getTime();
				sumOfPrimes = sumInSequential(minNum,maxNum);
				end = getTime();
				cout << "Total of primes: " << sumOfPrimes << endl;
				cout << "Time Elapsed: " << totalTime(start,end) << endl;
				break;

		case 2:	start = getTime();
				sumOfPrimes = sumInParallel(minNum,maxNum);
				end = getTime();
				cout << "Total of primes: " << sumOfPrimes << endl;
				cout << "Time Elapsed: " << totalTime(start,end) << endl;
				break;	

		case 3: break;
	}

}while (userChoice != 3);


	


	return 0;

	


}