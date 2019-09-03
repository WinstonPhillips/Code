/*
	Winston Phillips
	3/1/2018
*/
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <ctime>
using namespace std;

//function prototypes for the recursive functions
int sumOfNumbers(int num);
bool isMember(int* array, int valueToSearch, int size);
void stringReverse(string userString, int size);
bool isPalindrome(string userString);
int multiply(int num1, int num2);

const int ARRAY_SIZE = 10;

int main()
{
	int choice, num, num1, num2;
	int myArray[ARRAY_SIZE];
	srand(time(NULL));
	string userString, userStrWithoutSpaces;
	
	do{
		
		cout << "\n\nWhat do you want to do?\n";
		cout << "\t1.  Sum of Numbers\n";
		cout << "\t2.  IsMember Array Function\n";
		cout << "\t3.  String Reverser\n";
		cout << "\t4.  Palindrome Detector\n";
		cout << "\t5.  Recursive Multiplication\n";
		cout << "\t6.  End the Program\n";
		cout << "CHOOSE 1-6:  ";
		cin >> choice;
		while(choice < 1 || choice > 6)
		{
			cout << "\nInvalid input!  CHOOSE 1-6:  ";
			cin >> choice;
		}
		switch(choice)
		{
			case 1:
				cout << "\n\nSUM OF NUMBERS\n";
				cout << "Enter an integer:  ";
				cin >> num;
				cout << "Sum of integer: " << sumOfNumbers(num) << endl;
				break;
				
				
			case 2:
				for(int x=0; x<ARRAY_SIZE; x++)
				{
					myArray[x] = (rand()%100)+1;
				}
				cout << "\n\nISMEMBER ARRAY FUNCTION\n";
				cout << "Enter an integer:  ";
				cin >> num;
				cout << "\nHere are the array values:  ";
				for(int x=0; x<ARRAY_SIZE; x++)
				{
					cout << myArray[x] << " ";
				}


				if (isMember(myArray, num, ARRAY_SIZE))
				{
					cout << endl;
					cout << "Yes! " << num << " is in the array!" << endl;
				}	

				else
				{
					cout << endl;
					cout << "No! " << num << " is NOT in the array!" << endl;
				}			
				
				break;
				
				
			case 3:
				cout << "\n\nSTRING REVERSER\n";
				cout << "Enter a string and I will reverse it:  ";
				cin.ignore();
				getline(cin, userString);
				stringReverse(userString, userString.length());
				
				break;
				
				
			case 4:
				cout << "\n\nPALINDROME DETECTOR\n";
				cout << "Enter a string and I will tell you if it is a palindrome:  ";
				cin.ignore();
				getline(cin, userString);
				
				//change string to be all uppercase
				for(int x=0; x<userString.length(); x++)
				{
					userString[x] = toupper(userString[x]);
				}
				
				//remove spaces from string
				userStrWithoutSpaces = userString;
				for(int x=0; x<userStrWithoutSpaces.size(); x++)
				{
					if(userStrWithoutSpaces[x] == ' ') 
						userStrWithoutSpaces.erase(x, 1);
				}
				
				//print out whether the user's string is a palindrome or not here.
				//when you print out the user's string, print out the uppercase version that doesn't have the spaces removed.
				

				if (isPalindrome(userStrWithoutSpaces) == true)
				{
					cout << "\n" << userStrWithoutSpaces << " is a palindrome!" << endl;
				}
				else 
				{
					cout << "\n" << userStrWithoutSpaces << " is NOT a palindrome" << endl;
				}
								
				break;
				
				
			case 5:
				cout << "\n\nRECURSIVE MULTIPLICATION\n";
				cout << "Enter in the first integer:  ";
				cin >> num1;
				cout << "\nEnter in the second integer:  ";
				cin >> num2;
				cout << "Solution: " << multiply(num1,num2) << endl;
				
				break;
				
		}		
	}while(choice != 6);
	
	cout << "\n\nGOODBYE!\n\n";
	return 0;
}


//implement the five recursive functions below!!!!

int sumOfNumbers(int num)
{
	if (num == 1)
	{
		return 1;
	}
	else 
	{
		return sumOfNumbers(num -1) + num;
	}
}

bool isMember(int* array, int valueToSearch, int size)
{
	if (size < 0)
	{
		return false;
	}
	else if (array[size-1] == valueToSearch)
	{
		return true;
	}
  	else
	{
		isMember(array, valueToSearch, size-1);
	}
}

void stringReverse(string userString, int size)
{
	if (size < 0)
	{
		return;
	}
	else 
	{
		cout << userString[size-1];
		stringReverse(userString, size-1);
	}
	cout <<  endl;
}

bool isPalindrome(string userString)
{

 	if (userString.length() <= 1)
 	{
 		return true;
 	}

 	else if (userString[0] == userString[userString.length()-1])
 	{
 		string newString;
 		newString.resize(userString.length()-2);
 		
	 	for (int i = 0; i < userString.length()-2; i++)
	 	{
	 			newString[i] = userString[i+1];
	 	}
	 	
 		return isPalindrome(newString);
	}

	else if (userString[0] != userString[userString.length()-1])
	{
		return false;
	}
}

int multiply(int num1, int num2)
{
	if (num2 == 0)
	{
		return 0;
	}
	else 
	{
		return multiply(num1,num2-1) + num1;
	}
}









