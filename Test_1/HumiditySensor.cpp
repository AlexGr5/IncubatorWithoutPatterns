#include "HumiditySensor.h"

HumiditySensor::HumiditySensor()
{
	AverageHumidity = 50;
}

HumiditySensor::HumiditySensor(double humidity)
{
	AverageHumidity = humidity;
}

// Установить среднюю Владность датчика
void HumiditySensor::SetAverageHum(double humidity)
{
	AverageHumidity = humidity;
}

// Получить влажность с датчика
double HumiditySensor::GetHumidity()
{
	return(this->GenericHumidity(AverageHumidity - 2, AverageHumidity + 2)); // Эмитируем работу датчиков
}

// Сгенерировать влажность для имитации работы датчика
double HumiditySensor::GenericHumidity(double min, double max)
{
	return (RandomNumbers::GetRandomInt(min, max));
}

// Повысить влажность на 1 процент
void HumiditySensor::UpOneHimid()
{
	AverageHumidity += 1;
}

// Понизить влажность на 1 процент
void HumiditySensor::DownOneHimid()
{
	AverageHumidity -= 1;
}