#pragma once
#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

class Brick
{
private:
	float size;
	float posX;
	float posY;
	float posZ;
	int durability;

public:
	Brick(void);
	Brick(float x, float y, float z);
	~Brick(void);

	void display();
	float getPosX();
	float getPosY();
	float getPosZ();
	float getSize();
	bool damage(int amount);
};

