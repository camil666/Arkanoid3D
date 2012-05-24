#pragma once
#include <vector>
#include "Particle.h"

using namespace std;

class ParticleSet
{
	private:
	vector <Particle*> particles;
public:
	ParticleSet(void);
	~ParticleSet(void);
	
	void add_particle(float a, float b, float c,const int n);	//dodanie nowej czasteczki
	void erase(int index);
	void display();
	void update();
	void add(Particle *particle);
};

