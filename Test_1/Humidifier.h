#pragma once
#include "Heater.h"

// Увлажнитель
class Humidifier
{
private:
	// Набор сенсоров влажности
	vector <HumiditySensor>* HumidSensors;

public:

	Humidifier();

	void AddSensor(HumiditySensor humidSensor);

	// Задать сенсоры
	void SetHimidSensors(vector <HumiditySensor>* humidSensors);

	// Увеличить влажность всех датчиков на 1 процент
	bool WarmUpOnePercent();

	vector <HumiditySensor>* GetSensors();
};

