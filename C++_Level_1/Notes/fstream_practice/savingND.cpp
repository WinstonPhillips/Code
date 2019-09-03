#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	ofstream writeTo;
	ifstream writeFrom;
	int number, x, numEntries, addNum, newNum;
	int totalScore = 0;
	writeTo.open("favnumbers.txt");
	

	printf("What are your favorite numbers?");

	
		cin >> number;
		writeTo << number << endl;
		
	printf("Add number? ");
		cin >> addNum;
		writeTo << addNum + number << endl;

	
	//writeFrom.open("favnumbers.txt");

	/*writeFrom >> x;
	cout << x;
	printf("What number do you wish to add?");
		cin >> addNum;
		newNum = addNum + x;
		writeTo << newNum << endl;
	
	writeFrom.close();*/
	writeTo.close();
		
}