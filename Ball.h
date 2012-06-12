#pragma once
class Border;
class BrickSet;
class Platform;
class PowerUpSet;

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
	float calculateDistance(float x1, float y1, float z1, float x2, float y2, float z2);
	void bounce(BounceType type);

public:
	Ball(void);
	~Ball(void);

	void display();
	void move(float rate);
	void checkCollisions(Border *border);
	int checkCollisions(BrickSet *brickSet);
	int checkCollisions(Platform *platform);
};