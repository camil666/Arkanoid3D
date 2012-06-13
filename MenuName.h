#pragma once
#include "OS.h"
#include <vector>
#include <string>
#include "MenuBase.h"

using namespace std;

class MenuName
{
private:
	vector<string> menuEntries;
	char buffer[21];
	long points;
	GLfloat width;
	GLfloat height;
	void DrawMenu(void);

public:
	MenuName(long pts);
	~MenuName(void);

	void display();
	int pressKey (int key, int x, int y);
	GLfloat getWidth();
	GLfloat getHeight();
	void setWidth(GLfloat);
	void setHeight(GLfloat);
	long getPoints() {return points;};
	char* getBuffer();
};

