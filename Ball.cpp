#include "Ball.h"
#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include "Border.h"
#include "BrickSet.h"
#include "Platform.h"

Ball::Ball(void):velX(-0.1),velY(-0.2),velZ(-0.2),posX(0),posY(0),posZ(0),radius(1)
{
}

Ball::~Ball(void)
{
}

void Ball::display()
{
    //rysowanie2
	glPushMatrix();
    glColor3f(0.0f, 0.0f, 1.0f);
	glTranslatef(posX, posY, posZ);
    glutSolidSphere(radius, 12, 12);
	glPopMatrix();
}

void Ball::move(float rate)
{
	posX+=velX*rate;
	posY+=velY*rate;
	posZ+=velZ*rate;
}

void Ball::bounce(BounceType type)
{
	switch(type)
	{
		case X_BOUNCE: velX = -velX;
				break;
		case Y_BOUNCE: velY = -velY;
				break;
		case Z_BOUNCE: velZ = -velZ;
				break;
	}
}

void Ball::checkCollisions(Border *border)
{
	float tmpBounceCoord = border->getSize()/2.0;
	float tmpBallRespawnCoord = tmpBounceCoord-radius;

	if (posX+radius > tmpBounceCoord)
	{
		bounce(X_BOUNCE);
		posX = tmpBallRespawnCoord;
	}
	else if (posX-radius < -tmpBounceCoord)
	{
		bounce(X_BOUNCE);
		posX = -tmpBallRespawnCoord;
	}

	if (posY+radius > tmpBounceCoord)
	{
		bounce(Y_BOUNCE);
		posY = tmpBallRespawnCoord;
	}
	else if (posY-radius < -tmpBounceCoord)
	{
		bounce(Y_BOUNCE);
		posY = -tmpBallRespawnCoord;
	}

	//if (posZ+radius > 0)		//pilka stracona, koniec gry, do usuniecia w odpowiednim czasie
	//{
	//	bounce(Z_BOUNCE);
	//	posZ = -radius;
	//}
	//else 
	if (posZ-radius < -(tmpBounceCoord*4.0))
	{
		bounce(Z_BOUNCE);
		posZ = -((tmpBounceCoord*4.0)-1.0);
	}
}

void Ball::checkCollisions(BrickSet *brickSet)
{
	if (brickSet->getBricks().size() != 0)
	{
		double cX, cY, cZ;		//wsp�rz�dne punktu bloku najbli�szego kolizji

		for (unsigned int i=0; i<brickSet->getBricks().size(); ++i)
		{
			float brickXLeft = brickSet->getBricks()[i].getPosX() - (brickSet->getBricks()[i].getSize());
			float brickXRight = brickSet->getBricks()[i].getPosX() + (brickSet->getBricks()[i].getSize());
			float brickYUp = brickSet->getBricks()[i].getPosY() + (brickSet->getBricks()[i].getSize()/2.0);
			float brickYDown = brickSet->getBricks()[i].getPosY() - (brickSet->getBricks()[i].getSize()/2.0);
			float brickZClose = brickSet->getBricks()[i].getPosZ() + (brickSet->getBricks()[i].getSize()/2.0);
			float brickZFar = brickSet->getBricks()[i].getPosZ() - (brickSet->getBricks()[i].getSize()/2.0);

			if( posX < brickXLeft )	//je�li kula jest z lewej strony bloku
			{
				cX = brickXLeft;
			}
			else if( posX > brickXRight )	//je�li kula jest z prawej strony bloku
			{
				cX = brickXRight;
			}
			else	//je�li kula jest mi�dzy praw� a lew� kraw�dzi� bloku
			{
				cX = posX;
			}

			if( posY > brickYUp )	//je�li kula jest powy�ej bloku
			{
				cY = brickYUp;
			}
			else if( posY < brickYDown )	//je�li kula jest poni�ej bloku
			{
				cY = brickYDown;
			}
			else	//je�li kula jest pomi�dzy g�rna a daln� kraw�dzi� bloku
			{
				cY = posY;
			}

			if( posZ < brickZFar )	//je�li kula jest za blokiem
			{
				cZ = brickZFar;
			}
			else if( posY > brickZClose )	//je�li kula jest przed blokiem
			{
				cZ = brickZClose;
			}
			else	//je�li kula jest pomi�dzy przednia a tylnia kraw�dzi� bloku
			{
				cZ = posZ;
			}

			if( calculateDistance( posX, posY, posZ, cX, cY, cZ ) < radius )	//sprawdzenie czy kula koliduje z blokiem
			{
				if(cY == brickYDown)		//odbicie od dolnej kraw�dzi
				{
					posY = brickYDown - radius;
					bounce(Y_BOUNCE);
				}
				else if(cY == brickYUp)		//odbicie od g�rnej kraw�dzi
				{
					posY = brickYUp + radius;
					bounce(Y_BOUNCE);
				}
				else if (cX == brickXRight)	//odbicie od prawej kraw�dzi
				{
					posX = brickXRight + radius;
					bounce(X_BOUNCE);
				}
				else if(cX == brickXLeft)		//odbicie od lewej kraw�dzi
				{
					posX = brickXLeft - radius;
					bounce(X_BOUNCE);
				}
				else if(cZ == brickZClose)		//odbicie od przedniej kraw�dzi
				{
					posZ = brickZClose + radius;
					bounce(Z_BOUNCE);
				}
				else if(cZ == brickZFar)		//odbicie od tylniej kraw�dzi
				{
					posZ = brickZFar - radius;
					bounce(Z_BOUNCE);
				}

				if (brickSet->getBricks()[i].damage(20) == false)
				{
					brickSet->erase(i);
					--i;
				}
			} 
		}
	}
}

void Ball::checkCollisions(Platform *platform)
{
	float tmpXLeftPos = platform->getPosX()-(platform->getSize()/2.0);
	float tmpXRightPos = platform->getPosX()+(platform->getSize()/2.0);
	float tmpYUpPos = platform->getPosY()-(platform->getSize()/2.0);
	float tmpYDownPos = platform->getPosY()+(platform->getSize()/2.0);

	if(posZ + radius >= platform->getPosZ()*2.0)
	{
		if ((posX >= tmpXLeftPos) && (posX <= tmpXRightPos) && (posY >= tmpYUpPos) && (posY <= tmpYDownPos))	// bounce
		{
			bounce(Z_BOUNCE);
			posZ = -radius+platform->getPosZ()*2;
		}
		else	//	game over
		{
			posZ = -20;	//tymczasowe cofniecie kulki na obszar gry
			bounce(Z_BOUNCE);
		}
	}
}

float Ball::calculateDistance(float x1, float y1, float z1, float x2, float y2, float z2)
{
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2));
}
