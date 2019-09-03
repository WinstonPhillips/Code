/*
	Title:  Movies.cpp
	Author:  April R Crockett
	Date:  11/7/2017
	Purpose:  Be able to create, manage, print, save & delete a movie library
*/
#include "Movies.h"
#include "Movie.h"
#include "LinkedList.h"
#include "Timer.h"

Movies::Movies()
{
	moviesList = new LinkedList<Movie*>();	// declaring the List to to be of Movie pointers
}


void Movies::addMovieToList() 
{
	char tempString[100];
	int length, year, numOscars;
	float numStars;
	Text* title;
	Text* genre;
	Text* rating;
	
	//get movie data from the user
	cin.ignore();  //remove the \n from the keyboard buffer
	cout << "\n\nMOVIE TITLE: ";
	cin.getline(tempString, 100);

	title =  new Text(tempString);
	const char* nameForSearching = title->getText();

	if(moviesList->getLength() == 0 || !moviesList->binarySearch(nameForSearching))
	{
		cout << "\nMOVIE LENGTH (in minutes): ";
		cin >> length;

		cout << "\nMOVIE YEAR: ";
		cin >> year;
		cin.ignore();

		cout << "\nMOVIE GENRE: ";
		cin.getline(tempString, 100);
		genre = new Text(tempString);

		cout << "\nMOVIE RATING: ";
		cin.getline(tempString, 100);
		rating = new Text(tempString);
		cout << "\nNUMBER OF OSCARS WON: ";
		
		cin >> numOscars;
		cout << "\nSTAR RATING (out of 10): ";
		cin >> numStars;
		
		//create the movie
		Movie* oneMovie = new Movie(title, length, year, genre, rating, numOscars, numStars);	// pointer to movie because we need to add to pointer array of pointers 
					

		//add the movie to the list
			moviesList->appendNode(oneMovie);	

			moviesList->insertionSort();
	}

	else if(moviesList->binarySearch(nameForSearching))
	{
		cout << "\nSorry, " << nameForSearching << " is already in the list!" << endl;
	}
	
}

void Movies::removeMovieFromList()
{
	int movieChoice;
	cout << moviesList->getLength() << endl << endl;
	
	if(moviesList->getLength() <= 1)
	{
	   cout << endl << "There must always be at least one movie in your library.  You can\'t";
	   cout << " remove any movies right now or you will have no movies in your library.\n";
	}
	else
	{
		cout << "\n\nChoose from the following movies to remove:\n";
		displayMovieTitles();
		cout << "\nChoose a movie to remove between 1 & " << moviesList->getLength() << ":  ";
		cin >> movieChoice;
		while(movieChoice < 1 || movieChoice > moviesList->getLength())
		{
			cout << "\nOops!  You must enter a number between 1 & " << moviesList->getLength() << ":  ";
			cin >> movieChoice;
		}
		
		int movieIndexToBeRemoved = movieChoice-1;
		
		
		//destroy this movie
		
		moviesList->deleteNode(movieIndexToBeRemoved);	
	}
}

void Movies::editMovieInList()
{
	int movieChoice;
	
	cout << "\n\nChoose from the following movies to edit:\n";
	displayMovieTitles();	//display all the movies in the array
	cout << "\nChoose a movie to edit between 1 & " << moviesList->getLength() << ":  ";
	cin >> movieChoice;
	while(movieChoice < 1 || movieChoice > moviesList->getLength())
	{
		cout << "\nOops!  You must enter a number between 1 & " << moviesList->getLength() << ":  ";
		cin >> movieChoice;
	}
	Movie* oneMovie = moviesList->getNodeValue(movieChoice-1);

	oneMovie->editMovie();

	moviesList->insertionSort();
}

Movies::~Movies()
{
	// will work on
}

void Movies::displayMovies()
{
	moviesList->insertionSort();
	
	if(moviesList->getLength() > 0)
	{
		moviesList->displayNodes();
	}
	else	
		cout << "\nThere are no movies in your library yet.";
}

void Movies::displayMovieTitles()
{	
	moviesList->displayNodes();
}

void Movies::readMoviesFromFile(char *filename)
{
	int numMoviesReadFromFile = 0;
	ifstream inFile;
	char temp[100];
	Text* title;
	Text* genre;
	Text* rating;
	Movie* oneMovie;
	int movieLength; //length of movie in minutes
	int movieYear; //year released
	int movieOscars; //number of oscars won
	float movieNumStars; //from IMDB out of 10 stars
	
	inFile.open(filename);
	if(inFile.good())
	{
		inFile.getline(temp, 100);
		while(!inFile.eof())
		{	
			title = new Text(temp);//create a text for the movie title
			inFile >> movieLength;
			inFile >> movieYear;
			inFile.ignore(); //get rid of \n in the inFile buffer
			
			inFile.getline(temp, 100); //read in genre
			genre =  new Text(temp); //create a text for genre
			inFile.getline(temp, 100); //read in rating
			rating = new Text(temp); //create a text for rating
			inFile >> movieOscars;
			inFile >> movieNumStars;
			inFile.ignore(); //get rid of \n in the inFile buffer
			
			//one movie has been read from the file.  Now create a movie object
			oneMovie = new Movie(title, movieLength, movieYear, genre, rating, movieOscars, movieNumStars);	// new because we are adding in the array
			
			const char* movieTitletoSearch = title->getText();

			if (moviesList->getLength() == 0 || !moviesList->binarySearch(movieTitletoSearch))	// because nothing is in the list yet
			{
				moviesList->appendNode(oneMovie);
				moviesList->insertionSort();	// sort that crap
				//confirm addition to the user
				cout << endl;
				title->displayText();
				cout << " was added to the movie library!\n";
				numMoviesReadFromFile++;
			}

			else
			{
				cout << "\nSorry, " << movieTitletoSearch << " is already in the list!" << endl;
			}
			
			
			inFile.getline(temp, 100); //read in the next movie title if there is one
		}
		
		cout << "\n\n" << numMoviesReadFromFile << " movies were read from the file and added to your movie library.\n\n";
	}
	else
	{
		cout << "\n\nSorry, I was unable to open the file.\n";
	}
}


void Movies::saveToFile(char *filename)
{
	moviesList->saveNodestoFile(filename);
}

int Movies::getNumMovies()
{
	return moviesList->getLength();
}

void Movies::algorithmAnalysis()
{
	linearSearch();
}

int linearSearch()
{
	char titleForSearch[100];

	cout << "What is the title of the Movie you wish to search for?";
		cin.getline(titleForSearch,100);

	ListNode* current = moviesList->head;

	while(current != NULL)
	{
		Text* currTitle = current->value->getmovieTitle();
		const char* currTitleArray = movieTitle2->getText();

		if(currTitleArray == titleForSearch)
		{
			cout << "Match Found!" << endl;
			return 1;
		}

		current = current->next;
	}

	cout << "No match found" << endl;

	return -1;
}







