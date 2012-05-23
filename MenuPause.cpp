#include "MenuPause.h"
#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <string>

MenuPause::MenuPause(void): MenuBase()
{
	menuEntries.push_back("Return");
	menuEntries.push_back("To Main Menu");
	menuEntries.push_back("Exit");

	paused = false;
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

