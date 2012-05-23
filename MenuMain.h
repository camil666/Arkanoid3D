#pragma once
#include <vector>
#include <string>
#include "MenuBase.h"

using namespace std;

class MenuMain: public MenuBase
{
private:
	
	void DrawMenu(void);

public:
	MenuMain(void);
	~MenuMain(void);

	void display();
	int pressKey (int key, int x, int y);
	
};

