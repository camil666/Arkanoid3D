#include "App.h"
#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include "Level.h"

Level *App::level;

App::App(void)
{
	level = new Level();
}

App::~App(void)
{
	delete level;
}

void App::display(void) 
{
    glClearColor (0.0,0.0,0.0,1.0); //clear the screen to black
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear the color buffer and the depth buffer
    glEnable (GL_DEPTH_TEST); //enable the depth testing
    glEnable (GL_LIGHTING); //enable the lighting
    glEnable (GL_LIGHT0); //enable LIGHT0, our Diffuse Light
	glEnable (GL_LIGHT1); //enable LIGHT1, our Ambient Light
	GLfloat AmbientLight[] = {0.1, 0.1, 0.1};
	glLightfv (GL_LIGHT1, GL_AMBIENT, AmbientLight); //change the light accordingly
	/*GLfloat LightPosition[] = {0.0, 0.0, 1.0, 0.0};	//set posiotion of light
	glLightfv (GL_LIGHT0, GL_POSITION, LightPosition); */
    glEnable (GL_COLOR_MATERIAL);
    glShadeModel (GL_SMOOTH); //set the shader to smooth shader
    
    glLoadIdentity();
	
	if (level != NULL)
		level->display();

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
	if (level != NULL)
		level->pressKey(key, x, y);
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