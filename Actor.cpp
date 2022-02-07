#include "Actor.h"
#include <iostream>
#include <Windows.h>

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

void Actor::Tick()
{
}

void Actor::Render()
{
	COORD Cur;
	Cur.X = GetX();
	Cur.Y = GetY();
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);

	std::cout << GetShape() << std::endl;
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
