#ifndef POINT_H
#define POINT_H

using namespace std;

struct Point
{
	double X;
	double Y;
	double Z;
};

Point* createPoint(double x, double y, double z);
void displayPoint(Point* p);
void destroyPoint(Point* p);

#endif