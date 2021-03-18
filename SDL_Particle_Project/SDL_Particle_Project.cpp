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

int main()
{
    // if is true something is wrong
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "SDL init failed" << endl;
        return 1;
    }

    cout << "SDL init succedded" << endl;

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
