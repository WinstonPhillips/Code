// basic file operations
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main () {
  ofstream myfile;		// writes to a file
  
  
  int x=5;
  myfile.open ("example.txt");
  myfile << x;
  myfile << "\n this too";
  myfile.close();
/********************************************/

  
  int outputInt;
  ifstream outputFile;  // reads from a file
  outputFile.open("score.txt");
  while ( getline("score.txt", outputInt) )
  {
  	outputFile >> outputInt; 
  }
  
  outputFile.close();


  



  return 0;
}