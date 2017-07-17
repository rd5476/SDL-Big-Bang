#pragma once
#include"Particles.h"
class Swarm
{
public:
	int NPARTICLE;
	Particles * particles;
	Swarm();
	Swarm(int n);// : NPARTICLE(n);
	~Swarm();
	Particles * getParticles(){ return particles; }
	void update();
};

