#pragma once
#include "HumiditySensor.h"


// Датчики температуры и влажности
// И методы работы с нимим как с одним целым
class Sensors
{
private:

	// Набор сенсоров температуры
	vector <TemperatureSensorC0> *TemperSensors;

	// Набор сенсоров влажности
	vector <HumiditySensor>* HumidSensors;

	Factory* fact;
	int Size = 0;

public:

	Sensors();

	// Задать сенсоры
	void SetHimidSensors(vector <HumiditySensor>* humidSensors);

	// Задать сенсоры
	void SetFact(Factory* fact1, int size) { fact = fact1; Size = size; }

	// Задать сенсоры
	void SetTempSensors(vector <TemperatureSensorC0>* temperSensors);

	double MinTemperature();	// Поиск минимума температуры
	double MaxTemperature();	// Поиск максимума температуры
	void SortTemperature();		// Сортировка температур

	double MinHummidity();		// Поиск минимума влажности
	double MaxHummidity();		// Поиск максимума влажности
	void SortHumidity();		// Сортировка влажности


	bool Poteri();				// Эмитация потерь температур и влажности,
								// которые происходят в настоящем инкубаторе

};

