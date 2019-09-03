#include "Computer.h"	// using functions 

using namespace std;

int main()
{
	Computer* asusS3 = createComputer("Asus S3",899.99,7);
	Computer* macbookAir = createComputer("Macbook Air",1299.99,7);
	Computer* lnvThink = createComputer("Lenovo ThinkPad",499.99,3);

	Monitor* alienwareMon = createMonitor("AlienWare Shit Bucket", 899.99, 32, 28);
	Monitor* toshibaMon = createMonitor("Toshiba Windspeed", 499.95, 28, 22);
	Monitor* asusMon = createMonitor("Toshiba D420", 349.99, 26, 21);

	displayComputer(asusS3);
	displayComputer(macbookAir);
	displayComputer(lnvThink);

	displayMonitor(alienwareMon);
	displayMonitor(toshibaMon);
	displayMonitor(asusMon);



}