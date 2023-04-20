#pragma once
#include "IComponentSensor.h"

// Датчик Влажности
class HumiditySensor : public IComponentSensor
{

public:
	HumiditySensor()
	{
		AverageHumidity = 50;
	}

	HumiditySensor(double humidity)
	{
		AverageHumidity = humidity;
	}

	// Установить среднюю Владность датчика
	void SetAverageHum(double humidity)
	{
		AverageHumidity = humidity;
	}

	// Получить влажность с датчика
	double GetHumidity()
	{
		return(this->GenericHumidity(AverageHumidity - 2, AverageHumidity + 2)); // Эмитируем работу датчиков
	}

	// Сгенерировать влажность для имитации работы датчика
	double GenericHumidity(double min, double max)
	{
		return (RandomNumbers::GetRandomInt(min, max));
	}

	// Повысить влажность на 1 процент
	void UpOneHimid()
	{
		AverageHumidity += 1;
	}

	// Понизить влажность на 1 процент
	void DownOneHimid()
	{
		AverageHumidity -= 1;
	}

};

