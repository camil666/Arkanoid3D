#pragma once

class Camera
{
private:
	float xrot, yrot;
	float cRadius;
	float lastx, lasty;
public:
	Camera(void);
	~Camera(void);

	void setAngle(void);
	void move(int x, int y, bool &justStarted);
};

