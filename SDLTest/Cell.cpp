#include "stdafx.h"
#include "Cell.h"

inline int randomInteger(int min, int max)
{
	return rand() % max + min;
}

Cell::Cell(int x, int y) :
	xPos(x),
	yPos(y),
	width(50),
	height(50)
{
	srand(time(NULL));

	screen = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
	color = SDL_MapRGB(screen->format, randomInteger(0, 255), randomInteger(0, 255), randomInteger(0, 255));

	rect = screen->clip_rect;
	rect.x = xPos;
	rect.y = yPos;

	SDL_FillRect(screen, NULL, color);
}

Cell::~Cell()
{

}

void Cell::update()
{

}
