#include <iostream>
#include <string>
#include "VG.h"


using namespace std;


VideoGame* createVideoGame (string name, int lvls, float diff)
{
	VideoGame* newvideoGame = new VideoGame;
	newvideoGame->Name = name;
	newvideoGame->Levels = lvls;
	newvideoGame->Difficulty = diff;

	return newvideoGame;
}

void displayVideoGame (VideoGame* s)
{
	cout << "Name: " << s->Name << endl;
	cout << "Number of Levels: " << s->Levels << endl;
	cout << "Difficulty(from 1-10): " << s->Difficulty << endl;
}

void destroyVideoGame (VideoGame* s)
{
	delete s;
}