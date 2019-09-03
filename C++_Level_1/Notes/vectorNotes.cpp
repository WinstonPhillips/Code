#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int myArray [20];
	vector<int> myVector (20,6);  		// 20 elements (all ints) in vecto, all are a 6
	vector<int> myOtherVector (myVector);	// 20 elements (all ints) in vecto, all are a 6 (Ditto)
	vector<int> myThirdVector {10,20,30,40};	// elements are 10,20,30,40
	vector<int> myFourthVector;					// has no elements



	myOtherVector.push_back(30);



	for (int i = 0; i < 20; i++)
	{
		cout << myOtherVector[i]<< " ";
	}

}