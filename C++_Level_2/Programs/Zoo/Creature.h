#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

class Creature
{

private:

	string name;
	string description;
	float cost;
	bool isDangerous;

public:

	/*
		Function Name: Creature()
		Purpose: default constructor for our Creature class
		Parameters: None
		Returns: None
	*/

	Creature();

	/*
		Function Name: Creature
		Purpose: overloaded constructor
		Parameters:	strings for name and description of creature, boolean value for if the creature is dangerous, float cost for cost of maintenance
		Returns: None
	*/

	Creature(string nm, string dscrp, bool isDngr, float cst);

	/*
		Function Name: printCreature()
		Purpose: prints the information of a creature
		Parameters: none
		Returns: void
	*/

	void printCreature();

	/*
		Function Name: printCreatureToFile()
		Purpose: saves all of a single creatures information to a file
		Parameters: a character array containing the name of the file to write to
		Returns: void
	*/

	void printCreatureToFile(char fileName[100]);

	/***Accessor Functions***/

	/*
		Function Name: getName()
		Purpose: returns name of a creature
		Parameters: none
		Returns: string name
	*/

	string getName();


	/*
		Function Name: getDescription()
		Purpose: returns description of a creature
		Parameters: none
		Returns: string description
	*/

	string getDescription();

	/*
		Function Name: getDangerous()
		Purpose: returns a boolean value stating of the creature is dangerous or not
		Parameters: none
		Returns: boolean isDangerous
	*/

	bool getDangerous();

	/*
		Function Name: getCost()
		Purpose: returns the cost of maintenance for a creature
		Parameters: none
		Returns: float cost
	*/

	float getCost();

	/***Mutator Functions***/

	/*
		Function Name: setName()
		Purpose: sets the name of the creature
		Parameters: string nm (name)
		Returns: void
	*/

	void setName(string nm);

	/*
		Function Name: setDescription()
		Purpose: sets the description of the creature
		Parameters: string dscrpt  (description)
		Returns: void
	*/

	void setDescription(string dscrpt);

	/*
		Function Name: setDangerous()
		Purpose: sets the boolean isDangerous of the creature
		Parameters: bool isDngr (is dangerous)
		Returns: void
	*/

	void setDangerous(bool isDngr);

	/*
		Function Name: setCost()
		Purpose: sets the cost of maintenance for a creature
		Parameters: float cst (cost)
		Returns: void
	*/

	void setCost(float cst);

};

#endif