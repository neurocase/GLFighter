void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
	

  // DRAW BOUNDARIES 
  
    glBegin(GL_LINES);
		glVertex3f(1.5, 0, -10.0);
		glVertex3f(1.5, 4, -10.0);
		glVertex3f(-1.5, 0, -10.0);
		glVertex3f(-1.5, 4, -10.0);
	glEnd();

	
	glColor3f(1,1,0);
	glTranslated(0,-2,0);
    glBegin(GL_TRIANGLES);
        glVertex3f(SpaceShipX-0.2, 0.0, -10.0);
        glVertex3f(SpaceShipX, 0.2, -10.0);
        glVertex3f(SpaceShipX+0.2, 0.0, -10.0);
    glEnd();
	
	

	
	timeNew = dazTime();

	if ((spwnedAliens < totNumAliens-1) && ((timeNew - timeStored) > 3)) {
		std::cout << "SPAWNING" << "spnd" << spwnedAliens << "tot" << totNumAliens << std::endl;
		spwnedAliens++;
		spawnAlien(steveAlien, 1);	
		timeStored = dazTime();
	}else if ((timeNew - timeStored) > 3){
		std::cout << "NOT SPAWNING" << std::endl;
		timeStored = dazTime();
	}
	
	for(int i = 0; i < spwnedAliens; i++){
		
	drawAlien(steveAlien, i);
		moveAlien(deltaT, steveAlien, i, spwnedAliens);
	}
		
	
	//}
	
	
/*	clock_t t = clock();
	double now = t / (double)CLOCKS_PER_SEC;
	deltaT = now - lastTime;
    lastTime = now;
    std::cout << "t: " << t << " now: " << now << " lastt :" << lastTime << "deltaT: " << deltaT << std::endl;
    */
    deltaT = 0.005;
	
	
	glColor3f(1,0,0);
	if (isBulletActive == true){
		glBegin(GL_LINES);
		glVertex3f(BulletX, BulletY, -10.0);
		glVertex3f(BulletX, BulletY+0.1, -10.0);
		if (BulletY > 4){
			isReloaded = true;
		}
		glEnd();
		BulletY+=deltaT * 20;
	}
	
	if (bulletHitAlien(steveAlien, 1)){
		steveAlien[1].isAlienAlive = false;
	}
	
	glutSwapBuffers();
		

	
	
		
}
