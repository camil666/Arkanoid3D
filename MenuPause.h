#pragma once
#include <vector>
#include <string>
#include "MenuBase.h"
#include <GL\GL.h>
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

