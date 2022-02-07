#include "MyEngine.h"
#include "World.h"
#include <fstream>
#include "Player.h"
#include "Wall.h"
#include "Goal.h"
#include <iostream>

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
		Input();
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

void MyEngine::LoadLevel(std::string LoadMapName)
{
	std::ifstream MapFile(LoadMapName);
	int X = 0;
	int Y = 0;

	while (!MapFile.eof())				// 파일이 끝인지 물어봄
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
	MapFile.close();
}

void MyEngine::SaveLevel(std::string SaveMapName)
{
	std::ofstream WriteFile(SaveMapName);

	int MaxX = -99999;
	int MaxY = -99999;

	std::vector<Actor*> ActorList = CurrentWorld->GetActorList();


	// 제일 큰 좌표값 저장 하기
	for (auto SelectedActor : ActorList)
	{
		if (MaxX <= SelectedActor->GetX())
		{
			MaxX = SelectedActor->GetX();
		}

		if (MaxY <= SelectedActor->GetY())
		{
			MaxY = SelectedActor->GetY();
		}
	}

	bool bIsWrite = false;

	for (int Y = 0; Y <= MaxY; ++Y)
	{
		for (int X = 0; X <= MaxX; ++X)
		{
			// 객체 저장
			for (auto SelectedActor : ActorList)
			{
				if (SelectedActor->GetX() == X && SelectedActor->GetY() == Y)
				{
					WriteFile.put(SelectedActor->GetShape());
					bIsWrite = true;
					break;
				}
			}

			// 빈칸 저장
			if (bIsWrite == false)
			{
				WriteFile.put(' ');
			}

			bIsWrite = false;
		}
		// 줄 바꿈
		WriteFile.put('\n');
	}

	WriteFile.close();
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
