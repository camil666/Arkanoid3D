#pragma once
class Camera;
class Border;
class Platform;
class BrickSet;
class BallSet;
class PowerUpSet;
class HUD;

class Level
{
private:
	int points;
	bool buttonPressed;
	bool justStarted;
	float fLastIdleTime;
	Camera *camera;
	Border *border;
	Platform *platform;
	BrickSet *brickSet;
	BallSet *ballSet;
	PowerUpSet *powerUpSet;
	HUD * hud;
public:
	Level(void);
	~Level(void);

	void display();
	void pressKey (int key, int x, int y);
	void releaseKey(int key, int x, int y);
	void mouseButton(int button, int state, int x, int y);
	void mouseMovement(int x, int y);
	void addPoints();
	HUD* getHUD();
};

