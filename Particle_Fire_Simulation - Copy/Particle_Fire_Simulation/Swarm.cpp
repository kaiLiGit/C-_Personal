#include "Swarm.h"

Swarm::Swarm()
{
	m_pParticles = new Particle[NPARTICLES];
}


Swarm::~Swarm()
{
	delete[] m_pParticles;
	std::cout << "Swarm destroyed and m_pParticles deleted" << std::endl;
}

void Swarm::update() {
	for (int i = 0; i < NPARTICLES; i++) {
		m_pParticles[i].update();
	}
}