#pragma once
#include<string>
#include "SDL.h"

class World;

class MyEngine
{
public:
	// MyEngine();
	MyEngine(std::string Title, std::string LevelName, int Width, int Height);
	virtual ~MyEngine();

	void Init(std::string Title, int Width, int Height);		// ������ â ũ��
	void Term();

	void Run();			// ���� ����

	void Stop();		// ���� ����

	void SpawnActor(class Actor* NewActor);				// ���� ����, ���� ����
	void DestroyActor(class Actor* DestroyActor);		// ���� ��������� �����

	void LoadLevel(std::string LoadMapName);
	void SaveLevel(std::string SaveMapName);

protected:							// �ۿ��� �����ϸ� �ȵǴ� �͵�
	void BeginPlay();
	void Tick();
	void Render();
	void Input();

protected:
	bool blsRunning = true;			// ���� ���� ������ ���� Ȯ��
	World* CurrentWorld;			// ���漱�� �ؼ� ��򰡿� �����Ŷ�°�, �����ͷ� ��ġ�� �����Ѿ��� 

	SDL_Window* MyWindow;
	SDL_Renderer* MyRenderer;
	SDL_Event MyEvent;
};