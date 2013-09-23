#include "openGL.h"
#include "game.h"
#include "draw.h"
#include "alien.h"
#include "asteroid.h"
#include "laser.h"
#include "timer.h"

#include <ctime>
#include <cmath>
#include <iostream>
#include <unistd.h>
#include <vector>

double playerX= 0;
int spwnedAl = 0;
int totAl = 25;
int spwnedAst = 0;
int totAst = 25;

double moveRate = 0.5;

Timer mytime;

double previousTime = 0;
double startTime = 0;
double holdTime = 0;
double lastFireTime = 0;
double lastTimeHit = 0;
double alienLastShootTime = 0;
double nowTime = 0;
int life = 3;

Draw draweth;
std::vector<Alien> myAliens;
std::vector<Asteroid> myAst;
std::vector<Laser> anyLaser;
Player Playr;


Game::Game()
{
}


Player* Game::getPlayer() {
	return &Playr;
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
	return std::abs(x) < 1.3;
}

void moveAlienX(Alien& alien){
	double X = alien.getAlienPosX();
	if (!insideBoundary(X) && alien.isAlienAlive){
		alien.goOtherWay();
	}
	alien.moveStep();
}

void Game::PlayerShoot(){
	if ((nowTime - lastFireTime)  > 1 && (life > 0))
	{
		std::cout << "player shoots";
		lastFireTime=nowTime;
    anyLaser.push_back(Laser(playerX, -1.2));
	}
		
}




