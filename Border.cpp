#include "Border.h"
#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

Border::Border(void):size(25.0f)
{
}

Border::~Border(void)
{
}

void Border::display()
{
	glPushMatrix();
    glColor3f(1.0f, 1.0f, 0.0f);
	glScalef(1.0f, 1.0f, 2.5f);
	glTranslatef(0.0f, 0.0f, -(size/2.0));
    glutWireCube(size);
	glPopMatrix();
}

float Border::getSize()
{
	return size;
}