#include "OS.h"
#include "App.h"

#ifdef WINDOWS //if using windows then do windows specific stuff.
#include <windows.h>
#endif

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glext.h>
#include "Level.h"
#include "MenuBase.h"
#include "MenuMain.h"
#include "MenuPause.h"
#include "MenuName.h"
#include "MenuHOF.h"
#include "HallOfFame.h"
#include "HUD.h"

Level *App::level;
MenuBase *App::menuBase;
MenuHOF *App::hof;
MenuName *App::menuName;
int width, heigth;
short lvl;

App::App(void)
{
	level = NULL;
	menuBase = new MenuMain();
}

App::~App(void)
{
	delete level;
	delete menuBase;
}

void App::display(void)
{
    glClearColor (0.0,0.0,0.0,1.0); //clear the screen to black
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear the color buffer and the depth buffer
    glEnable (GL_DEPTH_TEST); //enable the depth testing
    /*glEnable (GL_LIGHTING); //enable the lighting
    glEnable (GL_LIGHT0); //enable LIGHT0, our Diffuse Light
	glEnable (GL_LIGHT1); //enable LIGHT1, our Ambient Light
	GLfloat AmbientLight[] = {0.1f, 0.1f, 0.1f};
	glLightfv (GL_LIGHT1, GL_AMBIENT, AmbientLight); //change the light accordingly*/
	GLfloat DiffuseLight[] = {1.0f, 1.0f, 1.0f};
    GLfloat AmbientLight[] = {0.2f, 0.2f, 0.2f};
    GLfloat SpecularLight[] = {1.0f, 1.0f, 1.0f};

    glLightfv (GL_LIGHT0, GL_SPECULAR, SpecularLight);
    glLightfv (GL_LIGHT0, GL_DIFFUSE, DiffuseLight);
    glLightfv (GL_LIGHT0, GL_AMBIENT, AmbientLight);
	GLfloat LightPosition[] = {10.0, 0.0, 10.0, 0.0};	//set posiotion of light
	glLightfv (GL_LIGHT0, GL_POSITION, LightPosition);
    glEnable (GL_COLOR_MATERIAL);
    glShadeModel (GL_SMOOTH); //set the shader to smooth shader
	

    glLoadIdentity();

	if (level != NULL)
	{
		int gameOver = level->display();
		if (gameOver==-1)
		{
			long pts = level->getPoints();
			delete level;
			level = NULL;
			lvl++;
			level = new Level(lvl);
			level->addPoints(pts);
			/*menuBase = new MenuMain();
			menuBase->setHeight(heigth);
			menuBase->setWidth(width);*/
		}
		else if (gameOver==-2)
		{
			long pts = level->getPoints();
			delete level;
			level = NULL;
			HallOfFame hofList;
			if(hofList.checkIfWorthy(pts))
			{
				menuName = new MenuName(pts);
				menuName->setHeight(heigth);
				menuName->setWidth(width);
			}
			else
			{
				menuBase = new MenuMain();
				menuBase->setHeight(heigth);
				menuBase->setWidth(width);
			}
		}
	}
	if(menuBase != NULL)
	{
		menuBase->display();
	}
	if(hof != NULL)
	{
		hof->display();
	}
	if(menuName != NULL)
	{
		menuName->display();
	}
    
	glutSwapBuffers(); //swap the buffers
}

void App::reshape(int w, int h)
{
    glViewport (0, 0, (GLsizei)w, (GLsizei)h); //set the viewport to the current window specifications
    glMatrixMode (GL_PROJECTION); //set the matrix to projection

    glLoadIdentity ();

    gluPerspective (60, (GLfloat)w / (GLfloat)h, 0.1, 100.0); //set the perspective (angle of sight, width, height, , depth)

	width = w;
	heigth = h;

	if(menuBase != NULL)
	{
		menuBase->setWidth((GLfloat)w);
		menuBase->setHeight((GLfloat)h);
	}
	else if(hof != NULL)
	{
		hof->setWidth((GLfloat)w);
		hof->setHeight((GLfloat)h);
	}

    glMatrixMode (GL_MODELVIEW); //set the matrix back to model
}

void App::pressKey (int key, int x, int y)
{
	if (level != NULL)
		level->pressKey(key, x, y);
	if(menuBase != NULL)
		menuBase->pressKey(key,x,y);
	if(menuName != NULL)
		menuName->pressKey(key,x,y);
}

void App::pressKeyEnter (unsigned char key, int x, int y)
{
	if(menuBase != NULL)
	{
		switch(menuBase->pressKey(key,x,y))
		{
			case 0:		//Start new game
				delete menuBase;
				menuBase = NULL;
				lvl = 1;
				level = new Level(lvl);
				break;
			case 1:		//Hall of fame
				delete menuBase;
				menuBase = NULL;
				
				hof = new MenuHOF();
				hof->setHeight(heigth);
				hof->setWidth(width);
				
				/*
				menuName = new MenuName();
				menuName->setHeight(heigth);
				menuName->setWidth(width);
				*/
				break;
			case 2:		//Exit
				exit(0);
				break;
			case 3:		//
			default:
				break;
		}
	}
	else if(level != NULL)
	{
		level->pressKey(key,x,y);
	}
	else if(hof != NULL)
	{
		short closeHOF = hof->pressKey(key, x, y);
		if(closeHOF==-1)
		{
			delete hof;
			hof = NULL;
			menuBase = new MenuMain();
			menuBase->setHeight(heigth);
			menuBase->setWidth(width);
		}
	}
	else if(menuName != NULL)
	{
		short closeName = menuName->pressKey(key, x, y);
		if(closeName==-1)
		{
			long pts = menuName->getPoints();
			char* name = menuName->getBuffer();
			HallOfFame hofList;
			hofList.add(name, pts);
			delete menuName;
			menuName = NULL;
			hof = new MenuHOF();
			hof->setHeight(heigth);
			hof->setWidth(width);
		}
	}
}

void App::releaseKey(int key, int x, int y)
{
	if (level != NULL)
		level->releaseKey(key, x, y);
}

void App::mouseButton(int button, int state, int x, int y)
{
	if (level != NULL)
		level->mouseButton(button, state, x, y);
}

void App::mouseMovement(int x, int y)
{
	if (level != NULL)
		level->mouseMovement(x, y);
}

void App::run()
{

	glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc(reshape);

	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMovement); //check for mouse movement
    //glutPassiveMotionFunc(mouseMovement); //check for mouse movement

    glutSpecialFunc(pressKey);
	glutKeyboardFunc(pressKeyEnter);

	// here are the new entries
	glutIgnoreKeyRepeat(1);
	glutSpecialUpFunc(releaseKey);

    glutMainLoop();
}
