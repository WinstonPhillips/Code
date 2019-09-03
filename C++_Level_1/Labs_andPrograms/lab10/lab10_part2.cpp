#include <iostream>
#include <limits> // lib used for nhumeric value
#include <fstream>

using namespace std;

int main() {
    int total = 0;
    int num = 0;
    
    ifstream inputFile;
    
    inputFile.open("inFile.txt");


    while(!inputFile.eof()) 
    {   // until we have reached the end of the file
        try
        {
            inputFile >> num;
             if(inputFile.fail())
             {
                throw ' ';
             }   

            if( !( inputFile.eof() || isspace(inputFile.peek()) ) ) 
            {
                     throw &num;
            }
            
        }
            catch(char x)   // library that automatically handles most exceptions
                {
                    cout << "Skipping non-integer value" << endl;
                    inputFile.clear();                                  // reset error flags
                    inputFile.ignore(numeric_limits<int>::max(), '\n');     // to ensure an integer 
            
                }
            catch(int* numPtr)
            {

                cout << "Non-integer value. You entered something after " << *numPtr << "." << endl;
                inputFile.clear();                                  // reset error flags
                inputFile.ignore(numeric_limits<int>::max(), '\n'); // making an integer

                *numPtr = 0;      // reset num to zero so that it is not counted in the total brooooo

            }

            total += num;
    }
    
    inputFile.close();
    
    cout << "The total value is " << total << "." << endl;
}