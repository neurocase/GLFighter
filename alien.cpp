#include "openGL.h"
#include "game.h"
#include "draw.h"
#include "alien.h"
#include "timer.h"
#include <ctime>
#include <cmath>
#include <iostream>
#include <unistd.h>
#include <string>
#include <set>

static Timer dtime;

Alien::Alien(){
	isAlienAlive = true;
	//AlienX = -0.9 + rand() % 2 *1.5;
  AlienX = ((((rand() % 100) *0.01) *2.6)-1.25);
	AlienY = 2;
	AlienRot = 0;
	AlMovSpeed = 0.03;
	goRight = true;
	alienSize = 0.2;
	alienExplo = 0;
	
	
	
	for (int i = 0; i < 3; i++)
	{
		aLaserPos[i].lx = 0;
		aLaserPos[i].ly = -1;
		aLaserPos[i].isActive = 0;
	}
	
}

Alien::~Alien(){
}

void Alien::setAlLaserPos(double val,int i, char c){
		
		switch (c){
			case 'x':
				aLaserPos[i].lx = val;
				break;
			case 'y':
				aLaserPos[i].ly = val;
				break;
		}
	
}


// ---------- FOLLOWING ALIEN SHOOT CODE IS A MESS AND DOESN'T WORK

void Alien::AlFire(){
		
	double timeNow = dtime.getTime();
	bool fire = false;
	
	
   // segmentation fault not here
	for(int i = 0; i < 3; i++)
		{
		if (aLaserPos[i].ly < -2)
		{
			aLaserPos[i].lx = AlienX;
			aLaserPos[i].isActive = false;
			aLaserPos[i].ly = 1;
		}
		
	}
	if (timeNow - timeLastShoot > 1)
	{
		fired:
		while (!fire)
		{
			int i = 0;
			while ((i < 3) || (!fire))
			{
				if (!aLaserPos[i].isActive)
				{
         std::cout << "[" << i << "] fire! " ;
				 aLaserPos[i].isActive = true;
				 fire = true;
				 timeLastShoot = dtime.getTime();
				 goto fired;
				}
				i++;
			}
		}
		
		
	} 
}

void Alien::setAlienRot(double rot){
	AlienRot = rot;
}
double Alien::getAlienRot(){
	return AlienRot;
}
double Alien::getAlienMovSpd(){
	return AlMovSpeed;
}
double Alien::getAlienPosX(){
	return AlienX;
}
double Alien::getAlienPosY(){
	return AlienY;
}
bool Alien::isGoingRight(){
	return goRight;
}
void Alien::goOtherWay(){
	goRight = !goRight;
}
void Alien::moveStep() {
	if (goRight){
		AlienX += AlMovSpeed;
		AlienY-= 0.001;
	}else{
		AlienX -= AlMovSpeed;
		AlienY-= 0.005;
	}
}
void Alien::setAlienPos(double Ax,double Ay){
AlienX = Ax;
AlienY = Ay;
}
