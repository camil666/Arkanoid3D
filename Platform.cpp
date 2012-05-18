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
	float boundaryX = (border->getWidth()-size)/2.0;
	float boundaryY = (border->getHeight()-size)/2.0;

	if ((posY <= boundaryY) && (posY >= -boundaryY))
		if((velY > 0) && (posY == boundaryY))
		{
		}
		else if((velY < 0) && (posY == -boundaryY))
		{
		} 
		else
			posY += velY*rate;
	else if (posY < -boundaryY)
		posY = -boundaryY;
	else if (posY > boundaryY)
		posY = boundaryY;
	
	if ((posX <= boundaryX) && (posX >= -boundaryX))
		if((velX > 0) && (posX == boundaryX))
		{
		}
		else if((velX < 0) && (posX == -boundaryX))
		{
		} 
		else
			posX += velX*rate;
	else if (posX < -boundaryX)
		posX = -boundaryX;
	else if (posX > boundaryX)
		posX = boundaryX;
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