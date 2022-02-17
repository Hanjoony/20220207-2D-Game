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

	//for (auto iter = ActorList.begin(); iter != ActorList.end(); ++iter)			// 	밑에랑 똑같은거
	////for (std::vector<Actor*>::iterator iter = ActorList.begin(); iter != ActorList.end(); ++iter)
	//{
	//	delete *iter;
	//	*iter = nullptr;
	//}

	// range for
	for (auto CurrentActor : ActorList)		// 만든 액터 리스트 탐색해서 지우기
	{
		// delete CurrentActor;
		CurrentActor = nullptr;
	}

	ActorList.clear();						// 액터 리스트도 초기화
}

void World::SpawnActor(std::shared_ptr<Actor> NewActor)
{
	ActorList.push_back(NewActor);			// 새로만든 액터 넣어주기
}

void World::DestroyActor(std::shared_ptr<Actor> DestroyActor)
{
	//자료구조 Actor 리스트에서 관리 리스트에서 삭제
	ActorList.erase(find(ActorList.begin(), ActorList.end(), DestroyActor));
	//메모리에서 실제로 삭제
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
