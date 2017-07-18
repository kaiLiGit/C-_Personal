#pragma once

#include <iostream>
#include "Particle.h"

class Swarm
{
public:
	const static int NPARTICLES = 5000;

private: 
	Particle* m_pParticles;
	int lastTimeElaspe;

public:
	Swarm();
	~Swarm();
	const Particle* const getParticles() { return m_pParticles; };
	void update(int elapsed);
};

