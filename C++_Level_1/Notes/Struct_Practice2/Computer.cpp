#include <string>
#include <iostream>
#include "Computer.h" // because we are still using struct for programs

using namespace std;

Computer* createComputer(string name, double cost, int corenum)
{
	Computer* newComputer = new Computer;

	newComputer -> CompName = name;
	newComputer -> Cost = cost;
	newComputer -> CoreNum = corenum;

	return newComputer;
}

void displayComputer(Computer* s)
{
	cout << s->CompName << endl;
	cout << "Cost: " << s->Cost;
	cout << "\t Processor: Core i" << s->CoreNum << endl;
	cout << endl;
}

void destroyComputer(Computer* s)
{
	delete s;
}