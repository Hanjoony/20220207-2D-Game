#include <iostream>
#include <fstream>
#include "MyEngine.h"
#include "Floor.h"
#include "Player.h"
#include "Wall.h"
#include "Goal.h"

using namespace std;


//ÂüÁ¶ÀÚ, Reference
void Swapint(int& A, int& B)
{
	int Temp = A;
	A = B;
	B = Temp;
}

int main()
{
	MyEngine* PlayEngine = new MyEngine();

	PlayEngine->LoadLevel("Level02.map");

	PlayEngine->SaveLevel("Level03.map");


	// PlayEngine->Run();

	delete PlayEngine;
	PlayEngine = nullptr;

	return 0;
}

/*
int main()
{
	MyEngine* PlayEngine = new MyEngine();

	// **********
	PlayEngine->SpawnActor(new Wall(0, 0));
	PlayEngine->SpawnActor(new Wall(1, 0));
	PlayEngine->SpawnActor(new Wall(2, 0));
	PlayEngine->SpawnActor(new Wall(3, 0));
	PlayEngine->SpawnActor(new Wall(4, 0));
	PlayEngine->SpawnActor(new Wall(5, 0));
	PlayEngine->SpawnActor(new Wall(6, 0));
	PlayEngine->SpawnActor(new Wall(7, 0));
	PlayEngine->SpawnActor(new Wall(8, 0));
	PlayEngine->SpawnActor(new Wall(9, 0));

	// *        *
	PlayEngine->SpawnActor(new Wall(0, 1));
	PlayEngine->SpawnActor(new Wall(9, 1));

	PlayEngine->SpawnActor(new Wall(0, 2));
	PlayEngine->SpawnActor(new Wall(9, 2));
	PlayEngine->SpawnActor(new Wall(0, 3));
	PlayEngine->SpawnActor(new Wall(9, 3));
	PlayEngine->SpawnActor(new Wall(0, 4));
	PlayEngine->SpawnActor(new Wall(9, 4));
	PlayEngine->SpawnActor(new Wall(0, 5));
	PlayEngine->SpawnActor(new Wall(9, 5));
	PlayEngine->SpawnActor(new Wall(0, 6));
	PlayEngine->SpawnActor(new Wall(9, 6));
	PlayEngine->SpawnActor(new Wall(0, 7));
	PlayEngine->SpawnActor(new Wall(9, 7));
	PlayEngine->SpawnActor(new Wall(0, 8));
	PlayEngine->SpawnActor(new Wall(9, 8));

	PlayEngine->SpawnActor(new Wall(0, 9));
	PlayEngine->SpawnActor(new Wall(1, 9));
	PlayEngine->SpawnActor(new Wall(2, 9));
	PlayEngine->SpawnActor(new Wall(3, 9));
	PlayEngine->SpawnActor(new Wall(4, 9));
	PlayEngine->SpawnActor(new Wall(5, 9));
	PlayEngine->SpawnActor(new Wall(6, 9));
	PlayEngine->SpawnActor(new Wall(7, 9));
	PlayEngine->SpawnActor(new Wall(8, 9));
	PlayEngine->SpawnActor(new Wall(9, 9));

	PlayEngine->SpawnActor(new Player(1, 1));
	PlayEngine->SpawnActor(new Goal(8, 8));

	PlayEngine->Run();

	delete PlayEngine;
	PlayEngine = nullptr;

	return 0;
}
*/
