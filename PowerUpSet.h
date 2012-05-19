#pragma once
#include <vector>
#include "PowerUp.h"
class Platform;
using namespace std;

class PowerUpSet
{
private:
	vector<PowerUp*> powerUps;

public:
	PowerUpSet(void);
	~PowerUpSet(void);

	void display();
	void move(float rate);
	vector<PowerUp*> getPowerUps();
	void erase(int index);
	void add(PowerUp *powerUp);
	void checkCollisions(Platform *platform);
};

