#include "OS.h"
#include "BrickSet.h"

BrickSet::BrickSet(void)
{
	for (float i=-4.5; i<6.0; i+=4.5)		//create 3*5 bricks
	{
		for (float j=-5.0; j<6.0; j+=2.5)
		{
			Brick brick(i,j,-45.0);
			bricks.push_back(brick);
		}
	}

	//Brick brick(0,0,-45.0);
	//bricks.push_back(brick);
}

BrickSet::~BrickSet(void)
{
}

void BrickSet::display()
{
	for (unsigned int i=0; i<bricks.size(); ++i)
    {
		bricks[i].display();
    }
}

vector<Brick> BrickSet::getBricks()
{
	return bricks;
}

void BrickSet::erase(int index)
{
	bricks.erase(bricks.begin() + index);
}
