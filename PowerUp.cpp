#include "OS.h"
#include "PowerUp.h"
#ifdef WINDOWS //if using windows then do windows specific stuff.
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glut.h>

PowerUp::PowerUp(void):vel(0.1f)
{
}

PowerUp::PowerUp(float pX, float pY, float pZ):posX(pX),posY(pY),posZ(pZ),vel(0.1f),angle(0.0f),rotateSpeed(1.0f),size(0.6f)
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
	GLfloat mShininess[] = {50};

    GLfloat DiffuseMaterial[] = {colR, colG, colB};
    GLfloat AmbientMaterial[] = {colR/2, colG/2, colB/2};
    GLfloat SpecularMaterial[] = {1.0f, 1.0f, 1.0f};

    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, DiffuseMaterial);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, AmbientMaterial);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, SpecularMaterial);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mShininess);
    drawCheerios(size/2,size,15,15);
	glPopMatrix();
}

void PowerUp::move(float rate)
{
	posZ+=vel*rate;
	angle+=rate*rotateSpeed;
}

void PowerUp::drawCheerios(double innerRadius, double outerRadius, int nsides, int rings)
{
	glutSolidTorus(innerRadius, outerRadius, nsides, rings);
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
