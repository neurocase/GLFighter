#include "player.h"

#ifndef GAME_H
#define	GAME_H

class Game{
	private:
		long timeStored;
		long timeNew;
		bool quit;
		
		
	public:
		
		//double &ShipXPosAdd;
		Game();
		void run(int argc, char **argv);
		void GameLoop();
		void Reshape(int w, int h);
		long getTime();	
		void setMyShipX(double myS);
		void setPlayerAdd(Player&);
		//double getGShipXPosAddy();
		~Game();
	
	
};

#endif
