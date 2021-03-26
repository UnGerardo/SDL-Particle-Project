#pragma once

#include <iostream>
#include <SDL.h>

class Screen {
	public:
		const static int SCREEN_WIDTH = 800;
		const static int SCREEN_HEIGHT = 600;

		Screen();
		bool init();
		void setPixel(int x, int y, Uint8 r, Uint8 g, Uint8 b);
		void update();
		void clear();
		bool processEvents();
		void close();

	private:
		// prefix with m_ to show that these are instance variables not local
		SDL_Window *m_window;
		SDL_Renderer *m_renderer;
		SDL_Texture *m_texture;
		Uint32 *m_buffer;
};

