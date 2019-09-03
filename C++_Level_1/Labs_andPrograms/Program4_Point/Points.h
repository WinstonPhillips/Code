#ifndef POINTS_H
#define POINTS_H

#include <string>
#include "Point.h"

using namespace std;

struct Points
{
	Point** Points;
	int size;
};

Points* createPoints(const string fileName);
void displayPoints(Points* p);
void destroyPoints(Points* p);

#endif

