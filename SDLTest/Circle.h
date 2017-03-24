#pragma once

#include "stdafx.h"

#ifndef _CIRCLE_H
#define _CIRCLE_H

class Circle
{
private:
	SDL_Window* win;
	SDL_Renderer* rend;
	Uint32 radius;
public:
	Circle(SDL_Window* w)
	{
		win = win;
		rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	}
	Circle(SDL_Window* w, Uint32 rad)
	{
		win = w;
		rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
		radius = rad;
	}
public:
	void drawCircle(Uint16 color, Sint16* posx, Sint16* posy)
	{
		//filledCircleColor(rend, *posx, *posy, radius, color);
	}
};

#endif
