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
		void AlFire();
		bool isAlienAlive;
		void   moveStep();
		double alienSize;
		double alienExplo;
		void setAlLaserPos(double val,int i, char c);
		
		struct allaserPos
		{
		double lx;
		double ly;
		bool isActive;
		}aLaserPos[3];
		
	private:
		long getTime();
		double AlienX;
		double AlMovSpeed;
		double AlienY;
		double AlienRot;
		long timeLastShoot;
		double alienDiff; //difficulty	
		bool goRight;
	
};


#endif
