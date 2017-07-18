#pragma once
#include <iostream>
#include <SDL.h>
#include <math.h>

class Particle
{
private: 
	void init();

public: 
	double m_x; // position x of particle
	double m_y; // position y of particle
	 
	double m_speed; // particle speed 
	double m_direction; // particle direction

public:
	Particle();
	virtual ~Particle();  
	void moveUpdate(int interval);
};

