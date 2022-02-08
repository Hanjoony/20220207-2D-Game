#include <iostream>
#include "MyEngine.h"
#include "SDL.h"

#pragma comment(lib, "SDL2main.lib")		// 라이브러리가 필요하면 가져다 쓰라는 명령어
#pragma comment(lib, "SDL2.lib")

using namespace std;


int SDL_main(int argc, char* argv[])
{
	MyEngine* PlayEngine = new MyEngine("미로게임", "Level01.Map", 800, 600);
	PlayEngine->Run();

	delete PlayEngine;
	PlayEngine = nullptr;

	bool blsRunning = true;

	return 0;
}