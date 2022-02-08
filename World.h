#pragma once
#include <vector>
#include "SDL.h"

class World
{
public:
	World();
	virtual ~World();

	void SpawnActor(class Actor* NewActor);
	void DestroyActor(class Actor* DestroyActor);

	void Tick(SDL_Event& MyEvent);
	void Render(SDL_Renderer* MyRenderer);
	void BeginPlay();

	const std::vector<class Actor*>& GetActorList() { return ActorList; }  // 원본 값 지우지 못하게 const 사용

protected:
	std::vector<class Actor*> ActorList;

};

