#pragma once
#include "TemperatureSensorC0.h"

class IComponentSensor
{
protected:

	// Средняя Влажность датчика
	double AverageHumidity;

public:

	IComponentSensor()
	{
		AverageHumidity = 0;
	}

	IComponentSensor(double humidity)
	{
		AverageHumidity = humidity;
	}

	double GetValue()
	{
		return AverageHumidity;
	}

	void SetValue( double value)
	{
		AverageHumidity = value;
	}

	// Повысить влажность на 1 процент
	void UpOneHimid()
	{
		AverageHumidity += 1;
	}

};

