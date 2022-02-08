#include "Goal.h"

Goal::Goal()
{
	X = 0;
	Y = 0;
	Shape = 'G';
	Color.r = 0xff;		// RGB 값
	Color.g = 0xff;
	Color.b = 0x00;
	Color.a = 0xff;		// 알파
}

Goal::Goal(int NewX, int NewY)
{
	X = NewX;
	Y = NewY;
	Shape = 'G';
	Color.r = 0xff;		// RGB 값
	Color.g = 0xff;
	Color.b = 0x00;
	Color.a = 0xff;		// 알파
}

Goal::~Goal()
{
}
