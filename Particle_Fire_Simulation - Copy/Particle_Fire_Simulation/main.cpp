#include <iostream>
#include <SDL.h>
#include <stdio.h>
#include "Screen.h"

using namespace kl;

int main(int argc, char* args[]) {
	
	Screen screen; 

	if (!screen.init()) {
		cout << "Error initializing SDL screen." << endl; 
	}
	

	bool exit = false;
	
	//Uint32 bgColor = SDL_MapRGB(screen->format, 0, 0, 0);

	while (!exit) {
		// Update particles

		// iterating through every pixel of the screen 
		for (int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
			for (int x = 0; x < Screen::SCREEN_WIDTH; x++) {
				screen.setPixel(x, y, 0, 255, 0);
			}
		}

		screen.update();

		// Draw Particle 
		// Check for messages/events 

		if (!screen.processEvents()) break; 

		//SDL_FillRect(screen, NULL, bgColor);
		//SDL_UpdateWindowSurface(window);
	}

	return 0; 
}

