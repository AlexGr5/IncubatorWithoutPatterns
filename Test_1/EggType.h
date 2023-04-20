#pragma once
#include "InterfaceEggType.h"

class EggType : public InterfaceEggType
{
private:

	// Набор стадий инкубирования
	vector <Stage> KitStages;

	// Номер текущей стадии
	//int CurrentStageNumber;

	// Название типа яиц
	DEF(string, NameOfType);

public:

	EggType();

	EggType(string Name);

	// Установить набор стадий
	void SetKitStages(vector <Stage> kitStages);

	// Добавить стадию в конец списка
	void AppendStage(Stage oneStage);

	// Вернуть список стадий
	vector <Stage> GetStages();

	// Вернуть название
	string GetName();
};

