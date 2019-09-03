#include <iostream>
#include <cstring>
#include "String.h"


using namespace std;

int main()
{
	int userChoice;
	int startIndex, endIndex;
	int index; // for finding delimeter
	char delimeter;	// delimeter entered from user
	char userInput[100];
	int compareInt; // compare function's return value

	cout << "Phrase: ";
	cin.getline(userInput,100);
	String* str1 = createString(userInput);

	do{

	cout << "Menu\n";
	cout << "1. Display the String." << endl;
	cout << "2. Locate the next occurrence of a delimiting character starting at a specified index." << endl;
	cout << "3. Make a substring." << endl;
	cout << "4. Compare two seperate strings." << endl;
	cout << "5. Quit" << endl;
	cout << "\t Choice: ";

		cin >> userChoice;
		while (userChoice < 1 || userChoice > 5)
		{
			cout << "Invalid option. Please choose again: " << endl;
				cin >> userChoice;
		}

	
	if(userChoice == 1)
	{
		cout << endl;
		cout << "Your String: ";
		displayString(str1);
		cout << endl;
	}
	else if(userChoice == 2)
	{
				cout << "Enter a character: ";
					cin >> delimeter;
				cout << "Enter a starting index: ";
					cin >> startIndex;
				index = find(str1,delimeter,startIndex);
				cout << endl;
				cout << "Delimeter found at index: " << index << endl;
				cout << endl;
	}
	else if(userChoice == 3)
	{
				cout << "Enter a starting index: ";
					cin >> startIndex;
				cout << "Enter an ending index: ";
					cin >> endIndex;
				String* subString = substr(str1,startIndex,endIndex);
				cout << endl;
				cout << "Your sub-string: ";
				displayString(subString);
				destroyString(subString);
				cout << endl;	
	}

	else if(userChoice == 4)
	{
				
					cin.ignore();
					char otherInput[100];
				
				cout << "Enter the phrase you wish to compare your string to: ";
					cin.getline(otherInput,100);
				String* compStr = createString(otherInput);
				

				compareInt = compare(str1,compStr);

				cout << endl;
				cout << "Returned Value: " << compareInt << endl;
				destroyString(compStr);
	}


	}while(userChoice != 5);

	destroyString(str1);

	cout << "\n Goodbye! \n";

}