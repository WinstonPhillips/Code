#include <iostream>
#include <string>

#include "DogHealth.h"

using namespace std;


DogHealth::DogHealth()
{
	cout << "Dog's name: ";
		getline(cin,dogName);
	cout << "Dog Age: ";
		cin >> dogAge;

	weightArray = new float[12];
	heartRateArray = new int[12];


	for (int i = 0; i < 12; i++)
	{
		cout << dogName << "'s weight for month " << i+1 << ": ";
			cin >> weightArray[i];
		cout << endl;
		
		cout << dogName << "'s heart rate for month " << i+1 << ": ";
			cin >> heartRateArray[i];
		cout << endl;		
	}

}

DogHealth::~DogHealth()
{

 delete[] weightArray;
 delete[] heartRateArray;
 
}


void DogHealth::printDogHealth()
{
	cout << "Name: " << this->dogName << endl;
	cout << "Age: " << this->dogAge << endl;

	cout << "\n---Weight & Heart Rate---\n\n";

	for (int i  = 0; i < 12; i++)	
	{
		cout << dogName << "'s weight for month " << i+1 << ": " << this->weightArray[i] << endl;
	}

	cout << "\n---Heart Rate---\n\n";

	for (int i  = 0; i < 12; i++)
	{
		cout << dogName << "'s heart rate for month " << i+1 << ": " << this->heartRateArray[i] << endl;
	}
}


void DogHealth::printWeightStatistics()
{
	cout << endl;
	ArrayHelper<float>* arrayHelper = new ArrayHelper<float>(weightArray,12);

		cout << "Weight Statistics" << endl;
		cout << "-------------------------------------------" << endl;
		cout << dogName << " had the highest weight in month " << arrayHelper->getMax() + 1 << " at " << weightArray[arrayHelper->getMax()] << endl;
		cout << dogName << " had the lowest weight in month " << arrayHelper->getMin() + 1 << " at " << weightArray[arrayHelper->getMin()] << endl;

		cout << dogName << "'s average weight over one year was " << arrayHelper->getAvg() << endl;

}
 
void DogHealth::printHeartRateStatistics()
{
	cout << endl;
	ArrayHelper<int>* arrayHelper = new ArrayHelper<int>(heartRateArray,12);

	cout << "Heart Rate Statistics" << endl;
	cout << "-------------------------------------------" << endl;

	cout << dogName << " had the highest resting rate in month " << arrayHelper->getMax() + 1 << " at " << heartRateArray[arrayHelper->getMax()] << " beats per minute" << endl;
	cout << dogName << " had the lowest resting rate in month " << arrayHelper->getMin() + 1 << " at " << heartRateArray[arrayHelper->getMin()] << " beats per minute" << endl;

	cout << dogName << "'s average resting heart rate over one year was " << arrayHelper->getAvg() << endl;
}