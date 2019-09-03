/*
	Title:  Movies.h
	Author:  April R Crockett and Winston Phillips
	Date:  11/7/2017
	Purpose:  Be able to create, manage, print, save & delete a movie library
*/
#ifndef MOVIES_H
#define MOVIES_H

#include "Movie.h"
#include "LinkedList.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class Movies
{
private:
	LinkedList<Movie*>* moviesList; // linked list  holding movie objects


	/*
	Function name:  displayMovieTitles()
	Parameters:  	none
	Returns: 		none (void)
	Purpose:  		resizes the moviesArray if the numMovies = maxMovies
	*/

	void displayMovieTitles();
	void swap(int position1, int position2);
	int linearSearch();	// linear search for the list - made private
	void bubbleSort();
	int binarySearch();
	void insertionSort();
	void insertionSortDescending();
	void selectionSort();
	void mergeSort(int i, int k);
	void merge(int i, int j, int k);
	void quickSort(int low, int high);
	int partition(int low, int high);

	
public:

/*
	Function name:  overloaded constructor: Movies();
	Parameters:  	An integer containing the maximum size of the movie library 
	Returns: 		A pointer to a new Movies structure
	Purpose:  		This function should be called when the user needs to create a library
					of movies.  The function will dynamically allocate a movies array based
					on the maximum size and will also set the current number of movies to zero.
*/
Movies();



/*
	Function name:  addMovieToArray 
	Parameters:  	none 
	Returns: 		none
	Purpose:  		This function should be called when you need to add a single movie to the
					movie library.
*/
void addMovieToList();  



/*
	Function name:  editMovieInArray 
	Parameters:  	none
	Returns: 		none
	Purpose:  		This function should be called when you need to edit a movie in the array
*/
void editMovieInList();



/*
	Function name:  deconstructor: ~Movie() 
	Parameters:  	none
	Returns: 		none (void)
	Purpose:  		This function should be called when you need to remove all the single 
					movies in the movie library as well as the movie library.  This releases
					all the dynamically allocated space in memory.
*/
~Movies();	

/*
	Function name:  displayMovies 
	Parameters:  	none 
	Returns: 		none (void)
	Purpose:  		This function should be called when the user wants to have all the movies
					in the library printed to the screen.
*/
void displayMovies();



/*
	Function name:  readMoviesFromFile 
	Parameters:  	1) A pointer to a character (c-string or string literal argument) containing the file name
	Returns: 		none (void)
	Purpose:  		This function should be called when the user wants to read movie data from a file
					and add the movies to the movie library.  The file must have data in the following order:
					title, length, year, genre, rating, num oscars won, star rating
*/
void readMoviesFromFile(char* filename);

/*
	Function name:  removeMovieFromArray 
	Parameters:  	none
	Returns: 		none (void)
	Purpose:  		This function should be called when the user wants to remove one single movie
					from the movie library.  The function will list all the movie names and allow
					the user to select the movie that they wish to remove. Then this function removes the movie.
*/
void removeMovieFromList();

/*
	Function name:  saveToFile 
	Parameters:  	none 
	Returns: 		none (void)
	Purpose:  		This function should be called when the user wants to print all the movie data
					from the movie library to a file.  The data is printed in the following order (one piece
					of data per line):
					title, length, year, genre, rating, num oscars won, star rating
*/
void saveToFile(char *filename);

/********* Accessor Functions *****************/



int getNumMovies();

void algorithmAnalysis();



};

#endif