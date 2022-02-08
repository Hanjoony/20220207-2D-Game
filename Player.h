#pragma once
#include "Actor.h"

class Player : public Actor
{
public:
	Player();
	Player(int NewX, int NewY);
	virtual ~Player();

	virtual void Tick(SDL_Event& MyEvent) override;
};

