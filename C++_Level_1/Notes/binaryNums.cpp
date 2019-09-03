#include <cmath>
#include <iostream>

using namespace std;

int getArraySize(int userNum)
{
  int arraySize = (log(userNum+1)) / log(2);
  arraySize = arraySize + 1;
  return arraySize;
}

int main()
{
  int userNum;
  int arraySize;
  
  
  cout << "Number: ";
    cin >> userNum;
    arraySize = getArraySize(userNum);
  
    int* array = new int[arraySize];
    
    for (int i = arraySize-1; i>=0; i--) 
    {
      array[i] = userNum %2;
      userNum = userNum/2;
    }
    
    for (int i = 0; i < arraySize; i++)
    {
      cout << array[i];
    }
    
  
    
}
