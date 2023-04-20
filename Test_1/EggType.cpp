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

// Установить набор стадий
void EggType::SetKitStages(vector <Stage> kitStages)
{
	KitStages = kitStages;
}

// Добавить стадию в конец списка
void EggType::AppendStage(Stage oneStage)
{
	KitStages.push_back(oneStage);
}

// Вернуть список стадий
vector <Stage> EggType::GetStages()
{
	return(KitStages);
}

// Вернуть название
string EggType::GetName()
{
	return NameOfType;
}