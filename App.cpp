#include "App.h"
#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include "Platform.h"
#include "BrickSet.h"
#include "Border.h"
#include "Ball.h"
#include "Camera.h"

bool App::buttonPressed;
bool App::justStarted;
float App::fLastIdleTime;
Camera *App::camera;
Border *App::border;
Platform *App::platform;
BrickSet *App::brickSet;
Ball *App::ball;

App::App(void)
{
	buttonPressed = false;
	fLastIdleTime = 0;
	camera = new Camera();
	border = new Border();
	platform = new Platform();
	brickSet = new BrickSet();
	ball = new Ball();
}

App::~App(void)
{
	delete camera;
	delete border;
	delete platform;
	delete brickSet;
	delete ball;
}

void App::display(void) 
{
	float fTime, fSimTime;
 
	fTime=glutGet(GLUT_ELAPSED_TIME)/10;
 	fSimTime=fTime-fLastIdleTime;
 
    glClearColor (0.0,0.0,0.0,1.0); //clear the screen to black
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear the color buffer and the depth buffer
    glEnable (GL_DEPTH_TEST); //enable the depth testing
    glEnable (GL_LIGHTING); //enable the lighting
    glEnable (GL_LIGHT0); //enable LIGHT0, our Diffuse Light
    glEnable (GL_COLOR_MATERIAL);
    glShadeModel (GL_SMOOTH); //set the shader to smooth shader
    
    glLoadIdentity();
	
	camera->setAngle();
	border->display();
	platform->display();
	platform->move(fSimTime, border);
	brickSet->display();
	ball->move(fSimTime);
	ball->checkCollisions(border);
	ball->checkCollisions(brickSet);
	ball->checkCollisions(platform);
	ball->display();

	fLastIdleTime=fTime;

    glutSwapBuffers(); //swap the buffers
}

void App::reshape(int w, int h) 
{
    glViewport (0, 0, (GLsizei)w, (GLsizei)h); //set the viewport to the current window specifications
    glMatrixMode (GL_PROJECTION); //set the matrix to projection

    glLoadIdentity ();
    gluPerspective (60, (GLfloat)w / (GLfloat)h, 0.1, 100.0); //set the perspective (angle of sight, width, height, , depth)
    glMatrixMode (GL_MODELVIEW); //set the matrix back to model
}

void App::pressKey (int key, int x, int y) 
{
	switch (key)
	{
		case GLUT_KEY_UP: platform->setVelY(0.2);
						  break;
		case GLUT_KEY_DOWN:	platform->setVelY(-0.2);
							break;
		case GLUT_KEY_RIGHT: platform->setVelX(0.2);
							 break;
		case GLUT_KEY_LEFT:	platform->setVelX(-0.2);
							break;
    }
}

void App::releaseKey(int key, int x, int y)
{
	switch (key) 
	{
		case GLUT_KEY_UP:	
		case GLUT_KEY_DOWN:	platform->setVelY(0);
							break;
		case GLUT_KEY_RIGHT:	
		case GLUT_KEY_LEFT:	platform->setVelX(0);
							break;
	}
}

void App::mouseButton(int button, int state, int x, int y)
{
	// only start motion if the left button is pressed
	if (button == GLUT_RIGHT_BUTTON)
	{
		// when the button is released
		if (state == GLUT_UP) 
		{
			buttonPressed = false;
		}
		else // state = GLUT_DOWN
		{		
			buttonPressed = true;
			justStarted = true;
		}
	}
}

void App::mouseMovement(int x, int y)
{
	if(buttonPressed == true)
	{
		camera->move(x, y, justStarted);
	}
}

void App::run()
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Arkanoid");
	glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc(reshape);

	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMovement); //check for mouse movement
    //glutPassiveMotionFunc(mouseMovement); //check for mouse movement

    glutSpecialFunc(pressKey);

	// here are the new entries
	glutIgnoreKeyRepeat(1);
	glutSpecialUpFunc(releaseKey);

    glutMainLoop();
}