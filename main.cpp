#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <unistd.h>

#include <iostream>
#include "game.h"
#include "player.h"

/*check for input  _
*check for collision
* update entity existance, player.h && cpp, enemy.h, .cpp
* player.class maintains player health
*draw engine
* use Vectors instead of arrays (get glen to tech push and pop)
* 
* OBJECTIVES WITH SGT GRIM:
* 
* 	* Impliment Multiple Ship Spawn Time
* 	* Impliment Ship Fireing
* 	* Create appropriate timer ( currently appears not to have timer)
* 	* Use mathamatical formulas or clever programming to make ships move in interesting ways
* 	* Use inheritance and polymorphism to create bomber alien
* 	* Impliment player death
* 
* 
* 
* 	: STRETCH GOALS :
* 
* 	* Import 3D model instead of triangle
* 	
* 
*/



Game GameHeart;
Player Play;
static double myShipX = Play.getShipXPos();
void onKeyPress(unsigned char key, int x, int y) {
	std::cout << "key : " << key << std::endl;
	
}

void onSpecialKeyPress(int key, int x, int y) {
	std::cout << "SpKey : " << key << std::endl;
	
	if (key == GLUT_KEY_LEFT){
		Play.setShipXPos(-0.15);
	}else if (key == GLUT_KEY_RIGHT){
		Play.setShipXPos(0.15);
	}/*else if (key == GLUT_KEY_UP){

		//Play.fireLaser
		
	}else if (key == GLUT_KEY_DOWN){
	 
		//Play.fireMisl
	}*/
	myShipX = Play.getShipXPos();
	GameHeart.setMyShipX(myShipX);
	
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
