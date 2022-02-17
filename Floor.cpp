#include "Floor.h"

Floor::Floor()
{
	X = 0;
	Y = 0;
	Shape = ' ';
	Color.r = 0xE6;
	Color.g = 0xE6;
	Color.b = 0xE6;
	Color.a = 0xff;
	ZOrder = 0;
}

Floor::Floor(int NewX, int NewY)
{
	X = NewX;
	Y = NewY;
	Shape = ' ';
	Color.r = 0xE6;
	Color.g = 0xE6;
	Color.b = 0xE6;
	Color.a = 0xff;
	ZOrder = 0;
}

Floor::~Floor()
{
}