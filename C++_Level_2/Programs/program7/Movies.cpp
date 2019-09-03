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
	//const char* nameForSearching = title->getText();

	// if(moviesList->getLength() == 0 || !moviesList->binarySearch(nameForSearching))
	// {
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

	//moviesList->insertionSort();
}

Movies::~Movies()
{
	// will work on
}

void Movies::displayMovies()
{
	
	if(moviesList->getLength() > 0)
	{
		//moviesList->insertionSort();

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
			
			//const char* movieTitletoSearch = title->getText();

			// if (moviesList->getLength() == 0 || !moviesList->binarySearch(movieTitletoSearch))	// because nothing is in the list yet
			// {
				moviesList->appendNode(oneMovie);
				//moviesList->insertionSort();	// sort that crap
				//confirm addition to the user
				cout << endl;
				title->displayText();
				cout << " was added to the movie library!\n";
				numMoviesReadFromFile++;
			//}

			// else
			// {
			// 	cout << "\nSorry, " << movieTitletoSearch << " is already in the list!" << endl;
			// }
			
			
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
	time_t start;	// for insertionSortDescending
	time_t end;		// for insertionSortDescending

	start = getTime();
	linearSearch();
	end = getTime();
	cout << "\nLinear Search Time:\t" << setprecision(2) << fixed << totalTime(start,end) << " s";

	mergeSort(0,moviesList->getLength()-1); // sort for binary search
	start = getTime();
	binarySearch();
	end = getTime();
	cout << "\nBinary Search Time:\t" << setprecision(2) << fixed << totalTime(start,end) << " s";

	insertionSortDescending();
	start = getTime();
	bubbleSort();
	end = getTime();
	cout << "\nBubble Sort Time:\t" << setprecision(2) << fixed << totalTime(start,end) << " s";

	insertionSortDescending();
	start = getTime();
	selectionSort();
	end = getTime();
	cout << "\nSelection Sort Time:\t" << setprecision(2) << fixed << totalTime(start,end) << " s";

	insertionSortDescending();
	start = getTime();
	insertionSort();
	end = getTime();
	cout << "\nInsertion Sort Time:\t" << setprecision(2) << fixed << totalTime(start,end) << " s";

	start = getTime();
	insertionSortDescending();
	end = getTime();
	cout << "\nInsertion Sort Descending Time:\t" << setprecision(2) << fixed << totalTime(start,end) << " s";

	insertionSortDescending();
	start = getTime();
	mergeSort(0,moviesList->getLength()-1);
	end = getTime();
	cout << "\nMerge Sort Time:\t" << setprecision(2) << fixed << totalTime(start,end) << " s";
	
	insertionSortDescending();
	start = getTime();
	quickSort(0, moviesList->getLength() - 1);
	end = getTime();
	cout << "\nQuick Sort Time:\t" << setprecision(2) << fixed << totalTime(start,end) << " s";

	
}

int Movies::linearSearch()
{
	
	int iteration = 0;

	char titleForSearch[100] = "Llama";

	while(iteration < moviesList->getLength())
	{
		Text* currTitle = moviesList->getNodeValue(iteration)->getmovieTitle();
		const char* currTitleArray = currTitle->getText();


		if(strcmp(currTitleArray,titleForSearch) == 0)
		{	
			return 1;
		}

		iteration++;
	}

	return -1;
}

int Movies::binarySearch()
{

	int first = 0;
	int last = moviesList->getLength();
	int middle = (first+last) / 2;

	const char* itemToSearch = "Llama";

	while (first <= last)
	{
		Text* midTitle = moviesList->getNodeValue(middle)->getmovieTitle();
		const char* currTitleArray = midTitle->getText();

		if(strcmp(currTitleArray, itemToSearch) == 0)
		{
			return 1;
		}

		else if(strcmp(currTitleArray, itemToSearch) > 0)
		{
			last = middle -1;
		}

		else
		{
			first = middle +1;
		}

		middle = (first+last) / 2;
	}
	
	return -1;
}

void Movies::bubbleSort()
{

	for (int size = moviesList->getLength()-1; size > 0; size--)
	{

		for (int i = 0; i < size; i++)
		{
			Text* movieTitle1 = moviesList->getNodeValue(i)->getmovieTitle();
			const char* movieTitleArray1 = movieTitle1->getText();

			Text* movieTitle2 = moviesList->getNodeValue(i+1)->getmovieTitle();
			const char* movieTitleArray2 = movieTitle2->getText();

				if (strcmp(movieTitleArray1,movieTitleArray2) > 0)
				{
					moviesList->swap(i,i+1);
				}

		}

	}

}

void Movies::insertionSort()
{
	for (int i = 1; i < moviesList->getLength(); i++)		// int i = 1 because the first node of list is technically "sorted"
	{
		
		for (int x = i; x > 0 && strcmp(moviesList->getNodeValue(x)->getmovieTitle()->getText(),moviesList->getNodeValue(x-1)->getmovieTitle()->getText()) < 0; x--)
		{
				moviesList->swap(x,x-1);
		}

	} 

}

void Movies::insertionSortDescending()
{

	for (int i = 1; i < moviesList->getLength(); i++)		// int i = 1 because the first node of list is technically "sorted"
	{
		
		for (int x = i; x > 0 && strcmp(moviesList->getNodeValue(x)->getmovieTitle()->getText(),moviesList->getNodeValue(x-1)->getmovieTitle()->getText()) > 0; x--)
		{
				moviesList->swap(x,x-1);
		}

	} 

}

void Movies::selectionSort()
{
	int minIndex;

	for (int minimumPosition = 0; minimumPosition < moviesList->getLength() -1; minimumPosition++)
	{

		minIndex = minimumPosition;

		Text* movieTitle = moviesList->getNodeValue(minIndex)->getmovieTitle();	// for insertionPointer's movie title
		const char* smallestValueArray = movieTitle->getText();

			for (int x = minimumPosition+1; x < moviesList->getLength(); x++)
			{
				Text* movieTitleB = moviesList->getNodeValue(x)->getmovieTitle();	// for insertionPointer's movie title
				const char* movingPositionArray = movieTitleB->getText();

				if(strcmp(smallestValueArray,movingPositionArray) > 0)
				{
						minIndex = x;

						movieTitle = moviesList->getNodeValue(minIndex)->getmovieTitle();
						const char* movingPositionArray = movieTitleB->getText();

				}
			}


		moviesList->swap(minimumPosition,minIndex);

	}

}

void Movies::mergeSort(int i, int k)
{
	int j = 0;

	if (i < k)
	{
		j = (i+k)/2;

	mergeSort(i, j);	// for first half of array

	mergeSort(j+1,k);	//for second half
	
	merge(i,j,k);

	}
	

}

void Movies::merge(int i, int j, int k)
{
//cout << i << j << k << endl;
	LinkedList<Movie*>* mergedList = new LinkedList<Movie*>();
	
	int mergePosition = 0;
	int leftPosition = 0;
	int rightPosition = 0;

	leftPosition = i;

	rightPosition = j + 1;

	while (leftPosition < j+1 && rightPosition < k+1)
	{
		Text* movieTitle1 = moviesList->getNodeValue(leftPosition)->getmovieTitle();	// for insertionPointer's movie title
		const char* leftPosArray = movieTitle1->getText();

		Text* movieTitle2 = moviesList->getNodeValue(rightPosition)->getmovieTitle();	// for insertionPointer's movie title
		const char* rightPosArray = movieTitle2->getText();

		if (strcmp(leftPosArray,rightPosArray) < 0)
		{
			mergedList->insertNode(moviesList->getNodeValue(leftPosition),mergePosition);
			leftPosition++;
		}
		else 
		{
			mergedList->insertNode(moviesList->getNodeValue(rightPosition),mergePosition);
			rightPosition++;
		}

		mergePosition++;
	}

	while (leftPosition < j+1)	// if left half still has elements
	{
		mergedList->insertNode(moviesList->getNodeValue(leftPosition), mergePosition);
		leftPosition++;
		mergePosition++;
	}

	while (rightPosition < k +1)
	{
		mergedList->insertNode(moviesList->getNodeValue(rightPosition), mergePosition);
		rightPosition++;
		mergePosition++;
	}

	for(mergePosition = 0; mergePosition < k-i+1; mergePosition++)
	{
		moviesList->deleteNodeforSort(i+mergePosition);
		moviesList->insertNode(mergedList->getNodeValue(mergePosition), i+mergePosition);
	}

}

void Movies::quickSort(int low, int high)
{
	int pivLocation = 0;

	if (low >= high)
		{
			return;		// base case
		}

	pivLocation = partition(low, high); // our new pivot location is given after nodes get swapped
	
	quickSort(low, pivLocation);
	
	quickSort(pivLocation + 1, high);
}

int Movies::partition(int low, int high)
{
	int middle;
	const char* pivotTitle;
	int temp;

	bool done = false;

	middle = low + (high - low) /2;

	Text* pivotTitleText = moviesList->getNodeValue(middle)->getmovieTitle();
	pivotTitle = pivotTitleText->getText();

	int lw = low;
	int hgh = high;

	while(done == false)
	{
		Text* lowTitleText = moviesList->getNodeValue(lw)->getmovieTitle();
		const char* lowTitle = lowTitleText->getText();

		while (strcmp(lowTitle,pivotTitle) < 0)
			{
				lw++;
				lowTitleText = moviesList->getNodeValue(lw)->getmovieTitle();
				lowTitle = lowTitleText->getText();
			}

		Text* highTitleText = moviesList->getNodeValue(hgh)->getmovieTitle();
		const char* highTitle = highTitleText->getText();

		while (strcmp(highTitle,pivotTitle) > 0)
			{
				hgh--;
				highTitleText = moviesList->getNodeValue(hgh)->getmovieTitle();
				highTitle = highTitleText->getText();
			}

		if (lw >= hgh)	// we've gone all the way through
		{
			done = true;
		}
		else //swap elements while incrementing and decrementing 
		{
			moviesList->swap(lw,hgh);
			lw++;
			hgh--;
		}
	}

	return hgh;

}


