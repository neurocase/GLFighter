#include <ctime>
#include <cmath>
#include <iostream>
#include <unistd.h>

#ifndef GAME_H
#define	GAME_H

class Game{
	private:
		long timeStored;
		long timeNew;
		bool quit;
		
		
	public:
		
		Game();
		void run();
		long getTime();	
		~Game();
	
	
};



#endif

/*

long timeStored = dazTime();
long timeNew = dazTime();




long dazTime(){
	time_t dTime;
	long timeA = time(&dTime);
	return timeA;
}




*/
