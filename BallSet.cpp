#include "BallSet.h"

BallSet::BallSet(void)
{
}

BallSet::~BallSet(void)
{
}

void BallSet::display()
{
	for (unsigned int i=0; i<balls.size(); ++i)
    {
		balls[i].display();
    }
}

void BallSet::move(float rate)
{
	for (unsigned int i=0; i<balls.size(); ++i)
    {
		balls[i].move(rate);
    }
}

vector<Ball> BallSet::getBalls()
{
	return balls;
}

void BallSet::erase(int index)
{
	balls.erase(balls.begin() + index);
}

void BallSet::add(short level)
{
	Ball ball;
	ball.setVelMultiplier(level);
	balls.push_back(ball);
}

void BallSet::checkCollisions(Border *border)
{
	for (unsigned int i=0; i<balls.size(); ++i)
    {
		balls[i].checkCollisions(border);
    }
}

vector<int> BallSet::checkCollisions(BrickSet *brickSet)
{
	vector<int> returnValues;
	for (unsigned int i=0; i<balls.size(); ++i)
    {
		returnValues.push_back(balls[i].checkCollisions(brickSet));
    }
	return returnValues;
}

vector<int> BallSet::checkCollisions(Platform *platform)
{
	vector<int> returnValues;
	for (unsigned int i=0; i<balls.size(); ++i)
    {
		returnValues.push_back(balls[i].checkCollisions(platform));
    }
	return returnValues;
}