#ifndef DRAW_H
#define DRAW_H

class Draw{
	
	public:
	
	Draw();
	void DrawBoundaries();
	void DrawPlayer(double myX);
	void DrawAlien(double alX, double alY, double rot);
	void DrawMissle(double mislX, double mislY);
	void DrawLaser(double laserX,double laserY);
	~Draw();
	
	
};


#endif 
