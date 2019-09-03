#include "DogStuff.h"

using namespace std;

int main()
{
	DogStuff myDog("Rexie");
	
	myDog.appendNode();
	myDog.appendNode();
	myDog.appendNode();

	myDog.removeNode();
	myDog.removeNode();
	myDog.removeNode();
}