#pragma once
#include "SDL.h"								// 색상을 집어넣기 위해 사용

class Actor
{
public:
	// 오버로딩, 생성자 오버로딩
	Actor();
	Actor(int NewX, int NewY);

	virtual ~Actor();

	virtual void Tick();
	virtual void Render(SDL_Renderer* MyRenderer);
	virtual void BeginPlay();

	inline virtual void SetActorLocation(int NewX, int NewY);
	inline virtual void SetShape(char NewShape);
	inline virtual char GetShape() { return Shape; }
	inline virtual int GetX() { return X; }		// inline 키워드 컴파일 할때 최적화 가능 (판단해서 함수로 안만들고 문자열로 하기도함)
	inline virtual int GetY() { return Y; }

protected:
	int X;						// 위치 값
	int Y;
	char Shape;
	SDL_Color Color;			// 색상 넣기 위해
	int TileSize = 30;
};

