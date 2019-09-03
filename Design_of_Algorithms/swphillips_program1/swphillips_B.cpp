/* Written by Winston Phillips */

#include <iostream>
#include <cstdlib>

using namespace std;

int gcd(int num1, int num2, int mod)
{
	if (num1 % mod == 0 && num2 % mod == 0)
		{
			return mod;
		}
	else 
		{
			gcd(num1, num2, mod-1);
		}
}

int main(int argc, char* argv[])
{
	int num1 = atoi(argv[1]);	// to integer
	int num2 = atoi(argv[2]);
	int num3;

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
			cout << "gcd(" << num1 << "," << num2 << ") = " << gcd(num1, num2, num2);
		}
}