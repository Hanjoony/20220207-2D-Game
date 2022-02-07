#pragma once
#include<string>

class MyEngine
{
public:
	MyEngine();
	virtual ~MyEngine();

	void Run();			// 엔진 실행

	void Stop();		// 엔진 정지

	void SpawnActor(class Actor* NewActor);		// 전방 선언, 액터 생성
	void DestroyActor(class Actor* DestroyActor);		// 액터 만들었으니 지우기

	void LoadLevel(std::string LoadMapName);
	void SaveLevel(std::string SaveMapName);

protected:							// 밖에서 접근하면 안되는 것들
	void BeginPlay();
	void Tick();
	void Render();
	void Input();

protected:
	bool blsRunning = true;			// 엔진 실행 중인지 상태 확인
	class World* CurrentWorld;						// 전방선언 해서 어딘가에 있을거라는거, 포인터로 위치를 가르켜야함 
};