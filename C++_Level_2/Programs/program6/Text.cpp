/*
	Title:  Text.cpp
	Author:  Mark Boshart, modified by April Crockett
	Date:  11/7/2017
	About:  A structure version of the C++ string class
*/

#include "Text.h"

using namespace std;

Text::Text(const char* text)
{
	
	textLength = strlen(text);	// copy length of received text to textLength
	

	char* tempTextArray = new char[(textLength+1)];		// allocate memory for a temporary text array and make it's length equal to the previous text
	
	strcpy(tempTextArray, text);			// copy received text to tempTextarray 
	

	textArray = tempTextArray;		// make this movie's text array equal to tempTextArray
	
	
}

Text::~Text()  // destructor, in place of destroy function
{
	delete[] this->textArray;	//delete the character array from memory
}

void Text::displayText()
{
	
	cout << this->textArray;		//print out the c-string
}

/********************* Accessor Functions ***********************/

const char* Text::getText()
{
	return textArray;
}

int Text::getLength()
{
	return textLength;
}

/****************************************************************/