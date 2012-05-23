#pragma once
class Level;
class MenuBase;
//class MenuPause;

class App
{
private:
	static Level *level;	//area with balls and bricks
	static MenuBase *menuBase; //main menu
	
public:
	App(void);
	~App(void);

	void run();

private:
	static void display(void);
	static void reshape(int w, int h);
	static void pressKey (int key, int x, int y);
	static void pressKeyEnter (unsigned char key,int,int);
	static void releaseKey(int key, int x, int y);
	static void mouseButton(int button, int state, int x, int y);
	static void mouseMovement(int x, int y);
};

