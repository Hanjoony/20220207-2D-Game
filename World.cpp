#include "World.h"
#include "Actor.h"

World::World()
{
}

World::~World()
{
	for (auto CurrentActor : ActorList)		// ���� ���� ����Ʈ Ž���ؼ� �����
	{
		delete CurrentActor;
		CurrentActor = nullptr;
	}

	ActorList.clear();						// ���� ����Ʈ�� �ʱ�ȭ
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
