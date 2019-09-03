#include <string>
#include <iostream>
#include "Computer.h"

#include <string>
#include <iostream>
#include "Computer.h" 

using namespace std;

Monitor* createMonitor(string name, double cost, float width, float height)
{
	Monitor* newMonitor = new Monitor;

	newMonitor->Name = name;
	newMonitor->Cost = cost;
	newMonitor->Width = width;
	newMonitor->Height = height;

	return newMonitor;
}

void displayMonitor(Monitor* m)
{
	cout << "Monitor name: " << m->Name;
	cout << "\t Cost: " << m->Cost << endl;
	cout << "Size: " << m->Width << " x " << m->Height << endl;
}