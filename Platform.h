#pragma once
class Border;

class Platform
{
private:
	float size;
	float posX;
	float posY;
	float posZ;
	float velX;
	float velY;
public:
	Platform(void);
	~Platform(void);

	void display(void);
	void move(float rate, Border *border);
	void setVelX(float x);
	void setVelY(float y);
	float getPosX();
	float getPosY();
	float getPosZ();
	float getSize();
};

