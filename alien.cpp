#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "game.h"
#include "draw.h"
#include "alien.h"
#include <ctime>
#include <cmath>
#include <iostream>
#include <unistd.h>
#include <string>
#include <set>


Alien::Alien(){
	isAlienAlive = true;
	AlienX = 0;
	AlienY = 3;
	AlMovSpeed = 0.03;
	goRight = true;
}
Alien::~Alien(){
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
	}else{
		AlienX -= AlMovSpeed;
	}
}
void Alien::setAlienPos(double Ax,double Ay){
AlienX = Ax;
AlienY = Ay;
}
