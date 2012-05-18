#include "AddBallPowerUp.h"
#include "BallSet.h"

AddBallPowerUp::AddBallPowerUp(void)
{
}

AddBallPowerUp::AddBallPowerUp(float pX, float pY, float pZ, BallSet *bs):PowerUp(pX,pY,pZ)
{
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
	ballSet->add();	//add new ball to ballSet
}