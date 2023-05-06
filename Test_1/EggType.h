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

	Memento* tempMemento;

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

	// Эмитация какой-то деятельности, в результате которой, меняется содержимое списка KitStages
	void EmitateWork()
	{
		
		if (KitStages.size() > 0)
		{
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "Оригинальные данные:" << endl;
			KitStages[0].DisplayStage();

			cout << endl;

			cout << "Создаем копию данных в Memento:" << endl << endl;
			tempMemento = new Memento(KitStages[0].get_TimeStageOfMilliSec(), KitStages[0].get_CountFlips(),
				KitStages[0].get_CountVentilations(), KitStages[0].get_MinTemerature(),
				KitStages[0].get_MaxTemerature(), KitStages[0].get_MinHumidity(), KitStages[0].get_MaxHumidity());

			cout << endl;

			cout << "Какая-то деятельность, в результате которой, меняется содержимое Стадии:" << endl;
			KitStages[0].set_CountFlips(10);
			KitStages[0].set_CountVentilations(10);
			KitStages[0].set_MaxHumidity(90);
			KitStages[0].set_MaxTemerature(40);
			KitStages[0].set_MinHumidity(70);
			KitStages[0].set_MinTemerature(30);
			KitStages[0].set_TimeStageOfMilliSec(10000);

			cout << endl;

			cout << "Данные после деятельности:" << endl;
			KitStages[0].DisplayStage();

			cout << endl;

			cout << "Восстановление данных" << endl;
			this->Beack();

			cout << endl;

			cout << "Восстановленные данные:" << endl;
			KitStages[0].DisplayStage();
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		}
	}

	void Beack()
	{
		if (tempMemento != NULL)
		{
			KitStages[0].set_CountFlips(tempMemento->get_CountFlips());
			KitStages[0].set_CountVentilations(tempMemento->get_CountVentilations());
			KitStages[0].set_MaxHumidity(tempMemento->get_MaxHumidity());
			KitStages[0].set_MaxTemerature(tempMemento->get_MaxTemerature());
			KitStages[0].set_MinHumidity(tempMemento->get_MinHumidity());
			KitStages[0].set_MinTemerature(tempMemento->get_MinTemerature());
			KitStages[0].set_TimeStageOfMilliSec(tempMemento->get_TimeStageOfMilliSec());
		}
	}
};

