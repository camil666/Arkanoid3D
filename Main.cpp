#include <GL/glut.h>
#include "App.h"

int main (int argc, char **argv) 
{
    glutInit(&argc, argv);
	App app;
	app.run();

    return 0;
}