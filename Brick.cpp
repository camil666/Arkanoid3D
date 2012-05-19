#include "Brick.h"

Brick::Brick(void):size(2.0f),durability(20)
{
	posX=rand()%4 - 1;
	posY=rand()%4 - 1;
	posZ=rand()%4 + 1;
}

Brick::Brick(float x, float y, float z):size(2.0f),durability(20)
{
	posX = x;
	posY = y;
	posZ = z;
}

Brick::~Brick(void)
{
}

void Brick::display()
{
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);	//set colors
	glTranslated(posX, posY, posZ); //translate the cube
	glScalef(2.0f, 1.0f, 1.0f);	//scale the cube
	glutSolidCube(size); //draw the cuboid
	glPopMatrix();
}

float Brick::getPosX()
{
	return posX;
}

float Brick::getPosY()
{
	return posY;
}

float Brick::getPosZ()
{
	return posZ;
}

float Brick::getSize()
{
	return size;
}

bool Brick::damage(int amount)
{
	durability -= amount;
	if(durability > 0)
		return true;	//brick is still out there!
	else 
		return false;	//brick is destroyed :(
}