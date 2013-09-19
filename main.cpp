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
/*
struct laserPos
{
	double lx;
	double ly;
	bool isActive;
};*/
void keyboard(unsigned char key, int x, int y)
{
	Player* Playr = GameHeart.getPlayer();
   switch (key) {
      case 27: exit(0); break;
      case 'a':
      Playr->setDirection(-1);
      break;
      case 'd':
      Playr->setDirection(1);
      break;
      case ' ':
      GameHeart.PlayerShoot();
      break;
       case 'w':
      GameHeart.PlayerShoot();
      break;
      
      default: std::cout << "KEY DOWN = " << key << "\n"; break;
   }
}

void keyboardUp(unsigned char key, int x, int y)
{
		Player* Playr = GameHeart.getPlayer();
   switch (key) {
      case 27: exit(0); break;
      case 'a':
      if  (Playr->getDirection() == -1)
      Playr->setDirection(0); //-1
      break;
      case 'd':
      if  (Playr->getDirection() == 1)
      Playr->setDirection(0); //1
      break;
  }
   std::cout << "KEY UP = " << key << "\n";
}

void onKeyPress(unsigned char key, int x, int y) {
	std::cout << "key : " << key << std::endl;
	
}

void onSpecialKeyPress(int key, int x, int y) {

	
}
void display() {
	GameHeart.GameLoop();
}

void reshape(int w, int h) {
	GameHeart.Reshape(w, h);
}
void init() // Called before main loop to set up the program
{
	double r = 0 / 256.0;
	double g = 0 / 256.0;
	double b = 70 / 256.0;
	
	
    glClearColor(r, g, b, 0.0);
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
	
	glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboardUp);
	
  //  glutKeyboardUpFunc(keyboard_up); 
    init();

    // Starts the program.
    glutMainLoop();

	return 0;
}
