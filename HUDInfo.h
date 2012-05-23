#pragma once
class HUDInfo
{

private:
	int points;
	int lives;
	int level;

public:
	HUDInfo(void);
	~HUDInfo(void);

	int getPoints();
	int getLives();
	int getLevel();

	void setPoints(int);
	void setLives(int);
	void setLevel(int);
};

