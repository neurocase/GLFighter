#include "game.h"
#include <unistd.h>


Game::Game()
{
}

long Game::getTime()
{
	
	time_t dTime;
	long timeA = time(&dTime);
	return timeA;
}




void Game::run()
{
	/*
	 *		|| This is my attempt to make the game automaticly detect the computer speed
	 */
	
	long tSleep = 0;
	quit = false;
	bool clockSet;
	bool clockSatisfied =false;
	int clockT = 0;
	int clockKeep[8] {0,0,0,0,0,0,0,0};
	while(!quit)
	{
		
		if (!clockSatisfied)
		{
			long t = 0;
			
			long timeStored = getTime();
			long timeNew = getTime();
			std::cout << ":: CALIBRATING CLOCK ::";
			while (!clockSatisfied)
			{
				
				t++;
				std::cout << t << " ";
				
				
				
				
				if (t > 40000){
					tSleep+=50;
				}
				
				usleep(tSleep);
				if ((timeNew - timeStored) > 5){
					clockKeep[clockT] = tSleep;
					clockT++;
					if (clockT > 6){
					clockSatisfied = true;
					}
				if (t < 30000){
					tSleep-=50;
				}	
				}
				timeNew = getTime();
				
			}
			
			//std::cout << "t:" << t << "| tSleep:" << tSleep;
			
		}
		int totSleep = 0;
		for(int i =0; i < 6; i++){
		
		std::cout << "| Keep [" << i << "]" << clockKeep[i];
		totSleep += clockKeep[i];
		}
		tSleep = totSleep / 6;
		usleep(tSleep);
			std::cout << "| tSleep:" << tSleep;
		quit = true;
	}
	
	
	
	
	
}

Game::~Game()
{
}
