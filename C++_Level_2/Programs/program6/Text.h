/*
	Title:  Text.h
	Author:  Mark Boshart, modified by April Crockett
	Date:  11/7/2017
	About:  A structure version of the C++ string class
*/

#ifndef TEXT_H
#define TEXT_H

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

class Text
{
private:
	const char* textArray;		// text Array that stores cstring 
	int textLength;				// length of text

public:
/*
	Function Name:  Text() = overloaded constructor
	Parameters:  Send a pointer to a constant character array or a string literal to this function
	Returns: none
	Purpose:  To create a new Text variable
*/
Text(const char* text);

/*
	Function Name:  ~Text()
	Parameters:  Send a pointer to a Text variable, which contains a c-string & length of the string
	Returns:  nothing (void)
	Purpose:  release dynamically allocated memory that the pointer is pointing to.
*/
~Text();

/*
	Function Name:  displayText()
	Parameters:  none
	Returns:  nothing (void)
	Purpose:  prints out the string (character array)
*/
void displayText();

/*
	Function Name:  getText()
	Parameters: none 
	Returns:  nothing
*/
const char* getText();

/*
	Function Name:  getLength()
	Parameters:  none
	Returns:  nothing
*/
int getLength();

};


#endif