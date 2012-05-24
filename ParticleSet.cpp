//Funkcje sk³adowe klasy ParticleSet
#include "OS.h"
#include "ParticleSet.h"
#include "Particle.h"

ParticleSet::ParticleSet(void)
{
}

ParticleSet::~ParticleSet(void)
{

}


void ParticleSet::erase(int index)
{
	delete particles[index];
	particles.erase(particles.begin() + index);
}

void ParticleSet::display()
{
	for (unsigned int i=0; i<particles.size(); ++i)
    {
		if(particles[i]->is_dead())
			erase(i);
		else
			particles[i]->show();
    }
}

void ParticleSet::update()
{
	for (unsigned int i=0; i<particles.size(); ++i)
    {
		particles[i]->update();
    }
}

void ParticleSet::add(Particle *particle)
{

	particles.push_back(particle);
}

void ParticleSet::add_particle(float a, float b,  float c, const int n)
{
	for ( int i=0; i<n; ++i)
	{

		Particle *	newParticle = new Particle(a, b, c);
		particles.push_back(newParticle);
	}
}
