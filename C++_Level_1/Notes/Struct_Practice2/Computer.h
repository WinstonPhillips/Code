#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>

using namespace std;

struct Computer
{
	string CompName;
	double Cost;
	int CoreNum;
};

struct Monitor
{
	string Name;
	double Cost;
	float Width;
	float Height;

};

Computer* createComputer(string name, double cost, int corenum);
void displayComputer(Computer* s);
void destroyComputer(Computer* s);

Monitor* createMonitor(string name, double cost, float width, float height);
void displayMonitor(Monitor* m);
void destroyMonitor(Monitor* m);


#endif

