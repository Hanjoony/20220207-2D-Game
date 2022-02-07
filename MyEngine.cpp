#include "MyEngine.h"
#include "World.h"


MyEngine::MyEngine()
{
	CurrentWorld = new World();
	blsRunning = true;				// 엔진 시작 후 초기화
}

MyEngine::~MyEngine()
{
	delete CurrentWorld;
	CurrentWorld = nullptr;
	blsRunning = false;
}

void MyEngine::Run()
{
	// 1 Frame 한프레임 돌리는것
	BeginPlay();
	while (blsRunning)
	{
		Input();		// 순서가 중요
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
