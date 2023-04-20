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

