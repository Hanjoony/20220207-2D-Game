#include "Player.h"

Player::Player()
{
	X = 0;
	Y = 0;
	Shape = 'P';
	Color.r = 0xff;		// RGB 값
	Color.g = 0x00;
	Color.b = 0x00;
	Color.a = 0xff;		// 알파
}

Player::Player(int NewX, int NewY)
{
	X = NewX;
	Y = NewY;
	Shape = 'P';
	Color.r = 0xff;		// RGB 값
	Color.g = 0x00;
	Color.b = 0x00;
	Color.a = 0xff;		// 알파
}

Player::~Player()
{
}
