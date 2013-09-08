#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "game.h"
#include "draw.h"
#include "alien.h"
#include "player.h"
#include <ctime>
#include <cmath>
#include <iostream>
#include <unistd.h>
#include <vector>

double playerX= 0;
int spwned = 0;
int totAl = 5;
long startTime = 0;
long holdTime = 0;
long nowTime = 0;


Draw draweth;
std::vector<Alien> myAliens;


Game::Game()
{
	
}

void Game::setMyShipX(double myS)
{
	playerX = myS;
	
}

long Game::getTime()
{
	
	time_t dTime;
	long timeA = time(&dTime);
	return timeA;
}



void Game::run(int argc, char **argv)
{
	 
}
void Game::Reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-0.1, 0.1, -float(h)/(10.0*float(w)), float(h)/(10.0*float(w)), 0.5, 1000.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

bool insideBoundary(double x) {
	return std::abs(x) < 1;
}

void moveAlienX(Alien& alien){
	double X = alien.getAlienPosX();
	if (!insideBoundary(X)){
		alien.goOtherWay();
	}
	alien.moveStep();
}

void Game::GameLoop()
{
	if (startTime == 0){
		startTime = getTime();
	}
	if (holdTime == 0){
		startTime = getTime();
	}
	
	nowTime = getTime();
	if((spwned < totAl) && (nowTime - holdTime > 1))
	{
	myAliens.push_back(Alien());
	std::cout << "create alien " << myAliens.size() << std::endl;
	spwned++;
	holdTime = getTime();
	}
	
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();


	draweth.DrawPlayer(playerX);
	draweth.DrawBoundaries();
	
	//if laser active, laser y++
	
	//std::cout << "aliens " << myAliens.size() << std::endl;
	for (unsigned int i = 0; i < myAliens.size(); i++) {
		Alien& alien = myAliens[i];
		double myAlPosX = alien.getAlienPosX();
		double myAlPosY = alien.getAlienPosY();
		double myRot = alien.getAlienRot();
		/*if ((alien.isGoingRight()) && (myRot < 1)){
			myRot+=0.1;
		}*/
		//if ((!alien.isGoingRight()) && (myRot >-1)){
			myRot-=0.1;
		//}
		alien.setAlienRot(myRot);
		draweth.DrawAlien(myAlPosX, myAlPosY, myRot);
		moveAlienX(alien);
	}
	
	



	
	glutSwapBuffers();


	
}

Game::~Game()
{
	
}
