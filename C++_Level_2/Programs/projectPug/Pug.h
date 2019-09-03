#ifndef PUG_H
#define PUG_H

#include <iostream>
#include "Text.h"

using namespace std;

class Pug 
{
		private:
				Text* pugName;
				int pugAge;
				float pugWeight;
				Text* Status;
		public:
				Pug(Text* name, int age, float weight);
				~Pug();
				Text* getPugName();
				int getPugAge();
				float getPugWeight(); 
				void displayPugDetails();
};

#endif