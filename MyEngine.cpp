#include "MyEngine.h"
#include "World.h"


MyEngine::MyEngine()
{
	CurrentWorld = new World();
	blsRunning = true;				// ���� ���� �� �ʱ�ȭ
}

MyEngine::~MyEngine()
{
	delete CurrentWorld;
	CurrentWorld = nullptr;
	blsRunning = false;
}

void MyEngine::Run()
{
	// 1 Frame �������� �����°�
	BeginPlay();
	while (blsRunning)
	{
		Input();		// ������ �߿�
		Tick();
		Render();
	}
}

void MyEngine::Stop()
{
	blsRunning = false;
}

void MyEngine::SpawnActor(Actor* NewActor)
{
	CurrentWorld->SpawnActor(NewActor);
}

void MyEngine::DestroyActor(Actor* DestroyActor)
{
	CurrentWorld->DestroyActor(DestroyActor);
}

void MyEngine::BeginPlay()
{
	CurrentWorld->BeginPlay();
}

void MyEngine::Tick()
{
	CurrentWorld->Tick();
}

void MyEngine::Render()
{
	CurrentWorld->Render();
}

void MyEngine::Input()
{
	CurrentWorld->Input();
}
