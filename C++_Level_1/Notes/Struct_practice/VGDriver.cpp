
#include "VG.h"`// not really doing any displaying or input


int main()
{
	VideoGame* KingdomHearts = createVideoGame("Kingdom Hearts" , 20, 6.5); // making an array of type Video Game

	VideoGame* AssCreed = createVideoGame("Assasin's Creed" , 35 , 5.2);

	VideoGame* SuperMario = createVideoGame("Super Mario World" , 15, 9.8);

	displayVideoGame(KingdomHearts);
	displayVideoGame(AssCreed);
	displayVideoGame(SuperMario);

	destroyVideoGame(KingdomHearts);
	destroyVideoGame(AssCreed);
	destroyVideoGame(SuperMario);


}