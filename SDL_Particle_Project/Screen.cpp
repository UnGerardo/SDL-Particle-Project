#include "Screen.h"

Screen::Screen() : m_window(NULL), m_texture(NULL), m_renderer(NULL), m_buffer(NULL) {

}
bool Screen::init() {
    // if is true something is wrong
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return false;
    }

    // creates window to display whatever you want
    m_window = SDL_CreateWindow("Particle Fire Explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    // if window couldn't be created, quit
    if (m_window == NULL) {
        SDL_Quit();
        return false;
    }

    // create renderer and texture objects; renderer shows stuff on window; texture is what is shown by renderer
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
    m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

    // if renderer or texture is null, quit
    if (m_renderer == NULL) {
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }
    if (m_texture == NULL) {
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }

    // allocate memory for every pixel in the window
    Uint32* buffer = new Uint32[SCREEN_HEIGHT * SCREEN_WIDTH];

    // function that takes in an amount of memory and changes it to some value; here it takes the pixel memory and sets it a certain value
    memset(buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

    for (int i = 0; i < SCREEN_HEIGHT * SCREEN_WIDTH; i++) {
        buffer[i] = 0xFF00FFFF;
    }

    // updates texture with the info from buffer (the pixel memory)
    SDL_UpdateTexture(m_texture, NULL, buffer, SCREEN_WIDTH * sizeof(Uint32));
    // clears current rendering thing; resets renderer to render new stuff
    SDL_RenderClear(m_renderer);
    // copies the info from texture to the renderer to render the correct info; last two params say what section of each, NULL means entire thing
    SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
    SDL_RenderPresent(m_renderer);
	return true;
}
bool Screen::processEvents() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return false;
        }
    }
	return true;
}

// frees up allocated memory and properly exits program
void Screen::close() {
    delete[] m_buffer;
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyTexture(m_texture);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}