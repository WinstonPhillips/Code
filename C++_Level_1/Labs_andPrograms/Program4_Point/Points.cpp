#include <iostream>
#include <fstream>
#include <string>

#include "Points.h"

using namespace std;

Points* createPoints(const string fileName)
{
	ifstream inFile; // writing from a file
	int numPoints;
	double x,y,z; // points to be passed to create point

	inFile.open(fileName.c_str());

		

	inFile >> numPoints;		// get number of points for loop

	Points* newPoints = new Points;		// create a new pointS. Only need one of these

	newPoints->Points = new Point*[numPoints];		// the array of points, located at struct of newpoint, will be composed of numPoints of type point

	Point* p = new Point; 	// declaring a new point. Will need multiple to fill Point

	newPoints->size = numPoints;		// sets size (int) of struct to numPoints

	


	for (int i = 0; i < numPoints; i++)		// creating all points for points array
	{
		inFile >> x;
		inFile >> y;
		inFile >> z;

		p = createPoint(x,y,z);
		newPoints->Points[i] = p;	// puts point into ith subscript of Points

	}


	inFile.close();

	return newPoints;

}

void displayPoints(Points* p)
{
	for (int i = 0; i < p-> size; i++)
	{
		displayPoint(p->Points[i]);
	}
}

void destroyPoints(Points* p)
{
	for (int i = 0; i < p->size; i++)
	{
		destroyPoint(p->Points[i]);
	}

	delete[] p->Points;
}