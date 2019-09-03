/*
	Winston Phillips
	Date: 2/22/2018
*/

#include <iostream>
#include <string>
#include <stdlib.h>

#include "Stack.h"
#include "Queue.h"

using namespace std;

double calculateExpression(string expression);
bool isLowerPriority(char first, char second);	// will come back and rename

int main()
{
	char userChar;	// for input validation
	int counter = 0; // for dummy string 
	char ass;
	
	do
	{

	string tempExpression;

	if(counter > 0)
	{
		getline(cin, tempExpression);
	}

	if (counter == 0)
	{
	cout << "\nWelcome to Infix to Postfix Converter!" << endl;
	}


	cout << "\nPlease enter the expression you wish to convert:";
		getline(cin,tempExpression);

	string expression;

	int numSpaces = 0;

	for (int i = 0; i < tempExpression.length(); i++)		
	{
		if (tempExpression[i] == ' ')
		{
			numSpaces++;	// count number of spaces
			//expression[i] = tempExpression[i];
		}
	}

	expression.resize(tempExpression.length() - numSpaces);
	
	int y = 0;

	for (int i = 0; i < tempExpression.length(); i++)		
	{
		if (tempExpression[i] != ' ')
		{
			
			expression[y] = tempExpression[i];
			y++;
		}
	}

	cout << "\nExpression in infix notation: ";

	for (int i = 0; i < expression.length(); i++)
	{
		cout << expression[i] << " ";
	}
	cout << endl;


	Stack<char> opstack;
	Queue<char> postfix;
	int x = 0;

	

	for (int i = 0; i < expression.length(); i++)
	{

		if (expression[i] == '(')
		{
			opstack.Push('(');
		}

		else if (expression[i] == ')')
		{
			while(opstack.Peek() != '(')	
			{
				char tempChar = opstack.Pop();
				postfix.Push_back(tempChar);
				
			}
			char dummyChar = opstack.Pop();

			x = x+2;
		}

		else if (expression[i] == '*'  || expression[i] == '/' || expression[i] == '+' || expression[i] == '-')
		{
			if (opstack.isEmpty() == true)
			{
				opstack.Push(expression[i]);
			}
			else if (isLowerPriority(opstack.Peek(), expression[i]))
			{
				opstack.Push(expression[i]);
			}
			else
			{
				
					char tempValue = opstack.Pop();

					postfix.Push_back(tempValue);

					opstack.Push(expression[i]);
			
			}
	
		}

		else
		{
			postfix.Push_back(expression[i]);
		}

	}
		while(!opstack.isEmpty())
		{
			char tempValue = opstack.Pop();

			postfix.Push_back(tempValue);
		}


		string expressionTosend = " ";

		
	 expressionTosend.resize(expression.length()-x);

			
		for(int i = 0; i < expressionTosend.length(); i++)
		{
			expressionTosend[i] = postfix.Pop_front();
		}



		cout << "Expression in Postfix Notation: "; 

		for (int i = 0; i < expressionTosend.length(); i++)
		{
			cout << expressionTosend[i] << " ";
		}

		cout << "\nSolution: " << calculateExpression(expressionTosend) << endl << endl;

		cout << "Do you wish to enter another expression?(Y/N): ";
			cin >> userChar;

			counter++;


	}while(userChar == 'y' || userChar == 'Y');

	cout << "\n\n";

	cout << "Good Bye! Live long and prosper!" << endl;

}

bool isLowerPriority(char first, char second)
{
	int firstNum;
	int secondNum;

	if (first == '(')
	{
		firstNum = 0;
	}
	else if (first == ')')
	{
		firstNum = 3;
	}
	else if (first == '*' || first == '/')
	{
		firstNum = 2;
	}
	else if (first == '+' || first == '-')
	{
		firstNum = 1;
	}


	if (second == '(')
	{
		secondNum = 0;
	}
	else if (second == ')')
	{
		secondNum = 3;
	}
	else if (second == '*' || second == '/')
	{
		secondNum = 2;
	}
	else if (second == '+' || second == '-')
	{
		secondNum = 1;
	}


	if (firstNum < secondNum)
	{
		return true;
	}

	else 
	{
		return false;
	}
}

double calculateExpression(string expression)
{
	
	Stack<double> numStack;

	for (int i = 0; i < expression.length(); i++)
	{
		
		if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
		{

			if (expression[i] == '+')
			{
				double num1 = numStack.Pop();
				double num2 = numStack.Pop();

				double numberToPush = num1 + num2;

				numStack.Push(numberToPush);
			}

			else if (expression[i] == '-')
			{
				double num1 = numStack.Pop();
				double num2 = numStack.Pop();

				double numberToPush = num2 - num1;

				numStack.Push(numberToPush);
			}

			else if (expression[i] == '*')
			{
				double num1 = numStack.Pop();
				double num2 = numStack.Pop();

				double numberToPush = num1 * num2;

				numStack.Push(numberToPush);
			}

			else if (expression[i] == '/')
			{

				double num1 = numStack.Pop();
				double num2 = numStack.Pop();

				double numberToPush = num2 / num1;

				numStack.Push(numberToPush);
			}

		}
		else
		{
			double x = expression[i] - 48;

			numStack.Push(x);
		}	
	}

	double answer = numStack.Pop();

	return answer;

}