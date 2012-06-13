#include "AddBallPowerUp.h"
#include "BallSet.h"

AddBallPowerUp::AddBallPowerUp(void)
{
}

AddBallPowerUp::AddBallPowerUp(float pX, float pY, float pZ, BallSet *bs):PowerUp(pX,pY,pZ)
{
	level = 1;
	ballSet = bs;
	colR = 0.6f;
	colG = 0.3f;
	colB = 0.9f;
}

AddBallPowerUp::~AddBallPowerUp(void)
{
}

void AddBallPowerUp::activate()
{
	ballSet->add(level);	//add new ball to ballSet
}

void AddBallPowerUp::setLevel(short _level)
{
	level = _level;
}
