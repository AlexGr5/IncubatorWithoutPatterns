#pragma once
#include "InterfaceStage.h"


class Stage
{

public:
	Stage();

	void SetStage(double timeStageOfMilliSec,
		int countFlips, int countVentilations,
		double minTemerature, double maxTemerature,
		double minHumidity, double maxHumidity);

	void DisplayStage()
	{
		cout << "Стадия: " << endl;
		cout << "TimeStageOfMilliSec " << TimeStageOfMilliSec << endl;
		cout << "CountFlips " << CountFlips << endl;
		cout << "CountVentilations " << CountVentilations << endl;
		cout << "MinTemerature " << MinTemerature << endl;
		cout << "MaxTemerature " << MaxTemerature << endl;
		cout << "MinHumidity " << MinHumidity << endl;
		cout << "MaxHumidity " << MaxHumidity << endl;
	}

private:

	// Веремменной промежуток в милисекунда
	DEF(double, TimeStageOfMilliSec);

	// Количество переворотов
	DEF(int, CountFlips);

	// Количество проветриваний
	DEF(int, CountVentilations);

	// Минимальная и максимальные температуры
	DEF(double, MinTemerature);
	DEF(double, MaxTemerature);

	// Минимальные и максимальные влажности
	DEF(double, MinHumidity);
	DEF(double, MaxHumidity);

};


class Memento
{

public:
	Memento()
	{
		TimeStageOfMilliSec = 5000;

		CountFlips = 2;

		CountVentilations = 2;

		MinTemerature = 36.5;
		MaxTemerature = 38.5;

		MinHumidity = 45;
		MaxHumidity = 60;

	}

	Memento(double timeStageOfMilliSec,
		int countFlips, int countVentilations,
		double minTemerature, double maxTemerature,
		double minHumidity, double maxHumidity)
	{
		TimeStageOfMilliSec = timeStageOfMilliSec;

		CountFlips = countFlips;

		CountVentilations = countVentilations;

		MinTemerature = minTemerature;
		MaxTemerature = maxTemerature;

		MinHumidity = minHumidity;
		MaxHumidity = maxHumidity;
	}

	void SetMemento(double timeStageOfMilliSec,
		int countFlips, int countVentilations,
		double minTemerature, double maxTemerature,
		double minHumidity, double maxHumidity)
	{
		TimeStageOfMilliSec = timeStageOfMilliSec;

		CountFlips = countFlips;

		CountVentilations = countVentilations;

		MinTemerature = minTemerature;
		MaxTemerature = maxTemerature;

		MinHumidity = minHumidity;
		MaxHumidity = maxHumidity;
	}


private:

	// Времменный промежуток в милисекунда
	DEF(double, TimeStageOfMilliSec);

	// Количество переворотов
	DEF(int, CountFlips);

	// Количество проветриваний
	DEF(int, CountVentilations);

	// Минимальная и максимальные температуры
	DEF(double, MinTemerature);
	DEF(double, MaxTemerature);

	// Минимальные и максимальные влажности
	DEF(double, MinHumidity);
	DEF(double, MaxHumidity);


	
};

