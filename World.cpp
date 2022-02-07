#include "World.h"
#include "Actor.h"

World::World()
{
}

World::~World()
{
	for (auto CurrentActor : ActorList)		// 만든 액터 리스트 탐색해서 지우기
	{
		delete CurrentActor;
		CurrentActor = nullptr;
	}

	ActorList.clear();						// 액터 리스트도 초기화
}

void World::SpawnActor(Actor* NewActor)
{
}

void World::DestroyActor(Actor* DestroyActor)
{
}

void World::Tick()
{
}

void World::Render()
{
}

void World::Input()
{
}

void World::BeginPlay()
{
}
