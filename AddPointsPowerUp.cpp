#include "OS.h"
#include "AddPointsPowerUp.h"

AddPointsPowerUp::AddPointsPowerUp(void)
{
}

AddPointsPowerUp::AddPointsPowerUp(float pX, float pY, float pZ, int *p):PowerUp(pX,pY,pZ), points(p)
{
	colR = 0.5f;
	colG = 0.9f;
	colB = 0.3f;
}

AddPointsPowerUp::~AddPointsPowerUp(void)
{
}

void AddPointsPowerUp::activate()
{
	*points+=100;	//give additional points to player
}
