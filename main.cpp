#include <iostream>
#include "game.h"


/*check for input  _
*check for collision
* update entity existance, player.h && cpp, enemy.h, .cpp
* player.class maintains player health
*draw engine
* use Vectors instead of arrays (get glen to tech push and pop)
* 
* OBJECTIVES WITH SGT GRIM:
* 
* 	* Create appropriate timer that can work with multiple system clock speeds and adjust usleep(), if used.
*   * Rip apart GLSPACEINVADERS into seperate headers and classes to make it easier to work on
* 	* Use mathamatical formulas or clever programming to make ships move in interesting ways
* 	* Impliment player death
* 
* 	: STRETCH GOALS :
* 
* 	* Import 3D model instead of triangle
* 	
* 
*/


int main(){

Game GameHeart;
GameHeart.run();

return 0;

}
