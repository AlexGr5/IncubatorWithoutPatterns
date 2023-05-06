#pragma once
#include "InterfaceEggType.h"

class EggType : public InterfaceEggType
{
private:

	static EggType* instance;


protected:
	EggType();

	EggType(string Name);

	// ����� ������ �������������
	vector <Stage> KitStages;

	// ����� ������� ������
	//int CurrentStageNumber;

	// �������� ���� ���
	DEF(string, NameOfType);

public:

	static EggType* Instance(string Name);
	static EggType* Instance();

	// ���������� ����� ������
	void SetKitStages(vector <Stage> kitStages);

	// �������� ������ � ����� ������
	void AppendStage(Stage oneStage);

	// ������� ������ ������
	vector <Stage> GetStages();

	// ������� ��������
	string GetName();
};

