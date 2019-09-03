#include "Points.h"


using namespace std;


void selectionSort (Points* p, int size, float* array)
{
	int min;
	int swap;
	Point* point = new Point;;
	
	for (int i = 0; i < size; i++)
	{
		min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (array[j] > array[min])
			{
				min = j;
			}
		}

		swap = array[min];			// changes reference array
		array[min] = array[i];
		array[i] = swap;	

		point = p->Points[min];		// next three lines are used to arrange the myPoints
		p->Points[min] =  p->Points[i];
		p->Points[i] = point;
	}
}