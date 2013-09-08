#ifndef ALIEN_H
#define ALIEN_H


class Alien{
	
	public:
		Alien();
		~Alien();
		double getAlienPosX();
		double getAlienPosY();
		double getAlienRot();
		void setAlienRot(double rot);
		void setAlienPos(double Ax,double Ay);
		double getAlienMovSpd();
		bool   isGoingRight();
		void   goOtherWay();
		void   moveStep();
	private:
		double AlienX;
		double AlMovSpeed;
		double AlienY;
		double AlienRot;
		bool isAlienAlive;
		double alienSize;
		double alienDiff; //difficulty	
		bool goRight;
	
};


#endif
