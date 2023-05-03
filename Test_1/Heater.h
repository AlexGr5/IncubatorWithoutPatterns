#pragma once
#include "CountTimeUpTemp.h"

// Нагреватель
class Heater
{

private:
	// Набор сенсоров температуры
	vector <TemperatureSensorC0>* TemperSensors;

public:

	Heater();

	void AddSensor(TemperatureSensorC0 tempSensor);

	// Задать сенсоры
	void SetTempSensors(vector <TemperatureSensorC0>* temperSensors);

	// Нагреть все датчики на 0.1 градус
	bool WarmUpZeroOneDegreeC0();

	vector <TemperatureSensorC0>* GetSensors();
};

