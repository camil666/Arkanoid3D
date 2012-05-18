#include "PowerUpSet.h"
#include "Platform.h"

PowerUpSet::PowerUpSet(void)
{
}

PowerUpSet::~PowerUpSet(void)
{
	for (unsigned int i=0; i<powerUps.size(); ++i)
    {
		delete powerUps[i];
    }
}

void PowerUpSet::display()
{
	for (unsigned int i=0; i<powerUps.size(); ++i)
    {
		powerUps[i]->display();
    }
}

void PowerUpSet::move(float rate)
{
	for (unsigned int i=0; i<powerUps.size(); ++i)
    {
		powerUps[i]->move(rate);
    }
}

vector<PowerUp*> PowerUpSet::getPowerUps()
{
	return powerUps;
}

void PowerUpSet::erase(int index)
{
	delete powerUps[index];
	powerUps.erase(powerUps.begin() + index);
}

void PowerUpSet::add(PowerUp *powerUp)
{
	powerUps.push_back(powerUp);
}

void PowerUpSet::checkCollisions(Platform *platform)
{
	for (unsigned int i=0; i<powerUps.size(); ++i)
    {
		if((powerUps[i]->getPosZ() + powerUps[i]->getSize()) > 0)
		{
			float tmpXLeftPos = platform->getPosX()-(platform->getSize()/2);
			float tmpXRightPos = platform->getPosX()+(platform->getSize()/2);
			float tmpYUpPos = platform->getPosY()-(platform->getSize()/2);
			float tmpYDownPos = platform->getPosY()+(platform->getSize()/2);

			if ((powerUps[i]->getPosX() >= tmpXLeftPos) && (powerUps[i]->getPosX() <= tmpXRightPos) && (powerUps[i]->getPosY() >= tmpYUpPos) && (powerUps[i]->getPosY() <= tmpYDownPos))
			{
				powerUps[i]->activate();			//activate powerUp
				powerUps.erase(powerUps.begin() + i);	//erase powerup
				--i;
			}
			else
			{
				powerUps.erase(powerUps.begin() + i);	//erase powerup
				--i;
			}		
		}
    }
}