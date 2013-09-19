#include "openGL.h"
#include "game.h"
#include "draw.h"
#include "player.h"
#include "alien.h"
#include <ctime>
#include <cmath>
#include <iostream>
#include <unistd.h>
#include <vector>

time_t dTime;

Player::Player()
{	
	pDirection = 0;
	ShipXPos = 1;
	reloaded = true;

}

void Player::setDirection (int d){
	pDirection = d;
}
int Player::getDirection (){
	return pDirection;
}


double Player::getShipXPos()
{
	return ShipXPos;
	
}

void Player::setShipXPos(double xPos)
{
	ShipXPos = ShipXPos + xPos;
}

Player::~Player()
{	
}
