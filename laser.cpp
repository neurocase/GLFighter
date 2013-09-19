#include "openGL.h"
#include "game.h"
#include "draw.h"
#include "laser.h"
#include "alien.h"
#include "asteroid.h"

#include <ctime>
#include <cmath>
#include <iostream>
#include <unistd.h>
#include <vector>

Laser::Laser(){
	//empty constructor for no apparent reason
	lx = 0;
	ly = 0;
	isActive = false;
}

Laser::Laser(double shooterXPos, double shooterYPos){
	lx = shooterXPos;
	ly = shooterYPos;
	isActive = true;
	isGoUp = true;
}

Laser::Laser(double shooterXPos, double shooterYPos, bool goUp){
	lx = shooterXPos;
	ly = shooterYPos;
	isActive = true;
	isGoUp = goUp;
}

Laser::~Laser(){

}
