#pragma once
class PowerUp
{
protected:
	float vel;
	float posX;
	float posY;
	float posZ;
	float angle;
	float rotateSpeed;
	float size;
	float colR;
	float colG;
	float colB;

public:
	PowerUp(void);
	PowerUp(float pX, float pY, float pZ);
	virtual ~PowerUp(void);

	void display();
	void move(float rate);

	float getPosX();
	float getPosY();
	float getPosZ();

	float getSize();

	virtual void activate()=0;
};

