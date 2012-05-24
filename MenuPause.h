#pragma once
#include <vector>
#include <string>
#include "MenuBase.h"
#ifdef WIN32
#include <GL\GL.h>
#else
#include <GL/gl.h>
#endif

using namespace std;


class MenuPause: public MenuBase
{
public:
	MenuPause(void);
	~MenuPause(void);

	void display();
	int pressKey (int key, int x, int y);
	GLfloat getWidth();
	GLfloat getHeight();
	void setWidth(GLfloat);
	void setHeight(GLfloat);
};

