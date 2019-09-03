#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void seedRand()
{
	srand(time(0));
}

void randomInt1(int &num1)
{
	num1 = 1 + rand()% (999);
}

void randomInt2(int &num2)
{
	num2 = 1 + rand()% (999);
}