void Game::GameLoop()
{
	if (startTime == 0){
		startTime = mytime.getTime();
		lastFireTime = mytime.getTime();
		startTime = mytime.getTime();
		alienLastShootTime = mytime.getTime();
	}
	
	nowTime = mytime.getTime();
    double delta = nowTime - previousTime;
    // std::cout << delta << std::endl;
    //TODO:fix the speed constants where delta is used
    //a tempoary fix is to adjust the delta time directly
    delta = delta * 10;
	
	/*
	 *  ULTIMATELY WANT TO REPLACE THE FOLLOWING "SPAWN" SECTIONS OF CODE
	 *  BY CONTROLLING SPAWNING WITH TEXT FILES, EACH LINE SAYING
	 *  [enemytype] : [timespawn]
	 * 
	 */
	
	if((nowTime > 3) && (spwnedAst < totAst) && (nowTime - holdTime > 1))
	{
		
		myAst.push_back(Asteroid());
		std::cout << "create asteroid" << myAst.size() <<  std::endl;
		spwnedAst++;
	}
	
	
	
	
	if((nowTime > 3) && (spwnedAl < totAl) && (nowTime - holdTime > 1))
	{
		myAliens.push_back(Alien());
		std::cout << "create alien " << myAliens.size() << std::endl;
		spwnedAl++;
		holdTime = mytime.getTime();
	}
	
	if (spwnedAl == totAl){
		std::cout << nowTime;
	}
	
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();


	
	    // LASER   LASER   LASER   LASER   LASER   LASER   LASER   LASER   LASER  LASER   LASER   LASER   
    double charge = (nowTime - lastFireTime);
    draweth.DrawCharge(charge);
    
    draweth.DrawLife(life);
    
    for (int i = 0; i < anyLaser.size(); i++)
    {
      double ly = anyLaser[i].ly;
      double lx = anyLaser[i].lx;
      if(anyLaser[i].isActive)
      {
        if ((anyLaser[i].isGoUp) && (life > 0))
        {
          ly += moveRate * delta;
          draweth.DrawLaser(lx, ly);
        }else{
          ly -= moveRate * delta;
          draweth.DrawAlLaser(lx, ly);
          
        }
        anyLaser[i].ly = ly;
        
      }else{
        anyLaser[i].lx = playerX;
      }
    }
	
	if ((Playr.getDirection() == 1) && (playerX < 1.3)){
		playerX+= 0.35 * delta;
	}else if ((Playr.getDirection() == -1) && (playerX > -1.3)){
		playerX -= 0.35 * delta;
	}
	
		for (int j = 0; j < anyLaser.size(); j++)
			{
				if (!anyLaser[j].isGoUp)
				{
					double hitx;
					double hity;
					
					hitx = (anyLaser[j].lx) - playerX;
					hity = (anyLaser[j].ly) - -1.5;
					
					hitx = std::abs(hitx);
					hity = std::abs(hity);
					
					if ((hitx < 0.2 && hity < 0.2) && (nowTime - lastTimeHit > 1))
					{
						lastTimeHit = nowTime;
						life--;
							
					}
				}
				
			}
	
	
	if (life > 0){
	draweth.DrawPlayer(playerX, -1.5);
	}
	draweth.DrawBoundaries();
  
	//start ast
	
	for (unsigned int i = 0; i < myAst.size(); i++) {
		Asteroid& ast = myAst[i];
		double myAstPosX = ast.getAstPosX();
		double myAstPosY = ast.getAstPosY();
		if (ast.isAstAlive){
		double myRot = ast.getAstRot();
		myAstPosY-=0.25*delta;
		ast.setAstPos(myAstPosX,myAstPosY);
			
    			for (int j = 0; j < anyLaser.size(); j++)
			{
				if (anyLaser[j].isGoUp)
				{
					double hitx;
					double hity;
					
					hitx = (anyLaser[j].lx) - myAstPosX;
					hity = (anyLaser[j].ly) - myAstPosY;
					
					hitx = std::abs(hitx);
					hity = std::abs(hity);
					
					if (hitx < ast.AstSize && hity < ast.AstSize) 
					{

						ast.isAstAlive = false;
							
					}
				}
				
			}
			
			double phitx;
			double phity;
			
			phitx = playerX - myAstPosX;
			phity = -1.5 - myAstPosY;
			
			phitx = std::abs(phitx);
			phity = std::abs(phity);
			
			if ((phitx < ast.AstSize && phity < ast.AstSize) && (nowTime - lastTimeHit > 1))
			{

				lastTimeHit = nowTime;
				life--;
			}
	
		myRot+= moveRate * delta;
		ast.setAstRot(myRot);
			
		draweth.DrawAsteroid(myAstPosX, myAstPosY, myRot);

		}else if (ast.AstExplo < 0.3){
			ast.AstExplo += 0.1 * delta; 
			draweth.DrawExplosion(myAstPosX, myAstPosY, ast.AstExplo);
		}
	}	
	
	
	//end ast
	
	// ROTATING ALIEN
	for (unsigned int i = 0; i < myAliens.size(); i++) {
		Alien& alien = myAliens[i];
		double myAlPosX = alien.getAlienPosX();
		double myAlPosY = alien.getAlienPosY();
		if (alien.isAlienAlive)
		{
			double myRot = alien.getAlienRot();
			
			myRot-=0.1*delta;
  //CHECKING IF ALIEN IS HIT BY LASER
			for (int j = 0; j < anyLaser.size(); j++)
			{
				if (anyLaser[j].isGoUp)
				{
					double hitx;
					double hity;
					
					hitx = (anyLaser[j].lx) - myAlPosX;
					hity = (anyLaser[j].ly) - myAlPosY;
					
					hitx = std::abs(hitx);
					hity = std::abs(hity);
					
					if (hitx < alien.alienSize && hity < alien.alienSize) 
					{

						alien.isAlienAlive = false;
							
					}
				}
				
			}
			
			double phitx;
			double phity;
			
			phitx = playerX - myAlPosX;
			phity = -1.5 - myAlPosY;
			
			phitx = std::abs(phitx);
			phity = std::abs(phity);
			
			if ((phitx < alien.alienSize && phity < alien.alienSize) && (nowTime - lastTimeHit > 1))
			{

				lastTimeHit = nowTime;
				life--;
			}
			
			char c = 'g';
			//  IF ALIEN X POS = PLAYXPOS ALIEN SHOOT
			if ((std::abs(myAlPosX - playerX) < 0.2) && (life > 0)) {
				if ((nowTime - alienLastShootTime) > 1){
					std::cout << "alien shoots" << std::endl;
          anyLaser.push_back(Laser(myAlPosX, myAlPosY, false));
					alienLastShootTime = nowTime;
       
					}
			}
				
			draweth.DrawAlien(myAlPosX, myAlPosY, c);

		} else if (alien.alienExplo < 0.3){
			alien.alienExplo += 0.1 * delta; 
			draweth.DrawExplosion(myAlPosX, myAlPosY, alien.alienExplo);
		}
		moveAlienX(alien);

	}	
    previousTime = nowTime;
	glutSwapBuffers();
}

Game::~Game()
{
} 
