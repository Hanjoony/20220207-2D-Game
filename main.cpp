#include <iostream>
#include "MyEngine.h"
#include "SDL.h"
#include <memory>

#pragma comment(lib, "SDL2main.lib")		// ���̺귯���� �ʿ��ϸ� ������ ����� ��ɾ�
#pragma comment(lib, "SDL2.lib")

using namespace std;


int SDL_main(int argc, char* argv[])
{
	unique_ptr<MyEngine> PlayEngine = make_unique<MyEngine>("Maze Game", "Level01.Map", 800, 600);

	PlayEngine->Run();

	// delete PlayEngine;  ����Ʈ ������ ������� delete �� �޸� ������ �ʿ䰡 ����
	PlayEngine = nullptr;

	return 0;
}