#pragma once
#include "Stage.h"

class InterfaceEggType
{

	// Установить набор стадий
	virtual void SetKitStages(vector <Stage> kitStages) = 0;

	// Добавить стадию в конец списка
	virtual void AppendStage(Stage oneStage) = 0;

	// Вернуть список стадий
	virtual vector <Stage> GetStages() = 0;

};

