#pragma once
#include "Actor.h"

class Wall : public Actor
{
public:
	Wall();
	Wall(int NewX, int NewY);
	virtual ~Wall();

	virtual void Render(SDL_Renderer* MyRenderer) override;
};

