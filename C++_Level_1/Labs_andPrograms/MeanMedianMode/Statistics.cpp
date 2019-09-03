#include <iostream>
#include "Statistics.h"
#include "BasicSort.h"

using namespace std;

int findMode (int* originalArray, int size)
{
  int mode; // value to be returned 
  int numMatches;	// number of matches
  int counter = 0; // used to help figure the mode in for loop

  int* copyArray = new int[size]; // copy array

  for (int i = 0; i < size; i++)	// makes copy of array
  {
  	copyArray[i] = originalArray[i];
  }

  for (int i = 0; i < size; i++)	// searches through both arrays to find matches
  {
  	
  	numMatches = 0;  // reset num matches

  	for (int j = 0; j < size; j++)
  	{

  		if (originalArray[i] == copyArray[j])
  		{
  			numMatches++;
  		}

  	}
  	if (numMatches > counter)	// if this is the most matches made thus far
  	{
  		mode = originalArray[i];
  		counter = numMatches;
  	}
  }

  delete[] copyArray;	// cleanup old array

  return mode;
}


float findMedian (int* numbers, int size)
{
	float median = 0.0;	// value to be returned 

	int* sortedArray = new int[size];	// arrayy to be sent to basic sort function

	for(int i = 0; i < size; i++)	// making a copy of the original array
	{
		sortedArray[i] = numbers[i];
	}

	selectionSort(sortedArray,size);	// passing to basic sort, changing ssorted array and not our original

	
	if(size %2 != 0)	// if size is odd
	{
		median = static_cast<float>(sortedArray[((size+1)/2) - 1]);
	}
	else 				// if size is even
	{
		median = static_cast<float>( (sortedArray[size/2] + sortedArray[(size/2) -1]) /2.0 );
	}

	delete[] sortedArray;	// cleaning up

	return median;
}

float findMean (int* numbers, int size)
{
	float total = 0.0;
	float mean;

	for (int i = 0; i < size; i++)	// calculating total of all elements in array
	{
		total = total + numbers[i];
	}

	mean = total/static_cast<float>(size);	// calculates average of all elements 

	return mean;

}

