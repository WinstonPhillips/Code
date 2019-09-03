#include <iostream>
#include "Pug.h"

using namespace std;

Pug::Pug(Text* name, int age, float weight)
{
	pugName = name;
	pugAge = age;
	pugWeight = weight;
	
	if(pugWeight < 10)
	{
		Status = new Text("Skinny Pug");
	}
	else if(pugWeight > 10 && pugWeight < 14)
	{
		Status = new Text("Medium Pug");
	}
	else 
	{
		Status = new Text("Fat Pug");
	}
}

Pug::~Pug()
{
	pugName->~Text();
	Status->~Text();
}

Text* Pug::getPugName()
{
	return pugName;
}

int Pug::getPugAge()
{
	return pugAge;
}

float Pug::getPugWeight()
{
	return pugWeight;
}

void Pug::displayPugDetails()
{
	cout << "Name: " << "\t"; 
	pugName->displayText();
	cout << endl;
	cout << "Age: " << "\t" << pugAge << endl;
	cout << "Weight " << "\t" << pugWeight << " lbs" << endl;
	cout << "Build: " << "\t";
	Status->displayText();
	cout << endl;
}