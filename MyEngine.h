#pragma once
#include<string>

class MyEngine
{
public:
	MyEngine();
	virtual ~MyEngine();

	void Run();			// ���� ����

	void Stop();		// ���� ����

	void SpawnActor(class Actor* NewActor);		// ���� ����, ���� ����
	void DestroyActor(class Actor* DestroyActor);		// ���� ��������� �����

	void LoadLevel(std::string LoadMapName);
	void SaveLevel(std::string SaveMapName);

protected:							// �ۿ��� �����ϸ� �ȵǴ� �͵�
	void BeginPlay();
	void Tick();
	void Render();
	void Input();

protected:
	bool blsRunning = true;			// ���� ���� ������ ���� Ȯ��
	class World* CurrentWorld;						// ���漱�� �ؼ� ��򰡿� �����Ŷ�°�, �����ͷ� ��ġ�� �����Ѿ��� 
};