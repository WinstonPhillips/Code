#ifndef DOGHEALTH_H
#define DOGHEALTH_H

#include <string>
#include "ArrayHelper.cpp"

using namespace std;



class DogHealth
{
private: 
	string dogName;	// name of dog object
	int dogAge;		// age of dog
	float* weightArray;		// array containing the weights of the dog
	int* heartRateArray;	// array containing  the heart rates of the dog

public: 
	  /*
			Function Name: DogHealth();
			Parameters: none 
			Return: none
			Task:  constructor for the dog health class
	  */
	DogHealth();
	  /*
			Function Name: ~DogHealth
			Parameters: none
			Return: none
			Task:  destructor for the DogHealth class
	  */
	~DogHealth();
	  /*
			Function Name: printDogHealth()
			Parameters: none
			Return: none
			Task:  print all information, including both weight array and heart rate statistic
	  */

	void printDogHealth();
	  /*
			Function Name:	printWeightStatistics()
			Parameters: none
			Return: none
			Task:  displays the highest, lowest, and average weight of the dog object 
	  */
	void printWeightStatistics();
	  /*
			Function Name:	printeHeartRateStatistics()
			Parameters: none
			Return: none
			Task:  displays the highest, lowest, and average heart rate of the dog object
	  */

	
	void printHeartRateStatistics();

};



#endif