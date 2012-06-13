#include "OS.h"
#include "MenuHOF.h"
#ifdef WINDOWS //if using windows then do windows specific stuff.
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <string>

using namespace std;

MenuHOF::MenuHOF(void)
{
	HallOfFame hofList;
	menuEntries = hofList.get();
}


MenuHOF::~MenuHOF(void)
{

}

int MenuHOF::pressKey(int key, int x, int y)
{
	if (key==13)
	{
		return -1;
	}
	return 1;
}

void MenuHOF::display()
{
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);
    glScalef(1, -1, 1);
    glTranslatef(0, -height, 0);
    glMatrixMode(GL_MODELVIEW);
	DrawMenu();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
}

void MenuHOF::DrawMenu()
{
	int i;
	for(i = 0 ; i < menuEntries.size() ; i++)
	{
		glPushMatrix();
		glRasterPos2i(100,100+i*50);
		glColor3f(1.0f,1.0f,1.f);
		string temp = this->menuEntries.at(i);
		glutBitmapString(GLUT_BITMAP_HELVETICA_18,(unsigned char *)temp.c_str());
		glPopMatrix();
	}
}

GLfloat MenuHOF::getWidth()
{
	return this->width;
}


GLfloat MenuHOF::getHeight()
{
	return this->height;
}

void MenuHOF::setWidth(GLfloat width)
{
	this->width = width;
}

void MenuHOF::setHeight(GLfloat height)
{
	this->height = height;
}

