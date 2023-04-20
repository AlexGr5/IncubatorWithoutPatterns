#include "EggType.h"

EggType::EggType()
{
	NameOfType = "";
	KitStages.resize(0);
}

EggType::EggType(string Name)
{
	NameOfType = Name;
	KitStages.resize(0);
}

// ���������� ����� ������
void EggType::SetKitStages(vector <Stage> kitStages)
{
	KitStages = kitStages;
}

// �������� ������ � ����� ������
void EggType::AppendStage(Stage oneStage)
{
	KitStages.push_back(oneStage);
}

// ������� ������ ������
vector <Stage> EggType::GetStages()
{
	return(KitStages);
}

// ������� ��������
string EggType::GetName()
{
	return NameOfType;
}