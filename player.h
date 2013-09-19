#ifndef PLAYER_H
#define PLAYER_H


class Player{
	
	private:
	
	double ShipXPos;
	bool isAlive;
	int pHealth;
	bool reloaded;
	double laserPosX[4];
	double laserPosY[4];
	double mislPosX[4];
	double mislPosY[4];
	long timeNow;
	long timeLastShoot;
	int pDirection;
	
	
	public:

	
	Player();
	void setDirection (int);
	int getDirection ();
	
	
	double getShipXPos();
	void setShipXPos(double);
	void killPlayer();
	void fireLaser();
	void fireMissle();
	bool isReloaded();
	//laserPos getLaserPos(int);
	//void setLaserPos(laserPos, int, char);
	
	
	~Player();
	
	
	
	
};



#endif
