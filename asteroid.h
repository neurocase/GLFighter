#ifndef ASTEROID_H
#define ASTEROID_H


class Asteroid{
	
	public:
		Asteroid();
		~Asteroid();
		double getAstPosX();
		double getAstPosY();
		double getAstRot();
		void setAstRot(double rot);
		void setAstPos(double Ax,double Ay);
		double getAstMovSpd();
		bool isAstAlive;
		void   moveStep();
		double AstSize;
		double AstExplo;
	private:
		double AstX;
		double AstMovSpeed;
		double AstY;
		double AstRot;

		double astDiff; //difficulty	
	
};


#endif
