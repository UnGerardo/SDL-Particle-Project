/*
    To see what directories were added manually, right click on SDL_Particle_Project cpp file or go to Project and open properties.
    First is C/C++ -> General -> Additional Include Directories
    Second is Linker -> Additional Library Directories
    Third is Linker -> Input -> Additional Dependencies
    
    Also had to copy SDL2.dll (x64) to C:\Users\gerar\OneDrive\Desktop\vsRepos\SDL_Particle_Project\x64\Release
    12:57 in udemy
*/


#include <iostream>
#define SDL_MAIN_HANDLED // needed because SDL.h defines a main of its own and conflicts with main in this file
#include <SDL.h>
using namespace std;

int main() {
    // define window size
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;

    // if is true something is wrong
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "SDL init failed" << endl;
        return 1;
    }

    // creates window to display whatever you want
    SDL_Window *window = SDL_CreateWindow("Particle Fire Explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    // if window couldn't be created, quit
    if (window == NULL) {
        SDL_Quit();
        return 2;
    }
    
    // create renderer and texture objects; renderer shows stuff on window; texture is what is shown by renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

    // if renderer or texture is null, quit
    if (renderer == NULL) {
        cout << "Could not create renderer" << endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 3;
    }
    if (texture == NULL) {
        cout << "Could not create texture" << endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 3;
    }

    // allocate memory for every pixel in the window
    Uint32 *buffer = new Uint32[SCREEN_HEIGHT * SCREEN_WIDTH];

    // function that takes in an amount of memory and changes it to some value; here it takes the pixel memory and sets it a certain value
    memset(buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

    for (int i = 0; i < SCREEN_HEIGHT * SCREEN_WIDTH; i++) {
        buffer[i] = 0xFF00FFFF;
    }

    // updates texture with the info from buffer (the pixel memory)
    SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH * sizeof(Uint32));
    // clears current rendering thing; resets renderer to render new stuff
    SDL_RenderClear(renderer);
    // copies the info from texture to the renderer to render the correct info; last two params say what section of each, NULL means entire thing
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

    bool quit = false;
    SDL_Event event;
    while (!quit) {
        // Update Particles
        // Draw particles
        // Check for messages/events

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }
    }

    // frees up allocated memory and properly exits program
    delete [] buffer;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(texture);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
