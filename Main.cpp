#include "OS.h"
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glext.h>
#include "App.h"

int main (int argc, char **argv)
{
	//i moved that code from App.cpp temporary
	//because glew was causing problems somehow
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Arkanoid");
	glewInit();
	App app;
	app.run();

    return 0;
}
