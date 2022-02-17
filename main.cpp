#include <iostream>
#include <algorithm>
#include "MyEngine.h"
#include "SDL.h"
#include <memory>
#include <vector>
#include "Actor.h"


#pragma comment(lib, "SDL2main.lib")
#pragma comment(lib, "SDL2.lib")

using namespace std;

bool compare(int a, int b)
{
	return a > b;
}

class Test
{
public:
	Test(int NewNumber) { Number = NewNumber; }
	int Number = 0;

	//연산자, 오버로딩, operator overloading
	//Test[1] < Test[2]
	bool operator <(Test& RHS)
	{
		return this->Number < RHS.Number;
	}


};

#include "Floor.h"
#include "Wall.h"
#include "Player.h"
#include "Goal.h"

int SDL_main(int argc, char* argv[])
{
	unique_ptr<MyEngine> PlayEngine = make_unique<MyEngine>("Maze Game", "Level01.Map", 800, 600);
	PlayEngine->Run();
	PlayEngine = nullptr;



	//vector<Test> TestList;
	//TestList.push_back(Test(9));
	//TestList.push_back(Test(4));
	//TestList.push_back(Test(1));
	//TestList.push_back(Test(2));
	//TestList.push_back(Test(6));
	//TestList.push_back(Test(5));
	//TestList.push_back(Test(7));
	//TestList.push_back(Test(8));
	//TestList.push_back(Test(0));
	//TestList.push_back(Test(3));

	//sort(TestList.begin(), TestList.end());
	//for (auto Object : TestList)
	//{
	//	cout << Object.Number << endl;
	//}

	//BigO
	//int a[10] = { 9,4,1, 2 ,6,5,7,8,0,3 };

	//sort(a, a+10 , compare);

	////for (int i = 0; i < 10; ++i)
	////{
	////	for (int j = 0; j < 10; ++j)
	////	{
	////		if (a[i] < a[j])
	////		{
	////			int temp = a[i];
	////			a[i] = a[j];
	////			a[j] = temp;
	////		}
	////	}
	////}

	//for (int i = 0; i < 10; ++i)
	//{
	//	cout << a[i] << endl;
	//}
	return 0;
}