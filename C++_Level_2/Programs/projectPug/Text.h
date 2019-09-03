#ifndef TEXT_H
#define TEXT_H

#include <iostream>

using namespace std;

class Text	// text class so that we display our own text and destroy when needed
{
	private:
		const char* textArray;		// pointer so we can delete for cleanup
	public:
		Text(const char* sentText);
		~Text();
		void displayText();
};

#endif