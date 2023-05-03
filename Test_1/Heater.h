#pragma once
#include "Sensors.h"

// Нагреватель
class Heater
{

private:
	// Набор сенсоров температуры
	vector <TemperatureSensorC0>* TemperSensors;
	Factory* fact;
	int Size;

public:

	Heater();

	void AddSensor(TemperatureSensorC0 tempSensor);

	// Задать сенсоры
	void SetTempSensors(vector <TemperatureSensorC0>* temperSensors);

	void SetFactory(Factory* fact1, int size) { fact = fact1; Size = size; }

	// Нагреть все датчики на 0.1 градус
	bool WarmUpZeroOneDegreeC0();

	vector <TemperatureSensorC0>* GetSensors();
};

