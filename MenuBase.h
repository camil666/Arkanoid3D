#pragma once

#include <vector>
#include <string>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

using namespace std;


class MenuBase
{
protected:
	vector<string> menuEntries;
	char choice;
	GLfloat width;
	GLfloat height;

public:
	MenuBase(void);
	virtual ~MenuBase(void);
	virtual void display() = 0;
	virtual int pressKey (int key, int x, int y) = 0;
	virtual GLfloat getWidth() = 0;
	virtual void setWidth(GLfloat) = 0;
	virtual GLfloat getHeight() = 0;
	virtual void setHeight(GLfloat) = 0;
};

