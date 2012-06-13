#pragma once
class Camera;
class Border;
class Platform;
class BrickSet;
class BallSet;
class PowerUpSet;
class ParticleSet;
class Shader;
class HUD;
class HUDInfo;

class Level
{
private:
	short level;
	long points;
	short lives;
	bool buttonPressed;
	bool justStarted;
	float fLastIdleTime;
	Shader *shader;
	Camera *camera;
	Border *border;
	Platform *platform;
	BrickSet *brickSet;
	BallSet *ballSet;
	PowerUpSet *powerUpSet;
	ParticleSet *particleSet;
	HUD * hud;
	HUDInfo *hudInfo;

public:
	Level(short _level = 1);
	~Level(void);

	int display();
	void pressKey (int key, int x, int y);
	void releaseKey(int key, int x, int y);
	void mouseButton(int button, int state, int x, int y);
	void mouseMovement(int x, int y);
	void addPoints(long ammount = 100);
	void decLives();
	long getPoints();
	HUD* getHUD();
};

