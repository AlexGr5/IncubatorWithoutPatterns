#pragma once
#include "TemperatureSensorC0.h"

// Датчик Влажности
class HumiditySensor
{
private:
	
	// Средняя Влажность датчика
	double AverageHumidity;

public:
	double GetHumidity();			// Получить влажность с датчика

	HumiditySensor();

	HumiditySensor(double humidity);

	// Установить среднюю Владность датчика
	void SetAverageHum(double humidity);

	// Повысить влажность на 1 процент
	void UpOneHimid();

	// Понизить влажность на 1 процент
	void DownOneHimid();

protected:

	// Сгенерировать влажность для имитации работы датчика
	double GenericHumidity(double min, double max);

};

