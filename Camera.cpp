#include "Camera.h"
#ifdef WIN32 //if using windows then do windows specific stuff.
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glut.h>

Camera::Camera(void):xrot(0),yrot(0),cRadius(35)
{
}

Camera::~Camera(void)
{
}

void Camera::setAngle(void)
{
	glTranslatef(0.0f, 0.0f, -cRadius);
    glRotatef(xrot,1.0,0.0,0.0);
	glRotatef(yrot,0.0,1.0,0.0);
}

void Camera::move(int x, int y, bool &justStarted)
{
	int diffx = (int)(x-lastx); //check the difference between the current x and the last x position
	int diffy = (int)(y-lasty); //check the difference between the current y and the last y position

	if(justStarted == true)
	{
		diffx = 0;
		diffy = 0;
		justStarted = false;
	}

	lastx = x; //set lastx to the current x position
	lasty = y; //set lasty to the current y position

	xrot += (float) diffy; //set the xrot to xrot with the addition of the difference in the y position
	if (xrot > 90)
		xrot = 90;
	else if (xrot < -90)
		xrot= -90;

	yrot += (float) diffx;    //set the xrot to yrot with the addition of the difference in the x position
	if (yrot > 90)
		yrot = 90;
	else if (yrot < -90)
		yrot = -90;
}
