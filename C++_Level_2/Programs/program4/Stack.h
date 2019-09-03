#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

template<typename Type>
class Stack
{
	private:

	struct StackNode
	{
		Type value;
		StackNode* next;
	};

	StackNode* top; // top of stack

	public:

	Stack()
	{
		top = NULL;
	}

	~Stack()
	{
		delete top;	
	}

	void Push(Type sentValue)
	{
		StackNode* tempNode = new StackNode;
		
		tempNode->value = sentValue;

		if (top == NULL)
		{
			top = tempNode;
			top->next = NULL;
		}

		else
		{
			StackNode* pushNode = top;

			top = tempNode;

			top->next = pushNode;
		}
	}

	Type Pop()
	{
		Type valueToreturn = top->value;

		top = top->next;

		return valueToreturn;
	}

	Type Peek()
	{
		return top->value;
	}

	bool isEmpty()
	{
		if(top == NULL)
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
