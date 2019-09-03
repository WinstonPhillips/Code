#ifndef ARRAYHELPER_H
#define ARRAYHELPER_H

using namespace std;

template<typename Type>

class ArrayHelper
{
	private: Type* typeArray;	// array to hold data for later functions
			 int numElements;	// number of elements in typeArray
			 /*
			Function Name: GetTotal()
			Parameters: none
			Return: a variable of type Type
			Task: calculates total of all elements in tyepeArray
			*/
			 Type getTotal();	

	public:
			/*
			Function Name: ArrayHelper() -> constructor
			Parameters: an array of any type, an integer that sets the size of typeArray
			Return:	none
			Task: a constructor for the ArrayHelper class
			*/
			 ArrayHelper(Type* sentArray, int num);
			 /*
			Function Name: ~ArrayHelper();
			Parameters: None
			Return:None
			Task: a destructor for the ArrayHelper class
			*/
			 ~ArrayHelper();
			 /*
			Function Name: getMax();
			Parameters:	none
			Return:	integer 
			Task: returns the index of the largest number contained in typeArray
			*/
			 int getMax();
			 /*
			Function Name: getMin();
			Parameters: none
			Return: integer
			Task:  returns the index of the largest number contained in typeArray
			*/
			 int getMin();
			  /*
			Function Name:	getAvg();
			Parameters:	none
			Return: float 
			Task:  calculates the average of all elements int typeArray
			*/
			 float getAvg();
};


#endif
