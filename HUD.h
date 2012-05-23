#pragma once
#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

class HUD
{
private:
	

public:
	GLfloat w1;
	GLfloat h1;
	HUD(void);
	~HUD(void);
	void display(int);
};

