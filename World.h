#pragma once
#include <vector>

class World
{
public:
	World();
	virtual ~World();

	void SpawnActor(class Actor* NewActor);
	void DestroyActor(class Actor* DestroyActor);

	void Tick();
	void Render();
	void Input();
	void BeginPlay();

protected:
	std::vector<class Actor*> ActorList;

};

