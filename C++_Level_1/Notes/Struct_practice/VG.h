#ifndef VG_H
#define VG_H

#include <string>

using namespace std;

struct VideoGame
{
	string Name;
	int Levels;
	float Difficulty;
};

VideoGame* createVideoGame (string name, int lvls, float diff);
void displayVideoGame (VideoGame* s);
void destroyVideoGame (VideoGame* s);

#endif