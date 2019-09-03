#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

template<typename Type>
class LinkedList  // all functions pertaining to the appending or deletion of our list
{
private:

	struct ListNode
	{
		Type value;
		ListNode* next;
	};

	ListNode* head;
	ListNode* tail;
	
	int numNodes;

public:
	/*
		Function Name:	LinkedList()
		Purpose: Default Constructor for Linked ListClass
		Parameters:	None 
		Returns: None
	*/

	LinkedList()
	{
		head = NULL;
		tail = NULL;
		numNodes = 0;
	}

	/*
		Function Name: ~LinkedList()
		Purpose: deconstructor for LinkedList Class
		Parameters:	None
		Returns: None
	*/

	~LinkedList()
	{
		delete head;
		delete tail;
	}

	/*
		Function Name: getLength()
		Purpose: returns the number of Nodes (creatures) we have in our Zoo
		Parameters:	None
		Returns: an integer
	*/

	int getLength()
	{
		return numNodes;
	}

	/*
		Function Name: getNodeValue()
		Purpose: returns the vale of a node at a certain position (in our case, an object)
		Parameters: int position, or the position of the node we wish to remove
		Returns: the value at that node (creature)
	*/

	Type getNodeValue(int position)
	{
		ListNode* tempNode = head;

		for (int i = 0; i < position; i++)
		{
			tempNode = tempNode->next;
		}

		return tempNode->value;
	}

	/*
		Function Name:	appendNode()
		Purpose: adds a node to the end of our list
		Parameters: template type (in our case, a creature)
		Returns: void
	*/

	void appendNode(Type object)
	{
		ListNode* tempNode = new ListNode;
		tempNode->value = object;
		tempNode->next = NULL;

		if (head == NULL)
		{
			head = tempNode;
			tail = tempNode;
		}

		else
		{
			tail->next = tempNode;
			tail = tempNode;
		}

		numNodes++;
	}

	/*
		Function Name: deleteNode()
		Purpose: to remove a node at a certain position 
		Parameters: int position, the position of the node we wish to remove
		Returns: void
	*/

	void deleteNode(int position)
	{
		ListNode* tempNode = head;
		ListNode* tempNodeTwo = head;

		if (position == 1)
		{
			tempNode = head->next;
			head = tempNode;
			delete tempNode;
			delete tempNodeTwo;
			
		}
		else
		{
		for (int i = 0; i < position-1; i++)
		{
			if(i > 0)
			{
				tempNodeTwo = tempNodeTwo->next;	// stays one step behind
			}
			tempNode = tempNode->next;
		}

		tempNodeTwo->next = tempNode->next;

		cout << "\n" << tempNode->value.getName() << " was removed from the Zoo. \n\n";

		delete tempNode;

		}

		numNodes--;
	}


};

#endif