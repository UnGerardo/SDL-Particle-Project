/*
    To see what directories were added manually, right click on SDL_Particle_Project cpp file or go to Project and open properties.
    First is C/C++ -> General -> Additional Include Directories
    Second is Linker -> Additional Library Directories
    Third is Linker -> Input -> Additional Dependencies
    
    Also had to copy SDL2.dll (x64) to C:\Users\gerar\OneDrive\Desktop\vsRepos\SDL_Particle_Project\x64\Release
*/


#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define SDL_MAIN_HANDLED // needed because SDL.h defines a main of its own and conflicts with main in this file
#include <SDL.h>
#include "Screen.h"
#include "Swarm.h"
using namespace std;

int main() {

    srand(time(NULL));

    Screen screen;

    if (!screen.init()) {
        cout << "Error initializing SDL" << endl;
        return 0;
    }

	Swarm swarm;



    while (true) {
        
        // Update Particles
        // this func returns the number of ms since start of program
        int elapsed = SDL_GetTicks();

		swarm.update(elapsed);

        // multiply by 0.001 to smooth out change 
        unsigned char red = (1 + sin(elapsed * 0.0003)) * 128;
        unsigned char green = (1 + sin(elapsed * 0.0006)) * 128;
        unsigned char blue = (1 + sin(elapsed * 0.0009)) * 128;

		const Particle *const pParticles = swarm.getParticles();
		for(int i = 0; i < swarm.NPARTICLES; i++) {
			Particle particle = pParticles[i];

			int x = (particle.m_x + 1) * screen.SCREEN_WIDTH/2;
			int y = (particle.m_y * screen.SCREEN_WIDTH/2) + screen.SCREEN_HEIGHT/2;

			screen.setPixel(x, y, red, green, blue);
		}

		screen.boxBlur();

        // Draw screen
        screen.update();

        // Check for messages/events
        if (!screen.processEvents()) {
            break;
        }
    }

    screen.close();

    return 0;
}
