#include "OS.h"
#include "HUDInfo.h"


HUDInfo::HUDInfo(void)
{
}


HUDInfo::~HUDInfo(void)
{
}

int HUDInfo::getPoints()
{
	return this->points;
}

int HUDInfo::getLives()
{
	return this->lives;
}

int HUDInfo::getLevel()
{
	return this->level;
}

void HUDInfo::setPoints(int points)
{
	this->points = points;
}

void HUDInfo::setLives(int lives)
{
	this->lives = lives;
}

void HUDInfo::setLevel(int level)
{
	this->level = level;
}
