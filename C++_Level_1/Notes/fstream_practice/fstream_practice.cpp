#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	ofstream writeTo;
	ifstream writeFrom;
	int number, x, numEntries;
	int totalScore = 0;
	writeTo.open("favnumbers.txt");
	

	printf("What are your favorite numbers?");

	for (int i = 0; i < 5; i++)
	{
		cin >> number;
		writeTo << number << endl;
		numEntries++;
		if (i < 4)
		{
		printf("Next number?: ");
		}
	}
		cout << "Saved Numbmers in order: \n";
	writeFrom.open("favnumbers.txt");

	for (int i = 0; i < numEntries; i++)
	{
		writeFrom >> x;
		totalScore = totalScore + x;
		cout << x << endl;
	}
	printf("\n");

	cout << "Numbers all added up: ";
	
	cout << totalScore;



	writeTo.close();
	writeFrom.close();


	return 0;

}