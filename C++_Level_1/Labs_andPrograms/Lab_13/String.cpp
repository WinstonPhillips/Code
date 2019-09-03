#include <iostream>
#include <cstring>
#include "String.h"

using namespace std;

String* createString(char* charArray)
{

	int i = 0;
	
	String* newString = new String;

	while( i != 100)	// to get size
	{
		if (charArray[i] == '\0')
		{
			break;
		}
		i++;
	}
	
	newString->size = i;

	newString->text = charArray;

	return newString;

}

void displayString(String* str)
{
		cout << str->text;
		cout << endl;
}

void destroyString(String* str)
{
	delete str;
}

int find(String* str, char delimiter, int startIndex)
{
	int size = str->size;
	int index;	// value to be returned 
	bool foundMatch = false;

	for (int i = startIndex; i < size; i++) 
	{
		if (str->text[i] == delimiter)
		{
			foundMatch = true;
			index = i;
			break;
		}
	}
	if (foundMatch)
	{
		return index;
	}
	else
	{
		cout << "No match found." << endl;
		return -1;
	}
}

String* substr(String* str, int start, int end)
{
	String* substr = new String;
	int j = 0;

	for(int i = start; i <= end; i++)
	{
		substr->text[j] = str->text[i];
		j++;
	}

		substr->size = j;

		return substr;
}

int compare(const String* str1, String* str2)	
{

	int size = str1->size;

	if (str1->size > str2->size)
	{
		size = str2->size;
	}
	 

	for(int i = 0; i < size; i++)	// for making a copy string 
	{
		if(str1->text[i] > str2->text[i]){
			return 1;
		}else if(str2->text[i] > str1->text[i]){
			return -1;
		}
	}

	if(str1->size == str2->size){
		return 0;
	}else if (str1->size > str2->size){
		return 1;
	}else{
		return -1;
	}
}

