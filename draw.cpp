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
	
void Draw::DrawAlien(double alX, double alY)
{
	
	PrintOnce("aliens", "Alien has been drawn");
	glColor3f(0,1,0);
	
	glBegin(GL_TRIANGLES);  
        glVertex3f(alX-0.1, alY+0.1, -10.0);
        glVertex3f(alX, alY-0.1, -10.0);
        glVertex3f(alX+0.1, alY+0.1, -10.0);
    glEnd();
	
}


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
