#pragma once
#include "InterfaceEggType.h"

class EggType : public InterfaceEggType
{
private:

	// ����� ������ �������������
	vector <Stage> KitStages;

	// ����� ������� ������
	//int CurrentStageNumber;

	// �������� ���� ���
	DEF(string, NameOfType);

public:

	EggType();

	EggType(string Name);

	// ���������� ����� ������
	void SetKitStages(vector <Stage> kitStages);

	// �������� ������ � ����� ������
	void AppendStage(Stage oneStage);

	// ������� ������ ������
	vector <Stage> GetStages();

	// ������� ��������
	string GetName();
};

