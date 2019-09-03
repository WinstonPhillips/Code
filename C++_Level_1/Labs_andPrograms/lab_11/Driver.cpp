/*
  Winston Phillips
  T00212039
  11/15/2017
*/
#include <iostream>
#include <cstdlib>
#include "Permutations.h"

using namespace std;



int main()
{
  seedRandom();   // call random function
 
  int permuteSize;
  int cardChosen;

   cout << "How many cards are in your deck?";
    cin >> permuteSize;

  int* myArray = new int[permuteSize];
  myArray = initPermutation(permuteSize);   // initialize array to permuteSize
  
  
  cout << "Number of cards in deck: " << permuteSize << endl;
  cout << endl;
  
  do{
    
    
  cardChosen = nextPermutation(myArray,permuteSize);
  
  cout << "Chosen Card: " <<  cardChosen << endl;
  
  
  }while(permuteSize != 0);   // while we still have cards in the deck
  
}




