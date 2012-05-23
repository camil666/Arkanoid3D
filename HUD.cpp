#include "HUD.h"
#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <string>
#include <sstream>
using namespace std;

HUD::HUD(void):w1(800.0),h1(600.0)
{

}


HUD::~HUD(void)
{

}

void HUD::display(int points)
{
	
	glPushMatrix();

	glColor3f(1.0,0.0,0.0);
    glTranslatef(-12.0,-16.0,-1.5);
    glScalef(0.02,0.02,0.02);
	string s;
	stringstream out;
	out << points;
	s = "points:" + out.str();
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

