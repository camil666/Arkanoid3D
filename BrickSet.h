#pragma once
#include <vector>
#include "Brick.h"

using namespace std;

class BrickSet
{
private:
	vector<Brick> bricks;

public:
	BrickSet(void);
	~BrickSet(void);

	void display();
	vector<Brick> getBricks();
	void erase(int index);
};

