#include "OS.h"
#include "MenuPause.h"
#ifdef WINDOWS //if using windows then do windows specific stuff.
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glut.h>
#include <string>

MenuPause::MenuPause(void): MenuBase()
{
	menuEntries.push_back("Return");
	menuEntries.push_back("To Main Menu");
	menuEntries.push_back("Exit");

}


MenuPause::~MenuPause(void)
{

}

int MenuPause::pressKey(int key, int x, int y)
{
	switch (key)
	{
		case GLUT_KEY_UP:
						  break;
		case GLUT_KEY_DOWN:
							break;
		case 13:		//enter
			break;
		case 27:		//escape
			break;
    }
	return 0;
}

void MenuPause::display()
{

}

GLfloat MenuPause::getWidth()
{
	return this->width;
}


GLfloat MenuPause::getHeight()
{
	return this->height;
}

void MenuPause::setWidth(GLfloat width)
{
	this->width = width;
}

void MenuPause::setHeight(GLfloat height)
{
	this->height = height;
}
