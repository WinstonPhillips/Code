#include <iostream>
#include <limits>

using namespace std;

int main() {
    int num = 0;
    
    
    
    do
    {
        cout << "Enter a number between 1 and 10" << endl;
        try
        {
          
        cin >> num;
        if(cin.fail()){
          throw ' ';
        }
          if(!isspace(cin.peek()))
          {
            throw &num; // throwing the address of num
          }
        
        }catch(char c)
          {
            cout << "Non-integer value. Please enter a number." << endl;
            cin.clear();                                  // reset error flags
            cin.ignore(numeric_limits<int>::max(), '\n');        // clear buffer
          }
        catch(int* numPtr)
        {
          cout << "Non-integer value. You entered something after " << *numPtr << "." << endl;
          cin.clear();                                  // reset error flags
          cin.ignore(numeric_limits<int>::max(), '\n');

          *numPtr = 0;      // reset num to its initial value
        }

        
    } while (num < 1 || num > 10);
    
    cout << "Value " << num << " correctly entered! Thank you." << endl;
}
