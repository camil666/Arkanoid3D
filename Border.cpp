#include "OS.h"
#include "Border.h"
#ifdef WINDOWS //if using windows then do windows specific stuff.
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

Border::Border(void):width(25.0f), height(25.0f), depth(62.5f)
{
}

Border::~Border(void)
{
}

void Border::display()
{
	float min;
	if(width < height)		//get the lowest dimension
	{
		if(width < depth)
			min = width;
		else
			min = depth;
	}
	else
	{
		if(height < depth)
			min = height;
		else
			min = depth;
	}


	glPushMatrix();
    glColor3f(1.0f, 1.0f, 0.0f);
	glScalef(width/min, height/min, depth/min);	//set the right proportions
	glTranslatef(0.0f, 0.0f, -(min/2.0f));	//move the border
	GLfloat mShininess[] = {50.0f};

    GLfloat DiffuseMaterial[] = {0.0f, 0.7f, 0.0f};
    GLfloat AmbientMaterial[] = {0.0f, 0.7f, 0.0f};
    GLfloat SpecularMaterial[] = {1.0f, 1.0f, 1.0f};

    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, DiffuseMaterial);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, AmbientMaterial);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, SpecularMaterial);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mShininess);
    glutWireCube(min);
	glPopMatrix();
}

float Border::getWidth()
{
	return width;
}

float Border::getHeight()
{
	return height;
}

float Border::getDepth()
{
	return depth;
}
