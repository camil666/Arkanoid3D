#include "OS.h"
#include "Platform.h"
#ifdef WINDOWS //if using windows then do windows specific stuff.
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glut.h>
#include "Border.h"

Platform::Platform(void):size(5.0f),posX(0.0f),posY(0.0f),posZ(-(size*0.05f)),velX(0.0f),velY(0.0f)
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
	GLfloat mShininess[] = {50.0f};

    GLfloat DiffuseMaterial[] = {1.0f, 0.0f, 0.0f};
    GLfloat AmbientMaterial[] = {0.5f, 0.0f, 0.0f};
    GLfloat SpecularMaterial[] = {1.0f, 1.0f, 1.0f};

    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, DiffuseMaterial);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, AmbientMaterial);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, SpecularMaterial);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mShininess);
    glutWireCube(size);
	glPopMatrix();
}

void Platform::move(float rate, Border *border)
{
	float boundaryX = (border->getWidth()-size)/2.0f;
	float boundaryY = (border->getHeight()-size)/2.0f;

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
