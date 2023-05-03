#pragma once
#include "Heater.h"

// Увлажнитель
class Humidifier : public ImplementBooster
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
	bool UpOnePercent();

	vector <HumiditySensor>* GetSensors();
};

