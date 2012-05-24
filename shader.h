#ifndef __SHADER_H
#define __SHADER_H
#include "OS.h"
#include <string>

#if ( (defined(__MACH__)) && (defined(__APPLE__)) )
#include <stdlib.h>
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include <OpenGL/glext.h>
#else
#include <stdlib.h>
#include <GL/glew.h>
#ifdef WINDOWS //if using windows then do windows specific stuff.
#include <GL/wglew.h>
#endif
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glext.h>
#endif

class Shader {
public:
	Shader();
	Shader(const char *vsFile, const char *fsFile);
	~Shader();

    void init(const char *vsFile, const char *fsFile);

	void bind();
	void unbind();

	unsigned int id();

private:
	unsigned int shader_id;
	unsigned int shader_vp;
	unsigned int shader_fp;
};

#endif
