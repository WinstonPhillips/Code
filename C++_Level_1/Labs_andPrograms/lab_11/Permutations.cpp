#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void seedRandom()	// initialize random function
{
  srand(time(0));
}

int* initPermutation(int n)		// initialize array to whatever size user inputs
{
  int* myArray = new int[n];
  for (int i = 0; i < n; i++)
  {
    myArray[i] = i+1;
  }
  return myArray;
}

void removePermutation (int* permutation, int permuteSize, int removeIndex)	//
{
  
  for (int i = removeIndex; i < permuteSize; i++)	// from the random index, we will shift everything in array to the left one index
  {
    permutation[i] = permutation[i+1];
  }
  
}

int nextPermutation (int* permutation, int& permuteSize)	// chooses a random index to remove and sets the value (or card) at that index to be returned as card chosen
{
  int removeIndex;											
  int cardChosen;
   removeIndex = 0 + rand() % permuteSize;
   
   cardChosen = permutation[removeIndex];
   
   permuteSize--;	// to reduce the size of array so that we may have one less element 
  
   removePermutation(permutation,permuteSize,removeIndex);	// removes the random index's value from the array

  return cardChosen;
}