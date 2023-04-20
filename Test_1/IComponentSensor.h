#pragma once
#include "TemperatureSensorC0.h"

class IComponentSensor
{
protected:

	// ������� ��������� �������
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

	// �������� ��������� �� 1 �������
	void UpOneHimid()
	{
		AverageHumidity += 1;
	}

};

