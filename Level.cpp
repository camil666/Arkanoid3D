#include "Level.h"
#ifdef WIN32 //if using windows then do windows specific stuff.
#include <windows.h>
#endif
#include "shader.h"
#include <GL/gl.h>
#include <GL/glut.h>
#include <time.h>
#include <stdlib.h>
#include "Platform.h"
#include "BrickSet.h"
#include "Border.h"
#include "BallSet.h"
#include "Camera.h"
#include "PowerUpSet.h"
#include "AddBallPowerUp.h"
#include "AddPointsPowerUp.h"
#include "HUD.h"
#include "HUDInfo.h"
#include "ParticleSet.h"

Level::Level(void):points(0)
{
	buttonPressed = false;
	fLastIdleTime = 0;
	camera = new Camera();
	border = new Border();
	platform = new Platform();
	brickSet = new BrickSet();
	ballSet = new BallSet();
	powerUpSet = new PowerUpSet();
	particleSet = new ParticleSet();
	shader = new Shader();
	//load up shader files
	hud = new HUD();
	hudInfo = new HUDInfo();
	hudInfo->setPoints(points);
	shader->init("shader.vert", "shader.frag");

	ballSet->add();

}

Level::~Level(void)
{
	delete camera;
	delete border;
	delete platform;
	delete brickSet;
	delete ballSet;
	delete powerUpSet;
	delete particleSet;
	delete hud;
	delete shader;
	delete hudInfo;
}

void Level::display()
{
	float fTime, fSimTime;
	fTime=(float)(glutGet(GLUT_ELAPSED_TIME)/10);
 	fSimTime=fTime-fLastIdleTime;

	camera->setAngle();
	//turn shader on for everything drawen from now
	shader->bind();
	border->display();
	platform->display();
	platform->move(fSimTime, border);
	brickSet->display();
	ballSet->move(fSimTime);
	ballSet->checkCollisions(border);
	vector<int> values = ballSet->checkCollisions(brickSet);
	for (unsigned int i = 0; i < values.size(); ++i)
	{
		if (values[i] > 0)
		{
			particleSet->add_particle(brickSet->getBricks()[values[i]].getPosX(),brickSet->getBricks()[values[i]].getPosY(),brickSet->getBricks()[values[i]].getPosZ(),20);
			this->addPoints();
			srand (time(0));
			int random = rand() % 100;
			if (random < 15)
			{
				AddBallPowerUp *powerUp = new AddBallPowerUp(brickSet->getBricks()[values[i]].getPosX(),brickSet->getBricks()[values[i]].getPosY(),brickSet->getBricks()[values[i]].getPosZ(),ballSet);
				powerUpSet->add(powerUp);
			}
			else if (random < 30)
			{
				AddPointsPowerUp *powerUp = new AddPointsPowerUp(brickSet->getBricks()[values[i]].getPosX(),brickSet->getBricks()[values[i]].getPosY(),brickSet->getBricks()[values[i]].getPosZ(), &points);
				powerUpSet->add(powerUp);
			}
			brickSet->erase(values[i]);
		}
		else if (values[i] == -1)
		{
			//TODO: end of level, no bricks left D:
		}
	}
	ballSet->checkCollisions(platform);

	particleSet->display();
	particleSet->update();
	ballSet->display();
	powerUpSet->display();
	//turn shader off
	shader->unbind();
	hud->display(hudInfo);
	powerUpSet->move(fSimTime);
	powerUpSet->checkCollisions(platform);

	fLastIdleTime=fTime;
}

void Level::pressKey (int key, int x, int y)
{
	switch (key)
	{
		case GLUT_KEY_UP: platform->setVelY(0.2f);
						  break;
		case GLUT_KEY_DOWN:	platform->setVelY(-0.2f);
							break;
		case GLUT_KEY_RIGHT: platform->setVelX(0.2f);
							 break;
		case GLUT_KEY_LEFT:	platform->setVelX(-0.2f);
							break;
    }
}

void Level::releaseKey(int key, int x, int y)
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

void Level::mouseButton(int button, int state, int x, int y)
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

void Level::mouseMovement(int x, int y)
{
	if(buttonPressed == true)
	{
		camera->move(x, y, justStarted);
	}
}

void Level::addPoints()
{
	points+=100;
	hudInfo->setPoints(points);
}

HUD* Level::getHUD()
{
	return hud;
}
