#include <iostream>
#include <string>

#ifndef GRAPHMATRIX_H
#define GRAPHMATRIX_H

using namespace std;

class GraphMatrix{

	private: 
		int** vertexMatrix;
		int numVertices;
		int numEdges;

	public:

		GraphMatrix(int numVert) // initialize our 2D array
        {
            numVertices = numVert; // set number of vertices we have

            vertexMatrix = new int*[numVertices];

            for(int i = 0; i < numVertices; ++i) // to initialize a 2d array
                vertexMatrix[i] = new int[numVertices];

            for (int i = 0; i < numVertices; i++)
            {
                for (int j = 0; j < numVertices; j++)
                {
                    vertexMatrix[i][j] = 0; // initialiaze position to zero             
                }
            }
        
        }

       ~GraphMatrix() // destructor
        {
        
            for (int i = 0; i < numVertices; i++)
            {
                delete[] vertexMatrix[i];
            }
            delete[] vertexMatrix; 
        }

        void printGraph() // prints our 2D array
        {
            cout << "\nMatrix:\n";
            
            for (int i = 0; i < numVertices; i++)
            {
                for (int j = 0; j < numVertices; j++)
                {
                    cout << vertexMatrix[i][j] << " ";
                }

                cout << endl;
            }
            
        }

        void addEdge(int vert1, int vert2) //adds an edge to our vertexMatrix
        {
            vertexMatrix[vert1][vert2] = 1;
        }

        bool IsThereAnEdge(int row, int col) // will return true if the matrix element is equal to 1, false otherwise
        {
            if (vertexMatrix[row][col] == 1)
            {
                return true;
            }
            else 
            {
                return false;
            }
        }

        int getFirstVertex() // returns vertex that has nothing pointed to it, or zero
        {
            int counter; // for keeping track of vertices
            int vertexToReturn;

            counter = 0; 

            for (int j = 0; j < numVertices; j++) // going column by column instead of row by row
            {
                for (int i = 0; i < numVertices; i++)
                {
                    if (vertexMatrix[i][j] == 0) 
                    {
                        counter++;
                    }           
                }

                if (counter == numVertices) 
                {
                    vertexToReturn = j; // column with all zeros, nothing pointing to it
                    return vertexToReturn;
                }
                else
                {
                    counter = 0;
                }
            }

            return 0; // default


        }

        int getNumVertices()
        {
            return numVertices;
        }

        
        



};

#endif