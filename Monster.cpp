#include "Monster.h"
#include "MyEngine.h"
#include "World.h"

Monster::Monster()
{
	X = 0;
	Y = 0;
	Shape = 'E';
	Color.r = 0x81;
	Color.g = 0x18;
	Color.b = 0x82;
	Color.a = 0xff;

	ZOrder = 3;

	ElapseTime = 0;
	ProcessTime = 100;
}

Monster::Monster(int NewX, int NewY)
{
	X = NewX;
	Y = NewY;
	Shape = 'E';
	Color.r = 0x81;
	Color.g = 0x18;
	Color.b = 0x82;
	Color.a = 0xff;

	ZOrder = 3;
	srand((unsigned int)time(nullptr));

	ElapseTime = 0;
	ProcessTime = 100;
}

Monster::~Monster()
{
}

void Monster::Tick()
{
	ElapseTime += MyEngine::GetWorld()->GetWorldDeltaSeconds();

	if (ProcessTime <= ElapseTime)
	{
		int Direction = rand() % 4;
		switch (Direction)
		{
		case 0:
			CanMove(X - 1, Y);
			break;
		case 1:
			CanMove(X + 1, Y);
			break;
		case 2:
			CanMove(X, Y - 1);
			break;
		case 3:
			CanMove(X, Y + 1);
			break;
		}

		ElapseTime = 0;
	}
}
