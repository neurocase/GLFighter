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
		
	
	
	public:

	
	Player();
	struct laserPos
	{
		double lx;
		double ly;
		bool isActive;
	}pLaserPos[3];
	double getShipXPos();
	void setShipXPos(double);
	void killPlayer();
	void fireLaser();
	void fireMissle();
	bool isReloaded();
	laserPos getLaserPos(int);
	void setLaserPos(laserPos, int, char);
	
	
	~Player();
	
	
	
	
};



#endif
