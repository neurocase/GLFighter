#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "game.h"
#include "draw.h"
#include "player.h"
#include "alien.h"
#include <ctime>
#include <cmath>
#include <iostream>
#include <unistd.h>
#include <vector>


/*

	double ShipXPos;
	bool isAlive;
	int pHealth;
	bool reloaded;
	double laserPosX[3];
	double laserPosY[3];
	double mislPosX[4];
	double mislPosY[4];
	
	public:
	
	player();
	double getShipXPos();
	void setShipXPos(double xPos);
	void killPlayer();
	void fireLaser();
	void fireMissle();
	bool isReloaded();
	~player();
	
\*/
time_t dTime;

Player::Player()
{	
	ShipXPos = 0;
	reloaded = true;
	
	
	
	
	for (int i = 0; i < 3; i++)
	{
		pLaserPos[i].lx = 0;
		pLaserPos[i].ly = 0;
		pLaserPos[i].isActive = 0;
	}
}

Player::laserPos Player::getLaserPos(int n)
{
	return (pLaserPos[n]);
}

void Player::setLaserPos(laserPos newlaser, int n, char ch)
{
	switch (ch){
		
		case 'x':
		pLaserPos[n].lx = newlaser.lx;
		break;
		
		case 'y':
		pLaserPos[n].ly = newlaser.ly;
		
		break;
		case 't':
		pLaserPos[n].isActive = newlaser.isActive;
		
		break;
		case 'a':
		pLaserPos[n] = newlaser;
		
		break;
		default:
		pLaserPos[n] = newlaser;
		
	}
	
}


void Player::setShipXPos(double xPos)
{
	ShipXPos = ShipXPos + xPos;
}


void Player::fireLaser(){
	
	timeNow = time(&dTime);
	bool fire = false;
	
	if (timeNow - timeLastShoot > 1)
	{
		while (!fire)
		{
			int i = 0;
			while ((i < 3) || (!fire))
			{
				if (!pLaserPos[i].isActive)
				{
				 pLaserPos[i].isActive = true;
				 fire = true;
				}
				i++;
			}
		}
		timeLastShoot = time(&dTime);
	}
}

bool Player::isReloaded(){
	return reloaded;
}

double Player::getShipXPos()
{
	return ShipXPos;
}

Player::~Player()
{	
}
