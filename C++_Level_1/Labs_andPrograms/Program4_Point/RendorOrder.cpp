/*
	Winston Phillips
	T00212039
	11/27/2017
*/
#include <string>
#include <fstream>
#include <iostream>
#include <cmath>
#include "Points.h"
#include "BasicSort.h"

using namespace std;

float distanceFromRefPoint (Point* p, Point* refPoint)
{
 	float distance;

 	distance = (((p->X)-(refPoint->X))*((p->X)-(refPoint->X)))+ (((p->Y)-(refPoint->Y))*((p->Y)-(refPoint->Y))) + (((p->Z)-(refPoint->Z))*((p->Z)-(refPoint->Z)));

 	return distance;
}

void sortPointsByDistance (Points* p, float* distanceArray, int size)
{
	selectionSort(p, size, distanceArray);

}






int main(int argc, char* argv[])
{
/**********************Variables*******************************/
	string fileName = argv[1];	// designates filename from command line argument
	ifstream inFile;
	float distance;
	

	double x = (double)*argv[2] - 48;	// obtains coordinate x for reference point
	double y = (double)*argv[3] - 48;	// obtains coordinate y for reference point
	double z = (double)*argv[4] - 48;	// obtains coordinate z for reference point

	
/**************************************************************/

inFile.open(fileName.c_str());

		if(!inFile)	// input validation
		{
			cout << "Invalid input" << endl;
			cout << "Example of correct input: program name _ filename_XCoordinate_YCoordinate_ZCoordinate" << endl;
			cout << "Program Terminated" << endl;
			return -1;
		}
	inFile.close();

	Point* refPoint = createPoint(x,y,z);	// establishes reference point

	cout << endl;
	cout << "Reference Point: ";
    displayPoint(refPoint);
    cout << endl;

	Points* myPoints = createPoints(fileName);		// create a new points named mypoints

	cout << "Unsorted" << endl;
	cout << "--------" << endl;

	displayPoints(myPoints);		// displays unsorted points

	float* distanceArray = new float[myPoints->size];

	for (int i = 0; i < myPoints->size; i++)
	{
		distance = distanceFromRefPoint(myPoints->Points[i] , refPoint);	// gets distance between points
		distanceArray[i] = distance;		// adds distance to distance array that is used in basic sort
	}
	
	sortPointsByDistance(myPoints,distanceArray,myPoints->size);	//calls basic sort 

	cout << endl;
	cout << "Sorted" << endl;
	cout << "------" << endl;

	displayPoints(myPoints);	// display sorted points

	destroyPoints(myPoints);	// clean up

	delete[] distanceArray;		// clean up
	


}