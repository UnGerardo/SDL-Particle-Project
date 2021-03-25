/*
    To see what directories were added manually, right click on SDL_Particle_Project cpp file or go to Project and open properties.
    First is C/C++ -> General -> Additional Include Directories
    Second is Linker -> Additional Library Directories
    Third is Linker -> Input -> Additional Dependencies
    
    Also had to copy SDL2.dll (x64) to C:\Users\gerar\OneDrive\Desktop\vsRepos\SDL_Particle_Project\x64\Release
*/


#include <iostream>
#define SDL_MAIN_HANDLED // needed because SDL.h defines a main of its own and conflicts with main in this file
#include <SDL.h>
#include "Screen.h"
using namespace std;

int main() {

    Screen screen;

    if (!screen.init()) {
        cout << "Error initializing SDL" << endl;
        return 0;
    }

    while (true) {
        // Update Particles
        // Draw particles
        for (int y = 0; y < screen.SCREEN_HEIGHT; y++) {
            for (int x = 0; x < screen.SCREEN_WIDTH; x++) {
                screen.setPixel(x, y, 128, 0, 255);
            }
        }

        screen.setPixel(400, 300, 255, 255, 255);

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
