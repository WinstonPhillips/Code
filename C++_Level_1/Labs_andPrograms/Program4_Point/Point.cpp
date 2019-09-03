#include <iostream>
#include <iomanip>
#include "Point.h"


using namespace std;

Point* createPoint(double x, double y, double z)
{
	Point* newPoint = new Point;

	newPoint->X = x;
	newPoint->Y = y;
	newPoint->Z = z;

	return newPoint;


}

void displayPoint(Point* p)
{
	if(p->X > 0)
	{
		cout << setprecision(3) << fixed << "( " << setw(4) << p->X;
	}
	else 
	{
		cout << setprecision(3) << fixed << "(" << setw(4) << p->X;
	}

	if(p->Y > 0)
	{
	cout << setprecision(3) << fixed << ", " << setw(4) << p->Y;
	}
	else 
	{
		cout << setprecision(3) << fixed << "," << setw(4) << p->Y;
	}

	if(p->Z > 0)
	{
		cout << setprecision(3) << fixed << ", " << setw(4) << p->Z;
	}
	else 
	{
		cout << setprecision(3) << fixed << "," << setw(4) << p->Z;
	}
	cout << ")" << endl;
	
}

void destroyPoint(Point* p)
{
	delete p;
}