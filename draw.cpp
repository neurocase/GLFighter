#include "openGL.h"
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
	glColor3f(1,1,1);
    glBegin(GL_TRIANGLES);  
				glVertex3f(laserX, laserY-0.2, -10.0);
        glVertex3f(laserX-0.03, laserY, -10.0);
        glVertex3f(laserX+0.03, laserY, -10.0);
	glEnd();
} 

void Draw::DrawAlLaser(double laserX,double laserY){
 
	PrintOnce("laser", "LASER!");
	glColor3f(0,1,0.5);
    glBegin(GL_TRIANGLES);  
				glVertex3f(laserX, laserY, -10.0);
        glVertex3f(laserX-0.03, laserY-0.2, -10.0);
        glVertex3f(laserX+0.03, laserY-0.2, -10.0);
	glEnd();
} 



void Draw::DrawLife(int life){
	
	
	
	
	double r = 160 / 256.0;
	double g = 160 / 256.0;
	double b = 255 / 256.0;
	
	
	glColor3f(r,g,b);
	switch (life){
	
		case 3:
	
	glBegin(GL_TRIANGLES);
		glVertex3f(1.7, -1.17, -10.0);
		glVertex3f(1.85, -1.17, -10.0);
		glVertex3f(1.7, -0.9, -10.0);
	glEnd();
		case 2:
    glBegin(GL_TRIANGLES);
		glVertex3f(1.85, -1.2, -10.0);
		glVertex3f(1.7, -1.2, -10.0);
		glVertex3f(1.85, -1.5, -10.0);
	glEnd();
		case 1:
	glBegin(GL_TRIANGLES);
		glVertex3f(1.7, -1.6, -10.0);
		glVertex3f(1.85, -1.6, -10.0);
		glVertex3f(1.7, -1.3, -10.0);
	glEnd();
		default:
		break;
	}
	
	
}



void Draw::DrawCharge(double charge){
	
	double g = 0;
	double b = 1;
	
	if (charge > 1)
	{
		g = 1;
		b = 0;
		charge = 1;
		
	}
	
	
	
	glColor3f(0.3,g,b);
    glBegin(GL_LINES);
		glVertex3f(1.65, -1.7+charge, -10.0);
		glVertex3f(1.65, -1.7, -10.0);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(1.62, -1.7+charge, -10.0);
		glVertex3f(1.62, -1.7, -10.0);
	glEnd();
	
} 



void Draw::DrawBoundaries(){
  // DRAW BOUNDARIES 
	PrintOnce("boundary", "Boundary has been drawn");
	glColor3f(1,1,1);
    glBegin(GL_LINES);
		glVertex3f(1.5, -3, -10.0);
		glVertex3f(1.5, 3, -10.0);
		glVertex3f(-1.5, -3, -10.0);
		glVertex3f(-1.5, 3, -10.0);
	glEnd();
} 
	

double s = 0.04;

void Draw::DrawAsteroid(double alX, double alY, double rot)
{
	
	double alXt[3] = {-0.1, 0.1, 0};
	double alYt[3] = {0.1, 0.1, -0.1};
	double tmpalXt[3] = {alXt[0],alXt[1],alXt[2]};
	double tmpalYt[3] = {alYt[0],alYt[1],alYt[2]};
		
	for (int i = 0; i < 3; i++)
	{
		alXt[i] = tmpalXt[i]*cos(rot)-tmpalYt[i]*sin(rot);
		alYt[i] = tmpalXt[i]*sin(rot)+tmpalYt[i]*cos(rot);
		
	}
	
	PrintOnce("Asteroid", "Asteroid");
	glColor3f(0.7,0.2,1);
	
	glBegin(GL_TRIANGLES);  
        glVertex3f(alX+alXt[0], alY+alYt[0], -10.0); //point A
        glVertex3f(alX+alXt[1], alY+alYt[1], -10.0); //point B
        glVertex3f(alX+alXt[2], alY+alYt[2], -10.0); //point C
        
    glEnd();
	
}



void Draw::DrawAlien(double alX, double alY, char c)
{
	double alXt[3] = {-0.1, 0.1, 0};
	double alYt[3] = {0.1, 0.1, -0.1};
	
	
	PrintOnce("aliens", "Alien has been drawn");
  switch (c){
    case 'g':
      glColor3f(0,1,0.5);
      break;
    case 'f':
      glColor3f(1,1,1);
      break;  
    default:
      glColor3f(0.2,1,0);
      break;
  }
	glBegin(GL_TRIANGLES);  
        glVertex3f(alX+alXt[0], alY+alYt[0], -10.0); //point A
        glVertex3f(alX+alXt[1], alY+alYt[1], -10.0); //point B
        glVertex3f(alX+alXt[2], alY+alYt[2], -10.0); //point C
    glEnd();
	
}

void Draw::DrawRTri(double alX, double alY)
{
	glColor3f(1,0,0);
	
	glBegin(GL_TRIANGLES);  
        glVertex3f(alX-0.05, alY+0.05, -10.0);
        glVertex3f(alX, alY-0.05, -10.0);
        glVertex3f(alX+0.05, alY+0.05, -10.0);
    glEnd();
	
}

void Draw::DrawExplosion(double alX, double alY, double inc)
{

	
	glColor3f(1-(inc*4),1-(inc*4),1-(inc*2));
	glBegin(GL_TRIANGLES);  
        glVertex3f(alX-0.1-inc/2, alY+0.1 -inc  , -11.0);
        glVertex3f(alX          , alY-0.1 +inc*2, -11.0);
        glVertex3f(alX+0.1+inc/2, alY+0.1 -inc  , -11.0);
    glEnd();

	glBegin(GL_TRIANGLES);  
        glVertex3f(alX-0.05+inc, alY+0.05 +inc, -9.5);
        glVertex3f(alX     +inc, alY-0.05 +inc, -9.5);
        glVertex3f(alX+0.05+inc, alY+0.05 +inc, -9.5);
    glEnd();
    
    
    
    glBegin(GL_TRIANGLES);  
        glVertex3f(alX-0.05+inc, alY+0.05 -inc, -9.5);
        glVertex3f(alX     +inc, alY-0.05 -inc, -9.5);
        glVertex3f(alX+0.05+inc, alY+0.05 -inc, -9.5);
    glEnd();
    
    glBegin(GL_TRIANGLES);  
        glVertex3f(alX-0.05-inc, alY+0.05 +inc, -9.5);
        glVertex3f(alX     -inc, alY-0.05 +inc, -9.5);
        glVertex3f(alX+0.05-inc, alY+0.05 +inc, -9.5);
    glEnd();
    
    
	glBegin(GL_TRIANGLES);  
        glVertex3f(alX-0.05-inc, alY+0.05 -inc, -9.5);
        glVertex3f(alX     -inc, alY-0.05 -inc, -9.5);
        glVertex3f(alX+0.05-inc, alY+0.05 -inc, -9.5);
    glEnd();
    
    
    
	
}





void Draw::DrawPlayer(double myX, double myY){
	
	PrintOnce("drawplayer", "Player has been drawn");
	glColor3f(1,1,1);

    glBegin(GL_TRIANGLES);
        glVertex3f(myX-0.2, myY+0.0, -10.0);
        glVertex3f(myX, myY+0.2, -10.0);
        glVertex3f(myX+0.2, myY+0.0, -10.0);
    glEnd();
	
}


Draw::~Draw()
{
	
}
