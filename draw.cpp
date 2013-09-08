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

std::set<std::string> debug;

void PrintOnce(std::string key, std::string message) {
	if (debug.insert(key).second) {
	   std::cout << message << std::endl;
	}
}

Draw::Draw()
{
	
}


void Draw::DrawLaser(double laserX,double laserY){
 
	PrintOnce("laser", "LASER!");
	glColor3f(1,0.5,0);
    glBegin(GL_LINES);
		glVertex3f(laserX, laserY, -10.0);
		glVertex3f(laserX, laserY-0.2, -10.0);
	glEnd();
} 

void Draw::DrawMissle(double mislX, double mislY)
{
	
	PrintOnce("missle", "Missile!");
	glColor3f(1,0.3,0);
	
	glBegin(GL_TRIANGLES);  
		glVertex3f(mislX, mislY+0.1, -10.0);
        glVertex3f(mislX-0.03, mislY-0.1, -10.0);
        glVertex3f(mislX+0.03, mislY-0.1, -10.0);
        
    glEnd();
	
}


void Draw::DrawBoundaries(){
  // DRAW BOUNDARIES 
	PrintOnce("boundary", "Boundary has been drawn");
	glColor3f(1,1,1);
    glBegin(GL_LINES);
		glVertex3f(1.5, 0, -10.0);
		glVertex3f(1.5, 5, -10.0);
		glVertex3f(-1.5, 0, -10.0);
		glVertex3f(-1.5, 5, -10.0);
	glEnd();
} 
	

double s = 0.04;
void Draw::DrawAlien(double alX, double alY, double rot)
{
	
	double alXt [3] {-0.1, 0.1, 0};
	double alYt [3] {0.1, 0.1, -0.1};
	double tmpalXt [3] {alXt[0],alXt[1],alXt[2]};
	double tmpalYt [3] {alYt[0],alYt[1],alYt[2]};
		
	for (int i = 0; i < 3; i++)
	{
		alXt[i] = tmpalXt[i]*cos(rot)-tmpalYt[i]*sin(rot);
		alYt[i] = tmpalXt[i]*sin(rot)+tmpalYt[i]*cos(rot);
		
	}
	
	PrintOnce("aliens", "Alien has been drawn");
	glColor3f(0.7,0.7,0);
	
	glBegin(GL_TRIANGLES);  
        glVertex3f(alX+alXt[0], alY+alYt[0], -10.0); //point A
        glVertex3f(alX+alXt[1], alY+alYt[1], -10.0); //point B
        glVertex3f(alX+alXt[2], alY+alYt[2], -10.0); //point C
        
    glEnd();
	
}
/*
 * void Draw::DrawAlien(double alX, double alY)
{
	
	PrintOnce("aliens", "Alien has been drawn");
	glColor3f(0,1,0);
	
	glBegin(GL_TRIANGLES);  
        glVertex3f(alX-0.1, alY+0.1, -10.0);
        glVertex3f(alX, alY-0.1, -10.0);
        glVertex3f(alX+0.1, alY+0.1, -10.0);
    glEnd();
	
}*/


void Draw::DrawPlayer(double myX){
	
	PrintOnce("drawplayer", "Player has been drawn");
	glColor3f(1,1,0);
	glTranslated(0,-1.5,0);
    glBegin(GL_TRIANGLES);
        glVertex3f(myX-0.2, 0.0, -10.0);
        glVertex3f(myX, 0.2, -10.0);
        glVertex3f(myX+0.2, 0.0, -10.0);
    glEnd();
	
}


Draw::~Draw()
{
	
}
