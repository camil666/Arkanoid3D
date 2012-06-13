#pragma once
#include "PowerUp.h"

class AddPointsPowerUp :public PowerUp
{
private:
	long *points;

public:
	AddPointsPowerUp(void);
	AddPointsPowerUp(float pX, float pY, float pZ, long *p);
	~AddPointsPowerUp(void);

	void activate();
};
