#include <stdlib.h> 
#include "Particle.h"

using namespace std; 

Particle::Particle()
{
	init();
}

void Particle::init() {
	// starting from the center 
	m_x = 0.0; 
	m_y = 0.0; 

	m_direction = (2.0 * M_PI * rand()) / RAND_MAX; // calculating random degree
	m_speed = (0.03 * rand()) / RAND_MAX;

	m_speed = m_speed * m_speed; // making particle speed larger hence scatter uneven across the screen from the center
}

Particle::~Particle()
{
}

void Particle::moveUpdate(int interval) {
	// curling the direction 
	m_direction += interval * 0.0003;

	double xspeed = m_speed * cos(m_direction);
	double yspeed = m_speed * sin(m_direction);

	m_x += xspeed * interval; 
	m_y += yspeed * interval;

	if (m_x < -1 || m_x > 1 || m_y < -1 || m_y > 1) { init(); }

	// rand() less than (RAND_MAX / 100) 
	// reinitlized the particle's member variables
	if (rand() < (RAND_MAX / 100)) {
		init();
	}
}
 
