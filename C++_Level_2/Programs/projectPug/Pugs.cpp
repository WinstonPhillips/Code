#include <iostream>
#include "Pugs.h"
#include "Text.h"
#include "Pug.h"

using namespace std;

Pugs::Pugs(int max)
{
		pugsArray = new Pug*[max];		// an array holding pointers to pug
		arrayMax = max;
		numPugs = max;		// number of pugs to be initially put in the array
}

Pugs::~Pugs()
{
	for (int i = 0; i < arrayMax; i++)
	{
		pugsArray[i]->~Pug();
	}
	delete[] pugsArray;
}

void Pugs::displayPugs()
{
	
	if (numPugs > 0)
	{


			for (int i = 0; i < numPugs; i++)
			{
				cout << "-----------------PUG " << i+1 << "----------------------" << endl;
					pugsArray[i]->displayPugDetails();
			}
	
	}
	else 
	{
		cout << "You ain't got no pugs fool." << endl;
	}
}

void Pugs::removePug()
{
	int index;
	cout << "Choose the pug to remove. Choose wisely..." << endl;
	displayPugs();

	cin >> index;
	index = index -1;

	pugsArray[index]->~Pug();

	

	for (int i = index; i < numPugs-1; i++)
	{
		pugsArray[i] = pugsArray[i+1];
	}
	pugsArray[numPugs-1] = NULL;
	numPugs--;

	cout << "DONE!" << endl;
}

void Pugs::addPug()
{

	char temp[100];
	int age;
	float weight;
	 cout << "New Pug's name: ";
	 		cin >> temp;
	cout << "New Pug's Age: ";
			cin >> age;
	cout << "New Pug's Weight(_._)";
			cin >> weight;
	Text* newName = new Text(temp);

	Pug* newPug = new Pug(newName, age, weight);

	if (numPugs > arrayMax)
	{
		resizeArray();
	}

	pugsArray[numPugs] = newPug;

	numPugs++;

}

void Pugs::resizeArray()
{
	int newMax = arrayMax *2;		// now twice as big

	Pug** newArray = new Pug*[newMax];

	for (int i = 0; i < arrayMax; i++)
	{
		newArray[i] = pugsArray[i];		// copy all over to new array
	}

	delete[] pugsArray;		// yeah, you can do that

	pugsArray = newArray;

	arrayMax = newMax;

}
