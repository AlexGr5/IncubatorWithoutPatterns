#include "TemperatureSensorC0.h"

TemperatureSensorC0::TemperatureSensorC0()
{
    AverageTemperature = 37.5;
}

TemperatureSensorC0::TemperatureSensorC0(double temperaature)
{
    AverageTemperature = temperaature;
}

// Установить среднюю температуру датчика
void TemperatureSensorC0::SetAverageTemp(double temperaature)
{
    AverageTemperature = temperaature;
}

// Получить температуру с датчика
double TemperatureSensorC0::GetTemperatureC0()
{
    return(this->GenericTemperatureC0(AverageTemperature - 0.3, AverageTemperature + 0.3)); // Эмитируем работу датчиков
}

// Сгенерировать температуру для имитации работы датчика
double TemperatureSensorC0::GenericTemperatureC0(double min, double max)
{
    return (RandomNumbers::GetRandomDouble(min, max));
}

// Повысить температуру на 0.1 градус
void TemperatureSensorC0::UpZeroOneTemp()
{
    AverageTemperature += 0.1;
}

// Понизить температуру на 0.1 градус
void TemperatureSensorC0::DownZeroOneTemp()
{
    AverageTemperature -= 0.1;
}