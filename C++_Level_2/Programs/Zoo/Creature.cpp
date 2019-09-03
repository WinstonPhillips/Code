#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Creature.h"

using namespace std;

Creature::Creature()
{

}

Creature::Creature(string nm, string dscrp, bool isDngr, float cst)
{
	name = nm;
	description = dscrp;
	isDangerous = isDngr;
	cost = cst;
}

void Creature::printCreature()
{

	cout << "Name :\t" << name << endl;

	cout << "Description:" << endl;
	cout << "\t" << description << endl;

	cout <<  "Dangerous?\t";
		if(isDangerous)
		{
			cout << "yes" << endl;
		}
		else 
		{
			cout << "no" << endl;
		}

	cout << "Cost per Month to care for creature: \t$" << fixed << setprecision(2) << cost << endl;

}

void Creature::printCreatureToFile(char fileName[100])
{
		fstream outputFile;

		outputFile.open(fileName,fstream::app);	// fstream::app appends information to end of file

		outputFile << name << endl;
		outputFile << description << endl;
		outputFile << isDangerous << endl;
		outputFile << cost << endl;
	

		outputFile.close();
}


string Creature::getName()
{
	return name;
}

string Creature::getDescription()
{
	return description;
}

float Creature::getCost()
{
	return cost;
}

bool Creature::getDangerous()
{
	return isDangerous;
}



void Creature::setName(string nm)
{
	name = nm;
}

void Creature::setDescription(string dscrpt)
{
	description = dscrpt;
}

void Creature::setDangerous(bool isDngr)
{
	isDangerous = isDngr;
}

void Creature::setCost(float cst)
{
	cost = cst;
}