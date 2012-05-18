#pragma once
#include "powerup.h"
class BallSet;

class AddBallPowerUp :public PowerUp
{
private:
	BallSet *ballSet;

public:
	AddBallPowerUp(void);
	AddBallPowerUp(float pX, float pY, float pZ, BallSet *bs);
	~AddBallPowerUp(void);

	void activate();
};

