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
#include <vector>

double playerX= 0;
int spwned = 0;
int totAl = 5;


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
	if(spwned < totAl)
	{
	myAliens.push_back(Alien());
	std::cout << "create alien " << myAliens.size() << std::endl;
	spwned++;
	}
	
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

  

	draweth.DrawPlayer(playerX);
	draweth.DrawBoundaries();
	
	//std::cout << "aliens " << myAliens.size() << std::endl;
	for (int i = 0; i < myAliens.size(); i++) {
		Alien& alien = myAliens[i];
		double myAlPosX = alien.getAlienPosX();
		double myAlPosY = alien.getAlienPosY();
		draweth.DrawAlien(myAlPosX, myAlPosY);
		moveAlienX(alien);
	}
	
	



	
	glutSwapBuffers();


	
}

Game::~Game()
{
	
}
