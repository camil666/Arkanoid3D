#pragma once

class Border
{
private:
	float width;
	float height;
	float depth;

public:
	Border(void);
	~Border(void);

	void display();
	float getWidth();
	float getHeight();
	float getDepth();
};

