#include "Screen.h"


namespace kl {
	Screen::Screen() : m_window(NULL),
		               m_renderer(NULL),
		               m_texture(NULL),
		               m_buffer(NULL)
	{

	}

	

	Screen::~Screen()
	{
		cout << "Screen instance destroyed" << endl;
	}

	bool Screen::init() {
		if (SDL_Init(SDL_INIT_VIDEO) < 0) {
			//printf("SDL could not be initialized\n");
			return false;
		}
		m_window = SDL_CreateWindow("ParticleFireSim", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if (m_window == NULL) {
			//printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			return false;
		}
		
		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
		m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

		if (m_renderer == NULL) {
			//printf("Could not create renderer\n");
			close();
			return false;
		}

		if (m_texture == NULL) {
			//printf("Could not create texture\n");
			close();
			return false;
		}

		try {
			m_buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
			// assign (set) memory bytes to color buffer 
			memset(m_buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

			/*for (int i = 0; i < (SCREEN_WIDTH * SCREEN_HEIGHT); i++) {
				m_buffer[i] = 0xFF00FFFF;  // This is only for testing if m_buffer works correctly
			}*/
		}
		catch (std::bad_alloc &e) {
			std::cerr << "Exception: " << e.what() << std::endl;
			close();
		} 
		return true;
	}

	void Screen::update() {
		SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH * sizeof(Uint32));
		SDL_RenderClear(m_renderer);
		SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
		SDL_RenderPresent(m_renderer);
	}


	void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {
		Uint32 color = 0;  
		color += red; 
		color <<= 8; 
		color += green; 
		color <<= 8; 
		color += blue;
		color <<= 8;
		color += 0xFF; 
		// index conversion
		// m_buffer is an array but used as a two-d array, to get the right pixel position 
		// (y * SCREEN_WIDTH) gives the number of row and (y * SCREEN_WIDTH) + x gives the 
		// right position from that row
		m_buffer[(y * SCREEN_WIDTH) + x] = color; 
	}

	void Screen::close() {
		SDL_DestroyWindow(m_window);
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyTexture(m_texture);
		m_window = NULL;
		
		delete [] m_buffer;
		SDL_Quit();
	}

	bool Screen::processEvents() { 
		SDL_Event e;
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT || (e.key.keysym.sym == SDLK_ESCAPE)) {
				return false;
			}
		}
		return true; 
	}
}
