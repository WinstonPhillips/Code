#ifndef DOGSTUFF_H
#define DOGSTUFF_H

#include <list>
#include <string>
using namespace std;

class DogStuff
{
private:
		list<float> weightList;
		list<float>::iterator weightIterator;
		string Name;
public:
	DogStuff(string name);
	void appendNode();
	void removeNode();
	void displayList();
};

#endif