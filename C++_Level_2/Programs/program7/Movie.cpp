/*
	Title:  Movie.cpp
	Author:  April Crockett and Winston Phillips
	Date:  11/7/2017
	Purpose:  Be able to create, manage, print & delete a single movie.
*/
#include <iomanip>
#include "Movie.h"
#include "Text.h"

Movie::Movie(Text* title, int length)
{
	
	movieTitle = title;		// assign movieTitle
	movieLength = length;	// assign movieLength
	
}

Movie::Movie(Text* title, int length, int year, Text* genre, Text* rating, int nom, float stars) //all info is know
{
	// assign the received parameters to class attributes
	movieTitle = title;
	movieLength = length;
	movieYear = year;
	movieGenre = genre;
	movieRating = rating;
	movieOscars = nom;
	movieNumStars = stars;
}

Movie::~Movie()
{
	//deleting Texts of movie objects with deconstructor 
	delete movieTitle;
	delete movieGenre;
	delete movieRating;
}

void Movie::printMovieDetails()	// we are simply outputting the movie attributes
{
	cout << endl;
	cout << right << setw(30) << "Movie Title:  " << left;
	movieTitle->displayText();		// function of Text class
	cout << endl;
	cout << right << setw(30) << "Length (minutes):  " << left << movieLength << endl;
	cout << right << setw(30) << "Year Released:  " << left << movieYear << endl;
	cout << right << setw(30) << "Genre:  " << left;
	movieGenre->displayText();
	cout << endl;
	cout << right << setw(30) << "Rating:  " << left;
	movieRating->displayText();
	cout << endl;
	cout << right << setw(30) << "Number of Oscars Won:  " << left << movieOscars << endl;
	cout << right << setw(30) << "Number of Stars:  " << left << movieNumStars << endl << endl;
}

void Movie::printMovieDetailsToFile(ofstream &outFile)
{
	char temp[1000];
	strncpy(temp, movieTitle->getText(), 1000);
	outFile << temp << endl;
	outFile << movieLength << endl;
	outFile << movieYear << endl;
	strncpy(temp, movieGenre->getText(), 1000);
	outFile << temp << endl;
	strncpy(temp, movieRating->getText(), 1000);
	outFile << temp << endl;
	outFile << movieOscars << endl;
	outFile << movieNumStars << endl;
}


void Movie::editMovie()
{
	int choice;
	Text* tempText;
	char temp[100];
	
	do
	{
		cout << "\n\nWhich detail do you wish to edit?\n";
		cout << "1.  Title\n";
		cout << "2.  Length\n";
		cout << "3.  Year\n";
		cout << "4.  Genre\n";
		cout << "5.  Rating\n";
		cout << "6.  Number of Oscars Won\n";
		cout << "7.  Number of Stars\n";
		cout << "8.  DONE EDITING\n";
		cout << "CHOOSE 1-8:  ";
		cin >> choice;
		while(choice < 1 || choice > 8)
		{
			cout << "\nOOPS!  Enter choice 1 through 8:  ";
			cin >> choice;
		}
		cin.ignore();
		
		switch(choice)
		{
			case 1: cout << "\nCurrent Title: ";
					movieTitle->displayText();
					movieTitle->~Text();
					//destroyText(myMovie->movieTitle);
					cout << "\nNEW TITLE:  ";
					cin.getline(temp, 100);
					tempText = new Text(temp);		// allocate new Memory for the new movie title
					movieTitle = tempText;
					break;
			
			case 2:	int tempLength;
					cout << "\nCurrent Length: " << movieLength;
					cout << "\nNEW LENGTH:  ";
					cin >> tempLength;
					movieLength = tempLength;
					break;
					
			case 3: int tempMovieYear;
					cout << "\nCurrent Year: " << movieYear;
					cout << "\nNEW YEAR: ";
					cin >> tempMovieYear;
					movieYear = tempMovieYear;
					break;
					
			case 4:	cout << "\nCurrent Genre: ";		
					movieGenre->displayText();
					movieGenre->~Text();
					//destroyText(myMovie->movieGenre);
					cout << "\nNEW GENRE:  ";
					cin.getline(temp, 100);
					tempText = new Text(temp);	// allocate new Memory for the new movie genre
					movieGenre = tempText;
					break;
					
			case 5: cout << "\nCurrent Rating: ";
					movieRating->displayText();
					movieRating->~Text();
					//destroyText(myMovie->movieRating);
					cout << "\nNEW GENRE:  ";
					cin.getline(temp, 100);
					tempText = new Text(temp);		// allocate new Memory for the new movie Rating
					movieRating = tempText;
					break;
			
			case 6: int tempOscars;
					cout << "\nCurrent Number of Oscars Won: " << movieOscars;
					cout << "NEW OSCARS: ";
					cin >> tempOscars;
					movieOscars = tempOscars;

					break;
					
			case 7: float tempStars;
					cout << "\nCurrent Star Rating from IMDB: " << movieNumStars;
					cout << "\nNEW STAR RATING:  ";
					cin >> tempStars;
					movieNumStars = tempStars;
					break;
		}
	}while(choice != 8);
}

/****************** Mutator Functions ****************************/

void Movie::setmovieTitle(Text* mvTitle)
{
	movieTitle = mvTitle;
}

void Movie::setmovieLength(int mvLength)
{
	movieLength = mvLength;
}

void Movie::setmovieYear(int mvYear)
{
	movieYear = mvYear;
}

void Movie::setmovieGenre(Text* mvGenre)
{
	movieGenre = mvGenre;
}

void Movie::setmovieRating(Text* mvRating)
{
	movieRating = mvRating;
}

void Movie::setmovieOscars(int mvOscars)
{
	movieOscars = mvOscars;
}

void Movie::setmovieNumStars(float mvStars)
{
	float movieNumStars = mvStars;
}

/****************************************************************/

/********************* Accessor Functions ***********************/

Text* Movie::getmovieTitle()
{
	return movieTitle;
}

int Movie::getmovieLength()
{
	return movieLength;
}

int Movie::getmovieYear()
{
	return movieYear;
}

Text* Movie::getmovieGenre()
{
	return movieGenre;
}

Text* Movie::getmovieRating()
{
	return movieRating;
}

int Movie::getmovieOscars()
{
	return movieOscars;
}

float Movie::getmovieNumStars()
{
	return movieNumStars;
}

/******************************************************************/


