#pragma once
#include "RandomNumbers.h"

// Датчик температуры
class TemperatureSensorC0
{
private:

	// Средняя температура датчика
	double AverageTemperature;

public:

	TemperatureSensorC0();

	TemperatureSensorC0(double temperaature);

	// Получить температуру с датчика
	double GetTemperatureC0();

	// Установить среднюю температуру датчика
	void SetAverageTemp(double temperaature);

	// Повысить температуру на 0.1 градус
	void UpZeroOneTemp();

	// Понизить температуру на 0.1 градус
	void DownZeroOneTemp();

protected:

	// Сгенерировать температуру для имитации работы датчика
	double GenericTemperatureC0(double min, double max);

};