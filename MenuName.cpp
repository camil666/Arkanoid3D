#include "MenuName.h"
#include "OS.h"
#ifdef WINDOWS //if using windows then do windows specific stuff.
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <string>

using namespace std;


MenuName::MenuName(long pts)
{
	points = pts;
	buffer[0] = '\0';
	menuEntries.push_back("Congratulations! Have have earned yourself a place in Hall of Fame!");
	menuEntries.push_back("Press ENTER to confirm");
	menuEntries.push_back("Your name: ");
}


MenuName::~MenuName(void)
{

}

int MenuName::pressKey(int key, int x, int y)
{
	if ((key>=48 && key<=57)||(key>=65 && key<=90)||(key>=97 && key<=122))
	{
		if(strlen(buffer)<20)
		{
			char character[2] = {(char)key, '\0'};
			strcat(buffer, character);
			menuEntries.pop_back();
			char output[40] = "Your name: ";
			strcat(output, buffer);
			menuEntries.push_back(output);
		}
	}
	else if (key==8)
	{
		buffer[(strlen(buffer)-1)] = '\0';
		menuEntries.pop_back();
		char output[40] = "Your name: ";
		strcat(output, buffer);
		menuEntries.push_back(output);
	}
	else if (key==13)
	{
		return -1;
	}
	return 1;
}

void MenuName::display()
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

void MenuName::DrawMenu()
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

GLfloat MenuName::getWidth()
{
	return this->width;
}


GLfloat MenuName::getHeight()
{
	return this->height;
}

void MenuName::setWidth(GLfloat width)
{
	this->width = width;
}

void MenuName::setHeight(GLfloat height)
{
	this->height = height;
}

char* MenuName::getBuffer()
{
	return buffer;
}
