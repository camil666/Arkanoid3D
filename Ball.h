#pragma once
class Border;
class BrickSet;
class Platform;

enum BounceType {X_BOUNCE, Y_BOUNCE, Z_BOUNCE};

class Ball
{
private:
	float velX;
	float velY;
	float velZ;

	float posX;
	float posY;
	float posZ;

	float radius;

public:
	Ball(void);
	~Ball(void);

	void display();
	void move(float rate);
	void bounce(BounceType type);
	void checkCollisions(Border *border);
	void checkCollisions(BrickSet *brickSet);
	void checkCollisions(Platform *platform);
	float calculateDistance(float x1, float y1, float z1, float x2, float y2, float z2);
};