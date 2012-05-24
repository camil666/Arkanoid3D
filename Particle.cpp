#include "OS.h"
#include "Particle.h"
#ifdef WINDOWS //if using windows then do windows specific stuff.
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glut.h>


//konstruktor, tworzy cz¹steczkê w punkcie o wspó³rzêdnych aa, bb,cc
Particle::Particle(float aa, float bb,float cc):Xpos(aa),Ypos(bb),Zpos(cc)
{
	//losowanie wartosci o jaka czasteczke bedzie sie przemieszczac
	 Xmov = (((((((2) * rand()%11) + 1)) *	rand()%11) + 1) * 0.005) - (((((((2) * rand()%11) + 1) - 1 + 1) * rand()%11) + 1) * 0.005);
	 Zmov = (((((((2) * rand()%11) + 1)) *rand()%11) + 1) * 0.005) - (((((((2) * rand()%11) + 1) - 1 + 1) * rand()%11) + 1) * 0.005);
	 Red = 1;
	 Green = 1;
	 Blue = 0;
	 Scalez = 0.30;
	 Direction = 0;
	 Acceleration = ((((((8 - 5 + 2) * rand()%11) + 5) - 1 + 1) * rand()%11) + 1) * 0.02;
	 Deceleration = 0.0025;
}


Particle::~Particle(void)
{

}


void Particle::update(void)
{
	 Ypos =  Ypos + Acceleration -  Deceleration; //poczatkowo wyrzuca czasteczke do gory by pozniej spowodowac jej opadanie
	 Deceleration =  Deceleration +0.0025; //zwiekszenie tempa opadania czasteczki
	 Xpos =  Xpos +  Xmov;
	 Zpos =  Zpos +  Zmov;

	 Direction =  Direction + ((((((int)(0.5 - 0.1 + 0.1) * rand()%11) + 1) - 1 + 1) * rand()%11) + 1);
}


//wyswietlenie czasteczki
void Particle::show(void)
{
	glPushMatrix();
	glColor3f ( Red,  Green,Blue);
    glTranslatef ( Xpos,  Ypos,  Zpos);
	glRotatef ( Direction - 90, 0, 0, 1);
    glScalef ( Scalez,  Scalez,  Scalez);
    glBegin (GL_QUADS);
    glTexCoord2d (0, 0);
    glVertex3f (-1, -1, 0);
    glTexCoord2d (1, 0);
    glVertex3f (1, -1, 0);
    glTexCoord2d (1, 1);
    glVertex3f (1, 1, 0);
    glTexCoord2d (0, 1);
    glVertex3f (-1, 1, 0);
    glEnd();

	glPopMatrix();
}

//sprawdza czy czasteczka jest aktywna
bool Particle::is_dead(void)
{
    if(  (Xpos < -20) || (Xpos > 20) || (Ypos < -20 ) || (Ypos > 20))	//obszar na jakim czasteczki przestaja byc widoczne
        return true;
	else
		return false;
}
