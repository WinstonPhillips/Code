#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	int addNum, newNum, x;
	ifstream writeFrom;
	ofstream writeTo;
	writeTo.open("favnumbers.txt");
	writeFrom.open("favnumbers.txt");
	printf("Add Number? ");
		cin >> addNum;


		writeFrom >> x;

		newNum = x + addNum;

	cout << newNum;

	writeTo.close();
	writeFrom.close();
}

		
