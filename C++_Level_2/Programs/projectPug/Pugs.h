#ifndef PUGS_H
#define PUGS_H

#include <iostream>
#include "Pug.h"

using namespace std;

class Pugs
{
		private:
				Pug** pugsArray;
				int arrayMax;
				int numPugs;
		public:
				Pugs(int max);
				~Pugs();
				void displayPugs();
				void removePug();
				void addPug();
				void resizeArray();

};

#endif