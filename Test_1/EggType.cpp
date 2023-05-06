#include "EggType.h"


EggType* EggType::instance = NULL;


EggType* EggType::Instance(string Name) {
	if (instance == 0) {
		cout << "new object, type = " << Name << endl ;
		instance = new EggType(Name);
	}
	else cout << "object already exists! New = " << Name << " not set!" << endl;
	return instance;
}

EggType* EggType::Instance() {
	if (instance == 0) {
		cout << "new object \n";
		instance = new EggType();
	}
	else cout << "object already exists!\n";
	return instance;
}


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