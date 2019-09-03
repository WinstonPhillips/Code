#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class Person
{
	private: 
	struct weightNode
	{
	float weight;
	weightNode* next;
	};

	weightNode* head;
	weightNode* tail;
	
	string Name;
	
	public:
	Person(string name);
	void appendNode(float data);
	void displayWeight();
	void getSize();
	void insertNode(float data);
	void removeNode();
};

#endif
