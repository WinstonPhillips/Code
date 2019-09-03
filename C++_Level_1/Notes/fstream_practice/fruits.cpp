#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	ifstream inFile;		// fstream is a class, we are creating an object of the fstream class

	inFile.open("fruits.txt");			// just like using classes!!

	//checking for an error

	if (inFile.fail())		// fail is a func that sees if file exists
	{
		cerr << "Error Opening File";	// cerr = used for error messages
		return 1;
	}
	//printing the info

	string x,y,z;

	inFile >> x >> y >> z; 		//automatically assigns x and y to first 2 values. ">>" actually automatically skips lines

	cout << x << "\n" << y << "\n" << z;



}