#pragma once
#include <string>
#include "SDL.h"
#include <memory>

class World;				// 전방 선언

class MyEngine
{
public:
	//MyEngine();
	MyEngine(std::string Title, std::string LevelName, int Width, int Height);
	virtual ~MyEngine();

	void Init(std::string Title, int Width, int Height);		// 윈도우 창 크기
	void Term();

	void Run();			// 엔진 실행

	void Stop();		// 엔진 정지

	void SpawnActor(std::shared_ptr<class Actor> NewActor);				// 전방 선언, 액터 생성
	void DestroyActor(std::shared_ptr<class Actor> DestroyActor);		// 액터 만들었으니 지우기

	void LoadLevel(std::string LoadMapName);
	void SaveLevel(std::string SaveMapName);

	inline static SDL_Window* GetWindow() { return MyWindow; }
	inline static SDL_Renderer* GetRenderer() { return MyRenderer; }
	inline static SDL_Event& GetEvent() { return MyEvent; }

protected:							// 밖에서 접근하면 안되는 것들
	void BeginPlay();
	void Tick();
	void Render();
	void Input();

protected:
	bool bIsRunning = true;			// 엔진 실행 중인지 상태 확인
	std::unique_ptr<World> CurrentWorld;		// 포인터로 위치를 가르켜야함 

	static SDL_Window* MyWindow;
	static SDL_Renderer* MyRenderer;
	static SDL_Event MyEvent;
};