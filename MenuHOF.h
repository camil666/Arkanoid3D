#pragma once
#include "OS.h"
#include <vector>
#include <string>
#include "MenuBase.h"
#include "HallOfFame.h"

using namespace std;

class MenuHOF
{
private:
	vector<string> menuEntries;
	GLfloat width;
	GLfloat height;
	void DrawMenu(void);

public:
	MenuHOF(void);
	~MenuHOF(void);

	void display();
	int pressKey (int key, int x, int y);
	GLfloat getWidth();
	GLfloat getHeight();
	void setWidth(GLfloat);
	void setHeight(GLfloat);
};

