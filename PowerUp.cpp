#include "PowerUp.h"
#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

PowerUp::PowerUp(void):vel(0.1)
{
}

PowerUp::PowerUp(float pX, float pY, float pZ):posX(pX),posY(pY),posZ(pZ),vel(0.1),angle(0),rotateSpeed(1),size(0.6)
{
}

PowerUp::~PowerUp(void)
{
}

void PowerUp::display()
{
	glPushMatrix();
    glColor3f(colR, colG, colB);
	glTranslatef(posX, posY, posZ);
	glRotatef (angle, 1.0f, 1.0f, 1.0f);
    glutSolidTorus(size/2,size,15,15); 
	glPopMatrix();
}

void PowerUp::move(float rate)
{
	posZ+=vel*rate;
	angle+=rate*rotateSpeed;
}

float PowerUp::getPosX()
{
	return posX;
}

float PowerUp::getPosY()
{
	return posY;
}

float PowerUp::getPosZ()
{
	return posZ;
}

float PowerUp::getSize()
{
	return size;
}