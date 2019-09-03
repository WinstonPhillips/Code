#include <iostream>
#include "Person.h"

using namespace std;

Person::Person(string name)
{
	Name = name;
	head = NULL;
	tail = NULL;
}

void Person::appendNode(float data)
{
	weightNode* newNode = new weightNode;
	newNode->weight = data;
	newNode->next = NULL;

	if(head == NULL)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		tail = newNode;
	}
}

void Person::displayWeight()
{
	weightNode* nodePtr = head;

	int x = 1;

	cout << "--- " << Name << "'s Weights---\n\n";
	while(nodePtr != NULL)
	{
	cout << x << ") " << nodePtr->weight << endl;
	x++;
	nodePtr = nodePtr->next;
	}
}

void Person::getSize()
{
	weightNode* nodePtr = head;

	int x = 0;

	cout << "--- " << Name << "'s Weights---\n\n";
	while(nodePtr != NULL)
	{
		x++;
		nodePtr = nodePtr->next;
	}
	cout << Name << " has " << x << " weights logged!\n";
} 

void Person::insertNode(float data)
{
	int position;

	weightNode* newNode = new weightNode;
	newNode->weight = data;

	displayWeight();

	cout << "At what position do you wish to insert new data? ";
		cin >> position;

	weightNode* nodePtr = head;

	for(int i = 0; i < position-2; i++)
	{
		nodePtr = nodePtr->next;
	}

	newNode->next = nodePtr->next;
	nodePtr->next = newNode;

}

void Person::removeNode()
{
	int position;
	int x = 0;

	displayWeight();

	cout << "At what position do you wish to remove data? ";
		cin >> position;

		weightNode* nodePtr = head;
		weightNode* lagPtr = head;

	for(int i = 0; i < position-1; i++)
	{
		nodePtr = nodePtr->next;
			if(x > 0)
				lagPtr = lagPtr->next;

		x++;
	}
	lagPtr->next = nodePtr->next;

}
	
