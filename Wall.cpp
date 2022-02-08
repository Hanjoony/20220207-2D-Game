#include "Wall.h"
#include "SDL.h"

Wall::Wall()
{
	X = 0;
	Y = 0;
	Shape = '*';
	Color.r = 0x80;		// RGB 값
	Color.g = 0x3a;
	Color.b = 0x30;
	Color.a = 0xff;		// 알파
}

Wall::Wall(int NewX, int NewY)
{
	SetActorLocation(NewX, NewY);
	Shape = '*';
	Color.r = 0x80;		// RGB 값
	Color.g = 0x3a;
	Color.b = 0x30;
	Color.a = 0xff;		// 알파
}

Wall::~Wall()
{
}

void Wall::Render(SDL_Renderer* MyRenderer)
{
	Actor::Render(MyRenderer);
}