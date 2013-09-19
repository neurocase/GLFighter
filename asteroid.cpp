#include "openGL.h"
#include "game.h"
#include "draw.h"
#include "alien.h"
#include "asteroid.h"
#include <ctime>
#include <cmath>
#include <iostream>
#include <unistd.h>
#include <string>
#include <set>


Asteroid::Asteroid(){
	isAstAlive = true;
	AstX = ((((rand() % 100) *0.01) *2.6)-1.3);
	AstY = 2;
	AstRot = 0;
	AstMovSpeed = 0.03;
	AstSize = 0.2;
	AstExplo = 0;
}
Asteroid::~Asteroid(){
}

void Asteroid::setAstRot(double rot){
	AstRot = rot;
}
double Asteroid::getAstRot(){
	return AstRot;
}
double Asteroid::getAstMovSpd(){
	return AstMovSpeed;
}
double Asteroid::getAstPosX(){
	return AstX;
}
double Asteroid::getAstPosY(){
	return AstY;
}

void Asteroid::setAstPos(double Ax,double Ay){
AstX = Ax;
AstY = Ay;
}
