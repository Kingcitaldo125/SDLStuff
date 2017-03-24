#pragma once

#include "stdafx.h"

#ifndef CELL_H
#define CELL_H

class Cell
{
public://Constructor and destructor and vars
	Cell();
	Cell(int x, int y);
	~Cell();
private:
	SDL_Surface* screen;
	SDL_Rect rect;
	int xPos;
	int yPos;
	int width;
	int height;
	Uint32 color;

public://functions
	SDL_Rect getRect() { return rect; };
	int getWidth() { return width; };
	int getHeight() { return height; };
	int getxpos() { return xPos; };
	int getypos() { return yPos; };
	void update();
	void setColor(Uint32 c)
	{ color = c; };
	void draw(SDL_Surface* dest)
	{
		SDL_FillRect(screen, NULL, color);
		SDL_BlitSurface(screen, NULL, dest, &rect);
	};
};

#endif
