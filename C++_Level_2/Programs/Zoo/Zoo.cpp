/*
		Written by Winston Phillips
		Date: 2/14/2018
		Class: CSC 1310
*/
#include <iostream>
#include <string>
#include <fstream>	

#include "Creature.h"

using namespace std;

void enterMagicalCreature(LinkedList<Creature> &Zoo);
void enterMagicalCreatureFromFile(LinkedList<Creature> &Zoo);
void deleteCreature(LinkedList<Creature> &Zoo);
void printCreatures(LinkedList<Creature> &Zoo);
void printCreatureNames(LinkedList<Creature> &Zoo);

int main()
{
	int userChoice;
	int inputChoice;
	char userChar;
	char fileName[100]; // for saving all creatures to file at end of main

	LinkedList<Creature> Zoo;
	do
	{
		cout << "\n\t****MENU****\n\n";
	cout << "What would you like to do?" << endl;
	cout << "\t 1. Enter Magical Creature" << endl;
	cout << "\t 2. Delete a Magical Creature" << endl;
	cout << "\t 3. List/Print Creatures" << endl;
	cout << "\t 4. End Program" << endl;
	cout << "CHOICE: ";
		cin >> userChoice;
		while (userChoice > 4 || userChoice < 1)
		{
			cin.ignore();
			cout << "Invalid option. Please choose between 1 and 4." << endl;
			cout << "CHOICE: ";
				cin >> userChoice;
		}

	switch(userChoice)
	{
		case 1:	cout << "Do you wish to enter the creature(s)" << endl;
					cout << "\t 1. Manually?" << endl;
					cout << "\t 2. From a file?" << endl;
						cout << "CHOICE: ";
						cin >> inputChoice;
						while (inputChoice != 1 && inputChoice != 2)
						{
							cin.ignore();
							cout << "Please choose either a 1 or 2" << endl;
							cout << "CHOICE: ";
								cin >> inputChoice;
						}
						if (inputChoice == 1)
						{
							enterMagicalCreature(Zoo);
						}
						else if (inputChoice == 2)
						{
							enterMagicalCreatureFromFile(Zoo);	// not done yet
						}

						break;
		case 2: deleteCreature(Zoo);
				break;

		case 3: printCreatures(Zoo);
				break;

		case 4: break;
	}

	}while(userChoice != 4);

	cout << "Do you wish to save all of your creatures?(y/n): ";
		cin >> userChar;
	while(userChar != 'y' && userChar != 'Y' && userChar != 'n' && userChar && 'N')
	{
		cin.ignore();
		cout << "Invalid coice. Please choose a valid choice: ";
			cin >> userChar;
	}

	if (userChar == 'y' || userChar == 'Y')
	{
		cout << "Please enter the name of the file you wish to save creatures to: ";
			cin >> fileName;

		for (int i = 0; i < Zoo.getLength(); i++)
		{
			Creature tempCreature = Zoo.getNodeValue(i);
			tempCreature.printCreatureToFile(fileName);
			cout << tempCreature.getName() << " was saved to " << fileName << endl;
		}
		cout << "Creatures Saved!" << endl;
	}

	else
	{
		cout <<  "No creatures saved." << endl;
	}

	cout << "\nHAVE A GRYFFINDOR OF A DAY!" << endl;

	return 0;

}
//********************************************End of Main*******************************************************//

	/*
		Function Name: enterMagicalCreature()
		Purpose: prompts the user to give information about the creature and adds the creature to the linked list
		Parameters: address of our Zoo
		Returns: void
	*/

