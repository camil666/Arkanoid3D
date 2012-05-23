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
    glColor3f(0.0f, 0.0f, 1.0f);	//set color
	glTranslatef(posX, posY, posZ);	//set posiotion
	GLfloat mShininess[] = {50};
	//color modification - for better playing
    float mod = posZ/62.6;
    GLfloat DiffuseMaterial[] = {(0.0-mod), 0.0, (1.0+mod)}; 
    GLfloat AmbientMaterial[] = {0.0, 0.0, 0.0};
    GLfloat SpecularMaterial[] = {1.0, 1.0, 1.0}; 
    
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, DiffuseMaterial);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, AmbientMaterial);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, SpecularMaterial);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mShininess);
    glutSolidSphere(radius, 12, 12);	//render the sphere
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
	if (posX+radius > border->getWidth()/2.0)	//ball is past right side of the border
	{
		bounce(X_BOUNCE);
		posX = border->getWidth()/2.0 - radius;	//set ball position
	}
	else if (posX-radius < -(border->getWidth()/2.0))	//ball is past left side of the border
	{
		bounce(X_BOUNCE);
		posX = -(border->getWidth()/2.0 - radius);
	}

	if (posY+radius > border->getHeight()/2.0)	//ball is past lower side of the border
	{
		bounce(Y_BOUNCE);
		posY = border->getHeight()/2.0 - radius;
	}
	else if (posY-radius < -(border->getHeight()/2.0))	//ball is past upper side of the border
	{
		bounce(Y_BOUNCE);
		posY = -(border->getHeight()/2.0 - radius);
	}

	if (posZ-radius < -(border->getDepth()))	//ball is past far side of the border
	{
		bounce(Z_BOUNCE);
		posZ = -(border->getDepth() - radius);
	}
}

//return:
//index of destroyed brick
//0 if brick was hit but not destroyed or no brick was hit
//-1 if there is no bricks left
int Ball::checkCollisions(BrickSet *brickSet)
{
	if (brickSet->getBricks().size() != 0)
	{
		double cX, cY, cZ;		//wspó³rzêdne punktu bloku najbli¿szego kolizji

		for (unsigned int i=0; i<brickSet->getBricks().size(); ++i)
		{
			float brickXLeft = brickSet->getBricks()[i].getPosX() - (brickSet->getBricks()[i].getSize());
			float brickXRight = brickSet->getBricks()[i].getPosX() + (brickSet->getBricks()[i].getSize());
			float brickYUp = brickSet->getBricks()[i].getPosY() + (brickSet->getBricks()[i].getSize()/2.0);
			float brickYDown = brickSet->getBricks()[i].getPosY() - (brickSet->getBricks()[i].getSize()/2.0);
			float brickZClose = brickSet->getBricks()[i].getPosZ() + (brickSet->getBricks()[i].getSize()/2.0);
			float brickZFar = brickSet->getBricks()[i].getPosZ() - (brickSet->getBricks()[i].getSize()/2.0);

			if( posX < brickXLeft )	//jeœli kula jest z lewej strony bloku
			{
				cX = brickXLeft;
			}
			else if( posX > brickXRight )	//jeœli kula jest z prawej strony bloku
			{
				cX = brickXRight;
			}
			else	//jeœli kula jest miêdzy praw¹ a lew¹ krawêdzi¹ bloku
			{
				cX = posX;
			}

			if( posY > brickYUp )	//jeœli kula jest powy¿ej bloku
			{
				cY = brickYUp;
			}
			else if( posY < brickYDown )	//jeœli kula jest poni¿ej bloku
			{
				cY = brickYDown;
			}
			else	//jeœli kula jest pomiêdzy górna a daln¹ krawêdzi¹ bloku
			{
				cY = posY;
			}

			if( posZ < brickZFar )	//jeœli kula jest za blokiem
			{
				cZ = brickZFar;
			}
			else if( posY > brickZClose )	//jeœli kula jest przed blokiem
			{
				cZ = brickZClose;
			}
			else	//jeœli kula jest pomiêdzy przednia a tylnia krawêdzi¹ bloku
			{
				cZ = posZ;
			}

			if( calculateDistance( posX, posY, posZ, cX, cY, cZ ) < radius )	//sprawdzenie czy kula koliduje z blokiem
			{
				if(cY == brickYDown)		//odbicie od dolnej krawêdzi
				{
					posY = brickYDown - radius;
					bounce(Y_BOUNCE);
				}
				else if(cY == brickYUp)		//odbicie od górnej krawêdzi
				{
					posY = brickYUp + radius;
					bounce(Y_BOUNCE);
				}
				else if (cX == brickXRight)	//odbicie od prawej krawêdzi
				{
					posX = brickXRight + radius;
					bounce(X_BOUNCE);
				}
				else if(cX == brickXLeft)		//odbicie od lewej krawêdzi
				{
					posX = brickXLeft - radius;
					bounce(X_BOUNCE);
				}
				else if(cZ == brickZClose)		//odbicie od przedniej krawêdzi
				{
					posZ = brickZClose + radius;
					bounce(Z_BOUNCE);
				}
				else if(cZ == brickZFar)		//odbicie od tylniej krawêdzi
				{
					posZ = brickZFar - radius;
					bounce(Z_BOUNCE);
				}

				if (brickSet->getBricks()[i].damage(20) == false)
				{
					return i; //brick destroyed
				}
			} 
		}
		return 0;
	}
	else
		return -1; //end of game, no bricks left
}

//return:
//1 if player hit the ball
//-1 if player didn't hit the ball
//0 if ball is not in platform move plane
int Ball::checkCollisions(Platform *platform)
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
			return 1;
		}
		else	//	game over
		{
			posZ = -20;	//tymczasowe cofniecie kulki na obszar gry
			bounce(Z_BOUNCE);
			return -1;
		}
	}
	return 0;
}

float Ball::calculateDistance(float x1, float y1, float z1, float x2, float y2, float z2)
{
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2));
}
