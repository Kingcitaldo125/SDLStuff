// SDLTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Cell.h"
#include "Circle.h"

#define FPS 60
#define WINX 800
#define WINY 600

inline int randomInteger(int min, int max)
{
	return (rand()%max)+min;
}

inline void fillScreen(SDL_Window* swin, SDL_Surface* screen, Uint32 color)
{
	SDL_FillRect(screen, NULL, color);
	SDL_UpdateWindowSurface(swin);
}

inline void capFramerate(Uint32 before)
{
	if ((1000 / FPS) > (SDL_GetTicks() - before))
		SDL_Delay((1000 / FPS) - (SDL_GetTicks() - before));
}

// Make sure we correctly link to the SDL libs.
#ifdef _cplusplus
extern "C"
#endif
int main(int argc, char* argv[])
{
	srand(time(NULL));

	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* swin = SDL_CreateWindow("SDL square and stuff", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_RESIZABLE);
	SDL_Surface* screen = SDL_GetWindowSurface(swin);

	// Could not initialize SDL Window
	if (swin == 0)
	{
		std::cout << SDL_GetError() << std::endl;
		return -1;
	}

	bool run = true;
	Uint32 before, now;
	Uint32 circleRad = 25;

	//Draw a square

	Cell c(400, 300);
	Circle circ(swin, circleRad);

	int mousex=0, mousey=0;
	Sint16 circleX, circleY;
	circleX = 460;
	circleY = 570;

	// Main Game Loop
	while (run)
	{
		SDL_Event event;
		before = SDL_GetTicks();
		Uint32 ranColor = SDL_MapRGB(screen->format, randomInteger(0, 255), randomInteger(0, 255), randomInteger(0, 255));

		// Event Listener
		while (SDL_PollEvent(&event))
		{
			// Get the mouse's position in the window
			// SDL_GetMouseState(&mousex, &mousey);

			if (mousex > 400 && mousex <= 450)
			{
				if (mousey > 300 && mousey <= 350)
					c.setColor(ranColor);
			}

			if (event.type == SDL_KEYDOWN)//Get Key Presses
			{
				if (event.key.keysym.sym == SDLK_ESCAPE)
					run = false;
				if (event.key.keysym.sym == SDLK_UP)
					fillScreen(swin, screen, ranColor);
				if (event.key.keysym.sym == SDLK_DOWN)
					fillScreen(swin, screen, ranColor);
				if (event.key.keysym.sym == SDLK_LEFT)
					fillScreen(swin, screen, ranColor);
				if (event.key.keysym.sym == SDLK_RIGHT)
					fillScreen(swin, screen, ranColor);
			}

			if (event.type == SDL_QUIT)
				run = false;
		}

		c.draw(screen);
		circ.drawCircle(ranColor, &circleX, &circleY);

		// Flip the screen
		SDL_UpdateWindowSurface(swin);

		//capFramerate(before);
	}

	/* 
	Delay the window close
	Uint16 seconds = 2;
	SDL_Delay(seconds*1000);
	*/

	// Call before quitting program
	SDL_DestroyWindow(swin);

	// Call before quitting program
	SDL_Quit();

    return 0;
}

