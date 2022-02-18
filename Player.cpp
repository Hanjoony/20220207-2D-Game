#include "Player.h"
#include "MyEngine.h"
#include "World.h"

Player::Player()
{
	Init(0, 0);
}

Player::Player(int NewX, int NewY, std::string ImageName)
{
	Init(NewX, NewY);
	LoadBMP(ImageName);
}

Player::~Player()
{
}

void Player::Init(int NewX, int NewY)
{
	Actor::Init(NewX, NewY);
	Shape = 'P';
	Color.r = 0xff;
	Color.g = 0x00;
	Color.b = 0x00;
	Color.a = 0xff;

	ZOrder = 2;

	Surface = nullptr;
	Texture = nullptr;
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

void Player::Render()
{
	Actor::Render();
}