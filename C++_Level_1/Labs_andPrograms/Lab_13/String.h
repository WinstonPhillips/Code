#ifndef STRING_H
#define STRING_H

using namespace std;

struct String 
{
	char* text;
	int size;
};

int find (String* str, char delimiter, int startIndex);

String* substr (String* str, int start, int end);

int compare (const String* str1, String* str2);

String* createString(char* charArray);

void displayString (String* str);

void destroyString (String* str);

#endif