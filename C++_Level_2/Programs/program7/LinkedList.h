/*
	Title:  LinkedList.h
	Author:  April Crockett
	Date:  2/4/2018
	Purpose:  A template class which implements a singly-linked list.
*/

#ifndef LINKEDLIST
#define LINKEDLIST

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include "Movie.h"
#include "Text.h"
#include "Timer.h"

using namespace std;

template <typename T>
class LinkedList
{
	private:
		struct ListNode
		{
			T value;           	
			struct ListNode *next;  	
		}; 

		ListNode *head;		
		ListNode *tail;		
		int numNodes;

		
	public:
		LinkedList()
		{ 
			head = NULL; 
			tail = NULL;
			numNodes = 0;
		}
		~LinkedList();
		int getLength();
		T getNodeValue(int);
		void appendNode(T);
		void insertNode(T, int);
		void deleteNode(int);
		void saveNodestoFile(char *filename);
		void displayNodes();
		void insertionSort();
		bool binarySearch(const char* itemToSearch);
		void swap(int position1, int position2);
		void deleteNodeforSort(int position);
};

template <typename T>
int LinkedList<T>::getLength()
{
	return numNodes;
}

//returns the node value at a given position
template <typename T>
T LinkedList<T>::getNodeValue(int position)
{
	ListNode *nodePtr;
	nodePtr = head;
	int currentPos = 0;
	
	while(position >= currentPos)
	{
		if(position == currentPos)
			return nodePtr->value;
		currentPos++;
		nodePtr = nodePtr->next;
	}
}

//**************************************************
// appendNode appends a node containing the        *
// value passed into nodeValue, to the end of the list.   *
//**************************************************
template <typename T>
void LinkedList<T>::appendNode(T nodeValue)
{
	ListNode *newNode;  // To point to a new node
	ListNode *nodePtr;  // To move through the list
	// Allocate a new node and store nodeValue there.
	newNode = new ListNode;
	++numNodes;
	newNode->value = nodeValue;
	newNode->next = NULL;

	// If there are no nodes in the list make newNode the first node.
	if (!head ) 
	{
		head = newNode;
		tail = newNode;
	}
	else  // Otherwise, insert newNode at end.
	{
		//set the current last node's next pointer to the new node
		tail->next = newNode;
		
		//now the tail is the new node
		tail = newNode;
	}
}

template <typename T>
void LinkedList<T>::insertNode(T nodeValue, int iPos)
{
	ListNode *newNode;  // To point to a new node
	ListNode *nodePtr;  // To move through the list
	ListNode *previousNode;
	// Allocate a new node and store nodeValue there.
	newNode = new ListNode;
	++numNodes;
	newNode->value = nodeValue;
	newNode->next = NULL;

	// If there are no nodes in the list make newNode the first node.
	if (!head ) 
	{
		head = newNode;
		tail = newNode;
	}
	else  // Otherwise, insert newNode at position.
	{
		int pos = 0; 
		nodePtr = head;
		
		if(iPos == 0) //insert at beginning of list
		{
			newNode->next = head;
			head = newNode;
			return;
		}
		if(iPos >= this->getLength()-1) //insert at end
		{
			newNode->next = NULL;
			tail->next = newNode;
			tail = newNode;
			return;
		}
		while(iPos != pos)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
			pos++;
		}
		
		newNode->next = nodePtr;
		previousNode->next = newNode;
	}
}
//**************************************************
// The deleteNode function finds the node with the argument position & deletes it
//**************************************************
template <typename T>
void LinkedList<T>::deleteNode(int position)
{
	ListNode *nodePtr;       // To traverse the list
	ListNode *previousNode;  // To point to the previous node
	Text* name;	// for post deletion submission

	// Determine if the first node is the one.
	if (position == 0)
	{
		name = head->value->getmovieTitle();
		name->displayText();
		nodePtr = head->next;
		delete head;
		--numNodes;
		head = nodePtr;
		cout << " was deleted!" << endl;
		
	}
	else
	{
		// Initialize nodePtr to head of list
		nodePtr = head;
		int ptrPosition = 0;

		// Skip all nodes whose value member is not equal to the sent position.
		while (ptrPosition != position)
		{  
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
			ptrPosition++;
		}

		// If nodePtr is not at the end of the list, link the previous node to the node after
		// nodePtr, then delete nodePtr.
		if(nodePtr == tail)
			tail = previousNode;
		
 
		previousNode->next = nodePtr->next;
		name = nodePtr->value->getmovieTitle();
		delete nodePtr;
		--numNodes;
		cout << " was deleted!" << endl;
	}
}

