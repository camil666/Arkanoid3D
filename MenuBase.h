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
	bool paused;
	char choice;
	float torusAngle;

public:
	MenuBase(void);
	virtual ~MenuBase(void);
	
	GLfloat w1;
	GLfloat h1;
	virtual void display() = 0;
	virtual int pressKey (int key, int x, int y) = 0;

};

