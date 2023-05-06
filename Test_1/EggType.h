#pragma once
#include "InterfaceEggType.h"

class EggType : public InterfaceEggType
{
private:

	static EggType* instance;


protected:
	EggType();

	EggType(string Name);

	// Набор стадий инкубирования
	vector <Stage> KitStages;

	// Номер текущей стадии
	//int CurrentStageNumber;

	// Название типа яиц
	DEF(string, NameOfType);

public:

	static EggType* Instance(string Name);
	static EggType* Instance();

	// Установить набор стадий
	void SetKitStages(vector <Stage> kitStages);

	// Добавить стадию в конец списка
	void AppendStage(Stage oneStage);

	// Вернуть список стадий
	vector <Stage> GetStages();

	// Вернуть название
	string GetName();
};