template <typename T>
void LinkedList<T>::deleteNodeforSort(int position)
{
	ListNode *nodePtr;       // To traverse the list
	ListNode *previousNode;  // To point to the previous node
	Text* name;	// for post deletion submission

	// Determine if the first node is the one.
	if (position == 0)
	{
		name = head->value->getmovieTitle();
		nodePtr = head->next;
		delete head;
		--numNodes;
		head = nodePtr;
	}
	else
	{
		// Initialize nodePtr to head of list
		nodePtr = head;
		int ptrPosition = 0;

		// Skip all nodes whose value member is not equal to the sent position.
		while (ptrPosition != position)
		{  
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
			ptrPosition++;
		}

		// If nodePtr is not at the end of the list, link the previous node to the node after
		// nodePtr, then delete nodePtr.
		if(nodePtr == tail)
			tail = previousNode;
		
 
		previousNode->next = nodePtr->next;
		name = nodePtr->value->getmovieTitle();
		delete nodePtr;
		--numNodes;
	}
}


//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
// Similar to a typical list function RemoveAll    *
//**************************************************
template <typename T>
LinkedList<T>::~LinkedList()
{
	ListNode *nodePtr;   // To traverse the list
	ListNode *nextNode;  // To point to the next node

	// Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr is not at the end of the list...
	while (nodePtr != NULL)
	{
		// Save a pointer to the next node.
		nextNode = nodePtr->next;

		// Delete the current node.
		delete nodePtr;
		--numNodes;

		// Position nodePtr at the next node.
		nodePtr = nextNode;
	}
}

template <typename T>
void LinkedList<T>::displayNodes()
{
	ListNode* temp = head;
	int x = 1;
	while(temp != NULL)
	{
		cout << endl;
		cout << "Movie " << x << endl;
		temp->value->printMovieDetails();
		cout << "------------";

		temp = temp->next;

		x++;
	}
	cout << endl;
}
template<typename T>
void LinkedList<T>::saveNodestoFile(char *filename)
{
	ofstream outFile;
	
	outFile.open(filename);

	ListNode* temp = head;
	
	for(int x=0; x < (numNodes); x++)
	{
		temp->value->printMovieDetailsToFile(outFile); //function in Movies.cpp
		temp = temp->next;
	}
	outFile.close();
	
	cout << "\n\nAll movies in your library have been printed to " << filename << endl;
}

template<typename T>
void LinkedList<T>::insertionSort()
{
	ListNode* insertionPointer = head;	// because first node is already sorted
	ListNode* current = head->next;

	int positionA = 1;
	int positionB = 2;


	while (current != NULL)
	{

		Text* movieTitle2 = current->value->getmovieTitle();

		const char* movieTitleArray2 = movieTitle2->getText();


		while(insertionPointer != current)
		{
	
			Text* movieTitle1 = insertionPointer->value->getmovieTitle();	// for insertionPointer's movie title

			const char* movieTitleArray1 = movieTitle1->getText();

			
			if (strcmp(movieTitleArray1,movieTitleArray2) > 0)
			{
				
				swap(positionA,positionB);

			}
			

			insertionPointer = insertionPointer->next;

			positionA++;
		}

		insertionPointer = head;

		current = current->next;

		positionB++;

		positionA = 1;
	} 

}

template<typename T>
bool LinkedList<T>::binarySearch(const char* itemToSearch)
{
	int first = 0;
	int last = numNodes;
	int middle = (first+last) / 2;

	bool isFound = false;

	ListNode* current;	// to traverse the linked list


	while (!isFound && first <= last)
	{

		current = head;

		for (int i = 0; i < middle-1; i++)
		{
			current = current->next;
		}

		Text* movieTitle = current->value->getmovieTitle();

		const char* movieTitleArray = movieTitle->getText();

		if (strcmp(movieTitleArray, itemToSearch) == 0)
		{
			isFound = true;
		}

		else if(strcmp(movieTitleArray, itemToSearch) > 0)
		{
			last = middle -1;
		}
		else
		{
			first = middle +1;
		}

		middle = (first+last) / 2;
	}

	return isFound;
}

template <typename T>
void LinkedList<T>::swap(int pos1, int pos2)
{
	ListNode *nodePtr1=NULL;
	ListNode *nodePtr2=NULL;
	T tempValue;
	
	nodePtr1 = head;
	
	int curPos = 0;
	while(nodePtr1 != NULL && pos1 != curPos)
	{
		//traverse to next node
		nodePtr1 = nodePtr1->next;
		curPos++;
	}
	//now nodePtr1 is pointing to pos1 
	nodePtr2 = head;
	curPos = 0;
	while(nodePtr2 != NULL && pos2 != curPos)
	{
		//traverse to next node
		nodePtr2 = nodePtr2->next;
		curPos++;
	}	
	//now nodePtr2 is pointing to pos2 	

	tempValue = nodePtr1->value;
	nodePtr1->value = nodePtr2->value;
	nodePtr2->value = tempValue;
	
}



#endif