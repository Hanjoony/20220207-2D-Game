#include "World.h"
#include "Actor.h"

World::World()
{
}

World::~World()
{
	//UE4 
	//for (int i = 0; i < ActorList.size(); ++i)
	//{
	//	delete ActorList[i];
	//	ActorList[i] = nullptr;
	//}

	//for (auto iter = ActorList.begin(); iter != ActorList.end(); ++iter)			// 	�ؿ��� �Ȱ�����
	////for (std::vector<Actor*>::iterator iter = ActorList.begin(); iter != ActorList.end(); ++iter)
	//{
	//	delete *iter;
	//	*iter = nullptr;
	//}

	// range for
	for (auto CurrentActor : ActorList)		// ���� ���� ����Ʈ Ž���ؼ� �����
	{
		// delete CurrentActor;
		CurrentActor = nullptr;
	}

	ActorList.clear();						// ���� ����Ʈ�� �ʱ�ȭ
}

void World::SpawnActor(std::shared_ptr<Actor> NewActor)
{
	ActorList.push_back(NewActor);			// ���θ��� ���� �־��ֱ�
}

void World::DestroyActor(std::shared_ptr<Actor> DestroyActor)
{
	//�ڷᱸ�� Actor ����Ʈ���� ���� ����Ʈ���� ����
	ActorList.erase(find(ActorList.begin(), ActorList.end(), DestroyActor));
	//�޸𸮿��� ������ ����
	// delete DestroyActor;
	DestroyActor = nullptr;
}

void World::Tick()
{
	for (auto SelectedActor : ActorList)
	{
		SelectedActor->Tick();
	}
}

void World::Render()
{
	for (auto SelectedActor : ActorList)
	{
		SelectedActor->Render();
	}
}

void World::BeginPlay()
{
	for (auto SelectedActor : ActorList)
	{
		SelectedActor->BeginPlay();
	}
}
