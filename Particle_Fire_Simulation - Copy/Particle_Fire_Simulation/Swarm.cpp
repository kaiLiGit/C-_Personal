#include "Swarm.h"

Swarm::Swarm()
{
	m_pParticles = new Particle[NPARTICLES];
	lastTimeElaspe = 0; 
}


Swarm::~Swarm()
{   
	delete[] m_pParticles;
	std::cout << "Swarm destroyed and m_pParticles deleted" << std::endl;
}

void Swarm::update(int elapsed) {
	int interval = elapsed - lastTimeElaspe; // interval of the time passed since last update 
	for (int i = 0; i < NPARTICLES; i++) {
		m_pParticles[i].moveUpdate(interval);
	}
	lastTimeElaspe = elapsed; // record the elapsed time 
}