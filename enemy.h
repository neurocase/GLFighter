#ifndef ENEMY_H
#define ENEMY_H


class Alien{
	
	public:
		Alien();
		~Alien();
		double getAlienPosX();
		double getAlienPosY();
		void setAlienPos(double Ax,double Ay);
	
	private:
		double AlienX;
		double AlienY;
		bool isAlienAlive;
		double alienSize;
		double alienDiff; //difficulty	
	
};


struct Alien {


};



#endif
