#pragma once
class Level;

class App
{
private:
	static Level *level;	//area with balls and bricks

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

