#include <iostream>

#include "ArrayHelper.h"

using namespace std;
// help: is this right?
template<typename Type>
ArrayHelper<Type>::ArrayHelper(Type* sentArray, int num)
{
	numElements = 0;		//initialize number of elements of ArrayHelper's array to 0

	typeArray = new Type[num];

	for (int i = 0; i < num; i++)
	{
		typeArray[i] = sentArray[i];

		numElements++;

	}
}

template<typename Type>
ArrayHelper<Type>::~ArrayHelper()
{
	delete[] typeArray;
}

template<typename Type>
int ArrayHelper<Type>::getMax()
{
	int indexToReturn = 0;
	int maxNumber = 0;

	for (int i = 0; i < numElements; i++)
	{
		if (typeArray[i] > maxNumber)
		{
			maxNumber = typeArray[i];
			indexToReturn = i;
		}
	}
	return indexToReturn;
}

template<typename Type>
int ArrayHelper<Type>::getMin()
{
	int indexToReturn = 0;
	int minNumber = 500;

	for (int i = 0; i < numElements; i++)
	{
		if (typeArray[i] < minNumber)
		{
			minNumber = typeArray[i];
			indexToReturn = i;
		}
	}
	return indexToReturn;
}

template<typename Type>
Type ArrayHelper<Type>::getTotal()		// in private
{
	Type total;
	for (int i = 0; i < numElements; i++)
		{
			total = total + typeArray[i];
		}

	return total;
}

template<typename Type>
float ArrayHelper<Type>::getAvg()
{
	Type total = getTotal();
	float average = static_cast<float> (total) / static_cast<float>(numElements);

	return average;
}

