#ifndef LASER_H
#define LASER_H

class Laser{
	public:
	
	//enum colour {RED, BLUE, CYAN, GREEN, ORANGE, YELLOW, WHITE};
	//IMPLIMENT LATER
	
	Laser();
	Laser(double shooterXPos, double shooterYPOS);
	Laser(double shooterXPos, double shooterYPOS, bool goUp);
	bool isGoUp;
	double lx;
	double ly;
	bool isActive;
	~Laser();
};

#endif
