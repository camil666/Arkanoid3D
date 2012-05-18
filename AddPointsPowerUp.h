#pragma once
#include "powerup.h"

class AddPointsPowerUp :public PowerUp
{
private:
	int *points;

public:
	AddPointsPowerUp(void);
	AddPointsPowerUp(float pX, float pY, float pZ, int *p);
	~AddPointsPowerUp(void);

	void activate();
};

