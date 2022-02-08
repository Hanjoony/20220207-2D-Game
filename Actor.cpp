#include "Actor.h"
#include <iostream>
#include "Util.h"

Actor::Actor()
{
	X = 0;
	Y = 0;
	Shape = ' ';
}

Actor::Actor(int NewX, int NewY)
{
	SetActorLocation(NewX, NewY);
}

Actor::~Actor()
{
}

void Actor::Tick(SDL_Event& MyEvent)
{
}

void Actor::Render(SDL_Renderer* MyRenderer)
{
	// static 멤버 함수
	// Util::GotoXY(GetX(), GetY());				// 텍스트에 그림

	// std::cout << GetShape() << std::endl;

	SDL_SetRenderDrawColor(MyRenderer, Color.r, Color.g, Color.b, Color.a);
	SDL_Rect Rect = { GetX() * TileSize, GetY() * TileSize, TileSize, TileSize };

	SDL_RenderFillRect(MyRenderer, &Rect);
}

void Actor::BeginPlay()
{
}

inline void Actor::SetActorLocation(int NewX, int NewY)
{
	X = NewX;
	Y = NewY;
}

inline void Actor::SetShape(char NewShape)
{
	Shape = NewShape;
}
