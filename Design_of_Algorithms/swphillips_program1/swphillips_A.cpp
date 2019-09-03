/* Written by Winston Phillips */

#include <iostream>
#include <cstdlib>

using namespace std;

int gcd(int num1, int num2)
{
	if ((num1 % num2) == 0)
	{
		return num2;
	}
	else 
	{
		gcd(num2,num1%num2);
	}
}

int main(int argc, char* argv[])
{
	int num1 = atoi(argv[1]);	// to integer
	int num2 = atoi(argv[2]);

	if (num1 == 0 && num2 == 0)
		{
			cout << "gcd(" << num1 << ", " << num2 << ") is undefined" << endl;

		}
	else if (!num1 || !num2)
		{
			cout << "Incorrect format. Correct: filename.exe num1 num2" << endl;
			cout << "No Zeros!" << endl;
		}
	else 
		{
			cout << "gcd(" << num1 << "," << num2 << ") = " << gcd(num1, num2);
		}
}