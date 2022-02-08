#include <iostream>
#include "SDL.h"

#pragma comment(lib, "SDL2main.lib")		// ���̺귯���� �ʿ��ϸ� ������ ����� ��ɾ�
#pragma comment(lib, "SDL2.lib")

using namespace std;

int SDL_main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)			// ���� �� ��� �ϵ���� �ʱ�ȭ
	{
		cout << "SDL_Init Error :" << SDL_GetError() << endl;
		return -1;
	}

	SDL_Window* MyWindow = SDL_CreateWindow("First SDL Exaple", 100, 100, 800, 600, SDL_WINDOW_OPENGL);

	SDL_Event MyEvent;

	bool blsRunning = true;
	
	while (blsRunning)
	{
		SDL_PollEvent(&MyEvent);

		switch (MyEvent.type)
		{
		case SDL_QUIT:							// �ݱ� ������ �̺�Ʈ ����
			blsRunning = false;
			break;
		case SDL_KEYDOWN:						// Ű������ � Ű�� ������ ����
			cout << SDL_GetKeyName(MyEvent.key.keysym.sym) << "Ű ������" << endl;
			break;
		case SDL_MOUSEBUTTONDOWN:				// ���콺 ��ư ���������� ����
			cout << (MyEvent.button.button == SDL_BUTTON_LEFT) << "���콺 ��ư ������" << endl;
			cout << "(" << MyEvent.button.x << ", " << MyEvent.button.y << ")" << endl;			// ���콺 ��ǥ�� ǥ��
			break;
		}
	}

	SDL_DestroyWindow(MyWindow);				// ������ â ���� ������ �ٽ� ���� �ִ°� �ʿ�
	SDL_Quit();

	return 0;
}