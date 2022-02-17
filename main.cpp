#include <iostream>
#include "MyEngine.h"
#include "SDL.h"
#include <memory>

#pragma comment(lib, "SDL2main.lib")		// 라이브러리가 필요하면 가져다 쓰라는 명령어
#pragma comment(lib, "SDL2.lib")

using namespace std;


int SDL_main(int argc, char* argv[])
{
	unique_ptr<MyEngine> PlayEngine = make_unique<MyEngine>("Maze Game", "Level01.Map", 800, 600);

	PlayEngine->Run();

	// delete PlayEngine;  스마트 포인터 사용으로 delete 로 메모리 해제할 필요가 없음
	PlayEngine = nullptr;

	return 0;
}