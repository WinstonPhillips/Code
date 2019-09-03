#include <iostream>
#include <cstring>
#include "Text.h"

using namespace std;

Text::Text(const char* sentText)
{
	char* tempTextArray = new char[strlen(sentText)];		// will be an array
		strcpy(tempTextArray, sentText);
	textArray = tempTextArray;
}

Text::~Text()
{
	delete[] this->textArray;		// can delete because it is a pointer
}

void Text::displayText()
{
	cout << this->textArray;
}