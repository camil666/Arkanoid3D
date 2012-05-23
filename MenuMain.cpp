#include "MenuMain.h"
#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <string>

using namespace std;

MenuMain::MenuMain(void): MenuBase()
{
	menuEntries.push_back("New Game");
	menuEntries.push_back("Hall of fame");
	menuEntries.push_back("Exit");
}


MenuMain::~MenuMain(void)
{

}

int MenuMain::pressKey(int key, int x, int y)
{
	int retVal = -1;
	switch (key)
	{
		case GLUT_KEY_UP: 
			choice--;
			if(choice < 0)
				choice = menuEntries.size() - 1;
			break;
		case GLUT_KEY_DOWN:	
			choice++;
			if(choice >= menuEntries.size())
				choice = 0;
			break;
		case 13:		//enter
			retVal = choice;
			break;
		case 27:		//escape
			retVal = 2;
			break;
    }
	return retVal;
}

void MenuMain::display()
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

void MenuMain::DrawMenu()
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
		if(choice == i)
		{
			glBegin(GL_QUADS);
			glVertex2f(80, 90+i*50);
			glVertex2f(80, 100+i*50);
			glVertex2f(90, 90+i*50);
			glVertex2f(90, 100+i*50);
			glEnd();
		}
	}
}

GLfloat MenuMain::getWidth()
{
	return this->width;
}
	

GLfloat MenuMain::getHeight()
{
	return this->height;
}
	
void MenuMain::setWidth(GLfloat width)
{
	this->width = width;
}
	
void MenuMain::setHeight(GLfloat height)
{
	this->height = height;
}

