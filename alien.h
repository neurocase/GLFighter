#ifndef ALIEN_H
#define ALIEN_H


class Alien{
	
	public:
		Alien();
		~Alien();
		double getAlienPosX();
		double getAlienPosY();
		void setAlienPos(double Ax,double Ay);
		double getAlienMovSpd();
		bool   isGoingRight();
		void   goOtherWay();
		void   moveStep();
	private:
		double AlienX;
		double AlMovSpeed;
		double AlienY;
		bool isAlienAlive;
		double alienSize;
		double alienDiff; //difficulty	
		bool goRight;
	
};


#endif
