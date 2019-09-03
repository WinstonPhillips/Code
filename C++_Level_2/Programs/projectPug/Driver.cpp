#include <iostream>
#include "Pugs.h"

using namespace std;

int main()
{
	int initPugs;
	int << userChoice;
	cout << "Welcome to Pug Emporium!" << endl;
	cout << "How many pugs do you wish to inititally add?";
			cin >> initPugs;

	Pugs* myPugs = new Pugs(initPugs);

	for (int i = 0; i < initPugs; i++)
	{
		myPugs->addPug();
	}


cout << "\n\n";

do
{
cout << "\n****Menu****\n\n";
cout << "1. Display all of my pugs!" << endl;
cout << "2. Add a new pug!" << endl;
cout << "3. Remove a pug from the list :(" << endl;
cout << "Choice: ";
		cin >> userChoice;
	while (userChoice < 0 || userChoice > 4)
	{
		cin.ignore()
		cout << "You must be a Frenchie.... Please try again." << endl;
		cout << "Choice: "	
				cin >> userChoice;
	}

switch(userChoice)
{
	case 1: myPugs->displayPugs();
			break;

	case 2: myPugs->addPug();
			break;

	case 3: myPugs->removePug();
			break;
	case 4: break
}

}while(userChoice != 4);

}