#include <iostream>
#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include "Screen.h"
#include "Swarm.h"

using namespace kl;
using namespace std; 

int main(int argc, char* args[]) {
	// seed a random number which makes 
	// rand() return a different number every time
	srand(time(NULL));


	Screen screen; 

	if (!screen.init()) {
		cout << "Error initializing SDL screen." << endl; 
	}
	
	Swarm swarm;  
	const int HALFWIDTH = Screen::SCREEN_WIDTH / 2;
	const int HALFHEIGHT = Screen::SCREEN_HEIGHT / 2;

	//Uint32 bgColor = SDL_MapRGB(screen->format, 0, 0, 0);

	while (true) {
		// Update particles
		
		// Draw Particles 

		int elapsed = SDL_GetTicks();

		//screen.clear();
		swarm.update(elapsed);

		unsigned char red = (unsigned char)((1.6 + sin(elapsed * 0.0001)) * 128);
		unsigned char green = (unsigned char)((1.6 + sin(elapsed * 0.0002)) * 128);
		unsigned char blue = (unsigned char)((1.6 + sin(elapsed * 0.0003)) * 128);

		const Particle *const pParticle = swarm.getParticles();
		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			Particle particle = pParticle[i];
			// (particle.m_x + 1) ranges from 0 to 2
			int x = (particle.m_x + 1) * HALFWIDTH;
			// (particle.m_y * Screen::SCREEN_WIDTH / 2)) --> this will make y starts 0, the top of the screen
			// hence, add (Screen::SCREEN_HEIGHT / 2) half of screen to make it to the center 
			int y = (particle.m_y * HALFWIDTH) + (HALFHEIGHT); 
			screen.setPixel(x, y, red, green, blue); 
		}

		// bluring the color pixels vlaues
		screen.boxBlur();

		screen.update();

		// Draw Particle 
		// Check for messages/events 

		if (!screen.processEvents()) break; 

		//SDL_FillRect(screen, NULL, bgColor);
		//SDL_UpdateWindowSurface(window);
	}
	  
	return 0; 
}

