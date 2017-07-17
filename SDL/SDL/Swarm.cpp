#include "Swarm.h"


Swarm::Swarm(int n) : NPARTICLE(n)
{
	particles = new Particles[NPARTICLE];
}


Swarm::~Swarm()
{
	delete []particles;
}

void Swarm::update(){
	for (int i = 0; i < NPARTICLE; i++){
		particles[i].update();
	}
}