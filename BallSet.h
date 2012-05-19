#pragma once
#include <vector>
#include "Ball.h"

using namespace std;

class BallSet
{
private:
	vector<Ball> balls;

public:
	BallSet(void);
	~BallSet(void);

	void display();
	void move(float rate);
	vector<Ball> getBalls();
	void erase(int index);
	void add();
	void checkCollisions(Border *border);
	vector<int> checkCollisions(BrickSet *brickSet);
	vector<int> checkCollisions(Platform *platform);
};

