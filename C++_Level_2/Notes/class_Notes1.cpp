






	#include <iostream>
#include <string>
#include <iomanip>


using namespace std;

class VideoGame
{
  private:
    string Name;
    float Rating;
  public:
    void setName(string name);
    void setRating(float rating);
    string getName(); // string return type 
    float getRating();
    void displayAllInfo();
    void destroyGame();
  
};
/**************************************************************/
/*
VideoGame::VideoGame()  // default constructor (not overloaded)
{
  Name = "PlaceHolder";
  Rating = 0.0;
}

VideoGame::~VideoGame()
{
  cout << "Boom" << endl;
  delete Name;
  delete Rating;
}
*/

void VideoGame::setName(string name)
{
  Name = name;
}

void VideoGame::setRating(float rating)
{
  Rating = rating;
}


void VideoGame::displayAllInfo()
{
  cout << "***Game Info***" << endl;
  cout << "Video Game: " << Name << endl;
  cout << "Rating: " << Rating << endl;
}

string VideoGame::getName()  // const because we are not changing any value
{
  return Name;
}

float VideoGame::getRating() 
{
  return Rating;
}



/***********************************************************/

int main()
{
  string userName;
  float userRating;
  VideoGame Cuphead;
  Cuphead.setName("Cuphead");
  Cuphead.setRating(8.5);
  //cout << Cuphead.getName() << endl;
  //cout << Cuphead.getRating() << endl;
  Cuphead.displayAllInfo();
  
  VideoGame AssCreed;
  AssCreed.setName("Assassin's Creed");
  AssCreed.setRating(7.9);
  AssCreed.displayAllInfo();
  cout << "Name of video game you wish to add: ";
    getline(cin,userName);
  cout << "Rating you would give the game? (1-10, decimals included): ";
    cin >> userRating;
    
    while (userRating < 0 || userRating > 10)
    {
      cout << "Only values of 0-10 are accepted. Please try again" << endl;
      cout << "Rating you would give the game? (0-10, decimals included): ";
        cin >> userRating;
    }
  
  VideoGame Mario;
  Mario.setName(userName);
  Mario.setRating(userRating);
  Mario.displayAllInfo();
    
  cout << "Video game: " << Cuphead.getName() << endl;
  cout << "Rating: " << Cuphead.getRating() << endl;
  
  
  
  
  
  
}
