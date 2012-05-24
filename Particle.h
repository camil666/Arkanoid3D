// Klasa particle, reprezentuje czasteczke

#pragma once

class Particle
{
	//friend class ParticleList;
private:

	float Xpos;
	float Ypos;
	float Zpos;
	float Xmov;
	float Zmov;
	float Red;
	float Green;
	float Blue;
	float Direction;
	float Acceleration; //przyspieszenie z jakim czasteczka oddala sie od pkt poczatkowego
	float Deceleration; //zwolnienie tempa
	float Scalez;

public:
    Particle(float aa, float bb,float cc);
	~Particle(void);

	void update(void);
    void show(void);	//wyswietlenie czasteczki
    bool is_dead(void);		//czy czasteczka jest aktywna
};

