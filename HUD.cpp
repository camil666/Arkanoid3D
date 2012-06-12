#include "OS.h"
#include "HUD.h"
#ifdef WINDOWS //if using windows then do windows specific stuff.
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <string>
#include <sstream>
#include "HUDInfo.h"
using namespace std;

HUD::HUD(void)
{

}


HUD::~HUD(void)
{

}

void HUD::display(HUDInfo *hudInfo)
{
	glPushMatrix();

	glColor3f(1.0,0.0,0.0);
    glTranslatef(-12.0,-16.0,-1.5);
    glScalef(0.02f,0.02f,0.02f);
	string s;
	stringstream out;
	stringstream out2;
	out << hudInfo->getPoints();
	s = "points:" + out.str();
	out2 << hudInfo->getLives();
	s += " lives:" + out2.str();
	glutStrokeString(GLUT_STROKE_ROMAN,(unsigned char *)s.c_str());
	glPopMatrix();

	/*
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, w1/2, 0, h1/2);

	glScalef(0.1, 0.1, 0.1);
	glTranslatef(0, 13.0, -4.0);
	glMatrixMode(GL_MODELVIEW);


	glLoadIdentity ();

	glColor3f(1.0,0.0,0.0);
	glBegin(GL_TRIANGLES);
		glVertex3d(0,     0, -0.5);
		glVertex3d(1.0,   0, -0.5);
		glVertex3d(0.5, 1.0, -0.5);
	glEnd();

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	*/
}

