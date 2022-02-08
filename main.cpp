#include <iostream>
#include "SDL.h"

#pragma comment(lib, "SDL2main.lib")		// 라이브러리가 필요하면 가져다 쓰라는 명령어
#pragma comment(lib, "SDL2.lib")

using namespace std;

int SDL_main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)			// 에러 날 경우 하드웨어 초기화
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
		case SDL_QUIT:							// 닫기 누르면 이벤트 종료
			blsRunning = false;
			break;
		case SDL_KEYDOWN:						// 키누르면 어떤 키가 눌린지 잡힘
			cout << SDL_GetKeyName(MyEvent.key.keysym.sym) << "키 눌러짐" << endl;
			break;
		case SDL_MOUSEBUTTONDOWN:				// 마우스 버튼 눌러지는지 잡힘
			cout << (MyEvent.button.button == SDL_BUTTON_LEFT) << "마우스 버튼 눌러짐" << endl;
			cout << "(" << MyEvent.button.x << ", " << MyEvent.button.y << ")" << endl;			// 마우스 좌표도 표시
			break;
		}
	}

	SDL_DestroyWindow(MyWindow);				// 윈도우 창 생성 했으면 다시 없에 주는게 필요
	SDL_Quit();

	return 0;
}