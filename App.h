#pragma once
class Camera;
class Border;
class Platform;
class BrickSet;
class Ball;

class App
{
private:
	static bool buttonPressed;
	static bool justStarted;
	static float fLastIdleTime;
	static Camera *camera;
	static Border *border;
	static Platform *platform;
	static BrickSet *brickSet;
	static Ball *ball;

public:
	App(void);
	~App(void);

	void run();

private:
	static void display(void);
	static void reshape(int w, int h);
	static void pressKey (int key, int x, int y);
	static void releaseKey(int key, int x, int y);
	static void mouseButton(int button, int state, int x, int y);
	static void mouseMovement(int x, int y);
};

