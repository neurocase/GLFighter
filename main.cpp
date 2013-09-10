#include "openGL.h"
#include <unistd.h>

#include <iostream>
#include "game.h"
#include "player.h"

/*
*
*    CURRENT PROBLEMS, 
* 
* 
*  - 	Difficulty understanding passing variables between multiple .cpp files.
* 
*  -	Difficulty passing data with pointers and addresses. 
*   		this has created many problems, such as having both main.cpp and game.cpp co-operate with player.cpp
* 			all though there may be simpler ways to do this, or it be easier to contain all code in one class file,
* 			I am trying to increase my understanding of passing data to different parts of the program, over different barriers,
* 			such as different classes/files etc.
* 
* 	
* 
*/



Game GameHeart;
//Player Play;
//static double myShipX = Play.getShipXPos();
//double *shipXPosA = &GameHeart.getGShipXPosAddy();
//double* shipXPosP = &shipXPosA;
//double shipXtemp = *&shipXPosA;

struct laserPos
{
	double lx;
	double ly;
	bool isActive;
};



void onKeyPress(unsigned char key, int x, int y) {
	std::cout << "key : " << key << std::endl;
	
}

void onSpecialKeyPress(int key, int x, int y) {
	//std::cout << "SpKey : " << key << std::endl;
	//std::cout << "&shipXPosA : " << &GameHeart.getGShipXPosAddy() << std::endl;
	//std::cout << "GameHeart.getGShipXPosAddy()" << GameHeart.getGShipXPosAddy() << std::endl;
	//std::cout << "shipXPosA : " << *shipXPosA << std::endl;
	//std::cout << "*shipXPosP : " << *shipXPosP << std::endl;
	//std::cout << "shipXPosP : " << shipXPosA << std::endl;
	
	//double shipXtemp = GameHeart.getGShipXPosAddy();
	if (key == GLUT_KEY_LEFT){
		GameHeart.setMyShipX(-0.1);
	}else if (key == GLUT_KEY_RIGHT){
		GameHeart.setMyShipX(0.1);
	}else if (key == GLUT_KEY_UP){

		//Play.fireLaser();
		
	}
	
	
	/*else if (key == GLUT_KEY_DOWN){
	 
		//Play.fireMisl
	}*/
	//myShipX = Play.getShipXPos();
	//GameHeart.setMyShipX(myShipX);
	
}
void display() {
	GameHeart.GameLoop();
}

void reshape(int w, int h) {
	GameHeart.Reshape(w, h);
}
void init() // Called before main loop to set up the program
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
}
int main(int argc, char **argv){
 glutInit(&argc, argv); // Initializes glut

    // Sets up a double buffer with RGBA components and a depth component
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);

    // Sets the window size to 512*512 square pixels
    glutInitWindowSize(512, 512);

    // Sets the window position to the upper left
    glutInitWindowPosition(0, 0);

    // Creates a window using internal glut functionality
    glutCreateWindow("Hello!");

    // passes reshape and display functions to the OpenGL machine for callback
    glutReshapeFunc(reshape);
    
    glutDisplayFunc(display);
    glutIdleFunc(display);
    
   // void glutKeyboardFunc(void (*func)(unsigned char key, int x, int y));
	
	glutKeyboardFunc(onKeyPress);
	glutSpecialFunc(onSpecialKeyPress);

    init();

    // Starts the program.
    glutMainLoop();

	return 0;
}
