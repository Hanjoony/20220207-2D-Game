#pragma once
#include "Actor.h"
class Monster : public Actor
{
public:
	Monster();
	Monster(int NewX, int NewY);
	virtual ~Monster();

	virtual void Tick() override;

	Uint64 ElapseTime;
	Uint64 ProcessTime;
};