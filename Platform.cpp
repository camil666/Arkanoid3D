#include "Platform.h"
#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include "Border.h"

Platform::Platform(void):size(5.0f),posX(0),posY(0),posZ(-(size*0.05)),velX(0),velY(0)
{
}

Platform::~Platform(void)
{
}

void Platform::display(void)
{
	glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f);
	glTranslatef(posX, posY, posZ);
	glScalef(1.0f, 1.0f, 0.10f);
    glutWireCube(size);
	glPopMatrix();
}

void Platform::move(float rate, Border *border)
{
	float boundary = (border->getSize()-size)/2.0;

	if ((posY <= boundary) && (posY >= -boundary))
		posY += velY*rate;
	else if (posY < -boundary)
		posY = -boundary;
	else if (posY > boundary)
		posY = boundary;
	
	if ((posX <= boundary) && (posX >= -boundary))
		posX += velX*rate;
	else if (posX < -boundary)
		posX = -boundary;
	else if (posX > boundary)
		posX = boundary;
}

void Platform::setVelX(float x)
{
	velX = x;
}

void Platform::setVelY(float y)
{
	velY = y;
}

float Platform::getPosX()
{
	return posX;
}

float Platform::getPosY()
{
	return posY;
}

float Platform::getPosZ()
{
	return posZ;
}

float Platform::getSize()
{
	return size;
}