/*Written by Winston Phillips T00212039
*/
#include <fstream> // for ifstream object
#include <stdlib.h>

#include "GraphMatrix.h"
#include "Stack.h"

GraphMatrix readFile();
void sort(GraphMatrix matrix);
bool isDag(GraphMatrix matrix);


int main()
{
	GraphMatrix myGraph = readFile();
	myGraph.printGraph(); // for testing
	sort(myGraph);

	return 0;
}

GraphMatrix readFile()
{
	string fileName; // filename inputted from user
	ifstream inFile; // ifstream object for reading from a file
	int vertex1, vertex2, numVertices; // used for adding vertexes to matrix from ifstream object

	cout << "Name of file you wish to open: ";
			cin >> fileName;

	inFile.open(fileName.c_str());

	if (inFile)
	{
		inFile >> numVertices;

		GraphMatrix graph(numVertices); // declare our graph matrix!

			while(!inFile.eof())
			{
				inFile >> vertex1;

				inFile >> vertex2;
				
				graph.addEdge(vertex1,vertex2);
			}

			inFile.close(); // close file

			return graph;
	}

	else
	{
		cout << "Problem opening file... Goodbye" << endl;

		return -1;	// terminate

	}

}

void sort(GraphMatrix matrix)
{
	 Stack<int> stack;
	 bool* isVisited = new bool[matrix.getNumVertices()];
	 int* sortedVertices = new int[matrix.getNumVertices()];
	 int index = matrix.getNumVertices()-1;

		 for(int i = 0; i < matrix.getNumVertices(); i++)
		 {
		 	isVisited[i] = false;
		 	sortedVertices[i]  = -1;
		 }

	 int first = matrix.getFirstVertex();
	 stack.push(first);

	 int vertex; 
	 bool cycle = false;


		 while(!stack.isEmpty())
		 {
		 	stack.peek(vertex); // sets vertex = next item on stack

		 	isVisited[vertex] = true;	// this marks as visisted

		 	bool startover = false;

		 	for (int col = 0; col < matrix.getNumVertices() || startover == true; col++)
		 	{
		 		if(startover == true)
		 		{
		 			col = 0;
		 			startover = false;
		 		}

		 		if(matrix.IsThereAnEdge(vertex,col) == true && isVisited[col] == false)
		 		{
		 			stack.push(col);
		 			isVisited[col] = true;
		 			vertex = col;
		 			startover = true;
		 		}
		 		if(matrix.IsThereAnEdge(vertex,col) == true && isVisited[col] == true && stack.find(col) == true)
		 		{
		 			cycle = true;
		 		}

		 	}

		 	
		 		stack.pop(vertex);

		 		sortedVertices[index] = vertex;
		 		index--;

		 }

		 if(!cycle)
		 {
		 	cout << "Sorted : ";
			 for(int i = 0; i < matrix.getNumVertices(); i++)
			 {
			 	cout << sortedVertices[i] << " ";
			 }
		}
		else
		{
			cout << "\nSorry, Graph has a cycle. Goodbye!" << endl;
		}

}

