#include <iostream>
#include <algorithm>
#include "MyEngine.h"
#include "SDL.h"
#include <memory>
#include <vector>

#pragma comment(lib, "SDL2main.lib")
#pragma comment(lib, "SDL2.lib")

using namespace std;

int SDL_main(int argc, char* argv[])
{
	unique_ptr<MyEngine> PlayEngine = make_unique<MyEngine>("Maze Game", "Level01.Map", 800, 600);
	PlayEngine->Run();
	PlayEngine = nullptr;

	return 0;
}