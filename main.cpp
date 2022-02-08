#include <iostream>
#include "MyEngine.h"
#include "SDL.h"

#pragma comment(lib, "SDL2main.lib")		// ���̺귯���� �ʿ��ϸ� ������ ����� ��ɾ�
#pragma comment(lib, "SDL2.lib")

using namespace std;


int SDL_main(int argc, char* argv[])
{
	MyEngine* PlayEngine = new MyEngine("�̷ΰ���", "Level01.Map", 800, 600);
	PlayEngine->Run();

	delete PlayEngine;
	PlayEngine = nullptr;

	bool blsRunning = true;

	return 0;
}