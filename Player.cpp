#include "Player.h"
#include "MyEngine.h"
#include "World.h"

Player::Player()
{
	X = 0;
	Y = 0;
	Shape = 'P';
	Color.r = 0xff;
	Color.g = 0x00;
	Color.b = 0x00;
	Color.a = 0xff;

	ZOrder = 2;
}

Player::Player(int NewX, int NewY)
{
	X = NewX;
	Y = NewY;
	Shape = 'P';
	Color.r = 0xff;
	Color.g = 0x00;
	Color.b = 0x00;
	Color.a = 0xff;

	ZOrder = 2;
}

Player::~Player()
{
}

void Player::Tick()
{
	if (MyEngine::GetEvent().type == SDL_KEYDOWN)
	{
		switch (MyEngine::GetEvent().key.keysym.sym)
		{
		case SDLK_LEFT:
			CanMove(X - 1, Y);
			break;
		case SDLK_RIGHT:
			CanMove(X + 1, Y);
			break;
		case SDLK_UP:
			CanMove(X, Y - 1);
			break;
		case SDLK_DOWN:
			CanMove(X, Y + 1);
			break;
		}
	}
}