#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

using namespace std;

template<typename Type>
class Queue
{
	
	private:

	struct QueueNode
	{
		Type value;
		QueueNode* next;
	};

	QueueNode* front;

	public:

	Queue()
	{
		front = NULL;
	}

	~Queue()
	{
		delete front;	
	}

	void Push_back(Type sentValue)
	{
		QueueNode* tempNode = new QueueNode;

		tempNode->value = sentValue;
		tempNode->next = NULL;	// can do because an inserted node will be at the back of the list

		if (front == NULL)
		{
			front = tempNode;
		}

		else 
		{
			QueueNode* nodePtr = front;

			while (nodePtr->next != NULL)
			{
				nodePtr = nodePtr->next;
			}

			nodePtr->next = tempNode;
		}
	}

	Type Pop_front()
	{
		Type valueToReturn = front->value;

		front = front->next;

		return valueToReturn;
	}

	Type Peek()
	{
		return front->value;
	}

	bool isEmpty()
	{
		if (front == NULL)
		{
			return true;
		}

		else 
		{
			return false;
		}
	}
};

#endif

