#include "MyEngine.h"
#include "World.h"
#include <fstream>
#include "Player.h"
#include "Wall.h"
#include "Goal.h"

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

void MyEngine::LoadLevel(std::string MapName)
{
	std::ifstream MapFile(MapName);
	int X = 0;
	int Y = 0;

	while (!MapFile.eof())				// ������ ������ ���
	{
		char ReadData = MapFile.get();
		switch (ReadData)
		{
		case '\n':
			X = 0;
			Y++;
			continue;
		case '*':
			SpawnActor(new Wall(X, Y));
			break;
		case 'P':
			SpawnActor(new Player(X, Y));
			break;
		case 'G':
			SpawnActor(new Goal(X, Y));
			break;
		}

		X++;
	}
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