void enterMagicalCreature(LinkedList<Creature> &Zoo)
{
	string nm;
	string dscrp;
	float cst;
	int isDngr;		// for userInput and input validation, doesn't work with bool
	bool isdanger;	// for actual passing 
	string dummyString;		// dummy string to clear queue
	char userChar; 	// for repetition of adding a creature

	do 
	{

	cout << "\n\n";
	cin.ignore();
	cout << "Name of new creature: ";
		getline(cin,nm);

	cout << "Description of New Creature: ";
		getline(cin,dscrp);

	cout << "Is the new creature dangerous (y,n): ";
		cin >> userChar;

	while (userChar != 'y' && userChar != 'n')
	{
		cout << "Invalid Choice. Please Choose y or n." << endl;
		cout << "CHOICE: ";
			cin >> userChar;
	}

		if(isDngr == 'y')	// converting int to bool for storing in Node
		{
			isdanger = 1;
		}

		else 
		{
			isdanger = 0;
		}

	cout << "Monthly cost of keeping creature: $";
		cin >> cst;


	Creature newCreature(nm, dscrp, isdanger, cst);

	Zoo.appendNode(newCreature); 

	cout << "\n" << nm << " has been added to the list.\n" << endl;
	
	cout << "Would you like to add another creature to the Zoo?" << endl;
	cout << "For yes, type 'y'. For no, enter any other single character" << endl;
	cout <<  "CHOICE: ";
		cin >> userChar;

	}while(userChar == 'y' || userChar == 'Y');

}

	/*
		Function Name: enterMagicalCreatureFromFile()
		Purpose: adds creatures to the zoo based on the text file the user chooses
		Parameters: address of our Zoo
		Returns: void
	*/

void enterMagicalCreatureFromFile(LinkedList<Creature> &Zoo)
{
	int counter = 0; // number of creatures to be added
	string nm;
	string dscrp;
	float cst;
	bool isdanger;	// for actual passing 
	char fileName[100];

	ifstream inputFile;

	cout << "Name of the file you wish to add to the Zoo from: ";
		cin >> fileName;

		inputFile.open(fileName);

	if(!inputFile)
	{
		cout << "Could not locate " << fileName << endl;
		cout << endl;
	}
	else
	{

		while(!inputFile.eof())	
		{
			inputFile.ignore();	// so no infinite loop

			getline(inputFile,nm);		// must use getline because of strings
			getline(inputFile,dscrp);
			inputFile >> isdanger;
			inputFile >> cst;
			


			Creature newCreature(nm, dscrp, isdanger, cst);

			Zoo.appendNode(newCreature);

			counter++;
		}

		cout << endl;
		cout << counter << " creature(s) were added to the Zoo." << endl;
		cout << endl;

		inputFile.close();
		
	}
}

	/*
		Function Name: deleteCreature()
		Purpose: prompts the user to input what creature they wish to remove from the Zoo
		Parameters: address of our Zoo
		Returns: void
	*/

void deleteCreature(LinkedList<Creature> &Zoo)
{
	if (Zoo.getLength() == 0)
	{
		cout << "You have no creatures in your zoo!!" << endl;
	}
	else
	{
	int userChoice;
	printCreatureNames(Zoo);

	cout << "\n";
	cout << "Which creature do you wish to remove?";
		cin >> userChoice;
	while (userChoice < 1 || userChoice > Zoo.getLength())
	{
		cin.ignore();
		cout << "Invalid choice. Please choose between 1 and " << Zoo.getLength() << endl;
		cout << "CHOICE: ";
			cin >> userChoice;
	}

	Zoo.deleteNode(userChoice);
	}
}

	/*
		Function Name: printCreatures()
		Purpose: prints all of the creatures and their information residing in our Zoo
		Parameters: address of our Zoo
		Returns: void
	*/

void printCreatures(LinkedList<Creature> &Zoo)
{
	if (Zoo.getLength() == 0)
	{
		cout << "You have no creatures in your zoo!!" << endl;
	}
	else
	{
		for(int i = 0; i < Zoo.getLength(); i++)
		{
			cout << "------Creature " << i+1 << "------" << endl;
			Creature tempCreature = Zoo.getNodeValue(i);
			tempCreature.printCreature();
			cout << "\n\n";
		}
	}
}

	/*
		Function Name: printCreatureNames()
		Purpose: simply prints the creatures names out in order, for prompting the user for a choice
		Parameters: address of our Zoo
		Returns: void
	*/

void printCreatureNames(LinkedList<Creature> &Zoo)
{
	if (Zoo.getLength() == 0)
	{
		cout << "You have no creatures in your zoo!!" << endl;
	}
	else
	{
		for(int i = 0; i < Zoo.getLength(); i++)
		{
			cout << "------Creature " << i+1 << "------" << endl;
			Creature tempCreature = Zoo.getNodeValue(i);
			cout << tempCreature.getName() << endl;
		}
	}
}






















